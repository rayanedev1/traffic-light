# 🚦 Smart Traffic Light System (Arduino Uno Implementation)

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=ea4335&height=220&section=header&text=TRAFFIC%20LIGHT%20EXPLAINED&fontSize=50&animation=fadeIn" width="100%" />
</p>

## 📖 Introduction & Objectives
This project goes beyond simple LED manipulation. It is a real-world simulation of an **urban control system**. The objective is to program a microcontroller to manage traffic flows while ensuring user safety through strict temporal transitions and total hardware reliability.

---

## 🛠️ Hardware Architecture

### 📋 Pin Configuration Table
| Component | Arduino Pin | Resistor | Logic Function |
| :--- | :--- | :--- | :--- |
| 🔴 **Red LED** | `PIN 5` | 200 Ω | State: STOP (Strict Halt) |
| 🟡 **Yellow LED** | `PIN 4` | 200 Ω | State: CAUTION (Transition/Alert) |
| 🟢 **Green LED** | `PIN 3` | 200 Ω | State: GO (Free Flow) |
| **Ground (GND)** | `GND` | — | Common Current Return |

### 🔍 In-Depth Assembly Explanations

#### ⚡ Why 200Ω Resistors?
From an electronic standpoint, an LED has no significant internal resistance. The Arduino Uno delivers a voltage of **5V** on its digital outputs. Without protection, the current passing through the LED would be too high ($I = V/R$), leading to:
1. Immediate destruction of the LED due to overheating.
2. Risk of burning out the microcontroller's output port.
By adding a **200Ω resistor**, we limit the current to approximately **15-20mA**, which is the ideal nominal value for stable and safe brightness.



#### 🏗️ Breadboard Structure
The assembly uses a **common ground rail** (blue line). All short legs of the LEDs (Cathodes) are connected to this rail, which is itself connected to the **GND** pin of the Arduino. This allows the electrical circuit to be closed in a clean and organized manner.

---

## 🧠 Software Development Logic

The program is structured as a **Finite State Machine (FSM)**. The code follows a rigorous road safety protocol based on real-world cycles.



### 1. Technical Initialization (`void setup()`)
Upon startup, the microcontroller defines pins 3, 4, and 5 as `OUTPUT`. This means the Arduino will act as a voltage source to control external components. For safety reasons, all LEDs are set to "off" by default at launch.

### 2. Traffic Cycle Algorithm (`void loop()`)
The program executes an infinite loop simulating reality:

* **Flow Phase (GREEN):** Passage authorized. Pin 3 is activated. Others are forced to `LOW` to avoid any contradictory signals. **(Duration: 5000ms)**
* **Prevention Phase (YELLOW):** This is the most critical phase. It warns of an imminent change to allow for a progressive stop and prevent rear-end collisions. **(Duration: 2000ms)**
* **Safety Phase (RED):** Total stop. Pin 5 is active. This phase is calibrated to allow time for intersections to clear completely before the next cycle. **(Duration: 5000ms)**

---

## 🚀 Software Safety Analysis
* **Non-concurrency:** The code is written so that only one LED is lit at a time, perfectly simulating real-world safety systems where displaying two opposing colors is impossible.
* **Modularity:** Using constants for pins and delays allows for easy modification of the traffic rhythm (e.g., a longer pedestrian crossing time) by simply changing a value at the top of the script.

---

## 🛠️ Getting Started Guide

1.  **Assembly:** Reproduce the wiring on the breadboard, respecting the polarity of the LEDs (Long leg to positive).
2.  **Software:** Use the Arduino IDE (C++ language) to compile the code.
3.  **Flashing:** Connect the Arduino via USB and upload the program.
4.  **Testing:** Verify that the sequence matches the standard cycle (Green -> Yellow -> Red).

---

## 👨‍💻 Developer
**Rayane_Dev** 🇲🇦
> "Embedded engineering at the service of intelligent automation."

<p align="center">
  <a href="mailto:rayanedev1@gmail.com"><img src="https://img.shields.io/badge/Email-D14836?style=flat-square&logo=gmail&logoColor=white" /></a>
  &nbsp;
  <a href="https://discord.gg/rayaneouf"><img src="https://img.shields.io/badge/Discord-7289DA?style=flat-square&logo=discord&logoColor=white" /></a>
</p>

---
<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=rect&color=34a853&height=30&section=footer" width="100%" />
  <br>
  <i>System Status: OPERATIONAL | Safety Logic Verified</i>
</p>
