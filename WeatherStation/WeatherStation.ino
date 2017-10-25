#include "WebServerConfig.h"
#include "WeatherStation.h"

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

MDNSResponder mdns;
ESP8266WebServer webserver(WEBSERVER_PORT);

WeatherStation ws;

void setup() {
  Serial.begin(9600);
  while(!Serial) {
    ;
  } // Wait

  ws.initialize();

  Serial.print("MAC address    ");
  Serial.println(WiFi.macAddress());

  WiFi.begin(NETWORK_SSID, NETWORK_PASSWORD);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.print("IP address     ");
  Serial.println(WiFi.localIP());
  Serial.print("RSSI           ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");
  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }

  webserver.on("/", handleRoot);
  webserver.on("/weather", handleWeather);
  webserver.onNotFound(handleNotFound);

  webserver.begin();
  Serial.println("HTTP server started");
}

void loop() {
  webserver.handleClient();
}

void handleRoot() {
  String message = "<h1>ESP8266 Web Server</h1>\n";
  message += "Go to /weather to request values.";
  webserver.send(200, "text/html", message);
}

void handleWeather() {
  String message = "{";
  message += "\"name\":\"" + ws.getName() + "\",";
  message += "\"version\":\"" + ws.getVersion() + "\",";
  message += "\"battery\":" + String(ws.voltage()) + ",";
  message += "\"weather\":{";
  message += "\"temperature\":{";
  message += "\"celcius\":" + String(ws.thermometer_c()) + ",";
  message += "\"fahrenheit\":" + String(ws.thermometer_f());
  message += "},";
  message += "\"dew_point\":{";
  message += "\"celcius\":" + String(ws.dew_point_c()) + ",";
  message += "\"fahrenheit\":" + String(ws.dew_point_f());
  message += "},";
  message += "\"hygrometry\":" + String(ws.hygrometer()) + ",";
  message += "\"atmospheric_pressure\":" + String(ws.atmospheric_pressure()) + ",";
  message += "\"altitude\":{";
  message += "\"meters\":" + String(ws.altimeter_m()) + ",";
  message += "\"feet\":" + String(ws.altimeter_ft());
  message += "},";
  message += "\"wind_speed\":" + String(ws.anemometer()) + ",";
  message += "\"wind_direction\":" + String(ws.weathercock()) + ",";
  message += "\"pluviometry\":" + String(ws.rain_gauge());
  message += "}}";
  webserver.send(200, "application/json", message);
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += webserver.uri();
  message += "\nMethod: ";
  message += (webserver.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += webserver.args();
  message += "\n";
  for (uint8_t i=0; i<webserver.args(); i++){
    message += " " + webserver.argName(i) + ": " + webserver.arg(i) + "\n";
  }
  webserver.send(404, "text/plain", message);
}

