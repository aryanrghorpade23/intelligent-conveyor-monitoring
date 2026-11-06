
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

## 5. Demonstration

The integrated prototype demonstrates the operation of MCSA and MFL sensing within a common monitoring system.

**Demonstration videos:**

- [Project demonstration 1](https://www.youtube.com/watch?v=mVGQFcpraKI)
- [Project demonstration 2](https://www.youtube.com/watch?v=Fp9mtmHKMNk)

## 6. Source Code

The complete integrated ESP32 firmware will be maintained in this directory.

## 7. Future Scope

- Advanced signal processing.
- Improved magnetic defect detection.
- Multi-sensor data fusion.
- Automated anomaly identification.
- Industrial conveyor monitoring integration.

---

**Project:** Intelligent Conveyor Belt Health Monitoring System  
**Controller:** ESP32  
**Integrated Techniques:** MCSA and MFL
