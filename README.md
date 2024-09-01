# Arduino Laser Intensity Adjustment Project with LCD Display

This project demonstrates how to use an Arduino UNO with a KY-008 Laser Transmitter Module, an ultrasonic sensor, and an LCD display to adjust the laser intensity based on the distance from the target. Additionally, a buzzer is used to alert when the target is too close or too far.

## Components

- **Arduino UNO**: The microcontroller board for controlling the project.
- **KY-008 Laser Transmitter Module**: Emits a focused beam of coherent light.
- **Ultrasonic Sensor**: Measures the distance to the target by emitting and receiving sound waves.
- **LiquidCrystal I2C Display**: Displays distance and power on a 16x2 LCD screen.
- **Buzzer**: Emits a sound when the target distance is out of the specified range.
- **Jumper Wires**: Connect the components to the Arduino and each other.
- **Breadboard**: Used for prototyping and connecting components.

## How It Works

1. **KY-008 Laser Transmitter Module**: Contains a laser diode that emits a beam of coherent light. The intensity of the laser beam is adjusted based on the distance to the target.

2. **Ultrasonic Sensor**: Measures the distance to the target by emitting sound waves and calculating the time it takes for the echo to return. This distance information is used to adjust the laser intensity.

3. **LCD Display**: Shows the current distance and calculated laser power.

4. **Buzzer**: Alerts when the distance is outside the specified range (too close or too far).

5. **Arduino UNO**: Reads data from the ultrasonic sensor, calculates the required laser intensity, adjusts the laser power, and updates the LCD display and buzzer.

## Circuit Diagram

![Picture4](https://github.com/user-attachments/assets/7a2eac8c-d8e0-47f8-a464-e7ea98bc5d42)

![Picture3](https://github.com/user-attachments/assets/c9353adf-a817-42cd-9b80-172825510f87)


## Connections

- **KY-008 Laser Transmitter Module**:
  - VCC to 5V on Arduino
  - GND to GND on Arduino
  - Signal to pin 3 on Arduino

- **Ultrasonic Sensor**:
  - VCC to 5V on Arduino
  - GND to GND on Arduino
  - TRIG to pin 8 on Arduino
  - ECHO to pin 9 on Arduino

- **LiquidCrystal I2C Display**:
  - VCC to 5V on Arduino
  - GND to GND on Arduino
  - SDA to A4 on Arduino
  - SCL to A5 on Arduino

- **Buzzer**:
  - Positive to pin 12 on Arduino
  - Negative to GND on Arduino

- **Breadboard**: Use jumper wires to connect components to the breadboard and then to the Arduino.
