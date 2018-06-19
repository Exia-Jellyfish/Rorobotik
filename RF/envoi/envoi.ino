#include <VirtualWire.h>
#include <stdint.h>

int RF_TX_PIN = 7;
int n = 1;
uint8_t checkSum; 

struct entete{
  const uint8_t start = "$";
  const uint8_t recepter = "RobotGr1";
  const uint8_t emetter = "EmettGr1";
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

uint16_t creatPacket(){

  entete hEad;
  data dAta;  
  strcpy(hEad.idTram, n );
  n++;
  unsigned char *daTa = "Hello recepteur!";
  strcpy(dAta.data, daTa);
  uint16_t checksum = chksum8(daTa, 16);
  strcpy(hEad.checksum, checkSum);
  packet pcket = {hEad, dAta};
  
  uint16_t crypted = (hEad.start + hEad.recepter + hEad.emetter + n + hEad.checksum + dAta.data) ;
 return crypted; 
}

uint16_t chksum8(unsigned char *daTa, size_t len)
{
    unsigned int sum;       
    for ( sum = 0 ; len != 0 ; len-- ){
        sum += *daTa++;  
        Serial.print(sum);
        }
    return (uint8_t)sum;
}





void setup()
{
 vw_set_tx_pin(RF_TX_PIN); // Setup transmit pin
 vw_setup(2000); // Transmission speed in bits per second.
 struct packet packet; 
}

void loop()
{
 const char *msg = "Hello, World!";
uint16_t pckt = creatPacket();
 vw_send((uint8_t *)pckt, strlen(pckt));  
 delay(100);
}
