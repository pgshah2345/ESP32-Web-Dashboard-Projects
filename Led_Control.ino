#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Samsung F 54";
const char* password = "pgshah_2304";

WebServer server(80);

#define LED_PIN 2

void handleRoot() {
  String html =
  "<!DOCTYPE html><html>"
  "<head><title>ESP32 LED Control</title></head>"
  "<body style='text-align:center;font-family:Arial;'>"
  "<h1>ESP32 LED Dashboard</h1>"
  "<a href='/on'><button style='width:150px;height:60px;font-size:20px;'>ON</button></a><br><br>"
  "<a href='/off'><button style='width:150px;height:60px;font-size:20px;'>OFF</button></a>"
  "</body></html>";

  server.send(200, "text/html", html);
}

void ledOn() {
  digitalWrite(LED_PIN, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void ledOff() {
  digitalWrite(LED_PIN, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32 Started");

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  WiFi.begin(ssid, password);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", ledOn);
  server.on("/off", ledOff);

  server.begin();
}

void loop() {
  server.handleClient();
}
