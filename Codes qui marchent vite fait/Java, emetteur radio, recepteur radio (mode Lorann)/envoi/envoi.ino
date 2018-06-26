#include <VirtualWire.h>
#include <stdint.h>

char msg[255] = "";
int RF_TX_PIN = 8;

 /*
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



//Prend les entrées Sérial et les charge dans "msg"
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
 delay(3000);

}

void loop()
{  
 //createPacket();
 reception();
 vw_send((byte *)msg, strlen(msg));
 vw_wait_tx();
 Serial.println(msg);
 /*for(int i =0; i<strlen(msg); i++){ //reinitialisation des char de "msg"
    //msg[i] = "";
  }*/
}
