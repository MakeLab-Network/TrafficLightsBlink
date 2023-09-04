#include <Arduino.h>
#include "Periodic.h"
#include "SwitchingAction.h"

#ifdef ESP8266
constexpr uint8_t triggerPin = 5;
constexpr uint8_t pin1 = 3;
constexpr uint8_t pin2 = 4;
#endif

#ifdef ESP32
constexpr uint8_t triggerPin = 18;
constexpr uint8_t pin1 = 17;
constexpr uint8_t pin2 = 16;
#endif

SwitchingAction action(pin1, pin2, false);
Periodic periodic(&action, 500, 8000);
void setup() {
  pinMode(triggerPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(triggerPin) == LOW) {
    delay(30);   // debounce 
    while (digitalRead(triggerPin) == LOW) {
      delay(1); // wait for release
    }
    delay(30); // debounce
  
    periodic.start();
  }
  periodic.run();
  delay(1);  
}
