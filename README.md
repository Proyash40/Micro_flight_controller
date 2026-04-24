### Micro flight controller 
Okay so I couldn't find a flight controller small enough or light enough for what I needed, so I just designed one from scratch lol.

It uses a seeed XIAO and a bunch of tiny SMD parts (0805 mostly). it actually works and flies pretty smooth but u have to be okay with soldering things the size of a grain of rice.

---

### What is this?

Basically a 4 channel RC flight computer. it takes throttle, aileron, elevator, and rudder from an nRF24 radio, runs it through some PID math at 100Hz, checks the gyro, and moves the servos so your plane doesn't instantly do a death flip.

### Stuff u need to build this (BOM)
---

| Name | Purpose | Quantity | Price (1 Unit) | Price Total(USD) | Links| 
| :-- | :-- | :-- | :-- | :-- | :-- |
| 4.7k smd resistor| I2C Pull-up for MPU6050  | 2     | $3.61    | $3.61   | [Link](https://robu.in/product/pro-range-resistor-assortment-kit?gbraid=0AAAAADvLFWev9HLp4sxOwY4NhUPUn_UtG&gad_source=1&gclid=CjwKCAjwhqfPBhBWEiwAZo196v5bzfSOsC9HW_fTPULaQ9_nrkw8cpucVvh93sHcz886qdtSFOGdzhoCiaEQAvD_BwE&gad_campaignid=17413441824)|
| AMS1117 | Power Stability | 1 | $0.1 | $0.1 | [link](https://robu.in/product/ams1117-5-0-kexin-800ma-fixed-5v-positive-electrode-18v-sot-223-4-voltage-regulators-linear-low-drop-out-ldo-regulators-rohs?gclid=CjwKCAjwhqfPBhBWEiwAZo196rn1-FbjdC99BRNd9EsXMXFG3gaLsCGdJgY27B3j1U-KVRJFFhwOmRoCjTQQAvD_BwE&gbraid=0AAAAADvLFWcFOfMDkpSzIEVzy6CGMtIqJ&gad_campaignid=17427802703&gad_source=1) |
| MPU6050 | 3 axis gyro + accelerometer | 1 | $2.55 | $2.55 | [link](https://quartzcomponents.com/products/mpu-6050-3-axis-gyro-accelerometer-ic-tdk-invensense-qfn-24-smd-package?variant=45045443920106&country=IN&currency=INR&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&srsltid=AfmBOopUSjOK5jLivqVKUFYTqOvJck_zu4O2Uv3mEJbdvORH596ugewjbbI) |
| Seeed studio XIAO ESP32 supermini C3 | The main brain | 1 | $9.56 | $9.56 | [Link](https://robu.in/product/seeed-studio-xiao-esp32s3-2-4ghz-wifi-ble-5-0?gbraid=0AAAAADvLFWcFOfMDkpSzIEVzy6CGMtIqJ&gad_campaignid=17427802703&gad_source=1&gclid=CjwKCAjwhqfPBhBWEiwAZo196qhD7iCgQVOGc9_I62SJPdePZ3dxGMH-cF4la4ANgsBjqeiDQebpEhoCmOUQAvD_BwE) |
| PCB print | Holding all the components together | 1 | $ 3 | $3 | [Link](https://cart.jlcpcb.com/quote)
| Capacitor 0.1uF (100nF) 0805| Decoupling for MPU6050 | 3 | -- | -- | I'd recomend buying it offline |
| Capacitor 2.2nF 0805 | MPU6050 Charge Pump | 1 |  -- | -- | I'd recomend buying it offline |
| Capacitor 10uF 0805 | AMS1117 Input Filter| 2 |  -- | -- | I'd recomend buying it offline |
| Capacitor 100uF 1210 | nRF24 Power Buffer* | 2 | -- | -- | I'd recomend buying it offline |

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
