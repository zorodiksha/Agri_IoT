/*
  Pump Control with ESP32 and Relay Module

  This sketch demonstrates how to control a pump using an ESP32
  and a relay module.

  Wiring:
   * Connect the signal pin of the relay module to a digital pin on ESP32 (e.g., GPIO 12)
   * Connect the VCC and GND of the relay module to the appropriate power and ground sources
   * Connect one side of the pump to the normally open (NO) contact of the relay
   * Connect the other side of the pump to the power source
   * Connect the ground of the pump to the ground source

  This example code is in the public domain.
*/

const int relayPin = 23; // GPIO pin for the relay module

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Initialize the relay as off
}

void loop() {
  // Turn on the pump for 5 seconds
  pumpControl(true);
  delay(5000);

  // Turn off the pump for 2 seconds
  pumpControl(false);
  delay(2000);
}

// Function to control the pump using the relay module
void pumpControl(bool on) {
  digitalWrite(relayPin, on ? HIGH : LOW);
}
