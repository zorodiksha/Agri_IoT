/*
  Ping))) Sensor with ESP32

  This sketch reads a PING))) ultrasonic
  rangefinder and returns the distance to the
  closest object in range. To do this, it sends a
  pulse to the sensor to initiate a reading, then
  listens for a pulse to return. The length of
  the returning pulse is proportional to the
  distance of the object from the sensor.

  The circuit:
   * +V connection of the PING))) attached to +5V
   * GND connection attached to ground
   * SIG connection attached to digital pin 7

  For ESP32:
   * Connect the +V of the PING))) sensor to the 5V pin on ESP32
   * Connect GND to GND
   * Connect SIG to the digital pin 7 (or any other GPIO pin)

  This example code is in the public domain.
*/

const int triggerPin = 26;  // GPIO pin for trigger
const int echoPin = 27;     // GPIO pin for echo

int inches = 0;
int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  cm = 0.01723 * readUltrasonicDistance(triggerPin, echoPin);
  inches = (cm / 2.54);
  
  Serial.print("Distance: ");
  Serial.print(inches);
  Serial.print(" inches, ");
  Serial.print(cm);
  Serial.println(" cm");
  
  delay(100); // Wait for 100 milliseconds
}
