#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Samsung F 54";
const char* password = "pgshah_2304";

WebServer server(80);

#define IN1 2
#define IN2 4

void handleRoot() {
  String html =
  "<!DOCTYPE html><html>"
  "<head><title>ESP32 Fan Control</title></head>"
  "<body style='text-align:center;font-family:Arial;'>"
  "<h1>ESP32 Fan Dashboard</h1>"
  "<a href='/on'><button style='width:150px;height:60px;font-size:20px;'>FAN ON</button></a><br><br>"
  "<a href='/off'><button style='width:150px;height:60px;font-size:20px;'>FAN OFF</button></a>"
  "</body></html>";

  server.send(200, "text/html", html);
}

void fanOn() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  server.sendHeader("Location", "/");
  server.send(303);
}

void fanOff() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

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
  server.on("/on", fanOn);
  server.on("/off", fanOff);

  server.begin();
}

void loop() {
  server.handleClient();
}
