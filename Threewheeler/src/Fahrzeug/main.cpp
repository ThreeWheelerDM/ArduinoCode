#include <Arduino.h>
#include <ESP8266WiFi.h>

char *ssid = "Server_AP";
char *pass = "12345678";

WiFiServer server(93);

IPAddress ip(192, 168, 4, 22);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);

// Gleichstrommotor 1

int GSM1 = 10;
int in1 = 9;
int in2 = 8;

// Gleichstrommotor 1

int GSM2 = 5;
int in3 = 7;
int in4 = 6;

void setup()
{
  Serial.begin(115200);
  Serial.print("\nSetting soft-AP ... \n");
  WiFi.config(ip, gateway, subnet);       // forces to use the fix IP
  WiFi.softAP(ssid, pass) ? Serial.println("WiFi.softAP Bereit!") : Serial.println("WiFi.softAP Fehler!");
  server.begin();

  pinMode(GSM1, OUTPUT);    
  pinMode(GSM2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}
void loop()
{
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client is there!");
    if (client.connected()) {
      Serial.println("Client connected!");
      String request = client.readStringUntil('\r');
      Serial.print("Nachricht vom Client: "); Serial.print(request);
      client.flush();
    }
    client.print("Hi client! I am listening.\r"); // sends the answer to the client
    client.flush();
    Serial.printf("Stations connected to soft-AP = %d\n\n", WiFi.softAPgetStationNum());
    client.stop();

  delay(10);
}




