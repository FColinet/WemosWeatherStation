/*
  Weather.cpp
  Created by Florent Colinet, August 1, 2017.
*/

#include <Math.h>
#include <Wire.h>

#include "WeatherConfig.h"
#include "Weather.h"

#include <BME280I2C.h>

#include <ESP8266WiFi.h>

BME280I2C bme_sensor;

Weather::Weather(void) {
}

void Weather::initialize() {
  Serial.begin(9600);
  while(!Serial) {
    ;
  } // Wait

  Serial.println("");
  Serial.println(WEATHER_STATION_NAME);
  Serial.println("");

  WiFi.begin(NETWORK_SSID, NETWORK_PASSWORD);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.print("MAC address    ");
  Serial.println(WiFi.macAddress());
  Serial.print("IP address     ");
  Serial.println(WiFi.localIP());

  Serial.print("BME280         ");
  Serial.println(BME280_ENABLED?"Enabled":"Disabled");
  Serial.print("Anemometer     ");
  Serial.println(ANEMOMETER_ENABLED?"Enabled":"Disabled");
  Serial.print("Weathercock    ");
  Serial.println(WEATHERCOCK_ENABLED?"Enabled":"Disabled");
  Serial.print("Rain gauge     ");
  Serial.println(RAIN_GAUGE_ENABLED?"Enabled":"Disabled");

  if(BME280_ENABLED) {
    while(!bme_sensor.begin(BME280_SDA, BME280_SCL)){
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
 * Return the voltage in Volt (V)
 */
float Weather::voltage() {
  return analogRead(VOLTAGE_PIN) * VOLTAGE_MULTIPLIER;
}

/*
 * Return the temperature in Celsius (°C) degrees
 */
float Weather::thermometer() {
  if(!BME280_ENABLED) {
    return 0;
  }
  return bme_sensor.temp(BME280_METRIC);
}

/*
 * Return the relative humidity in percent (%)
 */
float Weather::hygrometer() {
  if(!BME280_ENABLED) {
    return 0;
  }
  return bme_sensor.hum();
}

/*
 * Return the atmospheric pressure in hectopascal (hPa)
 */
float Weather::atmospheric_pressure() {
  if(!BME280_ENABLED) {
    return 0;
  }
  return bme_sensor.pres(BME280_PRESSURE_UNIT);
}

/*
 * Return the altitude in meter (m)
 */
float Weather::altimeter() {
  if(!BME280_ENABLED) {
    return 0;
  }
  return bme_sensor.alt(BME280_METRIC);
}

/*
 * Return the dew point in Celsius (°C) degrees
 */
float Weather::dew_point() {
  if(!BME280_ENABLED) {
    return 0;
  }
  return bme_sensor.dew(BME280_METRIC);
}

/*
 * Return the wind speed in meter by second (m/s)
 */
float Weather::anemometer() {
  if(!ANEMOMETER_ENABLED) {
    return 0;
  }
  attachInterrupt(digitalPinToInterrupt(ANEMOMETER_PIN), reinterpret_cast<void (*)()>(&Weather::anemometer_pulse), LOW);
  return anemometer_count;
}

/*
 * Return the wind direction in degrees (°) : North at 0°
 */
float Weather::weathercock() {
  if(!WEATHERCOCK_ENABLED) {
    return 0;
  }
  return 1;
}

/*
 * Return the rain quantity in millimeter (mm)
 */
float Weather::rain_gauge() {
  if(!RAIN_GAUGE_ENABLED) {
    return 0;
  }
  return 1;
}

/*
 * 
 */
void Weather::anemometer_pulse() {
  anemometer_count++;
}

