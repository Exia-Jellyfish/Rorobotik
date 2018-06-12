#include "Grove_I2C_Motor_Driver.h"
//MOTOR2 = GAUCHE
//MOTOR1 = DROITE
// default I2C address is 0x0f
#define I2C_ADDRESS 0x0f

void forward (int x)
{

 Motor.speed(MOTOR1, -50);
  // Set speed of MOTOR2, Anticlockwise
  Motor.speed(MOTOR2, -50);
  delay(x);
  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
}

void turnRightCorner(){
    // Change speed and direction of MOTOR1
  Motor.speed(MOTOR1, -60);
  // Change speed and direction of MOTOR2
  Motor.speed(MOTOR2, 55);
  delay(710);
  // Stop MOTOR1 and MOTOR2
  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
 
}

void turnLeftCorner(){
 // Change speed and direction of MOTOR1
  Motor.speed(MOTOR1, 50);
  // Change speed and direction of MOTOR2
  Motor.speed(MOTOR2, -50);
  delay(1000);
  // Stop MOTOR1 and MOTOR2
  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
}

void setup() {
  Motor.begin(I2C_ADDRESS);
  delay(2000);
}

void loop() {
  
  forward(1000);
  turnLeftCorner();
  forward(2000);
   turnLeftCorner();
  forward(2000);
 turnLeftCorner();;
  forward(2000);
 turnLeftCorner();m
  forward(2000);
  turnRightCorner();
  forward(2000);
  turnRightCorner();
  forward(2000);
  turnRightCorner();
  forward(2000);
  turnRightCorner();
  forward(2000);
  turnRightCorner();
  forward(1000);
  delay(5000);
}

