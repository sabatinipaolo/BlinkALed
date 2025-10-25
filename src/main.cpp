#include <Arduino.h>

#ifndef LED_BUILTIN
    #define LED_PIN PC13
#else
    #define LED_PIN LED_BUILTIN
#endif



void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH); // su molte board PC13 è active-low -> HIGH = LED spento
}

void loop() {
    digitalWrite(LED_PIN, LOW);  // LED acceso
    delay(500);
    digitalWrite(LED_PIN, HIGH); // LED spento
    delay(500);
}