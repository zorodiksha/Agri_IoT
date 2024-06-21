#include <LiquidCrystal.h>
#include <dhtESP32-rmt.h>

LiquidCrystal lcd(13, 12, 14, 27, 26, 25); // Adjust these pin numbers based on your actual connections
float temperature = 0.0;
float humidity = 0.0;

void setup() {
  lcd.begin(16, 2);
  delay(1000);
  Serial.begin(115200);
}

void loop() {
  // Read DHT22 sensor data
  uint8_t error = read_dht(temperature, humidity, 21, DHT22, 0);

  // Display temperature and humidity on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");

  // Print temperature and humidity to Serial Monitor
  Serial.println("Temperature: " + String(temperature) + "°C, Humidity: " + String(humidity) + "%");

 
 delay(3000);
}
