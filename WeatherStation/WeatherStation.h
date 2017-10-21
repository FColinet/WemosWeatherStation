/*
  WeatherStation.h
  Created by Florent Colinet, August 1, 2017.
*/
#ifndef WeatherStation_h

  #define WeatherStation_h

  #include <Math.h>
  #include <Wire.h>

  #include <BME280I2C.h>

  class WeatherStation
  {
    private:
      int anemometer_count = 0;
      void anemometer_pulse(void);
    public:
      WeatherStation(void);
      void initialize(void);
      String getName(void);
      String getVersion(void);

      float voltage(void);
      float thermometer(void);
      float hygrometer(void);
      float atmospheric_pressure(void);
      float altimeter(void);
      float dew_point(void);
      float anemometer(void);
      float weathercock(void);
      float rain_gauge(void);
  };

#endif

