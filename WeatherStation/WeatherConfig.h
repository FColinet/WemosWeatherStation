/*
  WeatherConfig.h
  Created by Florent Colinet, August 2, 2017.
*/
#ifndef WeatherConfig_h

  #define WeatherConfig_h
  
  /*
   * Weather station settings
   */

  const char* WEATHER_STATION_NAME = "My weather station";

  /* ================================================================================ */

  /*
  * Network settings
  */

  const char* NETWORK_SSID = "SSID";
  const char* NETWORK_PASSWORD = "PASSWORD";

  /* ================================================================================ */

  /*
  * Voltage settings
  */

  const int VOLTAGE_PIN = 0; /* A0 */
  const float VOLTAGE_MULTIPLIER = 0.00496f;

  /* ================================================================================ */

  /*
  * BME280 settings
  */

  const bool BME280_ENABLED = false;
  const int BME280_SDA = 4; /* D2 */
  const int BME280_SCL = 5; /* D1 */
  const uint8_t BME280_PRESSURE_UNIT = 0x1; /* 0x0 = Pa (B000), 0x1 = hPa (B001), 0x2 = Hg (B010), 0x3 = atm (B011), 0x4 = bar (B100), 0x5 = torr (B101), 0x6 = N/m^2 (B110), 0x7 = psi (B111) */
  const bool BME280_METRIC = true;

  /* ================================================================================ */

  /*
  * Anemometer settings
  */

  const bool ANEMOMETER_ENABLED = false;
  const int  ANEMOMETER_PIN = 16; /* D0 */

  /* ================================================================================ */

  /*
  * Wheatercock settings
  */

  const bool WEATHERCOCK_ENABLED = false;
  const int  WEATHERCOCK_PIN_1 = 2; /* D4 */
  const int  WEATHERCOCK_PIN_2 = 14; /* D5 */
  const int  WEATHERCOCK_PIN_3 = 12; /* D6 */
  const int  WEATHERCOCK_PIN_4 = 13; /* D7 */
  const int  WEATHERCOCK_PIN_5 = 15; /* D8 */

  /* ================================================================================ */

  /*
  * Rain gauge settings
  */

  const bool RAIN_GAUGE_ENABLED = false;
  const int  RAIN_GAUGE_PIN = 0; /* D3 */

  /* ================================================================================ */

  /*
  * Weather Underground settings
  */

  const bool WEATHER_UNDERGROUND_ENABLED = false;
  const char* WEATHER_UNDERGROUND_URL = "https://weatherstation.wunderground.com/weatherstation/updateweatherstation.php";
  const char* WEATHER_UNDERGROUND_ID = "ID";
  const char* WEATHER_UNDERGROUND_PASSWORD = "PASSWORD";

#endif

