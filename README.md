### Micro flight controller ✈️
Okay so I couldn't find a flight controller small enough or light enough for what I needed, so I just designed one from scratch lol.

It uses a seeed XIAO and a bunch of tiny SMD parts (0805 mostly). it actually works and flies pretty smooth but u have to be okay with soldering things the size of a grain of rice.

### What is this?

Basically a 4 channel RC flight computer. it takes throttle, aileron, elevator, and rudder from an nRF24 radio, runs it through some PID math at 100Hz, checks the gyro, and moves the servos so your plane doesn't instantly do a death flip.

### Stuff u need to build this (BOM)

The Brain: Seeed Studio XIAO (I used the nRF52840 but RP2040 works too). You solder it flat onto the board.

The Gyro: MPU6050... BUT WAIT. NOT the blue breakout board. The actual raw QFN-24 black chip. Good luck soldering this without flux lmao.

Radio: nRF24L01+ PA+LNA (the one with the big antenna so u get like 700m-1km range).

Power: AMS1117 3.3V regulator (SOT-223) + a massive 100uF 1210 capacitor so the radio doesn't brown out and kill the connection mid flight.

Misc: Some 0805 resistors (4.7k for the I2C) and 0805 caps (0.1uF, 2.2nF, 10uF). 

### IMPORTANT RANT ABOUT SOLDER

Do NOT use cheap 60/40 or 35/65 solder for this. The vibrations from the drone motors will crack your joints. buy actual 63/37 (Tin/Lead) Rosin Core 0.5mm wire. It solidifies instantly and doesn't get mushy. Soldron is fine. Just don't buy the cheap unbranded tubes.

### Software stuff

The code is in C++. don't use the normal arduino IDE for this, it sucks for complex stuff. Use VS Code + PlatformIO.

### Libraries u need:

RF24 (for the radio)

MPU6050_light (so much better than writing custom kalman filters)

PID_v1 (for the stabilization math)

---

Note: The loop is locked at 100Hz so the servos don't twitch themselves to death. The I2C is boosted to 400kHz so the gyro reads fast enough.

---

### How to fly 

1) Turn on radio.

2) Plug in battery.

3) DO NOT touch the plane for like 3 seconds while the MPU6050 calibrates.

4) Arm the throttle (push it up past 1050us).

5) Pray your PID tuning is right.

---
If u haven't flown any rc before, I'd recomend to let someone experienced fly it first unless you want to destroy all your hard work on  the first flight.

---
(Disclaimer: if u copy my PID values and your plane nosedives into a tree, that's on u. tune it yourself for your airframe).

Have fun ✌️

### ~GODSPEED
