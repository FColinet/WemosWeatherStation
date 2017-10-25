/*
  WeatherStation.h
  Created by Florent Colinet, August 1, 2017.
*/
#ifndef WeatherStation_h

  #define WeatherStation_h

  #include <EnvironmentCalculations.h>
  #include <BME280I2C.h>

  class WeatherStation
  {
    private:
      const String Version = "1.1.0";
      int anemometer_count = 0;
      void anemometer_pulse(void);
    public:
      WeatherStation(void);
      void initialize(void);

      String getName(void);
      String getVersion(void);

      float voltage(void);

      float thermometer_c(void);
      float thermometer_f(void);

      float dew_point_c(void);
      float dew_point_f(void);

      float hygrometer(void);

      float atmospheric_pressure(void);

      float altimeter_m(void);
      float altimeter_ft(void);

      float anemometer(void);
      float weathercock(void);
      float rain_gauge(void);
  };

#endif


