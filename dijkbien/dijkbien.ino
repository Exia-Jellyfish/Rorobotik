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
<<<<<<< HEAD
String orders;
int dir;

=======
int i;
String orders;
int dir;
>>>>>>> 730ee90311f922beaf4d88efb642bdcc4c6f241c
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



void setDir(){
  switch (orders[0]){
    case 'n':
    dir = NORTH;
    break;
    case 's':
    dir = SOUTH;
    break;
    case 'e':
    dir = EAST;
    break;
    case 'w':
    dir = WEST;
    break;
    default:
    dir = NORTH;
    break; 
  }
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
      nextOrder();
      
    }
   else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW){  
      goForward();
      
    }
    else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == LOW ){
     
      adjustLeft();
      
    }
    else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW ){
       
      adjustRight();
  
    }
    else{
   
 }}

  

void goNorth(){
   t = millis();
  switch (dir){
    case NORTH:
   
    while(millis()< t+500){
      goForward();
    }
    break;
    case SOUTH:
    
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
   t = millis();
switch (dir){
    case NORTH:
    rotateLeft();
    break;
    case SOUTH:
    rotateRight();
    break;
    case EAST:
   
    while(millis()< t+500){
      rotateLeft();
    }
    while(digitalRead(LEFTLINE) == LOW || digitalRead(RIGHTLINE) == HIGH){
      rotateLeft();
    }
    break;
    case WEST:
   
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
 t = millis();
  switch (dir){
    case NORTH:
  
    while(millis()< t+500){
      rotateLeft();
    }
    while(digitalRead(LEFTLINE) == LOW || digitalRead(RIGHTLINE) == HIGH){
      rotateLeft();
    }
    break;
    case SOUTH:
    
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
   t = millis();
  switch (dir){
    case NORTH:
    rotateRight();
    break;
    case SOUTH:
    rotateLeft();
    break;
    case EAST:
   
    while(millis()< t+500){
      goForward();
    }
    break;
    case WEST:
   
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
   t= millis();
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
    while(millis()<t+100){
      goForward();
    }
    stopMotor();
    break;
  }
  n++;
}


  char * getCheckSum(char *string)
      {
        int XOR;  
        for (int i = 0; i < strlen(string); i++) 
        {
          XOR += *(string++); 
        }
        char xOR[12];
        sprintf(xOR, "%d", XOR);
        return xOR; 
      
      }




void standBy(){
<<<<<<< HEAD
      byte buf[VW_MAX_MESSAGE_LEN];
      byte buflen = VW_MAX_MESSAGE_LEN;
      int i =0; 
=======
      uint8_t buf[VW_MAX_MESSAGE_LEN];
      uint8_t buflen = VW_MAX_MESSAGE_LEN;
      char *checksum;
      char *chsum = ""; 
      int i; 
>>>>>>> 055d5c670a4f499d5afb85c38a5ef80e171d254a
      bool roger = false;
      Serial.println(VW_MAX_MESSAGE_LEN);
      while (roger == false){
        
       if(vw_get_message(buf, &buflen))
      {
<<<<<<< HEAD
         for(i = 0; i < buflen; ++i)
        {
          strcat(message, (char *)buf[i]);
        }
        
//      Serial.println((char *)buf);
        orders = (char *)buf;
         
         roger = true;
       if(buf[buflen] == '\0'){
        
       }
      }
=======
        Serial.println("wesh");
        Serial.println((char *)buf);
        orders = (char *)buf;
        roger == true;
        
        /*if ((uint8_t)buf[0] == 36 && (uint8_t)buf[1] == 103 && (uint8_t)buf[2] == 49 && (uint8_t)buf[3] == 101 && (uint8_t)buf[4] == 49 )
        { // vérification de l'entête. 
                for(i = 8; i < buflen; i++){
                  strcat(message, (char)buf[i]);
                  }
               chsum = getCheckSum((char *)message);
                for(i = 5 ; i < 8; i++){
                  strcat(checksum, (char *)buf[i]);
                  }
                if(checksum == chsum){
                   
                      Serial.print("msg: ");
                    Serial.println((char *)message);
                    roger = true;
                   
                }
           } */
>>>>>>> 055d5c670a4f499d5afb85c38a5ef80e171d254a
       
      }  
}

}


void setDir(){
  switch (orders[0]){
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


void setup() {
  delay(2000);
  Motor.begin(I2C_ADDRESS);
  vw_set_rx_pin(RF_RX_PIN);  // Setup receive pin.
  vw_setup(2000); // Transmission speed in bits per second.
  vw_rx_start(); // Start the PLL receiver.
  Serial.begin(9600);
  n=1;
<<<<<<< HEAD
  setDir();
  //standBy();
  orders = "wsenex";
  Serial.println(orders);
  
=======

   standBy();
>>>>>>> 730ee90311f922beaf4d88efb642bdcc4c6f241c
}

void loop() {
<<<<<<< HEAD
  
  for(int i =0; i<strlen(message); i++){
    message[i] = '\0';
  }
<<<<<<< HEAD
 standBy();
 Serial.print("message : ");
 Serial.println((char *)message);
//botChoice(); 
=======
botChoice(); 
>>>>>>> 055d5c670a4f499d5afb85c38a5ef80e171d254a
=======




botChoice(); 

Serial.println(orders);
>>>>>>> 730ee90311f922beaf4d88efb642bdcc4c6f241c
     
}
