#include <VirtualWire.h>
#include <stdint.h>

char msg[255] = "";
int RF_TX_PIN = 8;

 /* 
  
void createPacket(){
  entete hEad;
  data dAta;
  strcpy(dAta.data, msg);
  char *checkSum  = getCheckSum(msg);
  
  strcat(msg, (char *)hEad.start);
  strcat(msg, (char *)hEad.recepter);
  strcat(msg, (char *)hEad.emetter);
  strcat(msg, (char *)checkSum);
  strcat(msg, (char *)dAta.data);
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

} // ok */





void reception() {
 int i = 0;
  if(Serial.available()){
    while(Serial.available()){
      unsigned char c = Serial.read();
      msg[i] = c;
      i++;
      if(i >strlen(msg)){
        break;
      }
    }
  }
}


void setup()
{
 Serial.begin(9600);
 vw_set_tx_pin(RF_TX_PIN); // Setup transmit pin
 vw_setup(2000); // Transmission speed in bits per seconds
 vw_rx_start();
 Serial.println("emetteur");
}

void loop()
{ 
 int i = 0;
  if(Serial.available()>0){
    while(Serial.available()){
      unsigned char c = Serial.read();
      msg[i] = c;
      i++;
      if(i >strlen(c)){
        break;
      }
    }
    Serial.print(msg); 
  } 
 //createPacket();
 vw_send((byte *)msg, strlen(msg));
 vw_wait_tx();
 msg[0] = 0x00;

}

