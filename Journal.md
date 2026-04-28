### Journal :-

| Title | Micro Flight Controller |
| :-- | :---|
|Author | Proyash Kumar Sarkar (Godspeed)|
|Project Tire | 3|

### Components searching, basic design

This was my first time designing a cutom flight controller. Prior to this i had flown rc planes nd had experience with transmitter nd receiver making, so with a certain motivation by my frnd, i started working on this project.

At the begining i had to know about the componets of the flight controller, the sensors or function it does, then chose the right material and the smaller the better. We all know how hard its to make rc plane fly with heavy components.

So the first challenge was to find the componets small enough and fits the budget. First i was seacrhing for [ELRS](https://robu.in/product/radiomaster-tx16s-mkii-hall-v4-0-elrs-radio-controller?gbraid=0AAAAADvLFWcEtJgydUDXHOkumMk-7lT85&gad_source=1&gad_campaignid=17419548928&gclid=CjwKCAjwhqfPBhBWEiwAZo196qVLzycWXF_rut-7szrYOqwsNfNAqMsrlLLoI8UqdeaGwOyFOa1YlRoCq9EQAvD_BwE) modules then saw the price nd nearly pulled my heart out. So i went with the standard NRF240L01+(PA+LNA) module, it gives a range for about 700-1km, which is fairly good enough for a beginner project. {Cutting cost does comes with some drawbacks🥲}

Howsoever, after that, chossing the main brain, yea it was hecktic. Cz I myself prefer design PCB with KiCAD, now it doesn't have the footprint nor the library nor the symbol for Seeed studio Xiao ESP32 supermini. So i was thinking what the brain i might use. I called one of my friend nd he advised me to see this [video](https://www.youtube.com/watch?v=W9cLnIjvybo) by [PlumPot](https://www.youtube.com/@PlumPot). Then learnt how to insert or import whatever, to KiCAD and use it, so i went with the ESP32. (I used nothing else due to its tiny size and processing speed)

At the end i chose the MPU6050 module, it has 3 axis gyro and additionally accelerometer.

So finnally this was the basic design. I just tried to make the Flight Controller as small as possible.

---

<img width="567" height="304" alt="rough_idea" src="https://github.com/user-attachments/assets/3f48396c-fb85-4376-8628-ec27306075d5" />

---

Now lets see, how small I can make the PCB✌🏻

---
### The circuit design

<img width="973" height="768" alt="Screenshot 2026-04-28 at 12 12 12 PM" src="https://github.com/user-attachments/assets/6ac7e00d-6e60-426f-8b74-c93bf70b0ad5" />

This was my circuit diagram, I know its very hard to understand, so I'd recommned to look at the schematic which I'd make later on. And also I've not checked the whole diagram precisely, there is some issues with it which i ddecided to fix in the schematic.

---

### Schematic and PCB design

This morning, as soon as i woke up started gathering stuffs in KiCAD. But as i had mentioned in my last journal, it was pretty difficult to find the parts by their names. So I took some help for gemini and also google(not gonna lie😅)

So, after i found all the componenets and their libraries, i started making the schematic. For god's sake, it was very very difficult, i spent most of the time thinking, where to connect, nd with so many components. 😭

Though after a lot of struggle i managed to complete the schematic. Plot twist, as soon as I ran ERC, it gave a bunch of errors and warnings. It was my time to start crying. I slammed my laptop off, and went to bed with spotify at the full volume of my music system. Nd my mom came with her slippers in hand.😂

So I put on my headphones nd slept. after about an hour or so I woke up did some Maths for upcoming exams.(Yea ive not included this time in the session time). Then with a fresh mind i started making the schematic again and boom, i succesfully made the schematic.

---
<img width="1470" height="956" alt="schematic" src="https://github.com/user-attachments/assets/36a0c3e6-3fdf-4837-a15d-ba656b276d6e" />

---
<img width="1049" height="801" alt="schematic1" src="https://github.com/user-attachments/assets/4636b506-882b-4ef4-a9d9-8153106e34e0" />


I later cleanedup the schematic for a better understanding. And note that I've forgotten to add the "no connection mark" on the ESP32 3V3 pin, it wont create any blunder but while running ERC, it might show as unconnected port, thats all.

:) 
---

Then assigned the footprints, I downloaded the footprint for this specific ESP32 from [here](https://www.snapeda.com/parts/102010428/Seeed%20Technology%20Co.%2C%20Ltd/view-part/?ref=search&t=seeed%20studio%20xiao%20esp32&ab_test_case=b) and added to my library. Though it was pretty easy, but i forgot to save the footprint at first, nd was really screaming when i switched to PCB mode, as i couldn't see any of the components. Then i again went back and saved the footprints. Joined the wires again and prepared my mini PCB which is almost as small as a 4*4 cm square.

---

<img width="1470" height="956" alt="pcb" src="https://github.com/user-attachments/assets/91c97eb8-0081-4aa4-b031-bf650dcb2319" />

---

### Searching on Web for availability of the components

So finally after web screapping a lot, i found the materials i required and additonally keeping in mind the budget. So these given below are my whole listt of components. Hopefully they work all fine nd i myself don't make any mistake😅

---
<img width="1248" height="686" alt="robu_bill" src="https://github.com/user-attachments/assets/bf7487a1-d1ac-405b-8ec6-939f13542f4b" />

<img width="1311" height="760" alt="quartz_components_bill" src="https://github.com/user-attachments/assets/38c43b1d-0fa4-43da-849b-e8d7aa7ef28a" />

<img width="1296" height="760" alt="jlc_pcb_bill" src="https://github.com/user-attachments/assets/df306d2d-7dfd-4cf2-be92-4f6689838b56" />


---

### Project under [Stasis](https://stasis.hackclub.com/dashboard/projects/cmobnjizc019h01mn31wxweli)

### ~GODSPEED
