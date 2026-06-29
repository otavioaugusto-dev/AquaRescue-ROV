# Engineering Diagrams

This directory contains the official engineering diagrams for the **AquaRescue ROV** project.

These diagrams provide a visual representation of the system architecture and complement the technical documentation available in `PROJECT_ARCHITECTURE.md`.

Each diagram focuses on a specific subsystem and was created to improve system understanding, facilitate maintenance, and support future development.

---

# Diagram Index

|  ID  | Diagram                        | Description                                                                  | Status |
| :--: | ------------------------------ | ---------------------------------------------------------------------------- | :----: |
| D-00 | System Block Diagram | High-level Cyber-Physical System architecture. | ✅ |
| D-01 | High-Level System Architecture | Overall organization of the AquaRescue platform and subsystem interactions.  |    ✅   |
| D-02 | Mechanical Architecture        | Structural organization of the catamaran platform and mechanical components. |    ✅   |
| D-03 | Electrical Architecture        | Electrical interconnection between embedded electronics and actuators.       |    ✅   |
| D-04 | Communication Architecture     | Bluetooth and Wi-Fi communication flows between system modules.              |    ✅   |
| D-05 | Computer Vision Pipeline       | Image acquisition, processing, and person detection workflow.                |    ✅   |
| D-06 | Power Distribution             | Battery pack, voltage regulation, and subsystem power routing.               |    ✅   |
| D-07 | Mission Workflow               | Operational sequence executed during a rescue mission.                       |    ✅   |

---

# D-00 — System Block Diagram

The System Block Diagram provides a high-level overview of the AquaRescue platform, illustrating the major engineering subsystems and their interactions.

This diagram serves as the primary architectural reference for the project and summarizes the complete Cyber-Physical System (CPS) implemented during development.

```mermaid
flowchart LR

subgraph Operator["Operator Station"]
Controller["Bluetooth Controller"]
Notebook["Notebook"]
Software["Python + OpenCV"]
Alert["Detection Interface"]
end

subgraph Communication["Communication Layer"]
Bluetooth["Bluetooth"]
WiFi["Wi-Fi (MJPEG Stream)"]
end

subgraph Embedded["Embedded System"]
Arduino["Arduino Uno"]
ESP["ESP32-CAM"]
Relay["Relay Modules"]
end

subgraph Mechanical["Mechanical Platform"]
Hull["Catamaran Hull"]
Motors["2 × DC Motors"]
Winch["Camera Winch"]
Camera["Underwater Camera"]
Lights["LED Lighting"]
end

subgraph Power["Power System"]
Battery["2 × Li-Ion Battery Packs"]
Regulator["Voltage Regulation"]
end

Controller --> Bluetooth

Bluetooth --> Arduino

Arduino --> Relay

Relay --> Motors

Arduino --> Winch

Arduino --> Lights

Camera --> ESP

ESP --> WiFi

WiFi --> Notebook

Notebook --> Software

Software --> Alert

Battery --> Motors

Battery --> Winch

Battery --> Regulator

Regulator --> Arduino

Regulator --> ESP

Hull --- Motors

Hull --- Camera

Hull --- Winch
```

---

### Engineering Notes

The AquaRescue platform follows a modular Cyber-Physical System architecture composed of five major engineering domains:

* Mechanical System
* Embedded System
* Communication System
* Computer Vision System
* Power Distribution System

Each subsystem performs a specific set of responsibilities while interacting through clearly defined interfaces. This modular organization simplifies maintenance, supports future scalability, and allows independent evolution of hardware and software components without affecting the overall system architecture.

The separation between low-level embedded control and high-level computer vision processing reduces computational requirements onboard the vehicle while enabling the use of more sophisticated image processing algorithms on the operator station.

---

# D-01 — High-Level System Architecture

This diagram presents the complete system organization.

It illustrates how the embedded controller, communication modules, operator station, propulsion system, and computer vision pipeline interact during operation.

```mermaid
flowchart TB

Operator["Operator"]
Bluetooth["Bluetooth Controller"]
Arduino["Arduino Uno"]
Relay["Relay Modules"]
Motors["12V DC Motors"]
Winch["Camera Winch"]
Lights["Underwater Lights"]

ESP["ESP32-CAM"]
Camera["Underwater Camera"]

Notebook["Operator Notebook"]

Python["Python"]
OpenCV["OpenCV"]
AI["Person Detection"]

Operator --> Bluetooth
Bluetooth --> Arduino

Arduino --> Relay
Relay --> Motors

Arduino --> Winch
Arduino --> Lights

Camera --> ESP
ESP -->|"Wi-Fi MJPEG Stream"| Notebook

Notebook --> Python
Python --> OpenCV
OpenCV --> AI

AI -->|"Detection Alert"| Operator
```

---

# D-02 — Mechanical Architecture

This diagram represents the mechanical structure of the robotic platform, including the catamaran hull, waterproof enclosure, propulsion system, and underwater camera deployment mechanism.

```mermaid
flowchart TB

Catamaran["Catamaran Hull"]

Left["PVC Float"]
Right["PVC Float"]

Frame["Anodized Aluminum Frame"]

Box["11L Waterproof Acrylic Box"]

Battery["Battery Packs"]

Electronics["Embedded Electronics"]

Motors["Propulsion Motors"]

Camera["Underwater Camera"]

Winch["Motorized Winch"]

Catamaran --> Left
Catamaran --> Right

Catamaran --> Frame

Frame --> Box

Box --> Battery
Box --> Electronics
Box --> Winch

Left --> Motors
Right --> Motors

Winch --> Camera
```

---

# D-03 — Electrical Architecture

This diagram illustrates the electrical organization of the embedded system, showing the relationship between the battery pack, voltage regulation, microcontrollers, relay modules, motors, and auxiliary devices.

```mermaid
flowchart LR

Battery["3S10P Li-Ion Pack"]

Regulator["Voltage Regulator"]

Arduino["Arduino Uno"]

Relay["Relay Modules"]

Motors["DC Motors"]

ESP["ESP32-CAM"]

Bluetooth["Bluetooth"]

Lights["LED Lighting"]

Winch["Window Motor"]

Battery --> Motors

Battery --> Regulator

Regulator --> Arduino

Regulator --> ESP

Arduino --> Relay

Relay --> Motors

Arduino --> Bluetooth

Arduino --> Lights

Arduino --> Winch
```

---

# D-04 — Communication Architecture

This diagram describes the communication infrastructure used by AquaRescue.

It highlights the separation between the Bluetooth control channel and the Wi-Fi video transmission channel.

```mermaid
flowchart LR

Operator

Bluetooth

Arduino

ESP

WiFi["Wi-Fi"]

Notebook

Python

Operator --> Bluetooth

Bluetooth --> Arduino

ESP --> WiFi

WiFi --> Notebook

Notebook --> Python
```

---

# D-05 — Computer Vision Pipeline

This diagram illustrates the complete image processing workflow, from underwater image acquisition to human detection and operator notification.

```mermaid
flowchart LR

Camera

ESP32

Stream["MJPEG Stream"]

Notebook

Frame["Frame Capture"]

OpenCV

Neural["Neural Network"]

Detection

Alert

Camera --> ESP32

ESP32 --> Stream

Stream --> Notebook

Notebook --> Frame

Frame --> OpenCV

OpenCV --> Neural

Neural --> Detection

Detection --> Alert
```

---

# D-06 — Power Distribution

This diagram presents the electrical power distribution throughout the AquaRescue platform.

The propulsion system is powered directly by the battery pack, while sensitive electronic devices receive regulated voltage through dedicated voltage regulators. This separation minimizes electrical noise generated by the motors and improves overall system stability during operation.

```mermaid
flowchart TD

Battery["3S10P Li-Ion Battery Pack<br/>(11.1 V Nominal)"]

Battery --> Motors["2 × 12 V DC Propulsion Motors"]

Battery --> Winch["12 V Camera Winch Motor"]

Battery --> Lights["Underwater LED Lighting"]

Battery --> Reg["Voltage Regulator"]

Reg --> Arduino["Arduino Uno"]

Reg --> ESP["ESP32-CAM"]

Reg --> BT["Bluetooth Module (HC-05)"]

Arduino --> Relay["Relay Modules"]

Relay --> Motors

Arduino --> Lights

Arduino --> Winch

ESP --> Camera["OV2640 Camera"]

classDef power fill:#FFE599,stroke:#333,stroke-width:2px;
classDef control fill:#CFE2F3,stroke:#333,stroke-width:2px;
classDef actuator fill:#D9EAD3,stroke:#333,stroke-width:2px;

class Battery power;
class Reg power;

class Arduino control;
class ESP control;
class BT control;
class Relay control;

class Motors actuator;
class Winch actuator;
class Lights actuator;
class Camera actuator;
```

---

### Engineering Notes

The electrical architecture intentionally separates high-current loads (propulsion and winch motors) from low-power embedded electronics. Dedicated voltage regulation supplies the Arduino Uno, ESP32-CAM, and communication modules, improving electrical stability and reducing the likelihood of voltage drops or microcontroller resets caused by motor startup currents.

This modular power distribution strategy also simplifies maintenance and future hardware upgrades by isolating power domains according to subsystem requirements.

---

# D-07 — Mission Workflow

This diagram summarizes the operational sequence followed during a typical search mission.

It represents the interaction between the operator, robotic platform, communication system, and computer vision subsystem.

```mermaid
flowchart TB

Start

Operator

Navigation

Streaming

Detection

Target

End

Start --> Operator

Operator --> Navigation

Navigation --> Streaming

Streaming --> Detection

Detection -->|"No"| Navigation

Detection -->|"Yes"| Target

Target --> End
```

---

# Design Philosophy

The AquaRescue project follows a modular systems engineering approach.

Each subsystem was intentionally designed with well-defined responsibilities, allowing independent development, easier maintenance, improved fault isolation, and future scalability.

The diagrams contained in this directory are considered the graphical reference of the project architecture and are intended to remain synchronized with the technical specification provided in `PROJECT_ARCHITECTURE.md`.

---

# Revision History

| Version | Description                          |
| ------- | ------------------------------------ |
| v0.1    | Initial engineering diagram catalog. |
