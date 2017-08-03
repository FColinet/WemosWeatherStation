#include "WeatherStation.h"

WeatherStation ws;

void setup() {
  ws.initialize();

  Serial.print("Temperature    ");
  Serial.println(ws.thermometer());
  Serial.print("Humidity       ");
  Serial.println(ws.hygrometer());
  Serial.print("Pressure       ");
  Serial.println(ws.atmospheric_pressure());
  Serial.print("Altitude       ");
  Serial.println(ws.altimeter());
  Serial.print("Dew point      ");
  Serial.println(ws.dew_point());
  Serial.print("Wind speed     ");
  Serial.println(ws.anemometer());
  Serial.print("Wind direction ");
  Serial.println(ws.weathercock());
  Serial.print("Rain quantity  ");
  Serial.println(ws.rain_gauge());
}

void loop() {
  Serial.print("Voltage        ");
  Serial.println(ws.voltage());
  Serial.print("Wifi strength  ");
  Serial.println(ws.wifi_strength());
  delay(1000);
}

