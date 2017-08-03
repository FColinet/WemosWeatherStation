/*
  WeatherStation.h
  Created by Florent Colinet, August 1, 2017.
*/
#ifndef WeatherStation_h

  #define WeatherStation_h

  class WeatherStation
  {
    private:
      int anemometer_count = 0;
      void anemometer_pulse(void);
    public:
      WeatherStation(void);
      void initialize(void);
      float voltage(void);
      int32_t wifi_strength(void);
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

