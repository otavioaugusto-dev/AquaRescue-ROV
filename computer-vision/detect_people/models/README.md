# Models

This directory contains the pretrained model files required by the AquaRescue computer vision module.

## Detection Model

The computer vision system uses the **MobileNet SSD** architecture through OpenCV's DNN module.

The model receives image frames from the camera and performs object detection. The current implementation filters the inference results to identify the `person` class.

## Required Files

Before running the detection system, place the following files in this directory:

```text
MobileNetSSD_deploy.prototxt
MobileNetSSD_deploy.caffemodel
```

The expected directory structure is:

```text
models/
├── MobileNetSSD_deploy.prototxt
├── MobileNetSSD_deploy.caffemodel
└── README.md
```

### File Description

| File | Description |
|---|---|
| `MobileNetSSD_deploy.prototxt` | Defines the neural network architecture and model configuration. |
| `MobileNetSSD_deploy.caffemodel` | Contains the pretrained weights used during inference. |

## Configuration

The detection confidence threshold is defined in:

```text
../config.py
```

The default configuration uses:

```python
CONFIDENCE_THRESHOLD = 0.50
```

This value determines the minimum confidence required for a detection to be displayed.

## Model Files

The pretrained model files are not included in this repository.

They must be obtained from a compatible MobileNet SSD distribution and placed in this directory before running `main.py`.

This keeps the repository lightweight while making the required model structure explicit and reproducible.

## Integration

The model is loaded by:

```text
../main.py
```

The processing pipeline is:

```text
Camera
   │
   ▼
Video Frame
   │
   ▼
Image Preprocessing
   │
   ▼
MobileNet SSD
   │
   ▼
Object Detection
   │
   ▼
Person Filtering
   │
   ▼
Bounding Box + Confidence
```

The system can receive frames from either a webcam or an ESP32-CAM stream, according to the configuration defined in `config.py`.

## AquaRescue Context

The original AquaRescue project was developed as a low-cost robotic platform for the recognition and localization of potential drowning victims.

The computer vision subsystem was designed to assist the operator by identifying people in the camera feed and displaying the detected region on the computer screen.

The implementation contained in this repository provides a reproducible version of this subsystem while preserving the original operational concept of the project.
