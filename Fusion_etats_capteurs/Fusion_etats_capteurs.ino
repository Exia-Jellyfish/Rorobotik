#include "Grove_I2C_Motor_Driver.h"

#define I2C_ADDRESS 0x0f
#define IRLEFT 2 //left IR sensor
#define LEFTLINE 3 //left IR sensor line follower
#define RIGHTLINE 4 //right IR sensor line follower
#define IRRIGHT 6 //right IR sensor
//MOTOR1 = GAUCHE
//MOTOR2 = DROITE
char irr;
char irl;
char lineL;
char lineR;
int n;
#define I2C_ADDRESS 0x0f
#define crouise 30

/*
 * 
 * 
 * section mouvements
 * 
 */
void goForward(){
   Motor.speed(MOTOR1, -crouise);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -crouise);
}

void rotateLeft(){
    Motor.speed(MOTOR1, crouise);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -crouise);
}

void rotateRight(){
    Motor.speed(MOTOR1, -crouise);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, crouise);
}
void adjustLeft(){
    Motor.speed(MOTOR1, 20);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -20);
}

void adjustRight(){
    Motor.speed(MOTOR1, -20);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, 20);
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

/*
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
}*/

void botChoice(){
  if(digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == LOW && digitalRead(IRLEFT) == LOW && digitalRead(IRRIGHT) == LOW){
    n++;
    Serial.println(n);
    if (n>400){
      stop();
    } 
  }
  if(digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRLEFT) == LOW && digitalRead(IRRIGHT) == LOW){
    goForward();
    n=0;
    Serial.println("Foreward");
  }
  if(digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRLEFT) == LOW && digitalRead(IRRIGHT) == LOW){
    rotateRight();
    n=0;
    Serial.println("adjRight");
  }
  if(digitalRead(RIGHTLINE) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(IRRIGHT) == HIGH && digitalRead(IRLEFT) == HIGH){
   rotateLeft();
   n=0;
    Serial.println("adjLeft");
  }

  if(digitalRead(RIGHTLINE) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(IRRIGHT) == HIGH && digitalRead(IRLEFT) == LOW){
    Serial.println("tournant à droite"); 
  }
  if(digitalRead(RIGHTLINE) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(IRRIGHT) == LOW && digitalRead(IRLEFT) == HIGH){
    Serial.println("tournant à gauche"); 
  }
   if(digitalRead(RIGHTLINE) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(IRRIGHT) == HIGH && digitalRead(IRLEFT) == HIGH){
    Serial.println("tournant à gauche ou à droite"); 
  }
  
  if(digitalRead(RIGHTLINE) == HIGH && digitalRead(LEFTLINE) == HIGH && digitalRead(IRRIGHT) == HIGH && digitalRead(IRLEFT) == LOW){
    Serial.println("tournant à droit ou tout droit"); 
  }
  if(digitalRead(RIGHTLINE) == HIGH && digitalRead(LEFTLINE) == HIGH && digitalRead(IRRIGHT) == LOW && digitalRead(IRLEFT) == HIGH){
    Serial.println("tournant à gauche ou tout droit"); 
  }
  if(digitalRead(RIGHTLINE) == HIGH && digitalRead(LEFTLINE) == HIGH && digitalRead(IRRIGHT) == HIGH && digitalRead(IRLEFT) == HIGH){
    Serial.println("tournant à gauche, droite ou tout droit"); 
  }
  
  if(digitalRead(RIGHTLINE) == HIGH && digitalRead(LEFTLINE) == LOW && digitalRead(IRRIGHT) == HIGH && digitalRead(IRLEFT) == LOW){
    Serial.println("tournant à droite mais robot décalé à gauche"); 
  }
  if(digitalRead(RIGHTLINE) == HIGH && digitalRead(LEFTLINE) == LOW && digitalRead(IRRIGHT) == LOW && digitalRead(IRLEFT) == HIGH){
    Serial.println("tournant à guauche et robot décalé à gauche."); 
  }
  if(digitalRead(RIGHTLINE) == HIGH && digitalRead(LEFTLINE) == LOW && digitalRead(IRRIGHT) == HIGH && digitalRead(IRLEFT) == HIGH){
    Serial.println("tournant à droite, gauche et tout droit mais robot décalé à gauche "); 
  }
  
 
  if(digitalRead(RIGHTLINE) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(IRRIGHT) == HIGH && digitalRead(IRLEFT) == LOW){
    Serial.println("tournant à droite et tout droit et robot décalé sur la droite "); 
  }
  if(digitalRead(RIGHTLINE) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(IRRIGHT) == LOW && digitalRead(IRLEFT) == HIGH){
    Serial.println("tournant à gauche et tout droit et robot décalé sur la droite"); 
  }
   if(digitalRead(RIGHTLINE) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(IRRIGHT) == HIGH && digitalRead(IRLEFT) == HIGH){
    Serial.println("tournant à droite, gauche et tout droit et robot décalé sur la droite ");
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
  /*irr = '0';
  irl = '0';
  lineR = '0';
  lineL = '0';*/
  goForward(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  //check();
  botChoice();
  stop(); 
  
}
