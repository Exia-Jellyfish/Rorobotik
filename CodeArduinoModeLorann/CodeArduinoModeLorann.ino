#include <VirtualWire.h>
#include "Grove_I2C_Motor_Driver.h"

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
#define I2C_ADDRESS 0x0f
#define cruise 40 //cruise speed
#define adjust 45 //adjusting trajectory speed
#define COOLDOWN 3000
int n;
int i;
char order;
int dir;
int t;
int RF_RX_PIN = 6;
String test;
/*
 * 
 * 
 * section mouvements
 * 
 */
void goForward(){
   Motor.speed(MOTOR1, -(cruise-10));
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -(cruise-10));
}

void rotateLeft(){
   while(millis()<t+90){
     Motor.speed(MOTOR1, -adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -adjust);
  }
  while(millis()<t+500){
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
  while(millis()<t+500){
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
  while (digitalRead(LEFTLINE) == LOW){
    Motor.speed(MOTOR1, -(cruise-20));
  
  Motor.speed(MOTOR2, -cruise);
  }

}

void adjustRight(){
  while (digitalRead(LEFTLINE) == LOW){
    Motor.speed(MOTOR1, -cruise);
  
  Motor.speed(MOTOR2, -(cruise-20));
  
  }

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
   if(digitalRead(IRRIGHT) == HIGH || digitalRead(IRLEFT) == HIGH){  
      stopMotor();
      delay(1000);
      nextOrder();
      
    }
   else if( digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == HIGH){  
      goForward();
      delay(500);
      stopMotor();
      
    }
    else if( digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == LOW){
     
      adjustLeft();
      
    }
    else if( digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH ){
       
      adjustRight();
  
    }
    else{}
 }

  

void nextOrder(){
   t= millis();
  switch (order){
    case 'n':
    while (millis()< t+200){
    goForward();
    }
    break;
    case 'e':
    rotateRight();
    break;
    case 's':
    while (millis()< t+1000){
    adjustRight();
    }
    break;
    case 'w':
    rotateLeft();
    break;
    case 'x':
    stopMotor();
    break;
    default:
    stopMotor();
    break;
  }
  order = 'x';
}




void standBy(){
      byte buf[VW_MAX_MESSAGE_LEN];
      byte buflen = VW_MAX_MESSAGE_LEN;
      int i =0; 
      bool roger = false;
      while (roger == false){
       if(vw_get_message(buf, &buflen))
      {
        
        //Serial.println((char)buf);
        order = ((char *)buf)[0];
         
         roger = true;
       if(buf[buflen] == '\0'){
        
       }
      }
       
    }

}




void setup() {
  delay(2000);
  Motor.begin(I2C_ADDRESS);
  vw_set_rx_pin(RF_RX_PIN);  // Setup receive pin.
  vw_setup(2000); // Transmission speed in bits per second.
  vw_rx_start(); // Start the PLL receiver.
  Serial.begin(9600);
  Serial.print("recepteur");
  order = 'x';
  delay(1000);
}

void loop() {
botChoice(); 
standBy();
Serial.println(order);
     
}
