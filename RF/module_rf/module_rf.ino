#include <VirtualWire.h>

    int RF_RX_PIN = 8;
   

    void setup()
    {
      Serial.begin(9600);
      vw_set_rx_pin(RF_RX_PIN);  // Setup receive pin.
      vw_setup(2000); // Transmission speed in bits per second.
      vw_rx_start(); // Start the PLL receiver.
      Serial.println("ready recepteur");
    }

    void loop()
    {
      uint8_t buf[VW_MAX_MESSAGE_LEN];
      uint8_t buflen = VW_MAX_MESSAGE_LEN;
      //vw_wait_rx();
   
      if(vw_get_message(buf, &buflen)) // non-blocking I/O
      {
        int i;
        // Message with a good checksum received, dump HEX
        Serial.print("Got: ");
        for(i = 0; i < buflen; ++i)
        {
          Serial.print((char)buf[i]);
        }
        Serial.println("");
      } 
      
    }



  /*  void lecturemsg(){
      uint8_t buf[VW_MAX_MESSAGE_LEN];
      uint8_t buflen = VW_MAX_MESSAGE_LEN;
      char *message = "";
      char *chsum;
      char *checksum;

      if (buf[3] = "?"){
         if(buf[4] = "g" && buf[5] ="1"){
            if(buf[6] = "e" && buf(7] = "1"){
              for(int i = 11; i < buflen; i++){
              strcat(message, (char *)buf[i]);
              }
              chsum = getCheckSum(char *message);
                for(int i = 8; i < 11; i++){
                strcat(checksum, (char *)buf[i]);
                }
                  if(checksum == chsum){
                    
                  }
            }    
         }
        
            
      }
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

}*/

