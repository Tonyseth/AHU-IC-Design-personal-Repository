import numpy as np
from dataclasses import dataclass
from typing import Tuple, Optional
import matplotlib.pyplot as plt
import seaborn as sns

@dataclass
class AtmosphericParams:

    pressure: float           
    temperature: float        
    water_vapor_pressure: float  
    height: float            
    lapse_rate: float = 6.5  
    turbulence_cn2: float = 1e-14

@dataclass
class DelayResult:

    total_delay: float       
    hydrostatic_delay: float 
    wet_delay: float        
    bending_delay: float    
    uncertainty: float      

class LowElevationDelayModel:

    
    def __init__(self, freq_ghz: float, params: AtmosphericParams):
        self.freq = freq_ghz
        self.params = params
        self.validate_inputs()
        
            
    def calculate_bending_angle(self, elevation_deg: float) -> float:

        epsilon = np.radians(max(elevation_deg, 1.0))
        
        
        T = self.params.temperature
        P = self.params.pressure
        e = self.params.water_vapor_pressure
        
        
        freq_factor = np.exp(-0.02 * (self.freq - 20.0)/30.0)  
        n_dry = 77.6e-6 * (P - e) / T * freq_factor
        n_wet = (71.6e-6 * e / T + 3.75e-4 * e / T**2) * freq_factor
        n = 1 + n_dry + n_wet
        
        
        h0 = self.params.height / 1000.0  
        scale_height = 8.0  
        
        
        cot_epsilon = 1.0 / np.tan(epsilon)
        bending = (n - 1.0) * np.exp(-h0/scale_height) * cot_epsilon * (1.0 + 0.1 * cot_epsilon)
        
        
        lapse_effect = self.params.lapse_rate / 6.5
        bending *= (1.0 + 0.15 * lapse_effect)
        
        return np.degrees(np.abs(bending))  
    
    def calculate_turbulence_delay(self, elevation_deg: float) -> float:

        epsilon = np.radians(max(elevation_deg, 1.0))

        
        freq_factor = (20.0/self.freq)**0.8
        cn2_base = 1e-10 * freq_factor  

        
        h0 = self.params.height / 1000.0
        height_factor = np.exp(-h0/1.2)  
        temp_factor = (self.params.temperature/288.15)**4.0  

        
        e = self.params.water_vapor_pressure
        T = self.params.temperature
        rh = (e/6.11) * np.exp(17.67 * (T-273.15)/(T-29.65))
        humidity_factor = (1.0 + rh)**5.0  


        cn2 = cn2_base * height_factor * temp_factor * humidity_factor

        
        path_length = 1.0 / np.sin(epsilon)
        if elevation_deg <= 5.0:
            path_length *= (1.0 + 3.0/np.tan(epsilon))  

        
        turb_delay = 5.0e-1 * cn2 * path_length**2.5  

        
        if elevation_deg <= 5.0:
            angle_factor = 1.0 + (5.0 - elevation_deg) * 4.0  
            turb_delay *= angle_factor
        elif elevation_deg <= 10.0:
            angle_factor = 1.0 + (10.0 - elevation_deg) * 0.8
            turb_delay *= angle_factor

        
        min_delay = 1.0e-3 * ((20.0/self.freq)**0.8)  

        return max(turb_delay * 1e-9, min_delay * 1e-9)
    
    def improved_mapping_function(self, elevation_deg: float) -> Tuple[float, float]:
        epsilon = np.radians(max(elevation_deg, 1.0))
        sin_e = np.sin(epsilon)
        
        freq_scale = (20.0/self.freq)**0.15  
        h_km = self.params.height/1000.0
        height_scale = np.exp(-h_km/7.0)
        
        
        a_dry = (0.00125 + 0.00002 * h_km) * freq_scale
        b_dry = (0.00030 + 0.00003 * h_km) * freq_scale
        c_dry = (0.00045 + 0.00004 * h_km) * freq_scale

        a_wet = (0.00170 + 0.00004 * h_km) * freq_scale 
        b_wet = (0.00045 + 0.00005 * h_km) * freq_scale
        c_wet = (0.00055 + 0.00005 * h_km) * freq_scale
        
        m_dry = (1.0 + a_dry/(sin_e + b_dry/(sin_e + c_dry))) * height_scale
        m_wet = (1.0 + a_wet/(sin_e + b_wet/(sin_e + c_wet))) * height_scale
        
        
        if elevation_deg <= 10.0:
            correction = 1.0 + 0.08 * (10.0 - elevation_deg)/10.0  
            m_dry *= correction
            m_wet *= correction * 1.1  
        
        return m_dry, m_wet
    
    def calculate_uncertainty(self, elevation_deg: float, total_delay: float) -> float:
        # 基本不确定度（与总延迟相关）
        base_uncertainty = 0.02 * total_delay
        
        # 仰角相关的不确定度
        if elevation_deg <= 10.0:
            angle_uncertainty = 0.05 * total_delay * (10.0 - elevation_deg)/10.0
        else:
            angle_uncertainty = 0.0
        
        # 频率相关的不确定度
        freq_uncertainty = 0.01 * total_delay * (self.freq - 20.0)/30.0
        
        # 湍流引起的不确定度
        turb_uncertainty = self.calculate_turbulence_delay(elevation_deg)
        
        # 总不确定度
        total_uncertainty = np.sqrt(base_uncertainty**2 + 
                                  angle_uncertainty**2 + 
                                  freq_uncertainty**2 +
                                  turb_uncertainty**2)
        
        return total_uncertainty
    
    def calculate_delay(self, elevation_deg: float) -> DelayResult:
        
        
        bending_angle = self.calculate_bending_angle(elevation_deg)
        
        
        m_dry, m_wet = self.improved_mapping_function(elevation_deg)
        
        P = self.params.pressure
        T = self.params.temperature
        e = self.params.water_vapor_pressure
        
        k1 = 77.6e-2
        freq_factor_dry = (20.0/self.freq)**0.2  
        zhd = k1 * (P - e) / T * 5.5e-2 * freq_factor_dry
        
        
        k2 = 72.0e-2
        k3 = 38.0  
        freq_factor_wet = (20.0/self.freq)**0.3  
        
        
        rh = (e/6.11) * np.exp(17.67 * (T-273.15)/(T-29.65))
        rh_factor = (1.0 + rh)**1.2  
        
        
        temp_factor = (T/288.15)**(-0.6)  
        
        zwd = (k2 * e / T + k3 * e / T**2) * 4.8e-2 * freq_factor_wet * rh_factor * temp_factor
        
        
        turb_delay = self.calculate_turbulence_delay(elevation_deg)
        
        
        bending_delay = 0.0
        if elevation_deg <= 10.0:
            angle_factor = np.cos(np.radians(elevation_deg))
            bending_delay = (zhd + zwd) * 0.0015 * bending_angle * angle_factor  
            
            
            if elevation_deg <= 5.0:
                zwd *= (1.0 + 0.2 * (5.0 - elevation_deg)/5.0)
        
        
        hydro_delay = zhd * m_dry
        wet_delay = zwd * m_wet + turb_delay  
        total_delay = hydro_delay + wet_delay + bending_delay
        
        
        uncertainty = self.calculate_uncertainty(elevation_deg, total_delay)
        
        return DelayResult(
            total_delay=total_delay,
            hydrostatic_delay=hydro_delay,
            wet_delay=wet_delay,
            bending_delay=bending_delay,
            uncertainty=uncertainty
        )

def test_model():
    
    
    params = AtmosphericParams(
        pressure=1013.25,      
        temperature=288.15,    
        water_vapor_pressure=12.0,  
        height=100.0,          
        lapse_rate=6.5,        
        turbulence_cn2=1e-14   
    )
    
    
    frequencies = [20.0, 30.0, 40.0, 50.0]
    
    
    elevations = [10.0, 7.5, 5.0, 2.5, 1.0]
    
    for freq in frequencies:
        model = LowElevationDelayModel(freq_ghz=freq, params=params)
        
        for elev in elevations:
            result = model.calculate_delay(elev)
            print(f"{elev:8.1f} {result.total_delay:12.3f} {result.hydrostatic_delay:14.3f} "
                  f"{result.wet_delay:12.3f} {result.bending_delay:14.3f} {result.uncertainty:14.3f}")

        def plot_results():
            
            plt.style.use('fivethirtyeight')
            sns.set_palette("husl")
            
            
            elevs = np.linspace(1, 10, 50)
            freqs = [20, 30, 40, 50]
            results = {freq: [] for freq in freqs}
            
            for freq in freqs:
                model = LowElevationDelayModel(freq_ghz=freq, params=params)
                for elev in elevs:
                    result = model.calculate_delay(elev)
                    results[freq].append(result)
            
            
            plt.figure(figsize=(10, 6))
            for freq in freqs:
                total_delays = [r.total_delay for r in results[freq]]
                plt.plot(elevs, total_delays, label=f'{freq} GHz')
            
            plt.xlabel('Elevation Angle (degrees)')
            plt.ylabel('Total Delay (ns)')
            plt.title('Total Atmospheric Delay vs. Elevation Angle')
            plt.legend()
            plt.grid(True)
            plt.tight_layout()
            plt.savefig('total_delay_vs_elevation.png', dpi=300, bbox_inches='tight')
            plt.close()
            
            
            plt.figure(figsize=(10, 6))
            for freq in freqs:
                wet_ratios = [r.wet_delay/r.total_delay*100 for r in results[freq]]
                plt.plot(elevs, wet_ratios, label=f'{freq} GHz')
            
            plt.xlabel('Elevation Angle (degrees)')
            plt.ylabel('Wet Delay Ratio (%)')
            plt.title('Wet Delay Ratio vs. Elevation Angle')
            plt.legend()
            plt.grid(True)
            plt.tight_layout()
            plt.savefig('wet_delay_ratio.png', dpi=300, bbox_inches='tight')
            plt.close()
            
            
            plt.figure(figsize=(10, 6))
            for freq in freqs:
                bending_delays = [r.bending_delay for r in results[freq]]
                plt.plot(elevs, bending_delays, label=f'{freq} GHz')
            
            plt.xlabel('Elevation Angle (degrees)')
            plt.ylabel('Bending Delay (ns)')
            plt.title('Bending Delay vs. Elevation Angle')
            plt.legend()
            plt.grid(True)
            plt.yscale('log')
            plt.tight_layout()
            plt.savefig('bending_delay.png', dpi=300, bbox_inches='tight')
            plt.close()
            
            
            plt.figure(figsize=(10, 6))
            for freq in freqs:
                uncertainties = [r.uncertainty/r.total_delay*100 for r in results[freq]]
                plt.plot(elevs, uncertainties, label=f'{freq} GHz')
            
            plt.xlabel('Elevation Angle (degrees)')
            plt.ylabel('Relative Uncertainty (%)')
            plt.title('Delay Uncertainty vs. Elevation Angle')
            plt.legend()
            plt.grid(True)
            plt.tight_layout()
            plt.savefig('delay_uncertainty.png', dpi=300, bbox_inches='tight')
            plt.close()
            
            
            plt.figure(figsize=(12, 8))
            freq_range = np.linspace(20, 50, 30)
            elev_range = np.linspace(1, 10, 30)
            delay_matrix = np.zeros((len(elev_range), len(freq_range)))
            
            for i, elev in enumerate(elev_range):
                for j, freq in enumerate(freq_range):
                    model = LowElevationDelayModel(freq_ghz=freq, params=params)
                    result = model.calculate_delay(elev)
                    delay_matrix[i, j] = result.total_delay
            
            sns.heatmap(delay_matrix, xticklabels=np.round(freq_range, 1),
                       yticklabels=np.round(elev_range, 1), cmap='viridis')
            plt.xlabel('Frequency (GHz)')
            plt.ylabel('Elevation Angle (degrees)')
            plt.title('Total Delay Distribution (ns)')
            plt.tight_layout()
            plt.savefig('delay_heatmap.png', dpi=300, bbox_inches='tight')
            plt.close()
        plot_results()

if __name__ == "__main__":
    test_model()