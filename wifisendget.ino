#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid = "xxx";
const char* password = "xxx";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(3000);
    Serial.println("Conectando...");
    Serial.println(WiFi.status());

  }
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {

    WiFiClient client;

    HTTPClient http;
    http.begin(client, "http://baraujo-001-site1.dtempurl.com/WeatherForecast");
    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
      Serial.println(httpCode);
    }
    http.end();
  }
  delay(3000);
}