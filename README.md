# Bluetooth Remote-Controlled Wheelchair (Prototype)

A low-cost prototype of a wheelchair that you can control from a smartphone over Bluetooth. An Arduino reads commands from a Bluetooth module and drives two DC motors through a motor driver.

> **Note:** This is a small prototype for learning and testing. It is not a medical device and is not ready to carry a real person.

## Features

- Wireless control from a phone using Bluetooth
- Five commands: forward, backward, left, right, stop
- Simple code that is easy to read and change
- Built with cheap, easy-to-find parts

## Components

| Part | Quantity |
|------|----------|
| Arduino Uno                       | 1 |
| HC-05            Bluetooth module | 1 |
| L298N motor driver | 1 |
| DC gear motors with wheels | 2 |
| Battery pack for the motors | 1 |
| Jumper wires | As needed |

## How It Works

1. The phone connects to the HC-05 module by Bluetooth.
2. A Bluetooth RC controller app on the phone sends one character for each button.
3. The Arduino reads the character from the serial port (9600 baud).
4. The Arduino sets the motor driver pins HIGH or LOW, and the motors move.

### Commands

| Character | Action |
|-----------|--------|
| `F` | Move forward |
| `B` | Move backward |
| `L` | Turn left |
| `R` | Turn right |
| `S` | Stop |

## Wiring

**Arduino to L298N motor driver**

| Arduino Pin | L298N Pin | Motor |
|-------------|-----------|-------|
| 3 | IN1 | Left motor |
| 5 | IN2 | Left motor |
| 6 | IN3 | Right motor |
| 7 | IN4 | Right motor |

**Arduino to HC-05**

| HC-05 Pin | Arduino Pin |
|-----------|-------------|
| VCC | 5V |
| GND | GND |
| TX | RX (pin 0) |
| RX | TX (pin 1) |

Important notes:

- Connect the grounds of the Arduino, the motor driver, and the battery together.
- Keep the jumpers on the L298N ENA and ENB pins so both motors are always enabled.
- The HC-05 RX pin works at 3.3V. It is best to use a voltage divider  on the Arduino TX line.
- Disconnect the HC-05 TX and RX wires while uploading the code, because the Bluetooth module shares the same serial pins as USB.
- If a motor spins in the wrong direction, swap its two wires on the motor driver.



## How to Use

1. Wire the circuit.
2. Open the code in the Arduino IDE and upload it to the board.
3. Reconnect the HC-05 wires and power the motors.
4. Pair your phone with the HC-05 (the default PIN is usually `1234` or `0000`).
5. Open a Bluetooth RC controller app, connect to the HC-05, and set the buttons to send `F`, `B`, `L`, `R`, and `S`.
6. Press the buttons to move the wheelchair.


## My Contribution

This was a team project. My part was:

- **Idea:** I came up with the main idea of the project.
- **Circuit:** I built the circuit and connected all the parts.
- **Debugging:** I tested the prototype and fixed problems with pin settings and turning directions.

## Author

Md. Mamun Miah
Department of Information and Communication Technology
Mawlana Bhashani Science and Technology University (MBSTU), Tangail, Bangladesh

