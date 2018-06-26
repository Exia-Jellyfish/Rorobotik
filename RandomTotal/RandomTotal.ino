
#include "Grove_I2C_Motor_Driver.h"

#define I2C_ADDRESS 0x0f
#define IRLEFT 8 //left IR sensor
#define LEFTLINE 3 //left IR sensor line follower
#define RIGHTLINE 4 //right IR sensor line follower
#define IRRIGHT 7 //right IR sensor
//MOTOR1 = GAUCHE
//MOTOR2 = DROITE

#define I2C_ADDRESS 0x0f
#define cruise 40 //cruise speed
#define adjust 45 //adjusting trajectory speed

int t;


String test;
/*
 * 
 * 
 * section mouvements
 * 
 */
void goForward(){
   Motor.speed(MOTOR1, -cruise);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -cruise);
}

void rotateLeft(){
   while(millis()<t+90){
     Motor.speed(MOTOR1, -adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -adjust);
  }
  while(millis()<t+250){
     Motor.speed(MOTOR1, adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -adjust);
  }
  while(digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == LOW ){
    Motor.speed(MOTOR1, adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -adjust);
  }
  goForward();
}

void rotateRight(){
   while(millis()<t+90){
     Motor.speed(MOTOR1, -adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -adjust);
  }
  while(millis()<t+250){
     Motor.speed(MOTOR1, -adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, adjust);
  }
  while(digitalRead(RIGHTLINE) == LOW && digitalRead(LEFTLINE) == LOW){
    Motor.speed(MOTOR1, -adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, adjust);
  }
goForward();
}


void adjustLeft(){
 
    Motor.speed(MOTOR1, (cruise-20));
  
  Motor.speed(MOTOR2, -cruise);
  

}

void adjustRight(){
  
    Motor.speed(MOTOR1, -cruise);
  
  Motor.speed(MOTOR2, (cruise-20));
  
  

}



void stopMotor(){
  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
}




/* 
 * 
 * 
 * Section logique
 * 
 */



void botChoice(){
   if(digitalRead(IRRIGHT) == HIGH ){  
     rotateRight;
      
    }
    else if( digitalRead(IRLEFT) == HIGH){
      rotateLeft;
    }
   else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW){  
      goForward();
      
    }
    else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == LOW ){
     
      adjustLeft();
      
    }
    else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW ){
       
      adjustRight();
  
    }
    else{
   
 }}





void setup() {
  delay(2000);
  Motor.begin(I2C_ADDRESS);
 
  Serial.begin(9600);



}

void loop() {
  
 




botChoice(); 


     
}
