import pandas as pd
import numpy as np
from scipy import optimize, stats
import matplotlib.pyplot as plt
from sklearn.metrics import r2_score, mean_squared_error, mean_absolute_error
import seaborn as sns
from datetime import datetime
from sklearn.model_selection import train_test_split
from scipy import signal  # 添加这行导入

# 复用第一问的数据加载函数
def load_and_preprocess_data(file_path, train_size=702):
    """读取和预处理数据，并分割为训练集和测试集"""
    print("\n=== Data Loading and Preprocessing ===")
    
    # 读取CSV文件
    df = pd.read_csv(file_path, usecols=[1, 2], names=['MJD', 'PT_TT'])
    df['Time'] = df['MJD'] - df['MJD'].min()
    
    # 分割训练集和测试集
    train_df = df.iloc[:train_size]
    test_df = df.iloc[train_size:]
    
    print(f"\nData Summary:")
    print(f"Training set size: {len(train_df)}")
    print(f"Test set size: {len(test_df)}")
    print(f"Training time span: {train_df['MJD'].min():.2f} to {train_df['MJD'].max():.2f} MJD")
    print(f"Test time span: {test_df['MJD'].min():.2f} to {test_df['MJD'].max():.2f} MJD")
    
    return train_df, test_df

def complex_timing_model(t, *params):
    """增强的组合模型"""
    A1, w1, phi1 = params[0:3]
    A2, w2, phi2 = params[3:6]
    A3, w3, phi3 = params[6:9]
    a, b, c, d = params[9:13]  # 趋势项系数
    k1, k2 = params[13:15]  # 修改为两个调制项系数
    
    t_norm = (t - np.mean(t)) / np.std(t)
    
    # 增加更复杂的趋势项
    trend = a + b * t_norm + c * t_norm**2 + d * t_norm**3
    
    # 简化调制项，只使用两个参数
    modulation = k1 * np.exp(-k2 * t_norm)
    
    # 原有的周期项
    main_component = A1 * np.sin(w1 * t + phi1)
    harmonic1 = A2 * np.sin(w2 * t + phi2)
    harmonic2 = A3 * np.sin(w3 * t + phi3)
    
    return main_component + harmonic1 + harmonic2 + trend + modulation

def sliding_window_prediction(train_df, test_df, window_size=180):
    """滑动窗口预测"""
    predictions = []
    confidences = []
    
    # 初始训练窗口
    current_window = train_df.copy()
    
    for i in range(len(test_df)):
        # 训练模型
        model_params = train_prediction_model(current_window)
        
        # 预测下一个点
        next_point = test_df.iloc[i:i+1]
        pred, conf = make_predictions(model_params, next_point, np.std(current_window['PT_TT']))
        
        predictions.append(pred[0])
        confidences.append(conf)
        
        # 更新窗口
        current_window = pd.concat([current_window.iloc[1:], next_point])
    
    return np.array(predictions), np.mean(confidences)
def calculate_confidence_interval(residuals, predictions, alpha=0.05):
    """改进的置信区间计算"""
    # 使用残差的分位数
    z_score = stats.norm.ppf(1 - alpha/2)
    
    # 计算预测标准误差
    std_err = np.std(residuals)
    
    # 考虑预测距离的影响
    time_factor = np.linspace(1, 1.5, len(predictions))
    
    # 计算动态置信区间
    confidence_interval = z_score * std_err * time_factor
    
    return confidence_interval
# 预测模型训练函数
def train_prediction_model(train_df):
    """训练预测模型并返回最优参数"""
    print("\n=== Training Prediction Model ===")
    t = train_df['Time'].values
    y = train_df['PT_TT'].values
    
    # 修改参数边界，确保与模型参数数量一致
    bounds = [
        (-0.2, 0.2),   # A1
        (0.0001, 0.1), # w1
        (-np.pi, np.pi), # phi1
        (-0.2, 0.2),   # A2
        (0.0001, 0.1), # w2
        (-np.pi, np.pi), # phi2
        (-0.2, 0.2),   # A3
        (0.0001, 0.1), # w3
        (-np.pi, np.pi), # phi3
        (-0.2, 0.2),   # a
        (-0.2, 0.2),   # b
        (-0.2, 0.2),   # c
        (-0.2, 0.2),   # d
        (-0.2, 0.2),   # k1
        (0.0001, 0.1)  # k2
    ]
    
    # 全局优化
    result = optimize.differential_evolution(
        lambda p: np.sum((y - complex_timing_model(t, *p))**2),
        bounds=bounds,
        maxiter=1000,
        popsize=20,
        mutation=(0.5, 1.0),
        recombination=0.7,
        seed=42
    )
    
    # 局部优化
    try:
        popt, pcov = optimize.curve_fit(
            complex_timing_model,
            t,
            y,
            p0=result.x,
            method='lm',
            maxfev=10000
        )
    except Exception as e:
        print(f"Local optimization failed: {str(e)}")
        popt = result.x
    
    return popt

def make_staged_predictions(model_params, df_future, train_std, stage_length=30):
    """分段预测函数"""
    predictions = []
    confidences = []
    
    # 按固定时间长度分段预测
    for i in range(0, len(df_future), stage_length):
        stage_df = df_future.iloc[i:i+stage_length]
        stage_pred, stage_conf = make_predictions(model_params, stage_df, train_std)
        
        # 对每段预测结果进行校正
        if i > 0:
            # 使用前一段的结果调整当前预测
            adjust_factor = predictions[-1][-1] / stage_pred[0]
            stage_pred = stage_pred * adjust_factor
            
        predictions.append(stage_pred)
        confidences.append(stage_conf)
    
    return np.concatenate(predictions), np.mean(confidences)

# 预测评估函数
def evaluate_predictions(predictions, test_df, confidence_interval):
    """评估预测结果"""
    print("\n=== Prediction Evaluation ===")
    
    # 计算预测指标
    rmse = np.sqrt(mean_squared_error(test_df['PT_TT'], predictions))
    mae = mean_absolute_error(test_df['PT_TT'], predictions)
    r2 = r2_score(test_df['PT_TT'], predictions)
    
    print(f"Prediction Metrics:")
    print(f"RMSE: {rmse:.6f} seconds")
    print(f"MAE: {mae:.6f} seconds")
    print(f"R² Score: {r2:.6f}")
    
    # 计算预测区间覆盖率
    coverage = np.mean(
        (test_df['PT_TT'] >= predictions - confidence_interval) & 
        (test_df['PT_TT'] <= predictions + confidence_interval)
    )
    print(f"95% Confidence Interval Coverage: {coverage*100:.2f}%")
    
    return rmse, mae, r2, coverage

# 绘制预测结果
def plot_predictions(train_df, test_df, predictions, confidence_interval, r2):
    """可视化预测结果"""
    plt.figure(figsize=(15, 10))
    
    # 绘制训练数据
    plt.plot(train_df['MJD'], train_df['PT_TT'], 'b.', 
             label='Training Data', alpha=0.6, markersize=2)
    
    # 绘制测试数据
    plt.plot(test_df['MJD'], test_df['PT_TT'], 'g.', 
             label='Test Data', alpha=0.6, markersize=2)
    
    # 绘制预测结果
    plt.plot(test_df['MJD'], predictions, 'r-', 
             label=f'Predictions (R² = {r2:.4f})', linewidth=1.5)
    
    # 绘制置信区间
    plt.fill_between(test_df['MJD'], 
                     predictions - confidence_interval,
                     predictions + confidence_interval,
                     color='r', alpha=0.2, 
                     label='95% Confidence Interval')
    
    plt.xlabel('Modified Julian Date (days)')
    plt.ylabel('PT-TT (s)')
    plt.title('Pulsar Timing Noise: Predictions vs Actual')
    plt.legend()
    plt.grid(True)
    plt.show()

def make_predictions(model_params, df_future, train_std):
    """进行预测并计算置信区间
    
    参数:
        model_params: 模型参数
        df_future: 需要预测的数据集
        train_std: 训练集的标准差
    
    返回:
        predictions: 预测值数组
        confidence_interval: 置信区间
    """
    # 使用模型进行预测
    predictions = complex_timing_model(df_future['Time'].values, *model_params)
    
    # 计算残差
    residuals = df_future['PT_TT'].values - predictions
    
    # 计算置信区间
    confidence_interval = calculate_confidence_interval(residuals, predictions)
    
    return predictions, confidence_interval

def plot_detailed_analysis(train_df, test_df, predictions, model_params, confidence_interval):
    """创建详细的分析图表"""
    # 设置全局绘图样式
    plt.style.use('fivethirtyeight')
    plt.rcParams['font.family'] = 'Times New Roman'
    plt.rcParams['font.size'] = 12
    
    # 创建一个2x2的子图布局
    fig = plt.figure(figsize=(20, 16))
    
    # 1. 完整的预测图
    ax1 = fig.add_subplot(221)
    ax1.plot(train_df['MJD'], train_df['PT_TT'], 'b.', label='Training Data', alpha=0.6, markersize=2)
    ax1.plot(test_df['MJD'], test_df['PT_TT'], 'g.', label='Test Data', alpha=0.6, markersize=2)
    ax1.plot(test_df['MJD'], predictions, 'r-', label='Predictions', linewidth=1.5)
    ax1.fill_between(test_df['MJD'], 
                     predictions - confidence_interval,
                     predictions + confidence_interval,
                     color='r', alpha=0.2, 
                     label='95% Confidence Interval')
    ax1.set_xlabel('Modified Julian Date (days)')
    ax1.set_ylabel('PT-TT (s)')
    ax1.set_title('Complete Time Series Analysis')
    ax1.legend()
    ax1.grid(True)
    
    # 2. 残差分析
    ax2 = fig.add_subplot(222)
    residuals = test_df['PT_TT'].values - predictions
    ax2.hist(residuals, bins=50, density=True, alpha=0.7, color='blue')
    ax2.set_xlabel('Residuals (s)')
    ax2.set_ylabel('Density')
    ax2.set_title('Residuals Distribution')
    
    # 添加正态分布拟合曲线
    xmin, xmax = ax2.get_xlim()
    x = np.linspace(xmin, xmax, 100)
    mean = np.mean(residuals)
    std = np.std(residuals)
    p = stats.norm.pdf(x, mean, std)
    ax2.plot(x, p, 'r-', lw=2, label=f'Normal Dist.\n(μ={mean:.2e}, σ={std:.2e})')
    ax2.legend()
    
    # 3. 模型各组件分解
    ax3 = fig.add_subplot(223)
    t = test_df['Time'].values
    t_norm = (t - np.mean(t)) / np.std(t)
    
    # 分解各个组件
    A1, w1, phi1 = model_params[0:3]
    main_component = A1 * np.sin(w1 * t + phi1)
    
    trend = (model_params[9] + model_params[10] * t_norm + 
            model_params[11] * t_norm**2 + model_params[12] * t_norm**3)
    
    modulation = model_params[13] * np.exp(-model_params[14] * t_norm)
    
    ax3.plot(test_df['MJD'], main_component, label='Main Periodic', alpha=0.7)
    ax3.plot(test_df['MJD'], trend, label='Trend', alpha=0.7)
    ax3.plot(test_df['MJD'], modulation, label='Modulation', alpha=0.7)
    ax3.set_xlabel('Modified Julian Date (days)')
    ax3.set_ylabel('Component Value (s)')
    ax3.set_title('Model Component Decomposition')
    ax3.legend()
    ax3.grid(True)
    
    # 4. 预测误差随时间变化
    ax4 = fig.add_subplot(224)
    abs_errors = np.abs(residuals)
    ax4.plot(test_df['MJD'], abs_errors, 'b-', alpha=0.6)
    ax4.set_xlabel('Modified Julian Date (days)')
    ax4.set_ylabel('Absolute Error (s)')
    ax4.set_title('Prediction Error Over Time')
    
    # 添加移动平均线
    window = 20
    moving_avg = pd.Series(abs_errors).rolling(window=window).mean()
    ax4.plot(test_df['MJD'], moving_avg, 'r-', 
             label=f'{window}-point Moving Average', linewidth=2)
    ax4.legend()
    ax4.grid(True)
    
    plt.tight_layout()
    plt.savefig('detailed_analysis.png', dpi=300, bbox_inches='tight')
    plt.show()

def print_detailed_results(model_params, predictions, test_df, r2, rmse, mae):
    """打印详细的分析结果"""
    print("\n====== 详细分析结果 ======")
    
    # 1. 模型参数及其物理含义
    print("\n1. 模型参数解释:")
    param_names = ['A1', 'w1', 'phi1', 'A2', 'w2', 'phi2', 'A3', 'w3', 'phi3',
                  'a', 'b', 'c', 'd', 'k1', 'k2']
    param_descriptions = [
        '主周期振幅', '主周期频率', '主周期相位',
        '第一谐波振幅', '第一谐波频率', '第一谐波相位',
        '第二谐波振幅', '第二谐波频率', '第二谐波相位',
        '趋势常数项', '趋势一次项', '趋势二次项', '趋势三次项',
        '调制振幅', '调制衰减率'
    ]
    
    for name, value, desc in zip(param_names, model_params, param_descriptions):
        print(f"{name:4s}: {value:12.6f} - {desc}")
    
    # 2. 周期分析
    print("\n2. 周期分析:")
    periods = [2*np.pi/w for w in [model_params[1], model_params[4], model_params[7]]]
    for i, p in enumerate(periods, 1):
        print(f"周期 {i}: {p:.2f} 天")
    
    # 3. 预测性能统计
    print("\n3. 预测性能统计:")
    print(f"R² Score: {r2:.6f}")
    print(f"RMSE: {rmse:.6f} seconds")
    print(f"MAE: {mae:.6f} seconds")
    
    # 4. 残差分析
    residuals = test_df['PT_TT'].values - predictions
    print("\n4. 残差分析:")
    print(f"残差均值: {np.mean(residuals):.6e}")
    print(f"残差标准差: {np.std(residuals):.6e}")
    print(f"残差偏度: {stats.skew(residuals):.6f}")
    print(f"残差峰度: {stats.kurtosis(residuals):.6f}")
    
    # 5. 输出拟合函数表达式
    print("\n5. 拟合函数表达式:")
    print("PT-TT(t) = ")
    print(f"    {model_params[0]:.6f}*sin({model_params[1]:.6f}*t + {model_params[2]:.6f}) +")
    print(f"    {model_params[3]:.6f}*sin({model_params[4]:.6f}*t + {model_params[5]:.6f}) +")
    print(f"    {model_params[6]:.6f}*sin({model_params[7]:.6f}*t + {model_params[8]:.6f}) +")
    print(f"    {model_params[9]:.6f} + {model_params[10]:.6f}*t_norm + " +
          f"{model_params[11]:.6f}*t_norm² + {model_params[12]:.6f}*t_norm³ +")
    print(f"    {model_params[13]:.6f}*exp(-{model_params[14]:.6f}*t_norm)")

def plot_time_series(train_df, test_df, predictions, confidence_interval, r2):
    """绘制完整的时间序列预测图"""
    plt.figure(figsize=(15, 8))
    plt.style.use('fivethirtyeight')
    plt.rcParams['font.family'] = 'Times New Roman'
    plt.rcParams['font.size'] = 12
    
    plt.plot(train_df['MJD'], train_df['PT_TT'], 'b.', 
             label='Training Data', alpha=0.6, markersize=2)
    plt.plot(test_df['MJD'], test_df['PT_TT'], 'g.', 
             label='Test Data', alpha=0.6, markersize=2)
    plt.plot(test_df['MJD'], predictions, 'r-', 
             label=f'Predictions (R² = {r2:.4f})', linewidth=1.5)
    
    plt.fill_between(test_df['MJD'], 
                     predictions - confidence_interval,
                     predictions + confidence_interval,
                     color='r', alpha=0.2, 
                     label='95% Confidence Interval')
    
    plt.xlabel('Modified Julian Date (days)')
    plt.ylabel('PT-TT (s)')
    plt.title('Complete Time Series Analysis')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig('time_series_analysis.png', dpi=300, bbox_inches='tight')
    plt.show()

def plot_residuals_distribution(test_df, predictions):
    """绘制残差分布图"""
    plt.figure(figsize=(12, 8))
    plt.style.use('fivethirtyeight')
    plt.rcParams['font.family'] = 'Times New Roman'
    plt.rcParams['font.size'] = 12
    
    residuals = test_df['PT_TT'].values - predictions
    plt.hist(residuals, bins=50, density=True, alpha=0.7, color='blue', label='Residuals')
    
    # 添加正态分布拟合曲线
    xmin, xmax = plt.xlim()
    x = np.linspace(xmin, xmax, 100)
    mean = np.mean(residuals)
    std = np.std(residuals)
    p = stats.norm.pdf(x, mean, std)
    plt.plot(x, p, 'r-', lw=2, label=f'Normal Distribution\n(μ={mean:.2e}, σ={std:.2e})')
    
    plt.xlabel('Residuals (s)')
    plt.ylabel('Density')
    plt.title('Residuals Distribution Analysis')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig('residuals_distribution.png', dpi=300, bbox_inches='tight')
    plt.show()

def plot_model_components(test_df, model_params):
    """绘制模型各组件分解图"""
    plt.figure(figsize=(15, 8))
    plt.style.use('fivethirtyeight')
    plt.rcParams['font.family'] = 'Times New Roman'
    plt.rcParams['font.size'] = 12
    
    t = test_df['Time'].values
    t_norm = (t - np.mean(t)) / np.std(t)
    
    # 分解各个组件
    A1, w1, phi1 = model_params[0:3]
    A2, w2, phi2 = model_params[3:6]
    A3, w3, phi3 = model_params[6:9]
    
    # 计算各个组件
    main_component = A1 * np.sin(w1 * t + phi1)
    harmonic1 = A2 * np.sin(w2 * t + phi2)
    harmonic2 = A3 * np.sin(w3 * t + phi3)
    trend = (model_params[9] + model_params[10] * t_norm + 
            model_params[11] * t_norm**2 + model_params[12] * t_norm**3)
    modulation = model_params[13] * np.exp(-model_params[14] * t_norm)
    
    plt.plot(test_df['MJD'], main_component, label='Main Periodic Component', alpha=0.7)
    plt.plot(test_df['MJD'], harmonic1, label='First Harmonic', alpha=0.7)
    plt.plot(test_df['MJD'], harmonic2, label='Second Harmonic', alpha=0.7)
    plt.plot(test_df['MJD'], trend, label='Trend Component', alpha=0.7)
    plt.plot(test_df['MJD'], modulation, label='Modulation Component', alpha=0.7)
    
    plt.xlabel('Modified Julian Date (days)')
    plt.ylabel('Component Value (s)')
    plt.title('Model Component Decomposition')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig('model_components.png', dpi=300, bbox_inches='tight')
    plt.show()

def plot_prediction_error(test_df, predictions):
    """绘制预测误差随时间变化图"""
    plt.figure(figsize=(15, 8))
    plt.style.use('fivethirtyeight')
    plt.rcParams['font.family'] = 'Times New Roman'
    plt.rcParams['font.size'] = 12
    
    residuals = test_df['PT_TT'].values - predictions
    abs_errors = np.abs(residuals)
    
    plt.plot(test_df['MJD'], abs_errors, 'b-', alpha=0.6, label='Absolute Error')
    
    # 添加移动平均线
    window = 20
    moving_avg = pd.Series(abs_errors).rolling(window=window).mean()
    plt.plot(test_df['MJD'], moving_avg, 'r-', 
             label=f'{window}-point Moving Average', linewidth=2)
    
    plt.xlabel('Modified Julian Date (days)')
    plt.ylabel('Absolute Error (s)')
    plt.title('Prediction Error Over Time')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig('prediction_error.png', dpi=300, bbox_inches='tight')
    plt.show()

def plot_periodogram(train_df):
    """绘制周期图分析"""
    plt.figure(figsize=(15, 8))
    plt.style.use('fivethirtyeight')
    plt.rcParams['font.family'] = 'Times New Roman'
    plt.rcParams['font.size'] = 12
    
    # 计算周期图
    frequencies = np.linspace(0.001, 0.1, 1000)
    pgram = signal.lombscargle(train_df['Time'], 
                              train_df['PT_TT'], 
                              frequencies)
    
    # 转换为周期
    periods = 2*np.pi/frequencies
    
    plt.plot(periods, pgram)
    plt.xlabel('Period (days)')
    plt.ylabel('Power Spectral Density')
    plt.title('Lomb-Scargle Periodogram Analysis')
    plt.grid(True)
    plt.tight_layout()
    plt.savefig('periodogram.png', dpi=300, bbox_inches='tight')
    plt.show()

def main():
    # 记录开始时间
    start_time = datetime.now()
    print(f"Analysis started at: {start_time.strftime('%Y-%m-%d %H:%M:%S')}")
    
    # 加载和预处理数据
    train_df, test_df = load_and_preprocess_data('Attachment1.csv')
    
    # 训练预测模型
    model_params = train_prediction_model(train_df)
    
    # 计算训练集标准差（用于置信区间）
    train_std = np.std(train_df['PT_TT'] - 
                      complex_timing_model(train_df['Time'].values, *model_params))
    
    # 进行预测
    predictions, confidence_interval = make_predictions(model_params, test_df, train_std)
    
    # 评估预测结果
    rmse, mae, r2, coverage = evaluate_predictions(predictions, test_df, confidence_interval)
    
    # 绘制各种图表
    plot_time_series(train_df, test_df, predictions, confidence_interval, r2)
    plot_residuals_distribution(test_df, predictions)
    plot_model_components(test_df, model_params)
    plot_prediction_error(test_df, predictions)
    plot_periodogram(train_df)
    
    # 添加详细分析
    print_detailed_results(model_params, predictions, test_df, r2, rmse, mae)
    plot_detailed_analysis(train_df, test_df, predictions, model_params, confidence_interval)
    
    # 输出模型参数
    print("\n=== Model Parameters ===")
    param_names = ['A1', 'w1', 'phi1', 'A2', 'w2', 'phi2', 'A3', 'w3', 'phi3',
                  'a', 'b', 'c', 'd', 'k1', 'k2']
    for name, value in zip(param_names, model_params):
        print(f"{name:4s}: {value:10.6f}")
    
    # 记录结束时间
    end_time = datetime.now()
    duration = end_time - start_time
    print(f"\nAnalysis completed at: {end_time.strftime('%Y-%m-%d %H:%M:%S')}")
    print(f"Total duration: {duration}")
    
    return model_params, predictions, confidence_interval, r2

if __name__ == "__main__":
    model_params, predictions, confidence_interval, r2 = main()