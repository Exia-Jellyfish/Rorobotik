
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
#define adjust 30  //adjusting trajectory speed
#define COOLDOWN 3000
    int n;
    String orders = "senex";
    int dir;
    String nodes = "acbba";
    int t;
    int RF_RX_PIN = 6;
    char message[255] = "";

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
      
      while(millis()<t+700){
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
    
      while(millis()<t+700){
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
      switch (nodes[n]){
        case 'a':
     if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == LOW){  //0000 Lost
       
        } 
        else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW){  
          goForward();
        }
         else if(digitalRead(IRLEFT) == HIGH || digitalRead(IRRIGHT) == HIGH && millis() > (t+COOLDOWN)){  
          nextOrder();
        }
        else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == LOW && millis() > (t+COOLDOWN)){
          adjustLeft();
        }
        else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW && millis() > (t+COOLDOWN)){
          adjustRight();
        }
    
        break;
    
        case 'b':
     if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == LOW){  //0000 Lost
       
        } 
        else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW){  
          goForward();
        }
         else if(digitalRead(IRLEFT) == HIGH && digitalRead(IRRIGHT) == HIGH && millis() > (t+COOLDOWN)){  
          nextOrder();
        }
        else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == LOW && millis() > (t+COOLDOWN)){
          adjustLeft();
        }
        else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW && millis() > (t+COOLDOWN)){
          adjustRight();
        }
        break;
    
         case 'c':
     if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == LOW){  //0000 Lost
       
        } 
        else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW){  
          goForward();
        }
         else if(digitalRead(LEFTLINE) == HIGH&& digitalRead(RIGHTLINE) == HIGH && digitalRead(IRLEFT) == HIGH && digitalRead(IRRIGHT) == HIGH && millis() > (t+COOLDOWN)){  
          nextOrder();
        }
        else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == HIGH && digitalRead(RIGHTLINE) == LOW && digitalRead(IRRIGHT) == LOW && millis() > (t+COOLDOWN)){
          adjustLeft();
        }
        else if(digitalRead(IRLEFT) == LOW && digitalRead(LEFTLINE) == LOW && digitalRead(RIGHTLINE) == HIGH && digitalRead(IRRIGHT) == LOW && millis() > (t+COOLDOWN)){
          adjustRight();
        }
        break;
        default:
        break;
    
      }
     }

  
    
    void goNorth(){
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
        t= millis();
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











void setup() {
  delay(2000);
  // put your setup code here, to run once:
  Motor.begin(I2C_ADDRESS);
  vw_set_rx_pin(RF_RX_PIN);  // Setup receive pin.
  vw_setup(2000); // Transmission speed in bits per second.
  vw_rx_start(); // Start the PLL receiver.
  Serial.begin(9600);
  n=0;
  dir = WEST;
}

void loop() {
 botChoice();
 
      uint8_t buf[VW_MAX_MESSAGE_LEN];
      uint8_t buflen = VW_MAX_MESSAGE_LEN;
      char *checksum;
      char *chsum = ""; 
      int i; 
      
       if(vw_get_message(buf, &buflen))
      {
        if ((uint8_t)buf[0] == 36 && (uint8_t)buf[1] == 103 && (uint8_t)buf[2] == 49 && (uint8_t)buf[3] == 101 && (uint8_t)buf[4] == 49 )
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
                   
                }
           } 
      } 
}
