/*
  DC Motor Control with ESP32 and L298N Motor Driver

  This sketch demonstrates how to control a DC motor using an ESP32
  and an L298N motor driver.

  Wiring:
   * Connect IN1 to a digital pin on ESP32 (e.g., GPIO 12)
   * Connect IN2 to a digital pin on ESP32 (e.g., GPIO 14)
   * Connect ENA to a PWM-capable digital pin on ESP32 (e.g., GPIO 5)
   * Connect OUT1 and OUT2 to the DC motor
   * Connect GND of ESP32, L298N, and DC motor together
   * Connect VCC of ESP32 to the motor driver's VCC
   * Connect VCC of L298N to an external power supply (e.g., 5V)
   * Connect GND of the external power supply to GND of L298N
   * Connect the positive terminal of the DC motor to the external power supply

  This example code is in the public domain.
*/

const int motorPin1 = 5; // IN1 pin
const int motorPin2 = 18; // IN2 pin
const int enablePin = 13;  // ENA (Enable A) pin (PWM)

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
}

void loop() {
  // Move the motor forward
  motorControl(true, 255); // true for forward, 255 for full speed
  delay(2000); // Run forward for 2 seconds

  // Stop the motor
  motorControl(false, 0);
  delay(1000); // Stop for 1 second

  // Move the motor backward
  motorControl(false, 255); // false for backward, 255 for full speed
  delay(2000); // Run backward for 2 seconds

  // Stop the motor
  motorControl(false, 0);
  delay(1000); // Stop for 1 second
}

// Function to control the DC motor
void motorControl(bool forward, int speed) {
  digitalWrite(motorPin1, forward ? HIGH : LOW);
  digitalWrite(motorPin2, forward ? LOW : HIGH);
  analogWrite(enablePin, speed);
}
