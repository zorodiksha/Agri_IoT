/*
  MQUnifiedsensor Library - reading an MQ2

  Demonstrates the use of an MQ2 sensor.
  Library originally added 01 May 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 23 May 2019
  by Miguel Califa 

  Updated library usage
  modified 26 March 2020
  by Miguel Califa 
  Wiring:
  https://github.com/miguel5612/MQSensorsLib_Docs/blob/master/static/img/MQ_Arduino.PNG
  Please make sure the Arduino A0 pin represents the analog input configured on #define Pin

 This example code is in the public domain.

*/

// Include the library
#include <MQUnifiedsensor.h>

/************************Hardware Related Macros************************************/
#define Type                    "MQ-2" // MQ2
#define Voltage_Resolution      5
#define ADC_Bit_Resolution      12   // For ESP32 Dev Module
#define RatioMQ2CleanAir        9.83 // RS / R0 = 9.83 ppm 

#define Board                   "ESP32 Dev Module"
#define Pin                     15  // Analog input 3 of your Arduino

/*****************************Globals***********************************************/
MQUnifiedsensor MQ2(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);

void setup() {
  // Init the serial port communication - to debug the library
  Serial.begin(9600); // Init serial port

  // Set math model to calculate the PPM concentration and the value of constants
  MQ2.setRegressionMethod(1); // _PPM = a * ratio^b
  MQ2.setA(574.25);
  MQ2.setB(-2.222); // Configure the equation to calculate LPG concentration

  /*****************************  MQ Init ********************************************/
  // Remarks: Configure the pin of Arduino as input.
  /************************************************************************************/
  MQ2.init();

  /*****************************  MQ Calibration ********************************************/
  // Explanation: 
  // In this routine, the sensor will measure the resistance of the sensor supposedly before being pre-heated
  // and on clean air (Calibration conditions), setting up R0 value.
  // We recommend executing this routine only on setup in laboratory conditions.
  // This routine does not need to be executed on each restart; you can load your R0 value from EEPROM.
  // Acknowledgements: https://jayconsystems.com/blog/understanding-a-gas-sensor
  Serial.print("Calibrating please wait.");
  float calcR0 = 0;
  for (int i = 1; i <= 10; i++) {
    MQ2.update(); // Update data, the Arduino will read the voltage from the analog pin
    calcR0 += MQ2.calibrate(RatioMQ2CleanAir);
    Serial.print(".");
  }
  MQ2.setR0(calcR0 / 10);
  Serial.println("  done!.");
  
  if (isinf(calcR0)) {
    Serial.println("Warning: Connection issue, R0 is infinite (Open circuit detected) please check your wiring and supply");
    while (1);
  }
  if (calcR0 == 0) {
    Serial.println("Warning: Connection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply");
    while (1);
  }
  /*****************************  MQ Calibration ********************************************/

  MQ2.serialDebug(true);
}

void loop() {
  MQ2.update(); // Update data, the Arduino will read the voltage from the analog pin
  MQ2.readSensor(); // Sensor will read PPM concentration using the model, a and b values set previously or from the setup
  MQ2.serialDebug(); // Will print the table on the serial port
  delay(500); // Sampling frequency
}
