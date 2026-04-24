#include <Wire.h>
#include <Servo.h>
#include <RF24.h>
#include <MPU6050_light.h>
#include <PID_v1.h>

RF24 radio(6, 7);
const byte address[6] = "00001";

MPU6050 mpu(Wire);

Servo esc;
Servo aileron;
Servo elevator;
Servo rudder;

struct RadioPacket {
  int throttle;
  int pitch;
  int roll;
  int yaw;
  bool arm;
};

RadioPacket data;

double pitchInput, pitchOutput, pitchSetpoint;
double rollInput, rollOutput, rollSetpoint;

double kp = 2.0, ki = 0.5, kd = 1.0;

PID pitchPID(&pitchInput, &pitchOutput, &pitchSetpoint, kp, ki, kd, DIRECT);
PID rollPID(&rollInput, &rollOutput, &rollSetpoint, kp, ki, kd, DIRECT);

unsigned long lastRecvTime = 0;
unsigned long loopTimer = 0;
bool isArmed = false;

void setup() {
  Wire.setClock(400000);
  Wire.begin();
  
  mpu.begin();
  mpu.calcOffsets(true, true);
  
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_2MBPS);
  radio.startListening();
  
  esc.attach(0, 1000, 2000);
  aileron.attach(1);
  elevator.attach(2);
  rudder.attach(3);
  
  esc.writeMicroseconds(1000);
  
  pitchPID.SetMode(AUTOMATIC);
  pitchPID.SetOutputLimits(-400, 400); 
  pitchPID.SetSampleTime(10);
  
  rollPID.SetMode(AUTOMATIC);
  rollPID.SetOutputLimits(-400, 400);
  rollPID.SetSampleTime(10);

  data.throttle = 1000;
  data.pitch = 512;
  data.roll = 512;
  data.yaw = 512;
  data.arm = false;

  loopTimer = micros();
}

void loop() {
  mpu.update(); 

  if (radio.available()) {
    radio.read(&data, sizeof(RadioPacket));
    lastRecvTime = millis();
  }
  
  if (millis() - lastRecvTime > 500) {
    data.throttle = 1000;
    data.pitch = 512;
    data.roll = 512;
    data.yaw = 512;
    data.arm = false;
  }

  if (data.arm && data.throttle < 1050) {
    isArmed = true;
  } else if (!data.arm) {
    isArmed = false;
  }
  
  if (micros() - loopTimer >= 10000) {
    loopTimer = micros();
    
    pitchInput = mpu.getAngleY();
    rollInput = mpu.getAngleX();
    
    pitchSetpoint = map(data.pitch, 0, 1023, -30, 30);
    rollSetpoint = map(data.roll, 0, 1023, -30, 30);

    if (!isArmed || data.throttle < 1050) {
      pitchPID.SetMode(MANUAL);
      rollPID.SetMode(MANUAL);
      pitchOutput = 0;
      rollOutput = 0;
      pitchPID.SetMode(AUTOMATIC);
      rollPID.SetMode(AUTOMATIC);
    } else {
      pitchPID.Compute();
      rollPID.Compute();
    }
    
    int aileronVal = 1500 + rollOutput;
    int elevatorVal = 1500 - pitchOutput;
    int rudderVal = map(data.yaw, 0, 1023, 1100, 1900); 
    
    if (isArmed) {
      esc.writeMicroseconds(data.throttle);
    } else {
      esc.writeMicroseconds(1000);
    }
    
    aileron.writeMicroseconds(constrain(aileronVal, 1100, 1900));
    elevator.writeMicroseconds(constrain(elevatorVal, 1100, 1900));
    rudder.writeMicroseconds(constrain(rudderVal, 1100, 1900));
  }
}