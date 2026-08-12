# AquaRescue Person Detection

Computer vision module developed for the AquaRescue ROV project.

The module receives video frames from a webcam or an ESP32-CAM stream and uses a MobileNet SSD model through OpenCV's DNN module to detect people in the image.

## System Pipeline

```text
ESP32-CAM / Webcam
        │
        ▼
   Video Stream
        │
        ▼
   OpenCV Capture
        │
        ▼
 Image Preprocessing
        │
        ▼
   MobileNet SSD
        │
        ▼
 Person Detection
        │
        ▼
 Bounding Box + Confidence
        │
        ▼
 Operator Display
```

## Features

- Real-time person detection
- Webcam support
- ESP32-CAM MJPEG stream support
- Confidence threshold configuration
- Bounding box visualization
- Detection confidence display
- Real-time FPS display
- Lightweight inference through OpenCV DNN

## Requirements

Python 3.10 or newer is recommended.

Install the dependencies with:

```bash
pip install -r requirements.txt
```

## Model

The system uses MobileNet SSD.

The required model files are documented in:

```text
models/README.md
```

The expected structure is:

```text
detect_people/
├── main.py
├── config.py
├── requirements.txt
├── README.md
└── models/
    ├── MobileNetSSD_deploy.prototxt
    ├── MobileNetSSD_deploy.caffemodel
    └── README.md
```

## Configuration

The main configuration parameters are located in:

```text
config.py
```

### Camera source

For a webcam:

```python
USE_WEBCAM = True
WEBCAM_INDEX = 0
```

For an ESP32-CAM stream:

```python
USE_WEBCAM = False
STREAM_URL = "http://<ESP32-IP>:81/stream"
```

The exact stream address depends on the network configuration of the ESP32-CAM.

### Detection threshold

The minimum confidence required for a detection can be adjusted with:

```python
CONFIDENCE_THRESHOLD = 0.50
```

Higher values reduce false detections but may cause less confident people to be ignored.

## Running

After installing the dependencies and placing the required model files in `models/`, run:

```bash
python main.py
```

The detection window will display the camera feed with bounding boxes around detected people.

Press:

```text
Q
```

to exit.

## Output

When a person is detected, the system displays:

```text
Person (XX%)
```

together with a bounding box around the detected region.

The current FPS is also displayed in the upper-left corner of the window.

## Project Context

The computer vision subsystem is part of the AquaRescue robotic platform developed for the recognition and localization of potential drowning victims.

In the original system, the camera was connected to an ESP32-CAM, which transmitted the video stream to a computer. The computer performed the image processing and displayed the detected person to the operator.

This repository preserves that operational architecture while providing a reproducible implementation of the detection subsystem.

## Limitations

The detector depends on the quality of the incoming video stream.

Performance may be affected by:

- Low image resolution
- Poor lighting
- Water turbidity
- Occlusion
- Distance from the target
- Camera movement
- Network latency

The system is intended as an operator-assistance tool and should not be considered a replacement for human observation or professional rescue procedures.
