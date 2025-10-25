#include <Arduino.h>

#ifndef LED_BUILTIN
    #define LED_PIN PC13
#else
    #define LED_PIN LED_BUILTIN
#endif

#define LED_PIN PA10

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    
  for (volatile int i = 0; i < 1024; i+=16){
    analogWrite (LED_PIN, i); 
    delay(500);
  } 
  
  for (volatile int i = 1023; i > 0; i-=16){
    analogWrite (LED_PIN, i); 
    delay(500);
  }

}