
# Motor Current Signature Analysis (MCSA)

## 1. Overview

The Motor Current Signature Analysis (MCSA) subsystem monitors motor current variations to investigate changes in electrical loading and identify potential mechanical abnormalities in conveyor drive systems.

The prototype uses an ESP32, ACS712 Hall-effect current sensor and motor driver to create a controllable motor monitoring setup.

The ESP32 acquires current measurements, generates PWM signals for motor speed control and processes the acquired data to calculate electrical load indicators.

## 2. Objectives

- Measure motor current using the ACS712 sensor.
- Calculate RMS and peak current values.
- Investigate current variations under different motor operating conditions.
- Monitor electrical loading variations that may indicate abnormal mechanical behaviour.

## 3. Hardware Components

| Component | Application |
|---|---|
| ESP32 | Central controller and ADC acquisition |
| ACS712 Current Sensor | Motor current measurement |
| L298N Motor Driver | Motor switching and direction control |
| Buck Converter LM2596  | DC voltage step-down and power regulation |
| DC Motor | Conveyor drive simulation and load testing |
| DC Power Supply | Power source for the prototype |

## 4. Working Principle

### 4.1 Motor Current Measurement

The ACS712 Hall-effect current sensor measures the current flowing through the motor circuit and provides a proportional analog voltage output.

The ESP32 reads this analog signal through its ADC.

The current is calculated using:

I(t) = (V_sensor(t) - V_offset) / S

Where:

- V_sensor = Instantaneous sensor output voltage
- V_offset = Sensor output voltage at zero current
- S = Sensor sensitivity

### Calibration Note

The integrated firmware currently assumes a zero-current output of 1.65 V and a sensitivity of 0.033 V/A for the ACS712 calculation. These are firmware constants, not verified measurements of the installed sensor. Confirm the exact ACS712 variant, measure its zero-current output, and calibrate its sensitivity before relying on the displayed current values. The reported RMS and peak values should be treated as estimates until this validation is complete.

### 4.2 RMS Current Calculation

RMS current represents the effective current value over a selected sampling window.

I_RMS = sqrt[(1/N) × Σ(i[k]²)]

Where:

- N = Number of samples
- i[k] = Individual current samples

### 4.3 Peak Current Calculation

Peak current represents the maximum absolute current observed during the sampling window.

I_peak = max(|i[k]|)

These indicators help monitor changes in motor electrical loading.

## 5. PWM-Based Motor Control

In the current integrated firmware, the ESP32 enables the L298N motor driver using a digital HIGH signal on the enable input and controls direction through the input pins. The firmware does not currently vary the enable signal using PWM, so variable-speed PWM control should not be considered an implemented feature.

PWM-based speed control can be added in a future revision. If implemented, the duty cycle will be:

Duty Cycle (%) = (T_ON / T_PERIOD) × 100

Where T_ON is the HIGH time and T_PERIOD is the total PWM period.

## 6. Power Regulation

Buck converters are used to step down the available DC input voltage to suitable voltage levels required by the prototype.

This provides regulated power for the relevant electronic and motor-control subsystems.

The final voltage settings depend on the requirements of the connected hardware.

## 7. Software and Processing

The MCSA subsystem uses embedded C/C++ programming on the ESP32 platform.

Key software functions include:

- Analog signal acquisition.
- Current conversion and calibration.
- RMS current calculation.
- Peak current calculation.
- Threshold-based current monitoring.
- Data visualization through the Blynk dashboard.

## 8. Experimental Demonstration

The prototype allows motor operation under different PWM duty-cycle and loading conditions while monitoring the corresponding current response.

The acquired current measurements are used to investigate variations in electrical loading and potential abnormal operating conditions.

## 9. Future Scope

- Higher-frequency current sampling.
- FFT-based frequency-domain analysis.
- Three-phase motor current monitoring.
- Advanced fault classification.
- Machine-learning-based anomaly detection.
- Industrial motor condition monitoring.

## 10. Limitations

- The prototype uses development-grade current sensing hardware.
- Current variations alone cannot uniquely identify every mechanical fault.
- Advanced frequency-domain analysis and machine-learning-based fault classification require further development and validation.
- Industrial deployment requires suitable isolated sensing, protection and validated control hardware.

---

**Subsystem:** Motor Current Signature Analysis  
**Main Controller:** ESP32  
**Current Sensor:** ACS712  
**Motor Driver:** L298N
