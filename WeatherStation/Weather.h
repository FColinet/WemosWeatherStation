/*
  Weather.h
  Created by Florent Colinet, August 1, 2017.
*/
#ifndef Weather_h

  #define Weather_h

  class Weather
  {
    public:
      Weather(void);
      float thermometer();
      float hygrometer();
      float atmospheric_pressure();
      float altimeter();
      float anemometer();
      float weathercock();
      float rain_gauge();
      double dew_point();
  };

#endif

