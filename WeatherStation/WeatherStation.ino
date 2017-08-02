#include "Weather.h"

Weather weather;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){}
  
  weather.initialize();
  
  Serial.print("Temperature : ");
  Serial.println(weather.thermometer());
  Serial.print("Dew point : ");
  Serial.println(weather.dew_point());
}

void loop() {
  // put your main code here, to run repeatedly:

}

