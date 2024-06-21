#include <dhtESP32-rmt.h>

const int moisturePin = 32;      // Analog pin for the capacitive moisture sensor
const int raindropPin = 25;      // Analog pin for the raindrop sensor

float temperature = 0.0;
float humidity = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read moisture level
  int moistureLevel = analogRead(moisturePin);
  Serial.print("Moisture Level: ");
  Serial.println(moistureLevel);

  // Read temperature and humidity
  uint8_t error = read_dht(temperature, humidity, 4, DHT11, 0);
  if (error) {
    Serial.println(error);
  } else {
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Humidity: ");
    Serial.println(humidity);
  }

  // Read raindrop sensor value
  int sensorValue = analogRead(raindropPin);
  Serial.print("Raindrop Sensor Value: ");
  Serial.println(sensorValue);

  // Add logic here to interpret sensor values and take appropriate actions

  delay(1000); // Delay for 1 second, adjust as needed
}
