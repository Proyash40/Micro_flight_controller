Flight Controller - Firmware Dependencies

## Development Environment
* **IDE:** VS Code with the PlatformIO extension (Highly recommended over the basic Arduino IDE for a project this complex).
* **Framework:** Arduino Core
* **Board Manager URL/Package:** * `Earle Philhower's arduino-pico` (If using the XIAO RP2040)
  * `Seeed nRF52 mbed-enabled Boards` (If using the XIAO nRF52840)

## Core Libraries (Install via Library Manager)

### 1. Radio Communication
* **Library:** `RF24` 
* **Author:** TMRh20
* **Purpose:** The absolute gold standard for driving the nRF24L01. It handles the SPI communication, packet payloads, and error checking.

### 2. Sensor Fusion (MPU6050)
* **Library:** `MPU6050_Light` 
* **Author:** Romain Fétick (rfetick)
* **Purpose:** This is the secret weapon for DIY drones. Instead of reading raw, noisy accelerometer data and writing your own Kalman filters, this library automatically calculates the clean Pitch, Roll, and Yaw angles fast enough for a flight controller. 

### 3. Flight Stabilization (The Math)
* **Library:** `PID_v1`
* **Author:** Brett Beauregard
* **Purpose:** You need a PID (Proportional, Integral, Derivative) loop for Pitch, Roll, and Yaw to keep the plane level. This library handles the complex calculus for you. You just feed it your current angle and your desired angle, and it outputs the correction needed.

### 4. Hardware Outputs
* **Library:** `Servo` (Built-in)
* **Purpose:** Generates the exact 50Hz PWM signals required to talk to the ESC (Throttle) and the 3 Servos (Aileron, Elevator, Rudder).

## The Core Software Architecture (The Loop)
Your `void loop()` must run as fast as possible (target >100Hz) in this exact order:
1. **Radio Rx:** Check if a new command packet arrived from the transmitter.
2. **Read IMU:** Get the current pitch/roll angle from the MPU6050.
3. **Compute PID:** Compare the pilot's command to the current angle and calculate the difference.
4. **Mixer:** Mix the PID outputs to figure out exactly how far to move each servo.
5. **Output:** `Servo.write()` the new values to the physical pins.