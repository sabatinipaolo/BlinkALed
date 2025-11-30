#include <Arduino.h>
#include "robot.h"
//#include <Adafruit_SSD1306.h>

//Robot robot; 
        Motore _mot_ant_dx(AD_PIN_A, AD_PIN_B) ;
        Motore _mot_ant_sx(AS_PIN_A, AS_PIN_B) ;
        Motore _mot_post_dx(PD_PIN_A, PD_PIN_B);
        Motore _mot_post_sx(PS_PIN_A, PS_PIN_B);

//Adafruit_SSD1306 display = Adafruit_SSD1306();
void setup()
{
 // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  // display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)

    
  // // Clear the buffer.
  // display.clearDisplay();
  // display.display();


  
  // Serial.println("IO test");

  // // text display tests
  // display.setTextSize(2);
  // display.setTextColor(WHITE);

        
  // display.print("CO2: ");
  // display.print("VOC: ");
  // display.display();

 

}

void loop()
{
  
  
}