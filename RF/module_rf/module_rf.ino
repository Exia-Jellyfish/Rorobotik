#include <VirtualWire.h>

    int RF_RX_PIN = 6;
    char message[255] = "";

    void setup()
    {
      Serial.begin(9600);
      vw_set_rx_pin(RF_RX_PIN);  // Setup receive pin.
      vw_setup(2000); // Transmission speed in bits per second.
      vw_rx_start(); // Start the PLL receiver.
     Serial.println("recepteur");
    }

    void loop()
    {
      uint8_t buf[VW_MAX_MESSAGE_LEN];
      uint8_t buflen = VW_MAX_MESSAGE_LEN;
      char *checksum;
      char *chsum = ""; 
      int i; 
      
       if(vw_get_message(buf, &buflen))
      {
        //Serial.println((char *)buf); 
        //Serial.println((uint8_t) buf[0]);
        if ((uint8_t)buf[0] == 36 && (uint8_t)buf[1] == 103 && (uint8_t)buf[2] == 49 && (uint8_t)buf[3] == 101 && (uint8_t)buf[4] == 49 )
        { // vérification de l'entête. 
                for(i = 8; i < buflen; i++){
                  strcat(message, (char)buf[i]);
                  }
               chsum = getCheckSum((char *)message);
                for(i = 5 ; i < 8; i++){
                  strcat(checksum, (char *)buf[i]);
                  }
                if(checksum == chsum){
                   
                      Serial.print("msg: ");
                    Serial.println((char *)message);
                   
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
      
      }

