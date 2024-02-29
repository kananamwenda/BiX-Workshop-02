#include <BluetoothSerial.h>
BluetoothSerial BTSerial;

#define FLEX_SENSOR_PIN 27

// the setup routine runs on start and once when you press reset:
void setup() {
  //change Name_Board_Here to something distinct and memorable -- this is the device name you will see when Bluetooth pairing
  BTSerial.begin("ESP32_Trish");
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(FLEX_SENSOR_PIN, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int Reading = analogRead(FLEX_SENSOR_PIN);
  BTSerial.println(Reading);
  Serial.println(Reading);
  delay(100);
}
