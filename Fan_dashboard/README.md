# ESP32 DC Fan Control Dashboard

Control a DC fan from any device connected to the same Wi-Fi network using a web browser.

---

## Overview

This project demonstrates how an ESP32 can host a web server to remotely control a DC fan through an interactive dashboard. The fan can be turned ON and OFF using simple controls accessible from any device connected to the same network.

---

## Components Required

- ESP32 Development Board
- L298N Motor Driver Module
- DC Fan / DC Motor
- Jumper Wires
- Breadboard (optional)
- USB Cable

---

## Connections

| ESP32 Pin | L298N Pin | Function |
|-----------|------------|-----------|
| GPIO 2    | IN1        | Fan ON/OFF Control |
| GPIO 4    | IN2        | Fan Direction Control |
| GND       | GND        | Common Ground |
| VIN / External Supply | 12V | Motor Power Supply |

> **Note:** Ensure that the motor power requirements match the specifications of your DC fan.

---

## Features

- Web-based dashboard control
- Fan ON/OFF functionality
- ESP32 acts as a standalone web server
- No mobile application required
- Accessible through any browser on the same Wi-Fi network
- Simple and beginner-friendly implementation

---

## Files

- `Fan_control.ino` – ESP32 source code
- `dashboard.png` – Screenshot of the web dashboard
- `fan_on.jpeg` – Fan ON demonstration
- `fan_off.jpeg` – Fan OFF demonstration
- `circuit.jpeg` – Circuit setup image

---

## Project Demonstration

### Dashboard

![Dashboard](dashboard.png)

---

### Fan ON State

![Fan ON](fan_on.jpeg)

---

### Fan OFF State

![Fan OFF](fan_off.jpeg)

---

### Circuit Diagram

![Circuit Diagram](circuit.jpeg)

---

## Working Principle

1. The ESP32 connects to the configured Wi-Fi network.
2. A web server is hosted on the ESP32.
3. Users access the dashboard using the ESP32 IP address.
4. Clicking the control buttons sends requests to the ESP32.
5. The ESP32 drives the L298N motor driver to switch the fan ON or OFF.

---

## Applications

- Home automation systems
- Smart appliance control
- IoT learning projects
- Embedded systems experimentation
- Remote motor control applications

---

## Future Enhancements

- Fan speed control using PWM
- Temperature-based automatic fan operation
- MQTT integration for cloud control
- Mobile-responsive dashboard improvements
- Real-time monitoring and logging

---

## Author

**Pratham Shah**

Electronics and Communication Engineering Student

Interested in Embedded Systems, IoT, ESP32, and Web-Based Automation.

---

## Related Projects

- ESP32 LED Control Dashboard
- ESP32 Vehicle Monitoring System
- Home Automation Dashboard
