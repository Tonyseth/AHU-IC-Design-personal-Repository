import pandas as pd
import numpy as np
from scipy import optimize, stats
import matplotlib.pyplot as plt
from sklearn.metrics import r2_score, mean_squared_error, mean_absolute_error
import seaborn as sns
from datetime import datetime

# 1. 数据读取和预处理
def load_and_preprocess_data(file_path):
    """读取和预处理数据，并输出基本统计信息"""
    print("\n=== Data Loading and Preprocessing ===")
    
    # 读取CSV文件
    df = pd.read_csv(file_path, usecols=[1, 2], names=['MJD', 'PT_TT'])
    df['Time'] = df['MJD'] - df['MJD'].min()
    
    # 输出数据基本信息
    print(f"\nData Summary:")
    print(f"Time span: {df['MJD'].min():.2f} to {df['MJD'].max():.2f} MJD")
    print(f"Duration: {df['MJD'].max() - df['MJD'].min():.2f} days")
    print(f"Number of observations: {len(df)}")
    print("\nTiming Residuals Statistics:")
    print(f"Mean: {df['PT_TT'].mean():.6f} seconds")
    print(f"Std Dev: {df['PT_TT'].std():.6f} seconds")
    print(f"Max: {df['PT_TT'].max():.6f} seconds")
    print(f"Min: {df['PT_TT'].min():.6f} seconds")
    
    return df

# 2. 定义复杂的拟合模型
def complex_timing_model(t, *params):
    """组合模型包含多个组件，每个组件的贡献都会被记录"""
    A1, w1, phi1 = params[0:3]  # 主周期项
    A2, w2, phi2 = params[3:6]  # 第一谐波
    A3, w3, phi3 = params[6:9]  # 第二谐波
    a, b, c = params[9:12]      # 趋势项系数
    k1, k2 = params[12:14]      # 调制项系数
    
    t_norm = (t - np.mean(t)) / np.std(t)
    
    # 计算各个组件
    main_component = A1 * np.sin(w1 * t + phi1)
    harmonic1 = A2 * np.sin(w2 * t + phi2)
    harmonic2 = A3 * np.sin(w3 * t + phi3)
    trend = a + b * t_norm + c * t_norm**2
    modulation = k1 * np.exp(-k2 * t_norm)
    
    return main_component + harmonic1 + harmonic2 + trend + modulation, \
           (main_component, harmonic1, harmonic2, trend, modulation)

# 3. 模型训练函数
def train_model(df):
    """训练模型并输出优化过程信息"""
    print("\n=== Model Training ===")
    t = df['Time'].values
    y = df['PT_TT'].values
    
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
        (-0.2, 0.2),   # k1
        (0.0001, 0.1)  # k2
    ]
    
    # 优化过程
    print("\nPerforming global optimization...")
    result = optimize.differential_evolution(
        lambda p: np.sum((y - complex_timing_model(t, *p)[0])**2),
        bounds=bounds,
        maxiter=1000,
        popsize=20,
        mutation=(0.5, 1.0),
        recombination=0.7,
        seed=42
    )
    
    print("\nGlobal optimization results:")
    print(f"Success: {result.success}")
    print(f"Number of iterations: {result.nit}")
    print(f"Final optimization score: {result.fun:.6f}")
    
    # 局部优化
    print("\nPerforming local optimization...")
    try:
        popt, pcov = optimize.curve_fit(
            lambda t, *p: complex_timing_model(t, *p)[0],
            t,
            y,
            p0=result.x,
            method='lm',
            maxfev=10000
        )
        print("Local optimization successful")
    except Exception as e:
        print(f"Local optimization failed: {str(e)}")
        popt = result.x
    
    return popt

# 4. 模型评估函数
def evaluate_model(df, params):
    """详细评估模型性能，包括各组件的贡献"""
    print("\n=== Model Evaluation ===")
    t = df['Time'].values
    y = df['PT_TT'].values
    
    # 获取预测值和各组件
    y_pred, components = complex_timing_model(t, *params)
    main_comp, harm1, harm2, trend, mod = components
    
    # 计算各种性能指标
    r2 = r2_score(y, y_pred)
    rmse = np.sqrt(mean_squared_error(y, y_pred))
    mae = mean_absolute_error(y, y_pred)
    
    print("\nModel Performance Metrics:")
    print(f"R² Score: {r2:.6f}")
    print(f"RMSE: {rmse:.6f} seconds")
    print(f"MAE: {mae:.6f} seconds")
    
    # 分析各组件的贡献
    print("\nComponent Analysis:")
    components_dict = {
        'Main Period': main_comp,
        'First Harmonic': harm1,
        'Second Harmonic': harm2,
        'Trend': trend,
        'Modulation': mod
    }
    
    for name, comp in components_dict.items():
        variance = np.var(comp)
        contribution = (variance / np.var(y_pred)) * 100
        print(f"{name:15s} - Variance: {variance:.6f}, Contribution: {contribution:.2f}%")
    
    # 计算残差统计
    residuals = y - y_pred
    print("\nResiduals Analysis:")
    print(f"Mean of residuals: {np.mean(residuals):.6e} seconds")
    print(f"Std of residuals: {np.std(residuals):.6e} seconds")
    
    # 添加周期分析
    print("\nPeriod Analysis:")
    A1, w1, _, A2, w2, _, A3, w3, _ = params[:9]
    periods = [2*np.pi/w for w in [w1, w2, w3]]
    amplitudes = [A1, A2, A3]
    for i, (period, amp) in enumerate(zip(periods, amplitudes), 1):
        print(f"Component {i}: Period = {period:.2f} days, Amplitude = {abs(amp):.6f} seconds")
    
    # 添加趋势分析
    a, b, c = params[9:12]
    print("\nTrend Analysis:")
    print(f"Linear trend coefficient: {b:.6e}")
    print(f"Quadratic trend coefficient: {c:.6e}")
    
    # 添加调制分析
    k1, k2 = params[12:14]
    print("\nModulation Analysis:")
    print(f"Modulation amplitude: {k1:.6e}")
    print(f"Decay rate: {k2:.6e}")
    
    # 添加拟合优度检验
    chi_square = np.sum((y - y_pred)**2 / np.abs(y_pred))
    print(f"\nChi-square statistic: {chi_square:.6f}")
    
    # 添加自相关分析
    acf = np.correlate(residuals, residuals, mode='full')[len(residuals)-1:]
    acf = acf / acf[0]
    print("\nAutocorrelation of residuals:")
    print(f"Lag-1 autocorrelation: {acf[1]:.6f}")
    
    return r2, rmse, y_pred, components, residuals, acf

# 5. 增强的可视化函数
def plot_results(df, y_pred, components, residuals, r2, acf):
    """Enhanced visualization function with English labels"""
    # Set global plot style
    plt.style.use('fivethirtyeight')
    
    # 1. Original data vs fitted results
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(15, 12), height_ratios=[2, 1])
    
    # Upper panel: Data and fit
    ax1.scatter(df['MJD'], df['PT_TT'], c='blue', s=2, alpha=0.5, label='Observations')
    ax1.plot(df['MJD'], y_pred, 'r-', linewidth=2, label=f'Fitted Model (R² = {r2:.4f})')
    ax1.set_xlabel('Modified Julian Date (MJD)')
    ax1.set_ylabel('PT-TT (seconds)')
    ax1.set_title('Pulsar Timing Noise: Observations vs. Fitted Model', fontsize=14, pad=20)
    ax1.legend(fontsize=10)
    ax1.grid(True, alpha=0.3)
    
    # Lower panel: Residuals
    ax2.scatter(df['MJD'], residuals, c='green', s=2, alpha=0.5)
    ax2.axhline(y=0, color='red', linestyle='--', alpha=0.5)
    ax2.set_xlabel('Modified Julian Date (MJD)')
    ax2.set_ylabel('Residuals (seconds)')
    ax2.set_title('Fitting Residuals Distribution', fontsize=12)
    ax2.grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.savefig('timing_fit.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # 2. Component decomposition
    main_comp, harm1, harm2, trend, mod = components
    fig = plt.figure(figsize=(15, 15))
    gs = fig.add_gridspec(3, 2, hspace=0.3, wspace=0.3)
    
    component_info = [
        ('Main Period Component', main_comp, 'tab:blue'),
        ('First Harmonic', harm1, 'tab:orange'),
        ('Second Harmonic', harm2, 'tab:green'),
        ('Trend Component', trend, 'tab:red'),
        ('Modulation Component', mod, 'tab:purple')
    ]
    
    for i, (name, data, color) in enumerate(component_info):
        ax = fig.add_subplot(gs[i//2, i%2])
        ax.plot(df['MJD'], data, color=color, linewidth=2)
        ax.set_title(f'{name}', fontsize=12)
        ax.set_xlabel('MJD (days)')
        ax.set_ylabel('Amplitude (seconds)')
        ax.grid(True, alpha=0.3)
    
    plt.savefig('components.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # 3. Residuals analysis
    fig = plt.figure(figsize=(15, 5))
    gs = fig.add_gridspec(1, 3, wspace=0.3)
    
    # Residuals histogram
    ax1 = fig.add_subplot(gs[0])
    sns.histplot(residuals, kde=True, ax=ax1)
    ax1.set_title('Histogram of Residuals')
    ax1.set_xlabel('Residuals (seconds)')
    ax1.set_ylabel('Count')
    
    # Q-Q plot
    ax2 = fig.add_subplot(gs[1])
    stats.probplot(residuals, dist="norm", plot=ax2)
    ax2.set_title('Normal Q-Q Plot of Residuals')
    
    # Autocorrelation function
    ax3 = fig.add_subplot(gs[2])
    lags = np.arange(len(acf))
    ax3.stem(lags, acf)
    ax3.set_title('Autocorrelation Function of Residuals')
    ax3.set_xlabel('Lag')
    ax3.set_ylabel('Correlation Coefficient')
    
    plt.savefig('residuals_analysis.png', dpi=300, bbox_inches='tight')
    plt.show()

    # 4. Additional analysis plots (new)
    fig = plt.figure(figsize=(15, 10))
    
    # Power spectrum
    plt.subplot(2, 1, 1)
    freq = np.fft.fftfreq(len(residuals))
    ps = np.abs(np.fft.fft(residuals))**2
    plt.plot(freq[1:len(freq)//2], ps[1:len(freq)//2])
    plt.title('Power Spectrum of Residuals')
    plt.xlabel('Frequency')
    plt.ylabel('Power')
    plt.yscale('log')
    plt.grid(True, alpha=0.3)
    
    # Running standard deviation
    plt.subplot(2, 1, 2)
    window = 50
    running_std = pd.Series(residuals).rolling(window=window).std()
    plt.plot(df['MJD'], running_std)
    plt.title(f'Running Standard Deviation (Window Size: {window})')
    plt.xlabel('Modified Julian Date (MJD)')
    plt.ylabel('Standard Deviation (seconds)')
    plt.grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.savefig('additional_analysis.png', dpi=300, bbox_inches='tight')
    plt.show()

def print_model_equation(params):
    """打印完整的模型方程"""
    A1, w1, phi1, A2, w2, phi2, A3, w3, phi3, a, b, c, k1, k2 = params
    
    print("\n=== 完整模型方程 ===")
    print("y(t) = 主周期项 + 谐波项 + 趋势项 + 调制项，其中：")
    print(f"主周期项 = {A1:.6f} * sin({w1:.6f}t + {phi1:.6f})")
    print(f"第一谐波 = {A2:.6f} * sin({w2:.6f}t + {phi2:.6f})")
    print(f"第二谐波 = {A3:.6f} * sin({w3:.6f}t + {phi3:.6f})")
    print(f"趋势项 = {a:.6f} + {b:.6f}t_norm + {c:.6f}t_norm²")
    print(f"调制项 = {k1:.6f} * exp(-{k2:.6f}t_norm)")
    print("\n其中 t_norm 为标准化时间：(t - mean(t))/std(t)")

# 6. 主函数
def main():
    # 记录开始时间
    start_time = datetime.now()
    print(f"Analysis started at: {start_time.strftime('%Y-%m-%d %H:%M:%S')}")
    
    # 读取数据
    df = load_and_preprocess_data('Attachment1.csv')
    
    # 训练模型
    params = train_model(df)
    
    # 打印模型方程
    print_model_equation(params)
    
    # 评估模型并生成可视化
    r2, rmse, y_pred, components, residuals, acf = evaluate_model(df, params)
    
    # 模型参数解释
    print("\n=== Model Parameters ===")
    param_names = ['A1', 'w1', 'phi1', 'A2', 'w2', 'phi2', 'A3', 'w3', 'phi3',
                  'a', 'b', 'c', 'k1', 'k2']
    for name, value in zip(param_names, params):
        print(f"{name:4s}: {value:10.6f}")
    
    # 可视化结果
    plot_results(df, y_pred, components, residuals, r2, acf)
    
    # 记录结束时间
    end_time = datetime.now()
    duration = end_time - start_time
    print(f"\nAnalysis completed at: {end_time.strftime('%Y-%m-%d %H:%M:%S')}")
    print(f"Total duration: {duration}")
    
    return params, r2, rmse, y_pred, components, residuals, acf

if __name__ == "__main__":
    params, r2, rmse, y_pred, components, residuals, acf = main()