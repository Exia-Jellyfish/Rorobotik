#include <VirtualWire.h>
#include <stdint.h>

int RF_TX_PIN = 6;

  struct entete{
    const char start = "$";
    const char *recepter = "g1";
    const char *emetter = "g1";
    char *checksum = "";
  };
  
  struct data{
    char *data = ""; 
  };
  
  struct packet{
    entete head;
    data data; 
  };

 
  
 
char * createPacket(){
  entete hEad;
  data dAta;
  
  char *checkSum =  ""; 
  char *contra = "";
  char * daTa = "lol";
  strcpy(hEad.start, "?");
  strcpy(hEad.recepter, "g1");
  strcpy(hEad.emetter, "g1");
  strcpy(dAta.data, daTa);
  checkSum  = getCheckSum(daTa);
  strcpy(hEad.checksum, checkSum); 
  
  strcat(contra, (char *)hEad.start);
  strcat(contra, (char *)hEad.recepter);
  strcat(contra, (char *)hEad.emetter);
  strcat(contra, (char *)checkSum);
  strcat(contra, (char *)dAta.data);
  return (char *)contra; 
}

char * getCheckSum(char *string)
{
  int XOR;  
  if( strlen(string) != 0){
  for (int i = 0; i < strlen(string); i++) 
  {
    XOR += *(string++); 
  }
  }
  char xOR[12];
  sprintf(xOR, "%d", XOR);
 // Serial.println(xOR);
  return xOR; 

} // ok 




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
 char * msg = createPacket();
 Serial.println(msg);

 vw_send(msg, strlen(msg));
 vw_wait_tx(); 
 delay(10000000);
}
