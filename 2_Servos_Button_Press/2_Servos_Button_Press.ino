// Two servos controlled by button press code example
#include <ESP32Servo.h>

Servo servo1;
Servo servo2;

const int buttonPin = 38;  // The onboard button is connected to GPIO 38

void setup() {
  Serial.begin(115200);
  servo1.attach(12); //Connect Servo1 (PMW)Orange Wire to Pin 12
  servo2.attach(27); //Connect Servo2 (PMW)Orange Wire to Pin 27

  pinMode(buttonPin, INPUT_PULLUP);
}
// Create sweepServo Function
void sweepServo(Servo &servo) {
  // Sweep the servo from 0 to 180 degrees
  for (int angle = 180; angle <= 0; angle++) {
    servo.write(angle);
    delay(15);
  }
  delay(1000); // Wait for 1 second
  // Sweep the servo back from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    servo.write(angle);
    delay(15);
  }
  delay(1000); // Wait for 1 second
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    // Button is pressed, trigger servo movements
    sweepServo(servo1);
    delay(1000); // Wait for 1 second
    sweepServo(servo2);
    delay(1000); // Wait for 1 second
  }
}
