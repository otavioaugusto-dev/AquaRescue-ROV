# Person Detection Module

This module implements the computer vision pipeline responsible for detecting people in the live video stream transmitted by the AquaRescue robotic platform.

The implementation was developed as a proof of concept to assist operators during aquatic search missions by automatically highlighting people visible in the incoming video.

Although originally designed for AquaRescue, the detection pipeline can also be adapted for other computer vision applications based on ESP32-CAM or conventional webcams.

---

# Objectives

The software performs the following tasks:

- Connect to the ESP32-CAM video stream.
- Receive MJPEG frames in real time.
- Decode incoming frames.
- Execute person detection.
- Draw bounding boxes around detected people.
- Display the processed video to the operator.

The system provides visual assistance only.

Final decisions always remain under human supervision.

---

# Processing Pipeline

```
ESP32-CAM
      │
      ▼
 MJPEG Stream
      │
      ▼
OpenCV VideoCapture
      │
      ▼
Frame Acquisition
      │
      ▼
Person Detection
      │
      ▼
Bounding Box Rendering
      │
      ▼
Operator Screen
```

---

# Software Architecture

The software is organized as a sequential processing pipeline.

1. Connect to the video stream.
2. Capture a frame.
3. Preprocess the image.
4. Execute person detection.
5. Draw bounding boxes.
6. Display the processed frame.
7. Repeat until interrupted.

This architecture prioritizes simplicity, robustness, and ease of maintenance.

---

# Main Technologies

| Component | Technology |
|------------|------------|
| Language | Python |
| Vision Library | OpenCV |
| Stream Protocol | MJPEG |
| Image Processing | NumPy |
| Camera | ESP32-CAM |

---

# Repository Contents

```
detect_people/

README.md

main.py

requirements.txt
```

---

# Running the Software

Install the required libraries:

```bash
pip install -r requirements.txt
```

Edit the ESP32-CAM IP address inside `main.py`.

Then run:

```bash
python main.py
```

The processed video stream will be displayed in a window showing detected people highlighted with bounding boxes.

---

# Current Limitations

Current implementation limitations include:

- Fixed camera position
- Dependence on lighting conditions
- Reduced performance in turbid water
- Single-class detection (person)
- No tracking between frames

These limitations are acceptable for an educational research prototype.

---

# Future Improvements

Possible future upgrades include:

- YOLOv8
- MobileNet SSD
- Multi-object detection
- GPU acceleration
- Image enhancement
- Confidence filtering
- Object tracking
- Underwater image restoration

---

This module demonstrates the feasibility of combining low-cost embedded hardware with computer vision techniques to support public safety applications.
