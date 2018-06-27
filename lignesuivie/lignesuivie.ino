#include "Grove_I2C_Motor_Driver.h"
#include <VirtualWire.h>

#define I2C_ADDRESS 0x0f
#define IRLEFT 8 //left IR sensor
#define LEFTLINE 3 //left IR sensor line follower
#define RIGHTLINE 4 //right IR sensor line follower
#define IRRIGHT 7 //right IR sensor
//MOTOR1 = GAUCHE
//MOTOR2 = DROITE
#define WEST 0
#define EAST 2
#define NORTH 1
#define SOUTH 3
#define cruise 30 //cruise speed
#define adjust 25  //adjusting trajectory speed
int n;
char order;
int dir;
int t;
int RF_RX_PIN = 6;
char message[255] = "";
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
  while(digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == LOW ){

    Motor.speed(MOTOR1, adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -adjust);
  }
  
}

void rotateRight(){
  while(digitalRead(RIGHTLINE) == LOW && digitalRead(LEFTLINE) == LOW){
    Motor.speed(MOTOR1, -adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, adjust);
  }

}
void adjustLeft(){
  while (digitalRead(LEFTLINE) == LOW){
    Motor.speed(MOTOR1, adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -adjust);
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
      rotateRight();
    
    }else{
        goForward();
    }
  }
  if( digitalRead(IRLEFT) == HIGH && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW ){ //1110
   if (millis()%2 ==1){
      rotateLeft();
     
    }else{
       goForward();
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
    while(digitalRead(LEFTLINE) == LOW){
      adjustRight();
    }
    rotateRight();
  }
  if( digitalRead(IRLEFT) == HIGH && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH  && digitalRead(IRRIGHT) == LOW ){ //1000
   while(digitalRead(LEFTLINE) == LOW){
      adjustRight();
    }
    rotateLeft();
  }
  if( digitalRead(IRLEFT) == HIGH && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH  && digitalRead(IRRIGHT) == HIGH ){ //1011
    while(digitalRead(LEFTLINE) == LOW){
      adjustRight();
    }
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
    while(digitalRead(RIGHTLINE) == LOW){
      adjustLeft();
    }
     if (millis()%2 ==1){
      goForward();
    }else{
      rotateRight();
    }
  }
  if( digitalRead(IRLEFT) == HIGH && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == LOW &&  digitalRead(IRRIGHT) == LOW ){ //0101
    while(digitalRead(RIGHTLINE) == LOW){
      adjustLeft();
    }
    if (millis()%2 ==1){
      rotateLeft();
    }else{
      goForward();
    }
  }
   if( digitalRead(IRLEFT) == HIGH && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == LOW &&  digitalRead(IRRIGHT) == HIGH ){ //1101
   while(digitalRead(RIGHTLINE) == LOW){
      adjustLeft();
    }}
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


/*
void standBy(){

      byte buf[VW_MAX_MESSAGE_LEN];
      byte buflen = VW_MAX_MESSAGE_LEN;
      int i =0; 
      bool roger = false;
      Serial.println(VW_MAX_MESSAGE_LEN);
      while (roger == false){
        
       if(vw_get_message(buf, &buflen)){
        
//      Serial.println((char *)buf);
        order = (char)buf;
         roger = true;
       }       
   
      }  
}


void setDir(){
  switch (order){
    case 'n':
    dir = NORTH;
    break;
    case 'e':
    dir = EAST;
    break;
    case 's':
    dir = SOUTH;
    break;
    case 'w':
    dir = WEST;
    break;
    default:
    break;
  }
}
*/


 /*  
 * Setup et loop
 * 
 */
void setup() {
  delay(2000);
  // put your setup code here, to run once:
  Motor.begin(I2C_ADDRESS);
  vw_set_rx_pin(RF_RX_PIN);
  vw_setup(2000);  
  vw_rx_start();
  Serial.begin(9600);
  goForward(); 
}

void loop() {
  //standBy();
  // put your main code here, to run repeatedly
  botChoice();
   
  
}
