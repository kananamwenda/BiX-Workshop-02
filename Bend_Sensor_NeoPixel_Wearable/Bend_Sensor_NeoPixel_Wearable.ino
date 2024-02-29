#include <Adafruit_NeoPixel.h>

#define FLEX_SENSOR_PIN 27  //Bend sensor is connected to pin 27
#define NEOPIXEL_PIN 0      //NeoPixel is on pin GPIO0
#define NUM_PIXELS 1        // Number of Neopixels

Adafruit_NeoPixel pixels(NUM_PIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pinMode(FLEX_SENSOR_PIN, INPUT);
}

void loop() {
  // Read the value from the flex sensor
  int flexValue = analogRead(FLEX_SENSOR_PIN);

  // Map the flex sensor value to the color spectrum (adjust values according to your sensor)
  int red = map(flexValue, 0, 1023, 0, 255);
  int green = 0;
  int blue = map(flexValue, 0, 1023, 255, 0);

  // Can adjust the brightness between 0-255
  int brightness = 100;

  // Set the color and brightness of the Neopixel LED
  pixels.setPixelColor(0, pixels.Color(red, green, blue));  // Assuming only one Neopixel
  pixels.setBrightness(brightness);
  pixels.show();

  // Print flex sensor value for debugging
  Serial.print("Flex Sensor Value: ");
  Serial.println(flexValue);

  delay(100);  // Adjust delay according to your application
}


