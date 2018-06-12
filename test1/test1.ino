#include "Grove_I2C_Motor_Driver.h"
//MOTOR2 = GAUCHE
//MOTOR1 = DROITE
// default I2C address is 0x0f
#define I2C_ADDRESS 0x0f

void forward (int x)
{

 Motor.speed(MOTOR1, 50);
  // Set speed of MOTOR2, Anticlockwise
  Motor.speed(MOTOR2, 50);
  delay(x);
}

void turnRightCorner(){
  // Change speed and direction of MOTOR1
  Motor.speed(MOTOR1, -50);
  // Change speed and direction of MOTOR2
  Motor.speed(MOTOR2, 50);
  delay(1000);
  // Stop MOTOR1 and MOTOR2
}

void turnLeftCorner(){
  // Change speed and direction of MOTOR1
  Motor.speed(MOTOR1, 50);
  // Change speed and direction of MOTOR2
  Motor.speed(MOTOR2, -50);
  delay(1000);
  // Stop MOTOR1 and MOTOR2
}

void setup() {
  Motor.begin(I2C_ADDRESS);
}

void loop() {
  delay(2000);
  forward(2000);
  turnRightCorner();
  turnLeftCorner();
  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
  
}

