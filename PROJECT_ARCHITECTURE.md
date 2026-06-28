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
v0.1

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

---

## Revision History

| Version | Date | Description |
|:--------|:----|:------------|
| v0.1 | 2026 | Initial architecture specification containing project definition, objectives, stakeholders, and engineering requirements. |
