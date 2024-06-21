// Buzzer Pin Configuration
const int buzzerPin = 27; // You can choose any digital pin

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  // Generate sound for 100 cycles
  for (unsigned char i = 0; i < 80; i++) {
    digitalWrite(buzzerPin, HIGH); // Turn the buzzer ON
    delay(1); // Delay of 1ms (sets the frequency)
    digitalWrite(buzzerPin, LOW); // Turn the buzzer OFF
    delay(1); // Delay of 1ms
  }
}

