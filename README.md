# 🚗 Indicator Control Module – STM32

## Overview

This project implements an automotive-style Indicator Control Module using the STM32 Nucleo-F446RE microcontroller.
It supports Left Indicator, Right Indicator, Indicator Switching, and Hazard Light functionality.

The application logic is developed in **MATLAB Simulink** and integrated into STM32 firmware using **Embedded Coder generated C code**.

---

## Features

* Left & Right Indicator (1 second hold activation)
* Indicator Switching (Left ↔ Right)
* Hazard Mode (both buttons hold)
* 100 ms Cooperative Scheduler
* Button Debounce Logic
* PWM-based LED Control
* UART Logging with timestamps
* Layered Embedded Software Architecture

---

## Software Architecture

The system follows a layered design:

```
HAL → Drivers → Scheduler → Integration → Application (Simulink State Machine)

```

* **HAL Layer** – STM32 HAL (GPIO, TIM, UART)
* **Drivers** – GPIO (debounce), PWM (LED), UART (logging)
* **Scheduler** – 100 ms task execution using TIM6
* **Integration Layer** – connects drivers with Simulink logic
* **Application Layer** – IndicatorControl state machine

---

## Hardware Setup

* STM32 Nucleo F446RE
* 2 Push Buttons
* 2 LEDs

### Pin Mapping

| Function        | Pin  |
| --------------- | ---- |
| Left LED (PWM)  | PA0  |
| Right LED (PWM) | PA1  |
| UART TX         | PA2  |
| UART RX         | PA3  |
| Left Button     | PC13 |
| Right Button    | PB4  |

---

## Timing Design

* Scheduler Period: **100 ms**
* Button Hold Detection: **1 second**
* LED Blink Period: **300 ms**

---

## UART Logging Example

```
[33377 ms] LEFT_BUTTON_PRESSED
[33577 ms] LEFT_INDICATOR_ON
[33579 ms] LEFT_LED_TOGGLE
[33587 ms] HAZARD_ON

```

---

## Project Structure

```

Core/
Drivers/
Simulink_Model/
Documentation/
Indicator_Control.ioc

```

---

## Demo Video

👉 https://drive.google.com/drive/folders/1PblGP-97_xRYWnrP7eygRF27OttxQrPz?usp=drive_link

---

## Author

**LABIB SERJ**
