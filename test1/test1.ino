#include "Grove_I2C_Motor_Driver.h"
//MOTOR2 = GAUCHE
//MOTOR1 = DROITE
// default I2C address is 0x0f
#define I2C_ADDRESS 0x0f
#define IRLEFT 2 //left RI sensor
#define LEFTLINE 3 //left RI sensor line follower
#define RIGHTLINE 4 //right RI sensor line follower
#define IRRIGHT 5 //right RI sensor


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
  delay(900);
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
  

  if (digitalRead(IRLEFT) == HIGH){
     //Serial.println("IRLEFT HIGH");
  }
  else { //Serial.println("IRLEFT LOW");}

  if (digitalRead(LEFTLINE) == HIGH){
    //Serial.println("LEFTLINE HIGH");
  }else{
    //Serial.println("LEFTLINE LOW");
  }
  
  if (digitalRead(RIGHTLINE) == HIGH){
    //Serial.println("RIGHTLINE HIGH");
  }else{
    Serial.println("RIGHTLINE LOW");
  }

}}

void rectifyright(){

}

void rectifyleft(){

}


/*void driving(int lri, int rri){
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
}*/

void setup() {
  Motor.begin(I2C_ADDRESS);
}

void loop() {
  //delay(2000);
  //forward(2000);
  //turnRightCorner();
  //turnLeftCorner();
  getsensor();
  //stopMotor(); 

}
