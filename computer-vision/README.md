# Computer Vision

The computer vision subsystem is responsible for assisting the operator during aquatic search missions by processing the live video stream transmitted from the robotic platform.

Instead of performing image processing onboard the robot, AquaRescue adopts a distributed architecture in which image acquisition and computer vision are executed on different devices.

This approach significantly reduces the computational requirements of the embedded hardware while allowing more sophisticated image processing algorithms to be executed on a notebook.

---

# Objectives

The subsystem was designed to:

- Receive the live video stream transmitted by the ESP32-CAM.
- Process incoming frames in real time.
- Detect people using computer vision techniques.
- Highlight detections on the operator's screen.
- Assist firefighters during search operations.

The objective is not to replace human decision-making, but to provide visual assistance capable of reducing operator workload during prolonged missions.

---

# Architecture

The computer vision pipeline is divided into two independent stages.

## Image Acquisition

The ESP32-CAM operates exclusively as a streaming server.

Its responsibilities include:

- Capturing images.
- Encoding frames.
- Streaming MJPEG over Wi-Fi.

No computer vision processing is executed onboard.

---

## Image Processing

A notebook receives the video stream and executes the detection algorithm using Python and OpenCV.

Separating acquisition from processing provides:

- Higher processing capability.
- Easier algorithm development.
- Lower embedded hardware requirements.
- Greater flexibility for future AI upgrades.

---

# Processing Pipeline

```
ESP32-CAM
      │
      ▼
 MJPEG Stream
      │
      ▼
 OpenCV
      │
      ▼
 Frame Capture
      │
      ▼
 Person Detection
      │
      ▼
 Bounding Boxes
      │
      ▼
 Operator Display
```

---

# Software Stack

| Component | Technology |
|------------|------------|
| Programming Language | Python |
| Computer Vision | OpenCV |
| Streaming | MJPEG |
| Embedded Camera | ESP32-CAM |
| Video Capture | OpenCV VideoCapture |
| Operating System | Windows |

---

# Repository Structure

```
computer-vision/

README.md

detect_people/

models/
```

---

# Experimental Results

During field validation, the subsystem successfully:

- Received the wireless video stream.
- Processed frames in real time.
- Detected people visible in the camera.
- Displayed detections to the operator.

The system demonstrated the feasibility of combining low-cost embedded hardware with external computer vision processing for search assistance.

---

# Current Limitations

The current implementation presents some limitations:

- Detection depends on image quality.
- Lighting conditions influence performance.
- Water turbidity reduces visibility.
- Only person detection was implemented.
- No object tracking was employed.

These limitations are expected in low-cost research prototypes and provide opportunities for future improvements.

---

# Future Improvements

Possible future developments include:

- YOLOv8 integration.
- Object tracking.
- Semantic segmentation.
- Underwater image enhancement.
- GPU acceleration.
- Automatic target classification.
- Multi-object detection.
- Sonar data fusion.

---

This module documents the complete computer vision architecture adopted by AquaRescue and complements the engineering information presented in the main repository.
