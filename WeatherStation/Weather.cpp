/*
  Weather.cpp
  Created by Florent Colinet, August 1, 2017.
*/

#include "Math.h"

#include "WeatherConfig.h"
#include "Weather.h"

/* Include for BME280 */
#include "SparkFunBME280.h"

BME280 bme_sensor;

Weather::Weather(void) {
  bme_sensor.settings.I2CAddress = 0x76;
  bme_sensor.settings.runMode = 3; 
  bme_sensor.settings.tStandby = 0;
  bme_sensor.settings.filter = 0;
  if(!WEATHER_THERMOMETER_ENABLED) {
    bme_sensor.settings.tempOverSample = 1;
  }
  if(!WEATHER_HYGROMETER_ENABLED) {
    bme_sensor.settings.humidOverSample = 1;
  }
  if(!WEATHER_ATMOSPHERIC_PRESSURE_ENABLED) {
    bme_sensor.settings.pressOverSample = 1;
  }
  bme_sensor.begin();
}

/*
 * Return the temperature in Celsius (°C) degrees
 */
float Weather::thermometer() {
  if(!WEATHER_THERMOMETER_ENABLED) {
    return 0;
  }
  return bme_sensor.readTempC();
}

/*
 * Return the relative humidity in percent (%)
 */
float Weather::hygrometer() {
  if(!WEATHER_HYGROMETER_ENABLED) {
    return 0;
  }
  return bme_sensor.readFloatHumidity();
}

/*
 * Return the atmospheric pressure in hectopascal (hPa)
 */
float Weather::atmospheric_pressure() {
  if(!WEATHER_ATMOSPHERIC_PRESSURE_ENABLED) {
    return 0;
  }
  return bme_sensor.readFloatPressure();
}

/*
 * Return the altitude in meter (m)
 */
float Weather::altimeter() {
  if(!WEATHER_ATMOSPHERIC_PRESSURE_ENABLED) {
    return 0;
  }
  return bme_sensor.readFloatAltitudeMeters();
}

/*
 * Return the wind speed in meter by second (m/s)
 */
float Weather::anemometer() {
  if(!WEATHER_ANEMOMETER_ENABLED) {
    return 0;
  }
  return 1;
}

/*
 * Return the wind direction in degrees (°) : North at 0°
 */
float Weather::weathercock() {
  if(!WEATHER_WEATHERCOCK_ENABLED) {
    return 0;
  }
  return 1;
}

/*
 * Return the rain quantity in millimeter (mm)
 */
float Weather::rain_gauge() {
  if(!WEATHER_RAIN_GAUGE_ENABLED) {
    return 0;
  }
  return 1;
}

/*
 * Return the dew point in Celsius (°C) degrees
 */
double Weather::dew_point() {
  if(!WEATHER_THERMOMETER_ENABLED || !WEATHER_HYGROMETER_ENABLED) {
    return 0;
  }
  /*
   * T  : temperature in Celsius (°C) degrees
   * Rh : Relative Humidity in percent (%)
   * B  : Intermediate value (no units)
   * D  : Dewpoint in Celsius (°C) degrees
   */
  float T = thermometer();
  float Rh = hygrometer();
  double B = (log(Rh / 100) + ((17.27 * T) / (237.3 + T))) / 17.27;
  double D = (237.3 * B) / (1 - B);
  return D;
}

