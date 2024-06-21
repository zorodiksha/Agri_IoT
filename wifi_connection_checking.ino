#include <WiFi.h>

const char* ssid = "vivo Y22";
const char* password = "move1away2";

void setup() {
  Serial.begin(115200);
  Serial.println("Serial communication initialized");

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();

  // Print the ESP32's IP address after successful connection
  Serial.print("Connected to WiFi. IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Setup complete");
}

void loop() {
  // Your main code goes here
}
