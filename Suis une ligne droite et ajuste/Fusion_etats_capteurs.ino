#include "Grove_I2C_Motor_Driver.h"

#define I2C_ADDRESS 0x0f
#define IRLEFT 2 //left IR sensor
#define LEFTLINE 3 //left IR sensor line follower
#define RIGHTLINE 4 //right IR sensor line follower
#define IRRIGHT 6 //right IR sensor
//MOTOR1 = GAUCHE
//MOTOR2 = DROITE
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
    Motor.speed(MOTOR1, 50);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -50);
}

void adjustRight(){
    Motor.speed(MOTOR1, -50);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, 50);
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

void check(){
  if (digitalRead(IRLEFT) == HIGH){
   irl = '1';
  }
  else {irl= '0';}

  if (digitalRead(LEFTLINE) == HIGH){
   lineL = '1';
  }else{
   lineL = '0';
  }
  
  if (digitalRead(RIGHTLINE) == HIGH){
   lineR = '1';
  }else{
   lineR = '0';
  }

  if (digitalRead(IRRIGHT) == HIGH){
     irr = '1';
  }
  else { irr = '0';}
}

void botChoice(){
  if(lineR == '0' && lineL == '0'){
    stop();
    Serial.println("Staaap");
  }
  if(lineR == '1' && lineL == '1'){
    goForward();
    Serial.println("Foreward");
  }
  if(lineR == '1' && lineL == '0'){
    adjustRight();
    Serial.println("adjRight");
  }
  if(lineR == '0' && lineL == '1'){
    adjustLeft();
    Serial.println("AdjLeft");
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
  irr = '0';
  irl = '0';
  lineR = '0';
  lineL = '0';
  
}

void loop() {
  // put your main code here, to run repeatedly:
  check();
  botChoice();
  
  
}
