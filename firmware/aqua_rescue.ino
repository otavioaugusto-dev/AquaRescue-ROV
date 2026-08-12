/*
 * AquaRescue ROV
 * Embedded Control Firmware
 *
 * Platform: Arduino Uno
 *
 * Original control concept:
 * - Bluetooth command input
 * - Differential propulsion
 * - Lighting control
 * - Buzzer
 * - Bluetooth connection fail-safe
 *
 * Command protocol:
 *
 * F - Forward
 * B - Backward
 * L - Turn left
 * R - Turn right
 * G - Forward + right
 * I - Forward + left
 * S - Stop
 * V - Toggle buzzer
 * W - Toggle front lights
 * U - Camera mechanism command
 *
 * The original prototype used additional hardware for camera
 * deployment. Exact relay pin mapping was not preserved in
 * the recovered firmware and is therefore not assumed here.
 */

#include <Arduino.h>


// Motor pins

const uint8_t RIGHT_MOTOR_IN1 = 10;
const uint8_t RIGHT_MOTOR_IN2 = 9;
const uint8_t RIGHT_MOTOR_EN  = 11;

const uint8_t LEFT_MOTOR_IN1 = 6;
const uint8_t LEFT_MOTOR_IN2 = 5;
const uint8_t LEFT_MOTOR_EN  = 3;


// Peripheral pins

const uint8_t FRONT_LIGHT_PIN = 12;
const uint8_t REAR_LIGHT_PIN  = 13;
const uint8_t BUZZER_PIN      = 4;

const uint8_t BLUETOOTH_STATE_PIN = 2;


// Configuration

const uint8_t MOTOR_SPEED = 255;

const unsigned long SERIAL_BAUD_RATE = 9600;


// State

char currentCommand = 'S';

bool frontLightsEnabled = false;
bool rearLightsEnabled = false;
bool buzzerEnabled = false;


// Propulsion

void stopMotors()
{
    digitalWrite(RIGHT_MOTOR_IN1, LOW);
    digitalWrite(RIGHT_MOTOR_IN2, LOW);

    digitalWrite(LEFT_MOTOR_IN1, LOW);
    digitalWrite(LEFT_MOTOR_IN2, LOW);

    analogWrite(RIGHT_MOTOR_EN, 0);
    analogWrite(LEFT_MOTOR_EN, 0);
}


void moveForward()
{
    digitalWrite(RIGHT_MOTOR_IN1, LOW);
    digitalWrite(RIGHT_MOTOR_IN2, HIGH);

    digitalWrite(LEFT_MOTOR_IN1, LOW);
    digitalWrite(LEFT_MOTOR_IN2, HIGH);

    analogWrite(RIGHT_MOTOR_EN, MOTOR_SPEED);
    analogWrite(LEFT_MOTOR_EN, MOTOR_SPEED);
}


void moveBackward()
{
    digitalWrite(RIGHT_MOTOR_IN1, HIGH);
    digitalWrite(RIGHT_MOTOR_IN2, LOW);

    digitalWrite(LEFT_MOTOR_IN1, HIGH);
    digitalWrite(LEFT_MOTOR_IN2, LOW);

    analogWrite(RIGHT_MOTOR_EN, MOTOR_SPEED);
    analogWrite(LEFT_MOTOR_EN, MOTOR_SPEED);
}


void turnRight()
{
    digitalWrite(RIGHT_MOTOR_IN1, HIGH);
    digitalWrite(RIGHT_MOTOR_IN2, LOW);

    digitalWrite(LEFT_MOTOR_IN1, LOW);
    digitalWrite(LEFT_MOTOR_IN2, HIGH);

    analogWrite(RIGHT_MOTOR_EN, MOTOR_SPEED);
    analogWrite(LEFT_MOTOR_EN, MOTOR_SPEED);
}


void turnLeft()
{
    digitalWrite(RIGHT_MOTOR_IN1, LOW);
    digitalWrite(RIGHT_MOTOR_IN2, HIGH);

    digitalWrite(LEFT_MOTOR_IN1, HIGH);
    digitalWrite(LEFT_MOTOR_IN2, LOW);

    analogWrite(RIGHT_MOTOR_EN, MOTOR_SPEED);
    analogWrite(LEFT_MOTOR_EN, MOTOR_SPEED);
}


void forwardRight()
{
    digitalWrite(RIGHT_MOTOR_IN1, HIGH);
    digitalWrite(RIGHT_MOTOR_IN2, LOW);

    digitalWrite(LEFT_MOTOR_IN1, LOW);
    digitalWrite(LEFT_MOTOR_IN2, HIGH);

    analogWrite(RIGHT_MOTOR_EN, MOTOR_SPEED);
    analogWrite(LEFT_MOTOR_EN, MOTOR_SPEED);
}


void forwardLeft()
{
    digitalWrite(RIGHT_MOTOR_IN1, LOW);
    digitalWrite(RIGHT_MOTOR_IN2, HIGH);

    digitalWrite(LEFT_MOTOR_IN1, HIGH);
    digitalWrite(LEFT_MOTOR_IN2, LOW);

    analogWrite(RIGHT_MOTOR_EN, MOTOR_SPEED);
    analogWrite(LEFT_MOTOR_EN, MOTOR_SPEED);
}


// Lighting

void setFrontLights(bool enabled)
{
    frontLightsEnabled = enabled;
    digitalWrite(FRONT_LIGHT_PIN, enabled ? HIGH : LOW);
}


void setRearLights(bool enabled)
{
    rearLightsEnabled = enabled;
    digitalWrite(REAR_LIGHT_PIN, enabled ? HIGH : LOW);
}


void toggleFrontLights()
{
    setFrontLights(!frontLightsEnabled);
}


void toggleRearLights()
{
    setRearLights(!rearLightsEnabled);
}


// Buzzer

void toggleBuzzer()
{
    buzzerEnabled = !buzzerEnabled;

    if (buzzerEnabled)
    {
        tone(BUZZER_PIN, 1000);
    }
    else
    {
        noTone(BUZZER_PIN);
    }
}


// Command handling

void processCommand(char command)
{
    switch (command)
    {
        case 'F':
            moveForward();
            break;

        case 'B':
            moveBackward();
            break;

        case 'L':
            turnLeft();
            break;

        case 'R':
            turnRight();
            break;

        case 'G':
            forwardRight();
            break;

        case 'I':
            forwardLeft();
            break;

        case 'S':
            stopMotors();
            break;

        case 'V':
            toggleBuzzer();
            break;

        case 'W':
            toggleFrontLights();
            break;

        case 'U':
            /*
             * Camera deployment command.
             *
             * The original firmware contained the U command,
             * but the recovered source does not contain the
             * relay pin mapping required to safely control the
             * camera deployment motor.
             *
             * The command is therefore reserved until the
             * original wiring is recovered.
             */
            break;

        default:
            break;
    }
}


// Bluetooth safety

bool bluetoothConnected()
{
    return digitalRead(BLUETOOTH_STATE_PIN) == HIGH;
}


void handleBluetooth()
{
    if (!bluetoothConnected())
    {
        currentCommand = 'S';
        stopMotors();
        return;
    }

    if (Serial.available() <= 0)
    {
        return;
    }

    char command = Serial.read();

    currentCommand = command;

    processCommand(command);
}


// Setup

void setup()
{
    pinMode(RIGHT_MOTOR_IN1, OUTPUT);
    pinMode(RIGHT_MOTOR_IN2, OUTPUT);
    pinMode(RIGHT_MOTOR_EN, OUTPUT);

    pinMode(LEFT_MOTOR_IN1, OUTPUT);
    pinMode(LEFT_MOTOR_IN2, OUTPUT);
    pinMode(LEFT_MOTOR_EN, OUTPUT);

    pinMode(FRONT_LIGHT_PIN, OUTPUT);
    pinMode(REAR_LIGHT_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    pinMode(BLUETOOTH_STATE_PIN, INPUT);

    stopMotors();

    setFrontLights(false);
    setRearLights(false);

    noTone(BUZZER_PIN);

    Serial.begin(SERIAL_BAUD_RATE);
}


// Main loop

void loop()
{
    handleBluetooth();
}
