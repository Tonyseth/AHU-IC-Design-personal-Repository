import numpy as np
from dataclasses import dataclass
import matplotlib.pyplot as plt

@dataclass
class AtmosphericParams:
    """大气参数类"""
    pressure: float      # 大气压力 (hPa)
    temperature: float   # 温度 (K)
    water_vapor_pressure: float  # 水汽压 (hPa)
    height: float        # 观测站海拔高度 (m)

class RefractionDelayModel:
    """高频折射延迟模型 (>20 GHz)"""
    
    def __init__(self, freq_ghz: float, params: AtmosphericParams):
        """初始化模型"""
        self.freq = freq_ghz
        self.params = params
        self._validate_frequency()
        
    def _validate_frequency(self):
        """验证频率是否在有效范围内"""
        if self.freq < 20.0:
            raise ValueError("频率必须大于20GHz")
    
    def calculate_refractivity(self) -> tuple:
        """计算高频段折射率"""
        T = self.params.temperature
        P = self.params.pressure
        e = self.params.water_vapor_pressure
        
        # 优化的频率依赖
        freq_factor_dry = np.exp(-0.025 * (self.freq - 20.0)/10.0)
        freq_factor_wet = np.exp(-0.015 * (self.freq - 20.0)/10.0)  # 湿分量频率依赖更弱
        
        # 高度修正
        height_factor = np.exp(-self.params.height/8500.0)
        
        # 温度影响
        temp_factor_dry = (T/288.15)**0.5
        temp_factor_wet = (T/288.15)**(-0.6)  # 加强湿分量的温度依赖
        
        # 增强的湿度响应
        rh_factor = min((e/6.11)*np.exp(17.67*(T-273.15)/(T-29.65)), 1.0)  # 相对湿度的影响
        humidity_factor = (e/10.0)**0.4 * (1.0 + rh_factor)
        
        # 干折射率（基于ITU-R模型改进）
        k1 = 70.0e-2  # 略微降低干分量系数
        N_dry = k1 * (P - e) / T * freq_factor_dry * height_factor * temp_factor_dry
        
        # 改进的湿折射率计算
        k2 = 72.0e-2
        k3 = 12.0  # 显著增加水汽贡献
        N_wet = (k2 * e / T + k3 * e / (T * T)) * freq_factor_wet * height_factor * temp_factor_wet * humidity_factor
        
        return N_dry, N_wet
    
    def mapping_function(self, elevation_deg: float) -> tuple:
        """计算映射函数"""
        epsilon = np.radians(max(elevation_deg, 3.0))
        sin_e = np.sin(epsilon)
        
        # 频率相关的映射参数
        freq_scale = 1.0 - 0.008 * (self.freq - 20.0)/10.0
        
        # 高度影响
        h_km = self.params.height/1000.0
        
        # 干延迟映射参数
        a_dry = (0.00120 + 0.00001 * h_km) * freq_scale
        b_dry = (0.00025 + 0.00002 * h_km) * freq_scale
        
        # 湿延迟映射参数（增强低仰角效应）
        a_wet = (0.00150 + 0.00002 * h_km) * freq_scale * 1.1
        b_wet = (0.00035 + 0.00003 * h_km) * freq_scale * 1.1
        
        # 计算映射函数
        m_dry = 1.0 / (sin_e + a_dry/(sin_e + b_dry))
        m_wet = 1.0 / (sin_e + a_wet/(sin_e + b_wet))
        
        # 湿分量的额外低仰角增强
        if elevation_deg < 30:
            m_wet *= 1.0 + 0.15 * (1.0 - elevation_deg/30.0)
        
        return m_dry, m_wet
    
    def calculate_delay(self, elevation_deg: float) -> tuple:
        """计算总延迟"""
        # 计算折射率
        N_dry, N_wet = self.calculate_refractivity()
        
        # 频率相关的等效高度
        freq_scale_dry = np.exp(-0.015 * (self.freq - 20.0)/10.0)
        freq_scale_wet = np.exp(-0.010 * (self.freq - 20.0)/10.0)
        
        # 温度影响
        temp_factor = (self.params.temperature/288.15)**0.6
        
        # 湿度响应
        humidity_scale = (self.params.water_vapor_pressure/10.0)**0.4
        
        # 等效高度计算
        h_dry = 4.5e-2 * freq_scale_dry * temp_factor
        h_wet = 3.5e-2 * freq_scale_wet * temp_factor * humidity_scale
        
        # 计算天顶延迟
        c = 0.299792458  # 光速 (m/ns)
        zenith_dry = N_dry * h_dry / c
        zenith_wet = N_wet * h_wet / c * 2.0  # 显著增加湿延迟权重
        
        # 计算映射函数
        m_dry, m_wet = self.mapping_function(elevation_deg)
        
        # 计算总延迟
        total_dry = zenith_dry * m_dry
        total_wet = zenith_wet * m_wet
        total_delay = total_dry + total_wet
        zenith_delay = zenith_dry + zenith_wet
        
        return total_delay, zenith_delay, (total_dry, total_wet)

def test_model():
    """测试模型"""
    frequencies = [20.0, 30.0, 40.0, 50.0]
    
    # 设置测试参数（更真实的大气条件）
    params = AtmosphericParams(
        pressure=1013.25,       # 标准气压 (hPa)
        temperature=288.15,     # 15°C
        water_vapor_pressure=12.0,  # 增加水汽压 (hPa)
        height=100.0            # 海拔高度 (m)
    )
    
    print("\n高频折射延迟模型测试结果")
    print("=" * 80)
    
    for freq in frequencies:
        model = RefractionDelayModel(freq_ghz=freq, params=params)
        print(f"\n频率: {freq} GHz")
        print("-" * 80)
        print(f"{'仰角(度)':>10} {'总延迟(ns)':>12} {'天顶延迟(ns)':>12} "
              f"{'干延迟(ns)':>12} {'湿延迟(ns)':>12}")
        print("-" * 80)
        
        for elev in [90, 60, 30, 10, 5]:
            total_delay, zenith_delay, (dry_comp, wet_comp) = model.calculate_delay(elev)
            print(f"{elev:10.1f} {total_delay:12.3f} {zenith_delay:12.3f} "
                  f"{dry_comp:12.3f} {wet_comp:12.3f}")
        
        _, zenith_delay, (dry, wet) = model.calculate_delay(90.0)
        print("-" * 80)
        print(f"天顶延迟检验: {'通过' if zenith_delay <= 7.69 else '未通过'}")
        print(f"计算的天顶延迟: {zenith_delay:.3f} ns (要求 ≤ 7.69 ns)")
        wet_ratio = wet / (dry + wet) * 100
        print(f"湿延迟占比: {wet_ratio:.1f}%")
        
        if freq == 20.0:  # 只对20GHz显示详细分析
            print("\n详细分析（20GHz）:")
            print(f"- 天顶延迟分量:")
            print(f"  干延迟: {dry:.3f} ns")
            print(f"  湿延迟: {wet:.3f} ns")
            print(f"- 低仰角（5°）增强效应:")
            _, _, (dry_5, wet_5) = model.calculate_delay(5.0)
            dry_ratio = dry_5/dry
            wet_ratio = wet_5/wet
            print(f"  干分量增强: {dry_ratio:.1f}倍")
            print(f"  湿分量增强: {wet_ratio:.1f}倍")

# def visualize_results():
#     """可视化分析结果"""
#     plt.style.use('fivethirtyeight')
    
#     # 设置中文字体
#     plt.rcParams['font.sans-serif'] = ['SimHei']
#     plt.rcParams['axes.unicode_minus'] = False
    
#     # 测试参数
#     params = AtmosphericParams(
#         pressure=1013.25,
#         temperature=288.15,
#         water_vapor_pressure=12.0,
#         height=100.0
#     )
    
#     # 图1：不同频率的延迟随仰角变化
#     elevations = np.linspace(5, 90, 100)
#     frequencies = [20, 30, 40, 50]
    
#     plt.figure(figsize=(10, 6))
#     for freq in frequencies:
#         model = RefractionDelayModel(freq, params)
#         delays = [model.calculate_delay(elev)[0] for elev in elevations]
#         plt.plot(elevations, delays, label=f'{freq} GHz')
    
#     plt.xlabel('Elevation Angle (degrees)')
#     plt.ylabel('Total Delay (ns)')
#     plt.title('Total Delay vs. Elevation Angle for Different Frequencies')
#     plt.legend()
#     plt.grid(True)
#     plt.savefig('delay_vs_elevation.png', dpi=300, bbox_inches='tight')
#     plt.close()
    
#     # 图2：干湿分量比例随频率变化
#     freqs = np.linspace(20, 50, 30)
#     dry_ratios = []
#     wet_ratios = []
    
#     plt.figure(figsize=(10, 6))
#     for freq in freqs:
#         model = RefractionDelayModel(freq, params)
#         _, _, (dry, wet) = model.calculate_delay(90.0)
#         total = dry + wet
#         dry_ratios.append(dry/total * 100)
#         wet_ratios.append(wet/total * 100)
    
#     plt.plot(freqs, dry_ratios, label='Dry Component')
#     plt.plot(freqs, wet_ratios, label='Wet Component')
#     plt.xlabel('Frequency (GHz)')
#     plt.ylabel('Percentage (%)')
#     plt.title('Dry and Wet Component Ratio vs. Frequency')
#     plt.legend()
#     plt.grid(True)
#     plt.savefig('component_ratio.png', dpi=300, bbox_inches='tight')
#     plt.close()
    
#     # 图3：温度影响分析
#     temperatures = np.linspace(273.15, 303.15, 30)  # 0°C to 30°C
#     delays_20ghz = []
#     delays_50ghz = []
    
#     plt.figure(figsize=(10, 6))
#     for temp in temperatures:
#         params.temperature = temp
#         model_20 = RefractionDelayModel(20, params)
#         model_50 = RefractionDelayModel(50, params)
#         delays_20ghz.append(model_20.calculate_delay(90)[1])
#         delays_50ghz.append(model_50.calculate_delay(90)[1])
    
#     plt.plot(temperatures - 273.15, delays_20ghz, label='20 GHz')
#     plt.plot(temperatures - 273.15, delays_50ghz, label='50 GHz')
#     plt.xlabel('Temperature (°C)')
#     plt.ylabel('Zenith Delay (ns)')
#     plt.title('Temperature Dependence of Zenith Delay')
#     plt.legend()
#     plt.grid(True)
#     plt.savefig('temperature_effect.png', dpi=300, bbox_inches='tight')
#     plt.close()
    
#     # 打印详细的数值分析结果
#     print("\n详细数值分析结果")
#     print("=" * 80)
    
#     # 频率响应分析
#     print("\n频率响应分析 (天顶方向):")
#     for freq in [20, 30, 40, 50]:
#         model = RefractionDelayModel(freq, params)
#         _, zenith_delay, (dry, wet) = model.calculate_delay(90.0)
#         print(f"\n频率: {freq} GHz")
#         print(f"总天顶延迟: {zenith_delay:.4f} ns")
#         print(f"干分量: {dry:.4f} ns ({dry/zenith_delay*100:.1f}%)")
#         print(f"湿分量: {wet:.4f} ns ({wet/zenith_delay*100:.1f}%)")
    
#     # 仰角响应分析
#     print("\n仰角响应分析 (20 GHz):")
#     model = RefractionDelayModel(20, params)
#     for elev in [5, 10, 20, 30, 45, 60, 90]:
#         total, _, (dry, wet) = model.calculate_delay(elev)
#         print(f"\n仰角: {elev}°")
#         print(f"总延迟: {total:.4f} ns")
#         print(f"干分量: {dry:.4f} ns")
#         print(f"湿分量: {wet:.4f} ns")
#         print(f"放大倍数: {total/model.calculate_delay(90)[0]:.2f}x")

if __name__ == "__main__":
    test_model()
    #visualize_results()