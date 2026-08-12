# Firmware

Firmware subsystem of the AquaRescue ROV.

The embedded control system is responsible for receiving commands from the operator and controlling the propulsion, lighting and camera deployment mechanisms of the robotic platform.

## Embedded Architecture

The original AquaRescue prototype used an **Arduino Uno** as the main control unit.

The Arduino was connected to a shield and responsible for interfacing with the actuator control circuitry.

```text
                 Operator
                    │
                    │ Bluetooth
                    ▼
              ┌───────────┐
              │ Arduino   │
              │    Uno    │
              └─────┬─────┘
                    │
          ┌─────────┼─────────┐
          │         │         │
          ▼         ▼         ▼
       Propulsion  Lighting  Camera
          │         │        Winch
          │         │         │
          ▼         ▼         ▼
      DC Motors    LEDs    DC Motor
```

## Propulsion Control

The ROV uses two 12 V DC motors for propulsion.

The motors are independently controlled on the left and right sides of the platform. Differential control allows the vehicle to move and change direction without requiring a conventional steering mechanism.

The operational concept includes:

- Forward movement
- Reverse movement
- Left/right steering
- Independent motor control

The original prototype used relay-based switching circuitry to control the motors.

## Bluetooth Control

Commands are received by the Arduino through a Bluetooth communication interface.

The Bluetooth link allows the operator to control the ROV remotely while remaining near the vehicle's operating environment.

The exact command protocol and pin mapping of the original prototype are not available in the current project reconstruction and therefore are not assumed here.

## Camera Deployment

The underwater camera is mounted on a mechanical deployment mechanism.

A 12 V automotive power-window motor was used to drive the mechanism due to its high torque and low rotational speed.

The Arduino controls the motor through a relay-based interface, allowing the operator to command the camera mechanism.

The mechanism provides:

- Camera lowering
- Camera raising
- Motor activation through relay control

The mechanical implementation is documented separately in the `hardware/` section.

## Lighting

The embedded controller also operates the lighting system associated with the underwater camera.

The system includes:

- Underwater camera lighting
- Red status light on the main platform

Lighting control is performed through the Arduino and relay circuitry.

## Control Electronics

The original prototype used:

| Component | Function |
|---|---|
| Arduino Uno | Main embedded controller |
| Arduino Shield | Interface and connection layer |
| Bluetooth interface | Wireless command reception |
| Relays | Actuator switching |
| 12 V DC motors | Propulsion |
| 12 V DC motor | Camera deployment mechanism |
| LEDs | Illumination and status indication |

## Power System

The propulsion and mechanical actuation system operates from a 12 V battery system.

The battery packs were constructed using Li-Ion 18650 cells.

Each pack consisted of:

```text
3S10P
```

with 30 cells per pack.

Two battery packs were prepared so that one pack could be used while the other was available for charging.

Voltage regulation was used to provide appropriate supply levels for the electronic control boards and other low-voltage electronics.

## Firmware Responsibilities

The embedded firmware is responsible for the real-time control layer of the AquaRescue platform.

Its responsibilities include:

1. Receiving operator commands.
2. Interpreting movement commands.
3. Controlling the left propulsion motor.
4. Controlling the right propulsion motor.
5. Controlling the camera deployment motor.
6. Controlling the underwater lighting.
7. Controlling the platform status light.

The computer vision processing is intentionally performed outside the Arduino.

```text
Arduino
│
├── Propulsion
├── Camera deployment
├── Lighting
└── Status indication

ESP32-CAM
│
└── Video streaming

Computer
│
└── Computer vision processing
```

This separation allows the microcontroller to focus on deterministic actuator control while the computer performs the computationally intensive vision processing.

## Autonomous Operation

The original operational concept was primarily based on operator control.

The system architecture also allows the control layer to be extended toward autonomous or semi-autonomous search modes.

In such a configuration, movement commands could originate from an autonomous navigation or search algorithm rather than directly from the operator.

The autonomous mode is considered an extension of the control architecture rather than a documented feature of the original firmware implementation.

## Current Repository Status

The original firmware source was developed as part of the prototype and may not be fully preserved in the current project archive.

For this reason, this directory documents the known firmware architecture and responsibilities without fabricating unavailable pin mappings, command protocols or implementation details.

Any recovered source code will be added here and documented according to the actual implementation.

## Relation to the Original Project

The firmware was an integral part of the AquaRescue system, connecting the operator interface to the physical mechanisms of the vehicle.

Together with the mechanical structure, embedded electronics and computer vision subsystem, it formed the complete operational platform used during the project's tests and scientific presentations.
