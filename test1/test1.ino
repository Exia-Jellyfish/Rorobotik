#include "Grove_I2C_Motor_Driver.h"
//MOTOR2 = GAUCHE
//MOTOR1 = DROITE
// default I2C address is 0x0f
#define I2C_ADDRESS 0x0f
#define LRi 1 //left RI sensor
#define LRI 2 //left RI sensor line follower
#define RRI 3 //right RI sensor line follower
#define RRi 4 //right RI sensor


void forward (int x)
{
 Motor.speed(MOTOR1, 50);
  // Set speed of MOTOR2, Anticlockwise
  Motor.speed(MOTOR2, 50);
  delay(x);
  stopMotor(); 
}

void turnRightCorner(){
  // Change speed and direction of MOTOR1
  Motor.speed(MOTOR1, -50);
  // Change speed and direction of MOTOR2
  Motor.speed(MOTOR2, 50);
  delay(1000);
  // Stop MOTOR1 and MOTOR2
  stopMotor();
}

void turnLeftCorner(){
  // Change speed and direction of MOTOR1
  Motor.speed(MOTOR1, 50);
  // Change speed and direction of MOTOR2
  Motor.speed(MOTOR2, -50);
  delay(1000);
  // Stop MOTOR1 and MOTOR2
  stopMotor(); 
}


void stopMotor (){
  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
}


void getsensor(){
  int lri;
  int rri;

  if (digitalRead(LRI) == HIGH){
     lri = 1;
  }
  else {lri = 0;}

  if (digitalRead(RRI) == HIGH){
     rri = 1;
  }
  else {rri = 0;}

  driving(lri, rri);

}

void rectifyright(){

}

void rectifyleft(){

}


void driving(int lri, int rri){
  switch(lri){

      case 1:
      if(rri = 1){
        forward(200);
      }else {rectifyright();} // TO DO: CODE rectifyright()
      break;

      case 0: 
      if(rri == 1){
        rectifyleft();  // TO DO: CODE rectifyleft()
      } else {stopMotor();}
      break;

      default:
      stopMotor(); 
      break; 
      }
}

void setup() {
  Motor.begin(I2C_ADDRESS);
}

void loop() {
  delay(2000);
  forward(2000);
  turnRightCorner();
  turnLeftCorner();
  stopMotor(); 

}
