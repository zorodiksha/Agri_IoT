/*
  Capacitive Moisture Sensor with ESP32

  This sketch reads the analog output of a capacitive moisture sensor
  connected to an ESP32 and prints the moisture level to the serial monitor.

  The circuit:
   * Connect the capacitive moisture sensor VCC to the 3.3V pin on ESP32
   * Connect GND to GND
   * Connect AO (analog output) to an analog pin on ESP32 (e.g., A0)

  This example code is in the public domain.
*/

const int moisturePin = 32; // Analog pin for the capacitive moisture sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  int moistureLevel = analogRead(moisturePin);

  // Print the raw moisture level to the serial monitor
  Serial.print("Moisture Level: ");
  Serial.println(moistureLevel);

  // You can add logic here to interpret the moisture level and take appropriate actions

  delay(1000); // Delay for 1 second, adjust as needed
}
