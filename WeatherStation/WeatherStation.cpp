/*
  WeatherStation.cpp
  Created by Florent Colinet, August 1, 2017.
*/
#include "WeatherStation.h"
#include "WeatherStationConfig.h"

#include <Math.h>
#include <Wire.h>

Adafruit_BME280 bme_sensor;

WeatherStation::WeatherStation(void) {
}

void WeatherStation::initialize() {
  Serial.println("");
  Serial.println(WEATHER_STATION_NAME);
  Serial.println("");

  /* ================================================================================ */

  Serial.print("BME280         ");
  Serial.println(BME280_ENABLED?"Enabled":"Disabled");
  Serial.print("Anemometer     ");
  Serial.println(ANEMOMETER_ENABLED?"Enabled":"Disabled");
  Serial.print("Weathercock    ");
  Serial.println(WEATHERCOCK_ENABLED?"Enabled":"Disabled");
  Serial.print("Rain gauge     ");
  Serial.println(RAIN_GAUGE_ENABLED?"Enabled":"Disabled");

  if(BME280_ENABLED) {
    Wire.begin(BME280_SDA, BME280_SCL);
    while(!bme_sensor.begin()){
      Serial.println("Could not find BME280 sensor!");
      delay(500);
    }
  }

  if(ANEMOMETER_ENABLED) {
    pinMode(ANEMOMETER_PIN, INPUT);
  }

  if(WEATHERCOCK_ENABLED) {
    pinMode(WEATHERCOCK_PIN_1, INPUT);
    pinMode(WEATHERCOCK_PIN_2, INPUT);
    pinMode(WEATHERCOCK_PIN_3, INPUT);
    pinMode(WEATHERCOCK_PIN_4, INPUT);
    pinMode(WEATHERCOCK_PIN_5, INPUT);
  }

  if(RAIN_GAUGE_ENABLED) {
    pinMode(RAIN_GAUGE_PIN, INPUT);
  }

  Serial.println("");

}

/*
 * Return the name
 */
String WeatherStation::getName() {
  return WEATHER_STATION_NAME;
}

/*
 * Return the version
 */
String WeatherStation::getVersion() {
  return Version;
}

/*
 * Return the voltage in Volt (V)
 */
float WeatherStation::voltage() {
  return analogRead(VOLTAGE_PIN) * VOLTAGE_MULTIPLIER;
}

/*
 * Return the temperature in Celsius (°C) degrees
 */
float WeatherStation::thermometer() {
  if(!BME280_ENABLED) {
    return 0;
  }
  return bme_sensor.readTemperature();
}

/*
 * Return the dew point in Celsius (°C) degrees
 */
float WeatherStation::dew_point() {
  if(!BME280_ENABLED) {
    return 0;
  }
  float temp = bme_sensor.readTemperature();
  float hum = bme_sensor.readHumidity();
  float k;
  k = log(hum / 100) + (17.62 * temp) / (243.12 + temp);
  return 243.12 * k / (17.62 - k);
}

/*
 * Return the relative humidity in percent (%)
 */
float WeatherStation::hygrometer() {
  if(!BME280_ENABLED) {
    return 0;
  }
  return bme_sensor.readHumidity();
}

/*
 * Return the atmospheric pressure in hectopascal (hPa)
 */
float WeatherStation::atmospheric_pressure() {
  if(!BME280_ENABLED) {
    return 0;
  }
  return bme_sensor.readPressure() / 100.0F;
}

/**
 *  \brief Return the altitude in meters (m)
 */
float WeatherStation::altimeter() {
  if(!BME280_ENABLED) {
    return 0;
  }
  return bme_sensor.readAltitude(BME280_SEA_LEVEL_PRESSURE);
}

/*
 * Return the wind speed in meter by second (m/s)
 */
float WeatherStation::anemometer() {
  if(!ANEMOMETER_ENABLED) {
    return 0;
  }
  attachInterrupt(digitalPinToInterrupt(ANEMOMETER_PIN), reinterpret_cast<void (*)()>(&WeatherStation::anemometer_pulse), LOW);
  return anemometer_count;
}

/*
 * Return the wind direction in degrees (°) : North at 0°
 */
float WeatherStation::weathercock() {
  if(!WEATHERCOCK_ENABLED) {
    return 0;
  }
  return 1;
}

/*
 * Return the rain quantity in millimeter (mm)
 */
float WeatherStation::rain_gauge() {
  if(!RAIN_GAUGE_ENABLED) {
    return 0;
  }
  int val = digitalRead(RAIN_GAUGE_PIN);
  return val;
}

/*
 * 
 */
void WeatherStation::anemometer_pulse() {
  anemometer_count++;
}

