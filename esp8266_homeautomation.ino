#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
//#include <FS.h>/

ESP8266WebServer server;
char* ssid = "";
char* password = "";

int turnOffAfter = 0;         // time duration in seconds
unsigned long timestamp = 0;  // time at which on duration is set

//////////////////////////
uint8_t fan1        = D0;
uint8_t fan2        = D1;
uint8_t tubelight   = D2;
uint8_t ledBulb     = D3;
uint8_t waterBell   = D4;
uint8_t doorLight   = D5;
uint8_t chandelier  = D6;
uint8_t socket  	  = D7;
///////////////////////////

void setup() {

  // All pins initially LOW
  ////////////////////////////
  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  digitalWrite(D5, HIGH);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);
  ////////////////////////////

  pinMode(fan1, OUTPUT);
  pinMode(fan2, OUTPUT);
  pinMode(tubelight, OUTPUT);
  pinMode(ledBulb, OUTPUT);
  pinMode(waterBell, OUTPUT);
  pinMode(doorLight, OUTPUT);
  pinMode(chandelier, OUTPUT);
  pinMode(socket, OUTPUT);

  WiFi.mode(WIFI_STA);        // setting to station mode only,
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", homepage);
  server.on("/fan1", toggle_fan1);
  server.on("/fan2", toggle_fan2);
  server.on("/tubelight", toggle_tubelight);
  server.on("/ledBulb", toggle_ledBulb);
  server.on("/watertank", toggle_watertank);
  server.on("/doorLight", toggle_doorLight);
  server.on("/chandelier", toggle_chandelier);
  server.on("/socket", toggle_socket);

//  server.on("/fan.png", fan_image);
//  server.on("/tubelight.png", tubelight_image);
//  server.on("/lamp.png", lamp_image);
//  server.on("/socket.png", socket_image);
//  server.on("/watertank.png", watertank_image);
//  server.on("/chandelier.png", chandelier_image);
//  server.on("/door.png", door_image);

  server.begin();

///  SPIFFS.begin();
}

void loop() {
  server.handleClient();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  delay(100);
}


/////////////////////////////////////////////////////////
//      SPIFFS
/////////////////////////////////////////////////////////
//void homepage()
//{
//  File file = SPIFFS.open("/index.html.gz", "r");
//  size_t sent = server.streamFile(file, "text/html");
//}
//
//void fan_image()
//{
//  File file = SPIFFS.open("/fan.png", "r");
//  size_t sent = server.streamFile(file, "image/jpeg");
//}
//
//void tubelight_image () {
//  File file = SPIFFS.open("/tubelight.png", "r");
//  size_t sent = server.streamFile(file, "image/jpeg");
//}
//
//void lamp_image () {
//  File file = SPIFFS.open("/lamp.png", "r");
//  size_t sent = server.streamFile(file, "image/jpeg");
//}
//
//void socket_image () {
//  File file = SPIFFS.open("/socket.png", "r");
//  size_t sent = server.streamFile(file, "image/jpeg");
//}
//
//void watertank_image () {
//  File file = SPIFFS.open("/watertank.png", "r");
//  size_t sent = server.streamFile(file, "image/jpeg");
//}
//
//void chandelier_image () {
//  File file = SPIFFS.open("/chandelier.png", "r");
//  size_t sent = server.streamFile(file, "image/jpeg");
//}
//
//void door_image () {
//  File file = SPIFFS.open("/door.png", "r");
//  size_t sent = server.streamFile(file, "image/jpeg");
//}
///////////////////////////////////////////////////////////

void homepage(){
 server.send(200, "text/plain", "Running");
}

void toggle_fan1() {
  digitalWrite(fan1, !digitalRead(fan1));
  server.send(204);
}

void toggle_fan2() {
  digitalWrite(fan2, !digitalRead(fan2));
  server.send(204);
}

void toggle_tubelight() {
  digitalWrite(tubelight, !digitalRead(tubelight));
  server.send(204);
}

void toggle_ledBulb() {
  digitalWrite(ledBulb, !digitalRead(ledBulb));
  server.send(204);
}

void toggle_watertank() {
  digitalWrite(waterBell, !digitalRead(waterBell));
  server.send(204);
}

void toggle_doorLight() {
  digitalWrite(doorLight, !digitalRead(doorLight));
  server.send(204);
}

void toggle_chandelier() {
  digitalWrite(chandelier, !digitalRead(chandelier));
  server.send(204);
}

void toggle_socket() {
  digitalWrite(socket, !digitalRead(socket));
  server.send(204);
}
