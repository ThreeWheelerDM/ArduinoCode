#include <Wire.h>
#include <ESP8266WiFi.h>

IPAddress server(192, 168, 4, 1);
WiFiClient client;
char *ssid = "Server_AP";
char *password = "12345678";
void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(115200);           // start serial for output
  Serial.println("\nConnecting... " );
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)  {
    delay(500);
    Serial.print(".");
  }
  Serial.printf("\nConnected to: %s\n", ssid);
  Serial.printf("Client IP %s\n", WiFi.localIP().toString().c_str());
}

void loop()
{  
  client.connect(server, 93);
  Serial.println("Connected to Server!");
  client.println("Hallo Server! Schläfst du?\n");
  String answer = client.readStringUntil('\r');
  Serial.printf("Antwort vom Server: %s\n\n", answer.c_str());
  client.flush();
  delay(2000);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}



