#include "Weather.h"

Weather weather;

void setup() {
  weather.initialize();

  Serial.print("Voltage        ");
  Serial.println(weather.voltage());
  Serial.print("Temperature    ");
  Serial.println(weather.thermometer());
  Serial.print("Humidity       ");
  Serial.println(weather.hygrometer());
  Serial.print("Pressure       ");
  Serial.println(weather.atmospheric_pressure());
  Serial.print("Altitude       ");
  Serial.println(weather.altimeter());
  Serial.print("Dew point      ");
  Serial.println(weather.dew_point());
  Serial.print("Wind speed     ");
  Serial.println(weather.anemometer());
  Serial.print("Wind direction ");
  Serial.println(weather.weathercock());
  Serial.print("Rain quantity  ");
  Serial.println(weather.rain_gauge());
}

void loop() {
}

