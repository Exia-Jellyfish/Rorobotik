#include <VirtualWire.h>

    int RF_RX_PIN = 6;
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
      Serial.println("ready");
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
          Serial.print(buf[i], HEX);
          Serial.print(" ");
        }
        Serial.println("");
      }
       //Serial.println("sortie de boucle"); 
    }
