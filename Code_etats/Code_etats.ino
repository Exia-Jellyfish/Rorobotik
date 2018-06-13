#include "Grove_I2C_Motor_Driver.h"
//MOTOR1 = GAUCHE
//MOTOR2 = DROITE
unsigned long t;
// default I2C address is 0x0f
#define I2C_ADDRESS 0x0f


void goForward(){
   Motor.speed(MOTOR1, -50);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -50);
}

void rotateLeft(){
    Motor.speed(MOTOR1, 50);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -50);
}

void rotateRight(){
    Motor.speed(MOTOR1, -50);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, 50);
}

void adjustLeft(){
    Motor.speed(MOTOR1, -10);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -50);
}

void adjustRight(){
    Motor.speed(MOTOR1, -50);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -10);
}

void stop(){
  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
}

void setup() {
  delay(1500);
  // put your setup code here, to run once:
  Motor.begin(I2C_ADDRESS);
  Serial.begin(9600);
  t=millis();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (t+2000> millis()){
    adjustLeft();
  }
  else {
    if (t+4000> millis()){
    adjustRight();
  }
  else {
    if (t+6000> millis()){
    rotateRight();
  }
  else {
    stop();
  }
  }
  }
  
  
}
