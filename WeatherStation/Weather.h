/*
  Weather.h - Library of tools.
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
      Weather();
      float dew_point(float, float);
  };

#endif
