#include <VirtualWire.h>
#include <stdint.h>

int RF_TX_PIN = 2;
int n = 1; 
char *contra = "";
char *checkSum =  ""; 
char *daTa = "";
 

  struct entete{
  const char start = "$";
  const char *recepter = "g1";
  const char *emetter = "g1";
  char *idTram = n;
  char *checksum = "";
  };
  
  struct data{
    char *data = "Hello recepteur!"; 
  };
  
  struct packet{
    entete head;
    data data; 
  };

  entete hEad;
  data dAta; 
 
void createPacket(){
  strcpy(hEad.start, "$$");
  strcpy(hEad.recepter, "g1");
  strcpy(hEad.emetter, "g1");
  strcpy(hEad.idTram, n );
  daTa = "order";
  strcpy(dAta.data, daTa);
  getCheckSum(daTa);
  //Serial.print("so?");
  strcpy(hEad.checksum, checkSum); 
  strcat(contra, (char *)hEad.start);
  strcat(contra, (char *)hEad.recepter);
  strcat(contra, (char *)hEad.emetter);
  strcat(contra, (char *)hEad.idTram);
  strcat(contra, (char *)checkSum);
  strcat(contra, (char *)dAta.data); 
  n++; 
}
void getCheckSum(char *string)
{
  uint8_t XOR = 0; 
  for (int i = 0; i < strlen(string); i++) 
  {
    XOR = XOR ^ string[i];
  }
  char xOR[5];
  sprintf(xOR, "%d", XOR);
  checkSum = xOR; 
  Serial.print("xOR:");
  Serial.println(checkSum);
}

void setup()
{
 Serial.begin(9600);  
 vw_set_tx_pin(RF_TX_PIN); // Setup transmit pin
 vw_setup(2000); // Transmission speed in bits per seconds
 vw_rx_start();
 Serial.println("ready"); 
}

void loop()
{
 createPacket();
 Serial.print("contra");
 Serial.println(contra); 
 //vw_send((uint8_t *)contra, strlen(contra));
 //vw_wait_tx(); 
 delay(1000);
}
