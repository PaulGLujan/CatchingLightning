
#include "src/Led/Led.h"
#include "src/MillisDelay/MillisDelay.h"

#define LED_1_PIN 3

Led led1(LED_1_PIN);
MillisDelay ledDelay;

void setup() {
  ledDelay.start(100);
  led1.on();
};

void loop() {
  if (ledDelay.justFinished()) {
    ledDelay.repeat();
    if (led1.isOn()) {
      led1.off();
    } else {
      led1.on();
    }
  }
}