
#include "src/Led/Led.h"

#define LED_1_PIN 3

Led led1(LED_1_PIN);

void setup(){};

void loop() {
  led1.on();
  delay(1000);
  led1.off();
  delay(5000);
}