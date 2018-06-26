#include "Grove_I2C_Motor_Driver.h"

#define I2C_ADDRESS 0x0f
#define IRLEFT 8 //left IR sensor
#define LEFTLINE 3 //left IR sensor line follower
#define RIGHTLINE 4 //right IR sensor line follower
#define IRRIGHT 7 //right IR sensor
//MOTOR1 = GAUCHE
//MOTOR2 = DROITE
int n;
#define I2C_ADDRESS 0x0f
#define cruise 30 //cruise speed
#define adjust 35//adjusting trajectory speed
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
  while(digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == LOW ){
    Motor.speed(MOTOR1, adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -adjust);
  }
  goForward();
}

void rotateRight(){
  while(digitalRead(RIGHTLINE) == LOW && digitalRead(LEFTLINE) == LOW){
    Motor.speed(MOTOR1, -adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, adjust);
  }
goForward();
}
void adjustLeft(){
  while (digitalRead(LEFTLINE) == LOW){
    Motor.speed(MOTOR1, adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, adjust);
  }

}

void adjustRight(){
  while (digitalRead(LEFTLINE) == LOW){
    Motor.speed(MOTOR1, -adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, adjust);
  
  }

}

void stop(){
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
  if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == LOW){ //0000 Lost
    n++;
    Serial.println(n);
    if (n>400){
      stop();
    } 
  }
  if( digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW){ //0110 full forward
    goForward();
    n=0;
  }
  if( digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW){ //0010 forward with adjustments needed to the right
    adjustRight(); 
    n=0;
  }
  if( digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == LOW){ //0100
   adjustLeft();
   n=0;
  }

  if( digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == HIGH){ // 0001
    rotateRight();
  }
  if( digitalRead(IRLEFT) == HIGH && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == LOW  && digitalRead(IRRIGHT) == LOW  ){ //1000
    rotateLeft();
  }
   if( digitalRead(IRLEFT) == HIGH && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == HIGH ){ //1001
    if (millis()%2 ==1){
      rotateLeft();
    }else{
      rotateRight();
    }
  }
  
  if( digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == HIGH){ //0111
    if (millis()%2 ==1){
      goForward();
    }else{
      rotateRight();
    }
  }
  if( digitalRead(IRLEFT) == HIGH && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW ){ //1110
   if (millis()%2 ==1){
      goForward();
    }else{
      rotateLeft();
    }
  }
  if( digitalRead(IRLEFT) == HIGH && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == HIGH  && digitalRead(IRRIGHT) == HIGH ){ //1111
     switch (random(0-2)){
      case 0:
        goForward();
        break;
        
      case 1:
         rotateLeft();
         break;

      default:
         rotateRight();
     }
  }
  
  if( digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == HIGH  ){ // 0011
    rotateRight();
  }
  if( digitalRead(IRLEFT) == HIGH && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH  && digitalRead(IRRIGHT) == LOW ){ //1000
    rotateLeft();
  }
  if( digitalRead(IRLEFT) == HIGH && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH  && digitalRead(IRRIGHT) == HIGH ){ //1011
    switch (random(0-2)){
      case 0:
        goForward();
        break;
        
      case 1:
         rotateLeft();
         break;

      default:
         rotateRight();
     }
  }
  
  if( digitalRead(IRLEFT) == LOW  && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == HIGH ){ //0101
     if (millis()%2 ==1){
      goForward();
    }else{
      rotateRight();
    }
  }
  if( digitalRead(IRLEFT) == HIGH && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == LOW &&  digitalRead(IRRIGHT) == LOW ){ //0101
    if (millis()%2 ==1){
      rotateLeft();
    }else{
      goForward();
    }
  }
   if( digitalRead(IRLEFT) == HIGH && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == LOW &&  digitalRead(IRRIGHT) == HIGH ){ //1101
    switch (random(0-2)){
      case 0:
        goForward();
        break;
        
      case 1:
         rotateLeft();
         break;

      default:
         rotateRight();
     }
  }
  
  
}

 /*  
 * Setup et loop
 * 
 */
void setup() {
  delay(2000);
  // put your setup code here, to run once:
  Motor.begin(I2C_ADDRESS);
  Serial.begin(9600);

  goForward(); 
}

void loop() {
  // put your main code here, to run repeatedly
  botChoice();
   
  
}
