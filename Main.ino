
#include "src/Led/Led.h"
#include "src/MillisDelay/MillisDelay.h"

#define LED_1_PIN 2
#define LED_2_PIN 3
#define LED_3_PIN 4
#define LED_4_PIN 5
#define LED_5_PIN 6
#define LED_6_PIN 7

Led led1(LED_1_PIN);
Led led2(LED_2_PIN);

MillisDelay ledDelay;

void setup() {
  ledDelay.start(500);
  led1.on();
};

void loop() {
  if (ledDelay.justFinished()) {
    ledDelay.repeat();
    if (led1.isOn()) {
      led1.off();
      led2.on();
    } else {
      led1.on();
      led2.off();
    }
  }
}