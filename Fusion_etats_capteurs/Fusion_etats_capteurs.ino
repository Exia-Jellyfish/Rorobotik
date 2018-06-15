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
   Motor.speed(MOTOR1, crouise);
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
/*
void adjustLeft(){
    Motor.speed(MOTOR1, 50);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -50);
}

void adjustRight(){
    Motor.speed(MOTOR1, -50);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, 50);
}*/

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
  if(lineR == '0' && lineL == '0' && irr == '0' && irl == '0'){
    n++;
    Serial.println(n);
    if (n>400){
      stop();
    } 
  }
  if(lineR == '1' && lineL == '1' && irr == '0' && irl == '0'){
    goForward();
    n=0;
    Serial.println("Foreward");
  }
  if(lineR == '1' && lineL == '0' && irr == '0' && irl == '0'){
    rotateRight();
    n=0;
    Serial.println("adjRight");
  }
  if(lineR == '0' && lineL == '1'&& irr == '0' && irl == '0'){
   rotateLeft();
   n=0;
    Serial.println("adjLeft");
  }


  if(lineR == '0' && lineL == '0' && irr == '1' && irl == '0'){
    Serial.println("tournant à droite"); 
  }
  if(lineR == '0' && lineL == '0' && irr == '0' && irl == '1'){
    Serial.println("tournant à gauche"); 
  }
   if(lineR == '0' && lineL == '0' && irr == '1' && irl == '1'){
    Serial.println("tournant à gauche ou à droite"); 
  }
  
  if(lineR == '1' && lineL == '1' && irr == '1' && irl == '0'){
    Serial.println("tournant à droit ou tout droit"); 
  }
  if(lineR == '1' && lineL == '1' && irr == '0' && irl == '1'){
    Serial.println("tournant à gauche ou tout droit"); 
  }
  if(lineR == '1' && lineL == '1' && irr == '1' && irl == '1'){
    Serial.println("tournant à gauche, droite ou tout droit"); 
  }
  
  if(lineR == '1' && lineL == '0' && irr == '1' && irl == '0'){
    Serial.println("tournant à droite mais robot décalé à gauche"); 
  }
  if(lineR == '1' && lineL == '0' && irr == '0' && irl == '1'){
    Serial.println("tournant à guauche et robot décalé à gauche."); 
  }
  if(lineR == '1' && lineL == '0' && irr == '1' && irl == '1'){
    Serial.println("tournant à droite, gauche et tout droit mais robot décalé à gauche "); 
  }
  
 
  if(lineR == '0' && lineL == '1'&& irr == '1' && irl == '0'){
    Serial.println("tournant à droite et tout droit et robot décalé sur la droite "); 
  }
  if(lineR == '0' && lineL == '1'&& irr == '0' && irl == '1'){
    Serial.println("tournant à gauche et tout droit et robot décalé sur la droite"); 
  }
   if(lineR == '0' && lineL == '1'&& irr == '1' && irl == '1'){
    Serial.println("tournant à droite, gauche et tout droit et robot décalé sur la droite ");
  }
  
  
}


void direction(){
  if (irr == 0 && irl == 1){
    rotateLeft(); 
  }
  if(irr == 1 && irl == 1){
    Serial.print (" What should I do?");
  }
  if(irr == 1 && irl == 0){
    rotateRight(); 
  }
  if(irr == 0 && irl == 0){
    goForward(); 
  }
}



 /*  
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
  Motor.speed(MOTOR1, -crouise);
  Motor.speed(MOTOR2, -crouise);
}

void loop() {
  // put your main code here, to run repeatedly:
  check();
  botChoice();
   
  
}
