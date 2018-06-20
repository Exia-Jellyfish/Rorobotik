


#include "Grove_I2C_Motor_Driver.h"

#define I2C_ADDRESS 0x0f
#define IRLEFT 8 //left IR sensor
#define LEFTLINE 3 //left IR sensor line follower
#define RIGHTLINE 4 //right IR sensor line follower
#define IRRIGHT 6 //right IR sensor
//MOTOR1 = GAUCHE
//MOTOR2 = DROITE
#define WEST 0
#define EAST 2
#define NORTH 1
#define SOUTH 3
#define I2C_ADDRESS 0x0f
#define cruise 40 //cruise speed
#define adjust 30  //adjusting trajectory speed
int n;
String orders = "senex";
int dir;
int t;
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
   t = millis();
  while(millis()<t+300){
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
  t = millis();
  while(millis()<t+300){
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
    Motor.speed(MOTOR1, 40);
  
  Motor.speed(MOTOR2, -40);
  }

}

void adjustRight(){
  while (digitalRead(LEFTLINE) == LOW){
    Motor.speed(MOTOR1, -40);
  
  Motor.speed(MOTOR2, 40);
  
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
 if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == LOW){  //0000 Lost
   
    } 
    else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW){  
      goForward();
    }
     else if(digitalRead(IRLEFT) == HIGH || digitalRead(IRRIGHT) == HIGH){  
      nextOrder();
    }
    else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == LOW){
      adjustLeft();
    }
    else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW){
      adjustRight();
    }
 }

  

void goNorth(){
  switch (dir){
    case NORTH:
    t = millis();
    while(millis()< t+500){
      goForward();
    }
    break;
    case SOUTH:
     t = millis();
    while(millis()< t+500){
      rotateLeft();
    }
    while(digitalRead(LEFTLINE) == LOW || digitalRead(RIGHTLINE) == HIGH){
      rotateLeft();
    }
    
    break;
    case EAST:
    rotateLeft();
    break;
    case WEST:
    rotateLeft();
    break;
    default:
    stopMotor();
    break;
  }
  dir = NORTH;
}

void goWest(){
switch (dir){
    case NORTH:
    rotateLeft();
    break;
    case SOUTH:
    rotateRight();
    break;
    case EAST:
     t = millis();
    while(millis()< t+500){
      rotateLeft();
    }
    while(digitalRead(LEFTLINE) == LOW || digitalRead(RIGHTLINE) == HIGH){
      rotateLeft();
    }
    break;
    case WEST:
    t = millis();
    while(millis()< t+500){
      goForward();
    }
    break;
    default:
    stopMotor();
    break;
  }
  dir = WEST;
  
}

void goSouth(){
  switch (dir){
    case NORTH:
     t = millis();
    while(millis()< t+500){
      rotateLeft();
    }
    while(digitalRead(LEFTLINE) == LOW || digitalRead(RIGHTLINE) == HIGH){
      rotateLeft();
    }
    break;
    case SOUTH:
    t = millis();
    while(millis()< t+500){
      goForward();
    }
    break;
    case EAST:
    rotateRight();
    break;
    case WEST:
     rotateLeft();
    break;
    default:
    stopMotor();
    break;
  }
  dir = SOUTH;
}

void goEast(){
  switch (dir){
    case NORTH:
    rotateRight();
    break;
    case SOUTH:
    rotateLeft();
    break;
    case EAST:
    t = millis();
    while(millis()< t+500){
      goForward();
    }
    break;
    case WEST:
     t = millis();
    while(millis()< t+500){
      rotateLeft();
    }
    while(digitalRead(LEFTLINE) == LOW || digitalRead(RIGHTLINE) == HIGH){
      rotateLeft();
    }
    break;
    default:
    stopMotor();
    break;
  }
  dir = EAST;
}


void nextOrder(){
  switch (orders[n]){
    case 'n':
    goNorth();
    break;
    case 'e':
    goEast();
    break;
    case 's':
    goSouth();
    break;
    case 'w':
    goWest();
    break;
    default:
    stopMotor();
    break;
  }
  n++;
}












void setup() {
  delay(2000);
  // put your setup code here, to run once:
  Motor.begin(I2C_ADDRESS);
  Serial.begin(9600);
  n=0;
  dir = WEST;
}

void loop() {
 botChoice();
}