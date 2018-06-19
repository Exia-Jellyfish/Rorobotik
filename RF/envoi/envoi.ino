#include <VirtualWire.h>
#include <stdint.h>

int RF_TX_PIN = 2;
int n = 1; 

  struct entete{
  const uint8_t start = "$";
  const uint8_t recepter = "g1";
  const uint8_t emetter = "g1";
  uint8_t idTram;
  uint8_t checksum;
};

struct data{
  uint16_t data = "Hello recepteur!"; 
};

struct packet{
  entete head;
  data data; 
};

uint16_t createPacket(){

  entete hEad;
  data dAta;  
  strcpy(hEad.idTram, n );
  n++;
  uint16_t daTa = "!!";
  strcpy(dAta.data, daTa);
  uint8_t checksum = getCheckSum(daTa);
  strcpy(hEad.checksum, checksum);
  packet pcket = {hEad, dAta};
  
  char *crypted = hEad.start + hEad.recepter + hEad.emetter + n  + hEad.checksum  + dAta.data ;
  Serial.println(crypted); 
 return crypted; 
}

uint8_t getCheckSum(char *string)
{
  int XOR = 0;  
  for (int i = 0; i < strlen(string); i++) 
  {
    XOR = XOR ^ string[i];
  }
  Serial.print(XOR);
  return XOR;
}

void setup()
{
 Serial.println("setup"); 
 vw_rx_start();
 vw_set_tx_pin(RF_TX_PIN); // Setup transmit pin
 vw_setup(2000); // Transmission speed in bits per seconds
 Serial.println("ready"); 
}

void loop()
{
 const char *msg = "Hello, World!";
 Serial.print((char *)msg);
 vw_send((char *) msg, strlen(msg)); 
 vw_wait_tx(); 
//uint16_t pckt = createPacket();
// vw_send((uint8_t *)pckt, strlen(pckt));  
 delay(100);
}
