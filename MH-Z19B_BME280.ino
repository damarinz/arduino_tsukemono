#include "SparkFunBME280.h"
#include "Wire.h"
#include "SPI.h"

BME280 Sensor;

#define PWM_PIN 3

int prev_val = LOW;
long high_level_start = 0L;
long high_level_end = 0L;
long low_level_start = 0L;
long low_level_end = 0L;

void setup() {
  Serial.begin(9600);
  delay(500);

  // MH-Z19B setup
  pinMode(PWM_PIN, INPUT);

  // BME280 setup
  Sensor.settings.commInterface = I2C_MODE;
  Sensor.settings.I2CAddress = 0x76;
  Sensor.settings.runMode = 3;
  Sensor.settings.tStandby = 0;
  Sensor.settings.filter = 0;
  Sensor.settings.tempOverSample = 1 ;
  Sensor.settings.pressOverSample = 1;
  Sensor.settings.humidOverSample = 1;

  Serial.println("Starting BME280... ");
  delay(100);
  Sensor.begin();



}

void loop() {

  // MH-Z19B CO2 data
  long cycle_start_time = millis();
  int pin_in = digitalRead(PWM_PIN);

    delay(10);

  if (pin_in == HIGH) {
    if (prev_val == LOW) {
      long time_high = high_level_end - high_level_start;
      long time_low = low_level_end - low_level_start;
      long ppm = 5000 * (time_high - 0.002) / (time_high + time_low - 0.004);
      Serial.print("CO2: " + String(ppm));
      Serial.print(" ppm");
      Serial.print("\t Temp: ");
      Serial.print(Sensor.readTempC(), 2);
      Serial.print(" °C");
      Serial.print("\t Pressure: ");
      Serial.print(Sensor.readFloatPressure() / 100, 2);
      Serial.print(" hPa");
      Serial.print("\t Humidity: ");
      Serial.print(Sensor.readFloatHumidity(), 2);
      Serial.println(" %");


      high_level_start = cycle_start_time;
      prev_val = HIGH;
    } else {
      high_level_end = cycle_start_time;
    }
  } else {
    if (prev_val == HIGH) {
      low_level_start = cycle_start_time;
      prev_val = LOW;
    } else {
      low_level_end = cycle_start_time;
    }
  }
}