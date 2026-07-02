from dataclasses import dataclass
from pathlib import Path
import time

import cv2
import numpy as np

import config


CLASSES = [
    "background", "aeroplane", "bicycle", "bird", "boat",
    "bottle", "bus", "car", "cat", "chair",
    "cow", "diningtable", "dog", "horse", "motorbike",
    "person", "pottedplant", "sheep", "sofa", "train",
    "tvmonitor"
]


BoundingBox = tuple[int, int, int, int]

MODEL_DIR = Path(__file__).parent / "models"
PROTOTXT = MODEL_DIR / "MobileNetSSD_deploy.prototxt"
MODEL = MODEL_DIR / "MobileNetSSD_deploy.caffemodel"


@dataclass(slots=True)
class Detection:
    confidence: float
    box: BoundingBox


def load_model() -> cv2.dnn_Net:
    if not PROTOTXT.exists():
        raise FileNotFoundError(
            f"Model definition not found: {PROTOTXT}"
        )

    if not MODEL.exists():
        raise FileNotFoundError(
            f"Model weights not found: {MODEL}"
        )

    return cv2.dnn.readNetFromCaffe(
        str(PROTOTXT),
        str(MODEL),
    )


def connect_camera() -> cv2.VideoCapture:
    source = (
        config.WEBCAM_INDEX
        if config.USE_WEBCAM
        else config.STREAM_URL
    )

    camera = cv2.VideoCapture(source)

    if not camera.isOpened():
        raise ConnectionError(
            f"Unable to connect to video source: {source}"
        )

    camera.set(
        cv2.CAP_PROP_FRAME_WIDTH,
        config.FRAME_WIDTH,
    )

    return camera


def preprocess_frame(frame: np.ndarray):
    frame = cv2.resize(frame, (300, 300))

    return cv2.dnn.blobFromImage(
        frame,
        scalefactor=0.007843,
        size=(300, 300),
        mean=127.5,
    )


def detect_people(
    frame: np.ndarray,
    model: cv2.dnn_Net,
) -> list[Detection]:

    blob = preprocess_frame(frame)

    model.setInput(blob)

    outputs = model.forward()

    frame_height, frame_width = frame.shape[:2]

    detections: list[Detection] = []

    for index in range(outputs.shape[2]):

        confidence = float(outputs[0, 0, index, 2])

        if confidence < config.CONFIDENCE_THRESHOLD:
            continue

        class_index = int(outputs[0, 0, index, 1])

        if CLASSES[class_index] != "person":
            continue

        x1, y1, x2, y2 = (
            outputs[0, 0, index, 3:7]
            * np.array(
                [
                    frame_width,
                    frame_height,
                    frame_width,
                    frame_height,
                ]
            )
        ).astype(int)

        detections.append(
            Detection(
                confidence=confidence,
                box=(x1, y1, x2, y2),
            )
        )

    return detections

def draw_detections(
    frame: np.ndarray,
    detections: list[Detection],
) -> None:

    for detection in detections:

        x1, y1, x2, y2 = detection.box

        cv2.rectangle(
            frame,
            (x1, y1),
            (x2, y2),
            (0, 255, 0),
            2,
        )

        label = f"Person ({detection.confidence:.0%})"

        cv2.putText(
            frame,
            label,
            (x1, max(20, y1 - 10)),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.6,
            (0, 255, 0),
            2,
        )


def draw_fps(
    frame: np.ndarray,
    fps: float,
) -> None:

    cv2.putText(
        frame,
        f"{fps:.1f} FPS",
        (10, 30),
        cv2.FONT_HERSHEY_SIMPLEX,
        0.7,
        (255, 255, 255),
        2,
    )


def cleanup(camera: cv2.VideoCapture) -> None:
    camera.release()
    cv2.destroyAllWindows()


def main() -> None:

    try:
        model = load_model()
        camera = connect_camera()

    except Exception as error:
        print(error)
        return

    cv2.namedWindow(
        config.WINDOW_NAME,
        cv2.WINDOW_NORMAL,
    )

    previous_time = time.perf_counter()

    try:

        while True:

            success, frame = camera.read()

            if not success:
                print("Unable to read frame.")
                break

            detections = detect_people(
                frame,
                model,
            )

            draw_detections(
                frame,
                detections,
            )

            current_time = time.perf_counter()

            elapsed = current_time - previous_time

            fps = 1 / elapsed if elapsed > 0 else 0

            previous_time = current_time

            draw_fps(
                frame,
                fps,
            )

            cv2.imshow(
                config.WINDOW_NAME,
                frame,
            )

            key = cv2.waitKey(1)

            if key == config.EXIT_KEY:
                break

    finally:
        cleanup(camera)


if __name__ == "__main__":
    main()
