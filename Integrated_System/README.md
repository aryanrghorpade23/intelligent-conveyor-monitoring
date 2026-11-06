
# Integrated MCSA and MFL Monitoring System

## 1. Overview

This module documents the integration of Motor Current Signature Analysis (MCSA) and Magnetic Flux Leakage (MFL) into a common ESP32-based conveyor monitoring prototype.

The integrated system combines electrical current monitoring and magnetic-field sensing to investigate different indicators of conveyor health.

## 2. Integrated System Architecture

The system consists of two sensing subsystems:

### MCSA

- ACS712 current sensing.
- ESP32-based analog signal acquisition.
- RMS and peak current calculation.
- Motor enable and direction control through the L298N motor driver (the current firmware does not implement PWM speed control).

### MFL

- Permanent magnet-based magnetic field generation.
- Hall-effect magnetic sensing.
- ESP32-based signal acquisition.
- Magnetic response analysis around a ferromagnetic test element.

## 3. System Integration

Both sensing subsystems are integrated into a common monitoring platform using the ESP32.

The system acquires electrical and magnetic measurements and enables their combined monitoring.

## 4. Monitoring Interface

The acquired measurements are made available through the Blynk monitoring dashboard.

The interface provides visibility into the measured motor current and magnetic sensor response.

## 5. Firmware Connections and Dashboard Mapping

The current integrated firmware uses the following ESP32 GPIO assignments:

| Function | ESP32 GPIO |
|---|---:|
| L298N enable (ENA) | 25 |
| L298N direction input 1 (IN1) | 26 |
| L298N direction input 2 (IN2) | 27 |
| ACS712 current-sensor analog output | 34 |
| Voltage-monitor analog input | 32 |
| MFL Hall-sensor analog output | 35 |

The Blynk virtual-pin mapping in the firmware is:

| Virtual pin | Measurement |
|---|---|
| V0 | MCSA RMS current estimate (A) |
| V1 | MCSA peak current estimate (A) |
| V2 | MFL signal amplitude (V) |
| V3 | Derived MFL metric (relative until calibrated) |
| V5 | Voltage-monitor value (scaled estimate) |

Check the actual wiring, sensor variant, voltage-divider ratios and calibration constants before powering the circuit. These values describe the current source code and are not a substitute for hardware verification.

## 6. Demonstration

The integrated prototype demonstrates the operation of MCSA and MFL sensing within a common monitoring system.

**Demonstration videos:**

- [Project demonstration 1](https://www.youtube.com/watch?v=mVGQFcpraKI)
- [Project demonstration 2](https://www.youtube.com/watch?v=Fp9mtmHKMNk)

## 7. Source Code

The complete integrated ESP32 firmware will be maintained in this directory.

## 8. Future Scope

- Advanced signal processing.
- Improved magnetic defect detection.
- Multi-sensor data fusion.
- Automated anomaly identification.
- Industrial conveyor monitoring integration.

---

**Project:** Intelligent Conveyor Belt Health Monitoring System  
**Controller:** ESP32  
**Integrated Techniques:** MCSA and MFL
