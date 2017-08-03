/*
  Weather.h
  Created by Florent Colinet, August 1, 2017.
*/
#ifndef Weather_h

  #define Weather_h

  class Weather
  {
    private:
      int anemometer_count = 0;
      void anemometer_pulse(void);
    public:
      Weather(void);
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

