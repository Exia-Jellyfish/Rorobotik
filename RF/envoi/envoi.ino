#include <VirtualWire.h>
#include <stdint.h>

int RF_TX_PIN = 2;
int n = 1; 
char *contra = ""; 

  struct entete{
  const char start = "$";
  const char *recepter = "g1";
  const char *emetter = "g1";
  char *idTram = n;
  char *checksum;
};

struct data{
  char *data = "Hello recepteur!"; 
};

struct packet{
  entete head;
  data data; 
};

void createPacket(){

  entete hEad;
  data dAta; 
   
  strcpy(hEad.start, "$");
  strcpy(hEad.recepter, "g1");
  strcpy(hEad.emetter, "g1");
  strcpy(hEad.idTram, n );
  char *daTa = "lololol";
  strcpy(dAta.data, daTa);
  char *checksum = getCheckSum(daTa);
  strcpy(hEad.checksum, checksum);
  packet pcket = {hEad, dAta};
  
  strcat(contra, (char *)hEad.start);
  strcat(contra, (char *)hEad.recepter);
  strcat(contra, (char *)hEad.emetter);
  strcat(contra, (char *)hEad.idTram);
  strcat(contra, (char *)hEad.checksum);
  strcat(contra, (char *)dAta.data); 
  
  Serial.print("crypted:");
  Serial.println(contra);
  n++; 
}

char* getCheckSum(char *string)
{
  int XOR = 0; 
  for (int i = 0; i < strlen(string); i++) 
  {
    XOR = XOR ^ string[i];
  }
  char xOR[12];
  sprintf(xOR, "%d", XOR);
  Serial.println(xOR);
  return xOR;
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
 /*const char *msg = "Hello, World!";
 Serial.println((char *)msg);
 vw_send((char *) msg, strlen(msg)); 
 vw_wait_tx(); 
 delay(1000);*/
 
 createPacket();
 vw_send((char *)contra, strlen(contra));  
 vw_wait_tx(); 
 delay(1000);
}
