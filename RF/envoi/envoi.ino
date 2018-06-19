#include <VirtualWire.h>
#include <stdint.h>

int RF_TX_PIN = 2;
int n = 0; 

  struct entete{
  const char start = "$";
  const char *recepter = "g1";
  const char *emetter = "g1";
  char *idTram;
  char *checksum;
};

struct data{
  char *data = "Hello recepteur!"; 
};

struct packet{
  entete head;
  data data; 
};

uint16_t createPacket(){

  entete hEad;
  data dAta; 
   
  strcpy(hEad.start, "$");
  strcpy(hEad.recepter, "g1");
  strcpy(hEad.emetter, "g1");
  strcpy(hEad.idTram, n );
  n++;
  char *daTa = "go";
  strcpy(dAta.data, daTa);
  uint8_t checksum = getCheckSum(daTa);
  strcpy(hEad.checksum, checksum);
  packet pcket = {hEad, dAta};
  char *contra = ""; 
  strcat(contra, (char *)hEad.start);
  strcat(contra, (char *)hEad.recepter);
  strcat(contra, (char *)hEad.emetter);
  strcat(contra, (char *)n);
  strcat(contra, (char *)hEad.checksum);
  strcat(contra, (char *)dAta.data); 
  Serial.print("crypted:");
  Serial.println(contra); 
 return contra; 
}

char* getCheckSum(char *string)
{
  int XOR = 0;  
  for (int i = 0; i < strlen(string); i++) 
  {
    XOR = XOR ^ string[i];
  }
  //Serial.println(XOR);
  return (char *)XOR;
}

void setup()
{
 Serial.begin(9600); 
 Serial.println("setup"); 
 vw_set_tx_pin(RF_TX_PIN); // Setup transmit pin
 vw_setup(2000); // Transmission speed in bits per seconds
 vw_rx_start();
 Serial.println("ready"); 
}

void loop()
{
 const char *msg = "Hello, World!";
 Serial.println((char *)msg);
 vw_send((char *) msg, strlen(msg)); 
 vw_wait_tx(); 
/* delay(1000);
 uint16_t pckt = createPacket();
 vw_send((uint8_t *)pckt, strlen(pckt));  
 vw_wait_tx(); 
 delay(1000);*/
}
