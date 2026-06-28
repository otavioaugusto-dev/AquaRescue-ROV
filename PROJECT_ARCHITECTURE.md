# AquaRescue ROV
## Project Architecture Specification

---

**Project Name:** AquaRescue – Embedded Robotic Platform for Recognition and Localization of Drowning Victims

**Repository:**  
https://github.com/otavioaugusto-dev/AquaRescue-ROV

**Development Period:**  
2023 – 2025

**Institution:**  
Robotics Club – Colégio Militar do Corpo de Bombeiros do Ceará (CMCB)

**Primary Contributor:**  
Otávio Augusto

**Document Version:**  
v0.3

**Document Status:**  
In Development

---

# Table of Contents

1. Project Overview
2. Problem Statement
3. Project Objectives
4. Stakeholders
5. Engineering Requirements
6. System Overview *(Coming in v0.2)*
7. Mechanical Architecture *(Coming in v0.2)*
8. Electrical Architecture *(Coming in v0.2)*
9. Embedded System *(Coming in v0.3)*
10. Computer Vision System *(Coming in v0.3)*
11. Communication Architecture *(Coming in v0.3)*
12. Power Distribution *(Coming in v0.3)*
13. Operating Modes *(Coming in v0.4)*
14. Validation and Field Testing *(Coming in v0.4)*
15. Scientific Contributions *(Coming in v0.4)*
16. Awards *(Coming in v0.4)*
17. Lessons Learned *(Coming in v1.0)*
18. Future Improvements *(Coming in v1.0)*

---

# 1. Project Overview

## Abstract

AquaRescue is a low-cost robotic surface vehicle developed to assist search and rescue operations involving drowning victims. The project combines embedded systems, computer vision, wireless communication, naval engineering concepts, and artificial intelligence to provide firefighters with a technological support platform capable of improving operational safety and increasing search efficiency.

The platform was conceived through a user-centered engineering approach, beginning with interviews conducted with military firefighters, rescue divers, and professionals experienced in aquatic rescue operations. Their operational requirements guided the project's conception and technical decisions throughout its development.

Unlike conventional remotely operated platforms focused exclusively on teleoperation, AquaRescue integrates autonomous assistance features through computer vision techniques capable of identifying people in real time from underwater video streams. The system also incorporates modular mechanical construction, reusable materials, wireless communication, embedded propulsion control, and a portable operator station.

Throughout its development, AquaRescue evolved from an initial concept into a validated research prototype tested in controlled aquatic environments and presented at national scientific competitions. The project demonstrates how affordable engineering solutions can contribute to public safety while simultaneously serving as an educational platform for multidisciplinary engineering research.

---

# 2. Problem Statement

According to the World Health Organization (WHO), drowning causes more than 236,000 deaths every year worldwide, remaining one of the leading causes of accidental mortality.

Search operations performed by rescue teams are frequently characterized by long operational periods, limited underwater visibility, significant physical effort, and considerable risks to rescue divers. These factors increase operational costs while exposing professionals to hazardous environments.

During the project's conception phase, the development team interviewed firefighters, rescue divers, and military personnel from the Ceará Military Fire Department (CBMCE). These interviews revealed recurring operational challenges related to underwater victim localization, including:

- Limited underwater visibility;
- High physical fatigue during prolonged searches;
- Exposure of rescue divers to hazardous environments;
- Emotional pressure experienced by rescue teams;
- Psychological distress for victims' families during long search operations.

The motivation for the project became even stronger following a real drowning incident at the Federal University of Ceará (UFC), where search operations lasted several days due to the complexity of the underwater environment.

Based on these observations, the Robotics Club proposed the development of a robotic platform capable of supporting firefighters during search operations while reducing human exposure to hazardous situations through the use of embedded technologies and computer vision.

---

# 3. Project Objectives

## General Objective

Develop a low-cost robotic platform capable of assisting search and rescue teams during drowning victim localization by combining embedded systems, wireless communication, computer vision, and modular mechanical design.

## Specific Objectives

- Develop a stable catamaran-based floating platform;
- Design a modular waterproof structure suitable for aquatic environments;
- Implement a dual-motor propulsion system;
- Provide real-time underwater video streaming;
- Integrate computer vision techniques for human detection;
- Develop both manual and autonomous operating modes;
- Minimize operational costs through the reuse of mechanical components whenever feasible;
- Validate the platform under realistic field conditions;
- Demonstrate the feasibility of affordable robotic technologies for public safety applications.

---

# 4. Stakeholders

## Primary Stakeholders

- Ceará Military Fire Department (CBMCE)
- Search and Rescue Teams
- Firefighters
- Rescue Divers
- Victims and Their Families

## Secondary Stakeholders

- Robotics Club (CMCB)
- Engineering Students
- Educational Institutions
- Scientific Community
- Science Fair Organizations

---

# 5. Engineering Requirements

## Functional Requirements

| ID | Requirement | Status |
|:---|:------------|:------:|
| FR-01 | Navigate over water using differential propulsion | ✔ |
| FR-02 | Support manual remote operation | ✔ |
| FR-03 | Support autonomous navigation | Prototype |
| FR-04 | Capture underwater video | ✔ |
| FR-05 | Stream live video to the operator station | ✔ |
| FR-06 | Detect people using computer vision | ✔ |
| FR-07 | Illuminate underwater environments | ✔ |
| FR-08 | Raise and lower the underwater camera | ✔ |
| FR-09 | Provide visual status indication | ✔ |

## Non-Functional Requirements

| ID | Requirement |
|:---|:------------|
| NFR-01 | Low-cost construction |
| NFR-02 | Modular architecture |
| NFR-03 | High buoyancy |
| NFR-04 | Easy maintenance |
| NFR-05 | Waterproof electronics enclosure |
| NFR-06 | Reuse of recycled materials whenever possible |
| NFR-07 | Portable operation by a single operator |
| NFR-08 | Stable communication during field operation |

------

# 6. System Overview

## System Description

AquaRescue is composed of multiple engineering subsystems working together to support aquatic search and rescue missions.

Instead of being designed as a single robotic platform, the project follows a modular architecture where each subsystem performs a specific function while communicating with the remaining modules.

This modular approach simplifies maintenance, future upgrades, fault isolation, and hardware replacement while allowing each subsystem to evolve independently.

The complete system is divided into the following major subsystems:

- Mechanical Structure
- Propulsion System
- Embedded Control System
- Underwater Imaging System
- Computer Vision System
- Communication System
- Power Distribution System
- Human-Machine Interface

---

## High-Level System Architecture

> **Diagram Placeholder**
>
> The complete system architecture diagram will be inserted in a future revision.

```text
                 OPERATOR

        Bluetooth Controller
                │
                │
         ┌──────▼──────┐
         │   Arduino   │
         └──────┬──────┘
                │
      ┌─────────┴──────────┐
      │                    │
 Left Motor           Right Motor
      │                    │
      └─────────┬──────────┘
                │
          Catamaran Hull
                │
       Underwater Camera
                │
          ESP32 Streaming
                │
             Wi-Fi Network
                │
        Operator Notebook
                │
      Python + OpenCV + AI
                │
      Person Detection Alert
```

---

# 7. Mechanical Architecture

## Mechanical Design Philosophy

The mechanical structure was designed following three primary engineering principles:

- High buoyancy;
- Mechanical simplicity;
- Low manufacturing cost.

To achieve these objectives, the development team adopted a catamaran configuration composed of two PVC floating hulls connected by an anodized aluminum frame.

This configuration provides excellent lateral stability while creating sufficient internal space for propulsion components and electronic systems.

---

## Floating Structure

The floating platform consists of:

- Two 100 mm PVC pipes acting as flotation pontoons;
- An anodized aluminum structural frame;
- A sealed acrylic enclosure positioned between the pontoons;
- Reinforced mechanical supports for propulsion motors;
- Centralized weight distribution.

PVC was selected due to its:

- Low cost;
- High corrosion resistance;
- Excellent buoyancy;
- Ease of machining;
- Wide commercial availability.

Most structural components were obtained from recycled construction materials, reducing manufacturing costs while promoting sustainable engineering practices.

---

## Waterproof Enclosure

A central 11-liter acrylic enclosure houses the embedded electronics.

The enclosure protects:

- Arduino controller;
- Relay modules;
- Battery pack;
- Voltage regulators;
- Internal wiring;
- Camera winch mechanism.

Waterproof sealing was achieved using PU40 polyurethane sealant, providing protection against water ingress during field operation.

---

## Camera Deployment Mechanism

Instead of fixing the underwater camera directly below the platform, the project employs a motorized winch mechanism.

The system consists of:

- Automotive window motor (12 V);
- Cable spool;
- Camera support cable;
- Relay-controlled actuation.

This mechanism allows the operator to adjust camera depth according to water conditions, improving visibility while reducing image disturbances caused by surface turbulence.

---

## Mechanical Advantages

The selected mechanical architecture provides several operational benefits:

- High stability;
- Low center of gravity;
- Easy transportation;
- Modular maintenance;
- Simple assembly;
- Low production cost;
- Scalability for future upgrades.

---

# 8. Propulsion System

## Differential Drive Configuration

The propulsion system adopts a differential drive configuration composed of two independent DC motors positioned near the rear section of each floating pontoon.

This configuration allows movement without requiring rudders or steering mechanisms.

Vehicle motion is obtained by varying the rotational direction and speed of each propulsion motor.

Examples include:

| Left Motor | Right Motor | Movement |
|------------|-------------|----------|
| Forward | Forward | Forward |
| Reverse | Reverse | Backward |
| Forward | Reverse | Rotate Right |
| Reverse | Forward | Rotate Left |
| Stop | Forward | Smooth Left Turn |
| Forward | Stop | Smooth Right Turn |

---

## Propulsion Motors

The propulsion system employs:

- Two 12 V DC motors;
- High torque;
- High rotational speed;
- Gear-assisted mechanical transmission.

Mechanical components were recovered from discarded printers, reducing manufacturing costs while maintaining acceptable mechanical reliability.

---

## Propeller Design

Rather than using commercial marine propellers, the project reused four-blade propellers recovered from microwave oven cooling systems.

Engineering considerations included:

- Increased thrust at low RPM;
- Higher propulsion efficiency;
- Reduced battery consumption;
- Lower mechanical stress on transmission components.

Additional gears and bearings were incorporated to reduce shaft loading and improve long-term durability.

---

## Mechanical Transmission

The propulsion assembly includes:

- Bearings;
- Gear reduction;
- Motor couplings;
- Reinforced supports.

This mechanical arrangement minimizes vibration while improving energy transfer from the motors to the propellers.

---

## Design Considerations

The propulsion subsystem was designed to satisfy the following engineering constraints:

- Low manufacturing cost;
- Easy maintenance;
- Component availability;
- Mechanical robustness;
- Operational reliability;
- Efficient battery utilization.

---

# 9. Embedded Control System

## Design Philosophy

The embedded control system was designed following a distributed architecture in which each processing unit is responsible for a well-defined subset of tasks.

Instead of concentrating every function into a single microcontroller, the project separates navigation control from image acquisition and processing.

This approach reduces computational load, simplifies software maintenance, and improves overall system reliability.

The embedded architecture is divided into three processing layers:

- Low-Level Control
- Image Acquisition
- High-Level Computer Vision

---

## Low-Level Controller

The low-level controller is responsible for all real-time interactions with the robotic platform.

An Arduino Uno was selected due to its robustness, simplicity, large community support, and sufficient computational capability for deterministic control tasks.

Its responsibilities include:

- Reading Bluetooth commands;
- Controlling propulsion motors;
- Operating relay modules;
- Controlling the camera winch;
- Managing underwater lighting;
- Driving visual indicators;
- Executing navigation logic.

The Arduino operates independently from the computer vision subsystem, ensuring that vehicle control remains operational even if video processing is interrupted.

---

## Relay-Based Actuation

Instead of employing dedicated H-bridge motor drivers, the propulsion system utilizes relay modules to reverse motor polarity.

Although unconventional for robotic applications, this solution presented several advantages during development:

- Low implementation cost;
- Easy maintenance;
- Electrical isolation;
- Simple replacement;
- Availability of components.

Each relay module is controlled directly by the Arduino digital outputs.

---

## Embedded Responsibilities

The embedded system is responsible for:

| Function | Responsible Module |
|------------|-------------------|
| Propulsion control | Arduino Uno |
| Camera elevation | Arduino Uno |
| Lighting control | Arduino Uno |
| Visual indicators | Arduino Uno |
| Bluetooth communication | HC-05 Bluetooth Module |
| Motor switching | Relay Modules |

---

## Design Considerations

The embedded system prioritizes deterministic behavior over computational complexity.

Image processing tasks are intentionally delegated to an external computer, allowing the Arduino to maintain stable timing for vehicle control.

This architectural decision significantly reduces software complexity while improving reliability during field operations.

---

# 10. Computer Vision System

## Overview

One of AquaRescue's most innovative characteristics is the integration of computer vision techniques to assist firefighters during victim localization.

Instead of requiring operators to continuously inspect video streams manually, the system automatically analyzes incoming frames and highlights potential human detections in real time.

The objective is not to replace human judgment, but to reduce operator fatigue during prolonged search missions.

---

## System Architecture

The computer vision subsystem is composed of three independent stages:

1. Image Acquisition
2. Image Processing
3. Human Detection

Each stage operates independently while exchanging information through network communication.

---

## Image Acquisition

An ESP32-CAM module is responsible for transmitting live underwater video.

The ESP32 does not execute artificial intelligence algorithms.

Its exclusive responsibility is image acquisition and video streaming.

The module operates as a lightweight MJPEG streaming server connected through a local Wi-Fi network.

Typical streaming pipeline:

Camera

↓

ESP32-CAM

↓

HTTP MJPEG Stream

↓

Wi-Fi Network

↓

Operator Computer

---

## Processing Layer

The operator's notebook executes all computer vision algorithms.

Python was selected due to its mature ecosystem for artificial intelligence and image processing.

Major software components include:

- Python
- OpenCV
- NumPy
- cv2.dnn module

This architecture allows computationally intensive algorithms to execute on hardware considerably more powerful than a microcontroller.

---

## Human Detection

Each received frame undergoes the following processing pipeline:

Frame Acquisition

↓

Image Decoding

↓

Pre-processing

↓

Neural Network Inference

↓

Bounding Box Generation

↓

Confidence Evaluation

↓

Visual Alert

↓

Display

The implemented detection algorithm identifies human figures and overlays bounding boxes on detected individuals while presenting confidence information to the operator.

---

## Design Philosophy

Rather than embedding artificial intelligence directly into the robotic platform, the project deliberately separates sensing from inference.

This decision provides several engineering advantages:

- Lower onboard power consumption;
- Simpler embedded software;
- Reduced hardware cost;
- Easier model replacement;
- Increased computational performance;
- Future compatibility with more advanced neural networks.

---

# 11. Communication Architecture

## Overview

AquaRescue employs two independent communication channels, each optimized for a specific operational purpose.

This separation increases system robustness while simplifying subsystem integration.

---

## Bluetooth Communication

Bluetooth is responsible for command transmission between the operator and the robotic platform.

Commands include:

- Forward movement;
- Reverse movement;
- Turning;
- Camera elevation;
- Lighting control;
- Navigation mode selection.

The Bluetooth link connects directly to the Arduino controller.

---

## Wi-Fi Communication

Video transmission occurs independently through a dedicated Wi-Fi connection.

The ESP32-CAM operates as an MJPEG streaming server, continuously transmitting underwater video to the operator notebook.

The notebook accesses the stream through a standard HTTP endpoint and processes each received frame using OpenCV.

This architecture isolates navigation control from video transmission, preventing failures in one subsystem from directly affecting the other.

---

## Communication Summary

| Communication | Purpose |
|---------------|---------|
| Bluetooth | Robot control |
| Wi-Fi | Video transmission |
| HTTP MJPEG | Image streaming |
| USB | Software upload and maintenance |

---

## Engineering Rationale

Separating control communication from video transmission increases fault tolerance.

Even if the video stream experiences temporary degradation, the operator maintains full control over vehicle navigation through the independent Bluetooth channel.

This modular communication architecture improves operational safety during rescue missions.


## Revision History

| Version | Date | Description |
|:--------|:----|:------------|
| v0.1 | 2026 | Initial architecture specification containing project definition, objectives, stakeholders, and engineering requirements. |
| v0.2 | 2026 | Add architecture specification containing System Overview, Mechanical Architecture, and Propulsion System. |
| v0.3 | 2026 | Add embedded and comunication specification and fix schedule. |
