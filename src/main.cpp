#include <Arduino.h>
#include "robot.h"
//#include <Adafruit_SSD1306.h>

Robot robot; 


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

  robot.muovi_nord_est(100);

}
void loop()
{


  // robot.muovi_nord_est(100);
  // delay(500);
  // robot.stop();
  // delay(500);

  // robot.muovi_sud_est(100);
  // delay(500);
  // robot.stop();
  // delay(500);

  // robot.muovi_sud_ovest(100);
  // delay(500);
  // robot.stop();
  // delay(500);

  // robot.muovi_nord_ovest(100);
  // delay(500);
  // robot.stop();
  // delay(500);
}