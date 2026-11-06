
# Magnetic Flux Leakage (MFL) Monitoring

## 1. Overview

The Magnetic Flux Leakage (MFL) subsystem investigates magnetic-field variations around ferromagnetic materials to identify potential discontinuities.

The prototype uses a permanent magnet and a Hall-effect sensor to analyse changes in the local magnetic field around a ferromagnetic test element.

The ESP32 acquires the Hall-sensor output and processes the measured magnetic response.

## 2. Objectives

- Generate a magnetic field around the ferromagnetic test element.
- Measure magnetic-field variations using a Hall-effect sensor.
- Analyse the sensor response under different test conditions.
- Investigate magnetic signatures associated with material discontinuities.
- Integrate magnetic sensing with the MCSA monitoring system.

## 3. Hardware Components

| Component | Application |
|---|---|
| ESP32 | Analog signal acquisition and processing |
| Hall-effect Sensor | Magnetic-field measurement |
| Permanent Magnet | Establishes the magnetic field |
| GI Wire / Ferromagnetic Test Element | Magnetic inspection test target |
| DC Power Supply | Powers the sensing electronics |

## 4. Working Principle

MFL is a non-destructive testing technique based on changes in magnetic-field distribution around ferromagnetic materials.

The prototype operates as follows:

1. A permanent magnet establishes a magnetic field around the ferromagnetic test element.
2. The Hall-effect sensor measures the local magnetic-field response.
3. Changes in the material condition influence the magnetic-field distribution.
4. The Hall sensor produces a corresponding change in its output voltage.
5. The ESP32 acquires and analyses the sensor signal.

## 5. Magnetic Signal Analysis

For an analog Hall-effect sensor, the output can be represented by:

V_H = V_offset + S_B × B

Where:

- V_H = Hall sensor output voltage
- V_offset = Sensor output at the reference magnetic condition
- S_B = Sensor sensitivity
- B = Measured magnetic flux density component

The measured output is analysed to investigate variations in the magnetic field.

## 6. Software and Processing

The subsystem uses embedded C/C++ programming on the ESP32 platform.

Key functions include:

- Analog Hall-sensor signal acquisition.
- Magnetic signal monitoring.
- Baseline measurement.
- Magnetic response comparison.
- Threshold-based event detection.
- Data integration with the common monitoring platform.

## 7. Experimental Demonstration

The prototype demonstrates magnetic-field sensing using a permanent magnet, Hall-effect sensor and ferromagnetic test element.

The acquired sensor response is analysed under the tested conditions to investigate changes in magnetic behaviour.

## 8. Future Scope

- Multiple Hall-effect sensors for wider inspection.
- Improved magnetic-field measurement resolution.
- Magnetic defect localization.
- Optimized magnetizing arrangements.
- Detection of internal steel-cord discontinuities.
- Industrial conveyor belt inspection.

## 9. Limitations

- The prototype uses a simplified ferromagnetic test arrangement.
- A single Hall sensor cannot provide full-width conveyor belt inspection.
- Detection performance depends on magnet strength, sensor positioning and measurement resolution.
- Industrial steel-cord inspection requires further experimental validation and an appropriately designed magnetizing structure.

---

**Subsystem:** Magnetic Flux Leakage Monitoring  
**Controller:** ESP32  
**Sensing Element:** Hall-effect Sensor  
**Magnetic Source:** Permanent Magnet
