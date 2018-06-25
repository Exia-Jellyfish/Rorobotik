#include <VirtualWire.h>
#include <stdint.h>

/*char msg[255] = "";

  struct entete{
    const char *start = "$";
    const char *recepter = "g1";
    const char *emetter = "e1";
    char *checksum = "";
  };
  
  struct data{
    char *data = "order"; 
  };
  
void createPacket(){
  entete hEad;
  data dAta;
  char *daTa = "rt";
  strcpy(dAta.data, daTa);
  char *checkSum  = getCheckSum(daTa);
  
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

int RF_TX_PIN = 8;

void setup()
{
 Serial.begin(9600);
 vw_set_tx_pin(RF_TX_PIN); // Setup transmit pin
 vw_setup(2000); // Transmission speed in bits per seconds
 vw_rx_start();
 Serial.println("ready emetteur"); 
}

void loop()
{
 //createPacket();
 char *msg = "senex";
 Serial.println(msg);
 vw_send((uint8_t *)msg, strlen(msg));
 vw_wait_tx();
 msg[0] = 0x00;
}
