#include <Arduino.h>
/*
  Catch the Lightning

  Runs a light down a row of lights by tunring on a light. After a
  moment it turns off the light and turns on the next light. It does
  this down a row of lights.

  A button will be set up to "catch" the light. This means that if a
  the button if pressed when the light is on the LED associated with
  the button, the light is caught.

  To start with the light will stop stop. When the button is pressed
  again it will continue down the line.
*/

const int startPin = 2;
const int BUTTON_PIN = 12;
const int ledQuantity = 6;
long interval = 100;
const int specialPin = startPin + ledQuantity - 1;  // The last light pin

unsigned long previousMillis = 0;
int currentPin = startPin;
bool isCaptured = false;

void setup() {
  Serial.begin(9600);

  // Iterate through the light pins and assign each pin as output
  for (int thisPin = startPin; thisPin < startPin + ledQuantity; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }

  pinMode(12, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop()
{
  if (isCaptured && !isButtonPressed(BUTTON_PIN))
  {
    return;
  }

  if (isCaptured && isButtonPressed(BUTTON_PIN))
  {
    isCaptured = false;
    return;
  }

  if (isPinSelected(BUTTON_PIN, specialPin))
  {
    Serial.println("log2");
    isCaptured = true;
    return;
  }

  if (isIntervalComplete(previousMillis, interval))
  {
    // Reset current interval
    unsigned long currentMillis = millis();
    previousMillis = currentMillis;

    // Turn off current pin and turn on next
    int nextPin = getNextPin(currentPin, startPin, ledQuantity);
    digitalWrite(currentPin, LOW);
    digitalWrite(nextPin, HIGH);
    currentPin = nextPin;
  }
}

bool isButtonPressed(int buttonPin)
{
  bool sensorVal = digitalRead(buttonPin);
  if (sensorVal == LOW)
  {
    return true;
  }
  return false;
}

bool isIntervalComplete(unsigned long previousMillis, int interval) {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    return true;
  }
  return false;
}

bool isButtonDebounceOn() {
  // TO DO
}

int getNextPin(int num, int start, int quantity) {
  // If it's the last pin return the first
  if (num == (start + quantity - 1)) {
    return start;
  }

  return num + 1;
}

bool isPinSelected(int buttonPin, int ledPin) {
  bool isButtonPressed = false;
  bool sensorVal = digitalRead(buttonPin);
  if (sensorVal == LOW) {
    isButtonPressed = true;
  }

  bool isPinOn = digitalRead(ledPin);

  if (isButtonPressed && isPinOn) {
    return true;
  } else {
    return false;
  }
}
