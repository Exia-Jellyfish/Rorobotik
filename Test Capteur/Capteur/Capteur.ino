#include "Grove_I2C_Motor_Driver.h"

#define I2C_ADDRESS 0x0f
#define IRLEFT 2 //left IR sensor
#define LEFTLINE 3 //left IR sensor line follower
#define RIGHTLINE 4 //right IR sensor line follower
#define IRRIGHT 6 //right IR sensor



void enableIRr(){
 
  Serial.println("irr");
}

void enableIRl(){
  
  Serial.println("irl");
}

void enableR(){

  Serial.println("lineR");
}

void enableL(){
  
  Serial.println("lineL");
}

void setup() {
  // put your setup code here, to run once:7
  Serial.begin(9600);

  


}

void loop() {
/*if (digitalRead(IRLEFT) == HIGH){
     Serial.println("IRLEFT HIGH");
  }
  else { Serial.println("IRLEFT LOW");}*/

  if (digitalRead(LEFTLINE) == HIGH){
    Serial.println("LEFTLINE HIGH");
  }else{
    Serial.println("LEFTLINE LOW");
  }
  
  if (digitalRead(RIGHTLINE) == HIGH){
    Serial.println("RIGHTLINE HIGH");
  }else{
    Serial.println("RIGHTLINE LOW");
  }

 /* if (digitalRead(IRRIGHT) == HIGH){
     Serial.println("IRRIGHT HIGH");
  }
  else { Serial.println("IRRIGHT LOW");}*/

delay(300);

}
