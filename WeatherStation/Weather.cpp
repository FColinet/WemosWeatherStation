/*
  Weather.cpp - Library of tools.
  Created by Florent Colinet, August 1, 2017.
*/

#include "Arduino.h"
#include "Math.h"
#include "Weather.h"

/*
 * 
 */
Weather::Weather() {
}

float Weather::dew_point(float T, float Rh) {  
  /*
   * T  : temperature in celsius (C)
   * Rh : Relative Humidity in percent (%)
   * B  : Intermediate value (no units)
   * D  : Dewpoint in Centigrade (C) degrees
   */

  float B = (log(Rh / 100) + ((17.27 * T) / (237.3 + T))) / 17.27;
  float D = (237.3 * B) / (1 - B);
  return D;
}

