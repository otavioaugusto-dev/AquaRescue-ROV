# Computer Vision

Computer vision subsystem of the AquaRescue ROV.

The system is responsible for receiving the video stream from the onboard camera and processing the frames on a computer to assist in the recognition of people in the aquatic environment.

## Architecture

```text
Camera
   │
   ▼
ESP32-CAM
   │
   │ HTTP / MJPEG
   ▼
Local Wi-Fi Network
   │
   ▼
Computer
   │
   ▼
OpenCV DNN
   │
   ▼
MobileNet SSD
   │
   ▼
Person Detection
   │
   ▼
Operator Interface
```

## Directory Structure

```text
computer-vision/
├── README.md
│
└── detect_people/
    ├── main.py
    ├── config.py
    ├── requirements.txt
    ├── README.md
    │
    └── models/
        └── README.md
```

## Detection Module

The implementation is located in:

```text
detect_people/
```

The module provides:

- Camera stream acquisition
- Image preprocessing
- Person detection
- Confidence filtering
- Bounding box visualization
- FPS monitoring

Detailed installation and execution instructions are available in:

```text
detect_people/README.md
```

## Camera Integration

The original AquaRescue architecture used an ESP32-CAM as the camera interface.

The ESP32-CAM provides the video stream over the local network, while computationally intensive image processing is performed externally on a computer.

This division keeps the embedded system lightweight while allowing the computer to perform the computer vision workload.

## Processing

The current implementation uses:

- Python
- OpenCV
- OpenCV DNN
- MobileNet SSD
- NumPy

The detection model runs on the computer rather than directly on the ESP32-CAM.

## Operational Concept

During operation, the camera provides the visual information required by the operator.

The computer vision subsystem processes the incoming frames and highlights detected people, providing an additional layer of assistance during search and reconnaissance.

## Historical Context

The AquaRescue project was originally developed and tested as a robotic platform for assisting in the recognition and localization of potential drowning victims.

The current repository organizes and documents the computer vision subsystem so that the implementation can be reproduced and further developed..
