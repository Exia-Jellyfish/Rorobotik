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
#define cruise 50 //cruise speed
#define adjust 55 //adjusting trajectory speed
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
  
    Motor.speed(MOTOR1, adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, -adjust);
  

}

void adjustRight(){
 
    Motor.speed(MOTOR1, -adjust);
  // Set speed of MOTOR2, Clockwise
  Motor.speed(MOTOR2, adjust);
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
  switch (order){
    case 'n':
    goForward();
    break;
    case 's':
     Motor.speed(MOTOR1, cruise);
    // Set speed of MOTOR2, Clockwise
    Motor.speed(MOTOR2, cruise);
    break;
    case 'e':
    adjustRight();
    break;
    case 'w':
    adjustLeft();
    break;
    case 'x':
    stopMotor();
    break;
    default:
    
    break;
  }

  
}
  






void standBy(){
      byte buf[VW_MAX_MESSAGE_LEN];
      byte buflen = VW_MAX_MESSAGE_LEN;
      bool roger = false;
      while (roger == false){
       if(vw_get_message(buf, &buflen))
      {
        
        //Serial.println((char)buf);
       
        order = ((char *)buf)[0];
         roger = true;
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
