#include "Weather.h"

Weather weather;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Dew point : ");
  Serial.println(weather.dew_point(20, 57));
}

void loop() {
  // put your main code here, to run repeatedly:

}
