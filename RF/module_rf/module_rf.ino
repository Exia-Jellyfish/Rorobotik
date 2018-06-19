#include <VirtualWire.h>

    int RF_RX_PIN = 7;
    int n = 1;

    
    struct entete{
      uint8_t start;
      uint8_t recepter;
      uint8_t emetter;
      uint8_t idTram;
      uint8_t checksum;
    };
    
    struct data{
      uint16_t data; 
    };
    
    struct packet{
      entete head;
      data data; 
    };

    

    void setup()
    {
      Serial.begin(9600);
      vw_set_rx_pin(RF_RX_PIN);  // Setup receive pin.
      vw_setup(2000); // Transmission speed in bits per second.
      vw_rx_start(); // Start the PLL receiver.
      Serial.print("ready");
    }

    void loop()
    {
      Serial.println("le message est:");
    uint8_t buf[VW_MAX_MESSAGE_LEN];
         uint8_t buflen = VW_MAX_MESSAGE_LEN;
      vw_wait_rx();
      if(vw_get_message(buf, &buflen)) // non-blocking I/O
      {
        int i;
        //if((char)buf[1] + (char)buf[2] == "g1"){
   
        Serial.print("Got: ");
        for(i = 0; i < buflen; ++i)
        {
          Serial.print((char)buf[i]); 
        }
        Serial.println("");
      }
       
    }
