
# Intelligent Conveyor Belt Health Monitoring System

### Integrated Motor Current Signature Analysis (MCSA) and Magnetic Flux Leakage (MFL)

An ESP32-based conveyor health monitoring prototype developed under **Smart India Hackathon 2026 – Problem Statement 26008**, focused on monitoring electrical loading and detecting magnetic-field variations associated with discontinuities in ferromagnetic materials.

---

## 1. Project Overview

Conveyor belts are essential in heavy-duty mining operations for transporting bulk materials. Continuous operation under high mechanical stress, friction and heavy loading can lead to belt degradation, internal damage and unexpected breakdowns.

This project explores a multi-modal condition monitoring approach by integrating two sensing techniques:

- **Motor Current Signature Analysis (MCSA):** Monitors motor current to identify variations in electrical loading and potential mechanical abnormalities.
- **Magnetic Flux Leakage (MFL):** Analyses magnetic-field variations around ferromagnetic materials to investigate discontinuities and potential structural defects.

Both sensing systems are integrated into a common ESP32-based monitoring architecture.

## 2. Project Objectives

- Monitor motor current and calculate electrical load indicators.
- Analyse magnetic-field variations using Hall-effect sensing.
- Investigate the detection of discontinuities in ferromagnetic materials.
- Integrate both sensing systems into a common monitoring platform.
- Enable visualization of acquired sensor measurements through a dashboard.
- Explore the potential of multi-modal condition monitoring for conveyor maintenance.

## 3. System Architecture

The integrated prototype consists of two primary sensing subsystems.

### MCSA Subsystem

ACS712 Current Sensor → ESP32 ADC → Signal Processing → RMS and Peak Current Calculation

### MFL Subsystem

Permanent Magnet + Ferromagnetic Test Element → Hall-Effect Sensor → ESP32 ADC → Magnetic Signal Analysis

### Integrated Monitoring

MCSA + MFL → ESP32 Processing → Blynk Dashboard

## 4. Motor Current Signature Analysis (MCSA)

The MCSA subsystem uses an ACS712 Hall-effect current sensor to acquire motor current measurements.

The ESP32 samples the sensor output and processes the acquired signal to calculate:

- RMS Current
- Peak Current
- Variations in motor loading

The RMS current is calculated using:

I_RMS = sqrt((1/N) * sum(i[k]^2))

where N is the number of samples and i[k] represents the sampled current.

These measurements help investigate abnormal loading conditions, excessive friction, motor loading variations and possible mechanical problems.

## 5. Magnetic Flux Leakage (MFL)

The MFL subsystem investigates changes in magnetic-field distribution around a ferromagnetic test element.

A permanent magnet establishes the magnetic field, while a Hall-effect sensor measures the local magnetic response.

The sensing arrangement investigates the difference between:

- Magnetic response of an intact ferromagnetic element.
- Magnetic response when a discontinuity is introduced.

Changes in the measured Hall-sensor output are analysed to investigate the presence of material discontinuities.

The prototype demonstrates the sensing principle on a simplified ferromagnetic test element. It is not yet a full-width industrial steel-cord inspection system.

## 6. Hardware Components

| Component | Application |
|---|---|
| ESP32 | Central monitoring and processing |
| ACS712 | Motor current measurement |
| Hall-effect sensor | Magnetic-field measurement |
| Permanent magnet | Magnetic field generation |
| Ferromagnetic test element | MFL experimental target |
| Motor and load setup | MCSA testing |
| DC power supply | Prototype power |

## 7. Software and Technologies

- Embedded C/C++
- Arduino IDE
- ESP32 development platform
- Analog signal acquisition
- RMS and peak-current calculations
- Hall-effect magnetic sensing
- Blynk IoT dashboard

## 8. Experimental Demonstration

The prototype demonstrates the integration and operation of both MCSA and MFL sensing systems.

Experimental observations include motor current measurements and magnetic-field response analysis under the tested conditions.


---

## 9. Project Demonstration Videos

The following videos showcase the hardware implementation, subsystem testing and integrated operation of the Intelligent Conveyor Belt Health Monitoring System.

### Demonstration Video 1

[Watch Project Demonstration](https://www.youtube.com/watch?v=mVGQFcpraKI)

### Demonstration Video 2

[Watch Project Demonstration](https://www.youtube.com/watch?v=Fp9mtmHKMNk)


## 10. Repository Structure

```text
intelligent-conveyor-monitoring/
│
├── MCSA/
│   └── MCSA.ino
│
├── MFL/
│   └── MFL.ino
│
├── Integrated_System/
│   └── Integrated_MCSA_MFL.ino
│
├── Hardware/
│   ├── Circuit_Diagrams/
│   ├── Pin_Connections/
│   └── Components_List.md
│
├── Documentation/
│   ├── Project_Report.pdf
│   └── Experimental_Results/
│
└── README.md
```

*The directory structure will be updated to match the actual source files.*

## 11. Future Scope

- Advanced frequency-domain current analysis using FFT.
- Multi-sensor Hall-effect arrays for wider magnetic inspection.
- Improved magnetic defect localization.
- Integration of thermal and wireless strain monitoring.
- Machine-learning-based anomaly detection.
- Industrial PLC and SCADA integration.
- Validation on actual conveyor belt systems.

## 12. Limitations

- The prototype has been developed and demonstrated under laboratory conditions.
- The MFL arrangement uses a simplified ferromagnetic test element and a Hall-effect sensing arrangement.
- A single Hall sensor does not provide full-width steel-cord inspection.
- Current-based fault diagnosis requires further validation under different operating conditions.
- Industrial deployment requires ruggedized sensing hardware and additional validation.

## 13. Project Information

| Parameter | Details |
|---|---|
| Project | Intelligent Conveyor Belt Health Monitoring System |
| Competition | Smart India Hackathon 2026 |
| Problem Statement | 26008 |
| Organization | Ministry of Steel – NMDC |
| Domain | Electrical Engineering and Industrial Automation |
| Controller | ESP32 |
| Monitoring | MCSA and MFL |

---

**Developed as a student engineering prototype for Smart India Hackathon 2026.**
