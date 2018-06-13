#include "Grove_I2C_Motor_Driver.h"

#define I2C_ADDRESS 0x0f
#define IRLEFT 6 //left IR sensor
#define LEFTLINE 5 //left IR sensor line follower
#define RIGHTLINE 3 //right IR sensor line follower
#define IRRIGHT 2 //right IR sensor

bool irr;
bool irl;
bool lineR;
bool lineL;


void enableIRr(){
  irr = true;
  Serial.println("irr");
}

void enableIRl(){
  irl = true;
  Serial.println("irl");
}

void enableR(){
  lineR = true;
  Serial.println("lineR");
}

void enableL(){
  lineL = true;
  Serial.println("lineL");
}

void setup() {
  // put your setup code here, to run once:7
  Serial.begin(9600);
 
  
  attachInterrupt(digitalPinToInterrupt(IRRIGHT), enableIRr, FALLING);
  attachInterrupt(digitalPinToInterrupt(IRLEFT),enableIRl,FALLING);
  attachInterrupt(digitalPinToInterrupt(RIGHTLINE), enableR, FALLING);
  attachInterrupt(digitalPinToInterrupt(LEFTLINE), enableL, FALLING);


}

void loop() {


}
