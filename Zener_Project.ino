#include <Arduino.h>

// Wemos D1 Mini Pro A0 pin
const int ANALOG_PIN = A0;

// Voltage Divider Config
// ADC Max Value for ESP8266 is 1024 (10-bit)
// The A0 pin on Wemos D1 Mini Pro has an internal voltage divider (typically 220k:100k) 
// allowing it to measure up to ~3.2V-3.3V directly.
// HOWEVER, for 5V measurements, an EXTERNAL voltage divider is needed.
// This code assumes a scaling factor to convert the 0-1023 reading to actual Voltage.
// Calibration: Measure a known voltage, check the ADC reading, and adjust.
// Theoretical Factor for 3.3V max: 3.3 / 1023.0 ~= 0.0032258
// If using an external divider to measure up to 5V, the factor will be higher.
// Example: If 5.0V input gives 1023 reading -> Factor = 5.0/1023.0
const float VOLTAGE_SCALE_FACTOR = 5.0 / 1023.0; 

void setup() {
  Serial.begin(115200);
  // Wait for serial to stabilize
  delay(1000);
  Serial.println("Zener Diode Voltage Tester Initialized");
  Serial.println("Time(ms),ADC_Value,Voltage_V");
  
  pinMode(ANALOG_PIN, INPUT);
}

void loop() {
  int adcValue = analogRead(ANALOG_PIN);
  float voltage = adcValue * VOLTAGE_SCALE_FACTOR;

  Serial.print(millis());
  Serial.print(",");
  Serial.print(adcValue);
  Serial.print(",");
  Serial.println(voltage, 4); // 4 decimal places

  delay(500);
}
