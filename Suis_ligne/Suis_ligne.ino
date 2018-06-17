#include "Grove_I2C_Motor_Driver.h"

#define I2C_ADDRESS 0x0f
#define IRLEFT 7 //left IR sensor
#define LEFTLINE 3 //left IR sensor line follower
#define RIGHTLINE 4 //right IR sensor line follower
#define IRRIGHT 6 //right IR sensor
//MOTOR1 = Droite
//MOTOR2 = Gauche
unsigned long t;
char irr;
char irl;
char lineL;
char lineR;
String code;
char tab[5];
// default I2C address is 0x0f
#define I2C_ADDRESS 0x0f


/*
 * 
 * 
 * section mouvements
 * 
 */
void goForward(){
   Motor.speed(MOTOR1, -30);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -30);
}

void rotateLeft(){
    Motor.speed(MOTOR1, 30);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -30);
 
}

void rotateRight(){
    Motor.speed(MOTOR1, -30);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, 30);
}

void adjustLeft(){
    Motor.speed(MOTOR1, 30);
    Serial.println("wow");
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -30);
}

void adjustRight(){
    Motor.speed(MOTOR1, -30);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, 30);
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
  if(digitalRead(RIGHTLINE)== LOW && digitalRead(LEFTLINE) == LOW){
   
   // Serial.println("Staaap");
  }
  if(digitalRead(RIGHTLINE)== HIGH && digitalRead(LEFTLINE) == HIGH){
    goForward();
   // Serial.println("Forward");
  }
  if(digitalRead(RIGHTLINE)== HIGH && digitalRead(LEFTLINE) == LOW){
    adjustRight();
    
   // Serial.println("adjRight");
  }
  if(digitalRead(RIGHTLINE)== LOW && digitalRead(LEFTLINE) == HIGH){
    adjustLeft();
    
   // Serial.println("AdjLeft");
  } 
}


/*
 * 
 *  
 * Setup et loop
 * 
 */
void setup() {
  delay(1500);
  // put your setup code here, to run once:
  Motor.begin(I2C_ADDRESS);
  Serial.begin(9600);
   //goForward();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  botChoice();
  /*Serial.println(lineL);
  Serial.println(lineR);
  Serial.println("--------------------");*/
  
}
