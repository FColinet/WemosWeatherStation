/*
  Weather.h
  Created by Florent Colinet, August 1, 2017.
*/
#ifndef Weather_h

  #define Weather_h

  #include "Arduino.h"

  class Weather
  {
    private:
      char name;
    public:
      Weather(void);
      float thermometer();
      float hygrometer();
      float altimeter();
      float atmospheric_pressure();
      float anemometer();
      float weathercock();
      float rain_gauge();
      double dew_point();
  };

#endif

