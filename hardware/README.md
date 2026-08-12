# Hardware

Mechanical and electrical hardware architecture of the AquaRescue ROV.

The vehicle was designed as a compact catamaran-style robotic platform, combining two lateral flotation elements with an aluminum structural frame and an integrated electronics enclosure.

The design prioritizes stability, buoyancy, low cost, component reuse and ease of maintenance.

---

## Mechanical Architecture

The AquaRescue platform uses a **catamaran configuration**.

Two lateral flotation elements provide the primary buoyancy and help maintain the stability of the vehicle during operation.

```text
                 FRONT

        ┌─────────────────────┐
        │    ALUMINUM FRAME   │
        │                     │
   ┌────┴─────────────────────┴────┐
   │                                │
   │      ELECTRONICS ENCLOSURE     │
   │                                │
   └────┬─────────────────────┬─────┘
        │                     │
     PVC Ø100 mm           PVC Ø100 mm
      FLOATATION             FLOATATION
        │                     │
        ▼                     ▼

              PROPULSION
```

The main structural elements are:

- Two PVC flotation tubes
- Anodized aluminum chassis
- Acrylic electronics enclosure
- Silicone PU40 sealing
- Propulsion motors
- Propeller assemblies
- Camera deployment mechanism

---

## Flotation

The two lateral floats were constructed from **100 mm PVC pipes**.

The pipes were reused from construction materials, reducing the cost of the prototype and giving the platform sufficient buoyancy for the onboard systems.

The separated lateral arrangement provides:

- Buoyancy
- Stability
- Resistance to lateral rolling
- Structural support for the central chassis

The flotation elements were sealed using **PU40 silicone** to improve water resistance.

---

## Chassis

The main structural chassis was manufactured using **anodized aluminum**.

The chassis connects the two flotation elements and provides the structural support required for the onboard systems.

The aluminum structure was selected for its combination of:

- Low mass
- Structural rigidity
- Corrosion resistance
- Ease of fabrication
- Compatibility with the prototype construction process

The chassis also integrates the central electronics enclosure and mechanical components.

---

## Electronics Enclosure

The embedded electronics and battery system were housed inside an **11 L acrylic enclosure**.

The enclosure contains the main electrical and electronic components required for vehicle operation.

The enclosure was sealed to protect the electronics from the aquatic environment.

The system contained:

- Arduino Uno
- Arduino shield
- Bluetooth interface
- Relay circuitry
- Voltage regulation
- Battery system
- Associated wiring and connections

The enclosure also served as part of the mechanical integration of the camera deployment system.

---

## Propulsion

The vehicle uses **two 12 V DC motors** for propulsion.

One motor is positioned on each side of the platform.

The independent control of the left and right motors creates a differential propulsion system.

```text
             Forward

       LEFT MOTOR      RIGHT MOTOR
            │               │
            ▼               ▼
        ─────────         ─────────
          PROP.             PROP.
            │                 │
            ▼                 ▼

             Differential
               Steering
```

The propulsion system allows the vehicle to:

- Move forward
- Move backward
- Turn left
- Turn right
- Rotate using differential thrust

The motors were positioned toward the outer portions of the platform, close to the flotation elements.

---

## Propellers

The propulsion propellers were reused from a microwave oven component.

The selected propeller configuration used **four blades**, providing increased thrust at low and medium rotational speeds.

The design objective was to obtain sufficient thrust without requiring unnecessarily high motor speed.

This approach contributed to:

- Reduced electrical demand
- Lower motor loading
- Improved low-speed thrust
- More efficient propulsion

The propulsion assemblies incorporated a custom mechanical coupling using gears and bearings.

---

## Motor Coupling

A custom mechanical mechanism was developed to connect the motors to the propulsion shafts.

The mechanism incorporated:

- Gears
- Bearings
- Motor coupling components
- Propeller shaft

The use of bearings reduced mechanical friction and radial loading on the motor shaft.

The motors and mechanical components were partially reused from discarded printers and other equipment during the prototype development process.

Components were inspected and tested before integration into the vehicle.

---

## Differential Steering

The ROV does not use a conventional rudder.

Direction is controlled by varying the relative thrust of the two propulsion motors.

The control concept is:

```text
FORWARD

LEFT MOTOR   → forward
RIGHT MOTOR  → forward


TURN LEFT

LEFT MOTOR   → reduced / reverse
RIGHT MOTOR  → forward


TURN RIGHT

LEFT MOTOR   → forward
RIGHT MOTOR  → reduced / reverse


ROTATION

LEFT MOTOR   → forward
RIGHT MOTOR  → reverse
```

This arrangement simplifies the mechanical design by eliminating the need for a dedicated steering actuator.

---

## Camera Deployment System

The underwater camera is mounted on a vertically deployable mechanism.

The mechanism operates similarly to a cable spool or winch.

```text
          CAMERA
             │
             │
             │  Cable
             │
             ▼
        ┌─────────┐
        │  SPOOL  │
        └────┬────┘
             │
             ▼
       12 V DC MOTOR
```

The spool is driven by a **12 V automotive power-window motor**.

This motor was selected because of its:

- High torque
- Low rotational speed
- Availability
- Suitability for mechanical lifting

The mechanism allows the camera to be lowered into the water and subsequently recovered.

---

## Camera Assembly

The camera system consists of:

- Underwater camera
- Protective enclosure
- Cable
- Deployment mechanism
- ESP32-CAM interface

The camera was installed inside a repurposed surveillance-camera enclosure.

The camera signal was transmitted through a cable to the ESP32-CAM.

The ESP32-CAM then provided the video stream to the computer vision subsystem.

---

## Electrical Architecture

The vehicle combines a 12 V power system with regulated low-voltage electronics.

```text
                BATTERY SYSTEM
                      │
                ┌─────┴─────┐
                │           │
                ▼           ▼
          12 V ACTUATORS  VOLTAGE
                │          REGULATOR
        ┌───────┼───────┐      │
        │       │       │      ▼
        ▼       ▼       ▼   ELECTRONICS
     Motor   Motor   Camera
```

The propulsion motors and camera deployment motor operate from the 12 V system.

Voltage regulation provides appropriate power levels for the electronic control circuitry.

---

## Battery System

The prototype used **Li-Ion 18650 cells**.

Each battery pack contained:

```text
3S10P
```

resulting in:

```text
3 series groups
×
10 cells in parallel
=
30 cells per pack
```

Two packs were prepared for operation and charging rotation.

```text
             BATTERY SYSTEM

        ┌────────────────────┐
        │      PACK A        │
        │      3S10P         │
        │      30 cells      │
        └────────────────────┘

        ┌────────────────────┐
        │      PACK B        │
        │      3S10P         │
        │      30 cells      │
        └────────────────────┘

              ⇅

       Operating / Charging
            Rotation
```

The use of two packs allowed one battery assembly to be available for charging while the other was being used.

> **Note:** Exact cell capacity, BMS specification, measured runtime and charging parameters were not preserved in the available project documentation and are therefore not specified here.

---

## Embedded Electronics

The embedded control system was based on an **Arduino Uno**.

The controller interfaces with:

- Propulsion control
- Camera deployment
- Lighting
- Status indication
- Bluetooth communication

Relay-based switching was used to control the higher-power actuator circuits.

```text
                 ARDUINO UNO
                      │
        ┌─────────────┼──────────────┐
        │             │              │
        ▼             ▼              ▼
     RELAYS       BLUETOOTH       LIGHTING
        │
        ├──────────────┐
        ▼              ▼
   PROPULSION       CAMERA
     MOTORS        MECHANISM
```

---

## ESP32-CAM

The ESP32-CAM was dedicated to the camera subsystem.

Its primary role was to provide the camera stream rather than perform the main person-detection inference.

```text
Camera
   │
   ▼
ESP32-CAM
   │
   │ HTTP / MJPEG
   ▼
Wi-Fi Network
   │
   ▼
Computer
   │
   ▼
OpenCV + MobileNet SSD
```

This architecture separates embedded control from computationally intensive computer vision.

---

## Lighting

The vehicle incorporated lighting for the underwater camera system.

The embedded controller also operated a red status LED on the main platform.

Lighting was controlled through the embedded electrical system.

The lighting system was intended to improve visibility during underwater operation and provide a visible status indication for the platform.

---

## Waterproofing

Water resistance was achieved through mechanical sealing of the flotation and electronics structures.

The prototype used **PU40 silicone** as a sealing material.

The electronics enclosure was isolated from the external aquatic environment, while the flotation tubes were sealed to preserve buoyancy.

Waterproofing was verified through practical testing rather than through a formal ingress-protection certification.

---

## Component Reuse

A significant design principle of the AquaRescue project was the reuse of available components.

Examples include:

| Component | Source / Reuse |
|---|---|
| PVC flotation tubes | Construction material |
| Propellers | Microwave oven component |
| Motors / mechanical components | Reused equipment and printers |
| Camera enclosure | Surveillance camera housing |
| Battery cells | 18650 Li-Ion cells |

Component reuse reduced development cost and allowed the team to rapidly prototype mechanical solutions.

---

## Hardware Design Philosophy

The hardware architecture was developed around four main principles:

### Low Cost

The platform relied heavily on reused and commercially available components.

### Modularity

Mechanical and electrical subsystems were separated to facilitate testing and maintenance.

### Stability

The catamaran configuration provided a wide flotation base and improved stability on the water.

### Practicality

The design prioritized components that were accessible to the team and could be fabricated or adapted using available tools and materials.

---

## System Integration

The complete hardware system combines mechanical, electrical and computational subsystems.

```text
                         AQUARESCUE ROV
                              │
       ┌──────────────────────┼──────────────────────┐
       │                      │                      │
       ▼                      ▼                      ▼
   MECHANICAL              EMBEDDED             COMPUTER
    SYSTEM                 SYSTEM              VISION
       │                      │                      │
       │                      │                      │
 ┌─────┼──────┐        ┌──────┼──────┐             │
 │     │      │        │      │      │             │
 ▼     ▼      ▼        ▼      ▼      ▼             ▼
Float Chassis Camera Arduino Motors Lights     OpenCV
       │      │          │       │               │
       │      │          │       │               │
       └──────┴──────────┴───────┴───────────────┘
                         │
                         ▼
                  Integrated ROV
```

The mechanical platform provides flotation and structural support.

The embedded system controls the physical actuators.

The ESP32-CAM provides the visual data required by the computer vision subsystem.

The computer performs person detection and presents the results to the operator.

---

## Testing

The physical platform was tested in different aquatic environments during development.

Tests were performed in:

- The Olympic swimming pool at the school
- A coastal environment at Tabuba Beach, including the meeting point between river and sea

The tests evaluated the integrated system's:

- Buoyancy
- Stability
- Propulsion
- Camera operation
- Image quality
- Battery autonomy
- Person detection

During testing, the system successfully provided usable camera images and the computer vision system was able to identify a person during a diving test.

---

## Hardware Limitations

The prototype was developed as a low-cost research and demonstration platform.

The available documentation does not provide complete engineering specifications for:

- Exact chassis dimensions
- Total vehicle mass
- Maximum payload
- Measured thrust
- Motor current
- Propeller diameter and pitch
- Battery capacity in Ah
- Maximum operating depth
- Waterproofing rating
- Exact mechanical reduction ratio

These values should not be inferred from the prototype description and are therefore intentionally omitted.

---

## Related Subsystems

The hardware system is directly integrated with the other AquaRescue modules:

```text
hardware/
    │
    ├── Mechanical platform
    │
    ├── Propulsion
    │
    ├── Camera mechanism
    │
    └── Power system
          │
          ▼
firmware/
    │
    ├── Motor control
    ├── Lighting
    ├── Camera mechanism
    └── Bluetooth
          │
          ▼
computer-vision/
    │
    ├── ESP32-CAM stream
    ├── OpenCV
    └── MobileNet SSD
```

Together, these subsystems form the complete AquaRescue ROV architecture.
