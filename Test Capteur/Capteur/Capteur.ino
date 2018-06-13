#include "Grove_I2C_Motor_Driver.h"

#define I2C_ADDRESS 0x0f
#define IRLEFT D3 //left RI sensor
#define LEFTLINE D8 //left RI sensor line follower
#define RIGHTLINE D4 //right RI sensor line follower
#define IRRIGHT D7 //right RI sensor

void forward (int x)
{
  Motor.speed(MOTOR1, -50);
  // Set speed of MOTOR2, Anticlockwise
  Motor.speed(MOTOR2, -50);
  delay(x);
  stopMotor();
}

void turnRightCorner() {
  // Change speed and direction of MOTOR1
  Motor.speed(MOTOR1, -50);
  // Change speed and direction of MOTOR2
  Motor.speed(MOTOR2, 50);
  delay(900);
  // Stop MOTOR1 and MOTOR2
  Serial.println("rectifyright");
  stopMotor();
}

void turnLeftCorner() {
  // Change speed and direction of MOTOR1
  Motor.speed(MOTOR1, 50);
  // Change speed and direction of MOTOR2
  Motor.speed(MOTOR2, -50);
  delay(1000);
  // Stop MOTOR1 and MOTOR2
  Serial.println("trun left");
  stopMotor();
}


void stopMotor () {
  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
}


void rectifyright() {

  Motor.speed(MOTOR2, 50);
  Motor.speed(MOTOR1, -50);
  Serial.println("rectifyright");
}

void rectifyleft() {
  Motor.speed(MOTOR1, 50);
  Motor.speed(MOTOR2, -50);
  Serial.println("rectifyleft");
}


void setup() {
  // put your setup code here, to run once:7
  Serial.begin(9600);
  Motor.begin(I2C_ADDRESS);
  attachInterrupt(digitalPinToInterrupt(D8), rectifyLeft(), RISING);
  attachInterrupt(digitalPinToInterrupt(D4), rectifyRight(), RISING);
  attachInterrupt(digitalPinToInterrupt(D3), turnLeftCorner(), RISING);
  attachInterrupt(digitalPinToInterrupt(D7), turnRightCorner(), RISING);


}

void loop() {


}
