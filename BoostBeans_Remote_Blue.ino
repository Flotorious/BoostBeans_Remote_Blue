/*

    Project Schaukasten

    Boost Beans Technology Porbe

    Blue Remote Control with one Button


   created 10 June 2017 FG


*/

#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

long timestamp = 0; // for making the LED blink when the button is pressed.
boolean isLEDOn = false;

void setup() {

  Serial.begin(9600);
  mySwitch.enableTransmit(2);

  pinMode(7, INPUT); // Button
  digitalWrite(7, HIGH);
  pinMode(6, OUTPUT); // Control LED. Set high when device is switched on.
  digitalWrite(6, HIGH);
}

void loop() {
  if (digitalRead(7) == LOW) {
    mySwitch.send(65, 24);
    Serial.println("this signal will make the remote bean vibrate");
    if (abs(millis() - timestamp) > 250) {
      timestamp = millis();
      toggleLED();
    }
  } else {
    digitalWrite(6, HIGH);
  }
  delay(20);
}

void toggleLED() {
  if (isLEDOn) {
    digitalWrite(6, HIGH);
    isLEDOn = false;
  } else {
    digitalWrite(6, LOW);
    isLEDOn = true;
  }
  
  
}

