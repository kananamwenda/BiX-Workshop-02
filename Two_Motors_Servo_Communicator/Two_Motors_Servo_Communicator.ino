#include <BluetoothSerial.h>
BluetoothSerial BTSerial; 
#include <ESP32Servo.h>

Servo servo1;
Servo servo2;
bool dance = false;

#define FLEX_SENSOR_PIN 12

// the setup routine runs on start and once when you press reset:
void setup() {
  //change Name_Board_Here to something distinct and memorable -- this is the device name you will  see when Bluetooth paring
  BTSerial.begin("ESP32_Trish");
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  servo1.attach(12);  //Connect Servo1 (PMW)Orange Wire to Pin 12
  servo2.attach(27);  //Connect Servo1 (PMW)Orange Wire to Pin 27
}

// the loop routine runs over and over again forever:
void loop() {
  checkForDance();
  if (dance) {
    sweepServo(servo1);
  }
  checkForDance();
  if (dance) {
    sweepServo(servo2);
  }
}

void checkForDance() {
  while (BTSerial.available() > 0) {
    String data = BTSerial.readStringUntil('\n');
    Serial.println(data);
    if (data == "dance") {
      dance = true;
    } else if (data == "stop") {
      dance = false;
    }
  }
}
void sweepServo(Servo &servo) {
  // Sweep the servo from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    servo.write(angle);
    delay(15);
  }

  delay(1000);  // Wait for 1 second

  // Sweep the servo back from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    servo.write(angle);
    delay(15);
  }

  delay(1000);  // Wait for 1 second
}
