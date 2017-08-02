/*
  WeatherConfig.h
  Created by Florent Colinet, August 2, 2017.
*/
#ifndef WeatherConfig_h

  #define WeatherConfig_h
  
  const char* WEATHER_STATION_NAME = "My weather station";

  /* Connected on SDA/SCL pins */
  const bool WEATHER_THERMOMETER_ENABLED = false;
  const bool WEATHER_HYGROMETER_ENABLED = false;
  const bool WEATHER_ATMOSPHERIC_PRESSURE_ENABLED = false;

  /* Connected on a digital pin */
  const bool WEATHER_ANEMOMETER_ENABLED = false;
  const int  WEATHER_ANEMOMETER_PIN = 1;

  /* Connected on 5 digitals pins */
  const bool WEATHER_WEATHERCOCK_ENABLED = false;
  const int  WEATHER_WEATHERCOCK_PIN_1 = 3;
  const int  WEATHER_WEATHERCOCK_PIN_2 = 4;
  const int  WEATHER_WEATHERCOCK_PIN_3 = 5;
  const int  WEATHER_WEATHERCOCK_PIN_4 = 6;
  const int  WEATHER_WEATHERCOCK_PIN_5 = 7;

  /* Connected on a digital pin */
  const bool WEATHER_RAIN_GAUGE_ENABLED = false;
  const int  WEATHER_RAIN_GAUGE_PIN = 2;

#endif

