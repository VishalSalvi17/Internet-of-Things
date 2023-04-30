#include <ESP8266WiFi.h>
#include <Wire.h>
#include<DHT.h>
String apiKey = "WQTN94MLHW9X0XV1";     //  Enter your Write API key from ThingSpeak
#define WIFI_SSID       "AndroidSP21"
#define WIFI_PASSWORD   "11223344"
#define DHTPIN 0  
const char* server = "api.thingspeak.com";
WiFiClient client;

DHT dht(DHTPIN, DHT11);
void setup() 
{
// initialize the serial communication:
    Serial.begin(9600);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    pinMode(D5, INPUT); // Setup for leads off detection LO +
    pinMode(D6, INPUT); // Setup for leads off detection LO -
 
}
 
void loop() {
  float t = dht.readTemperature();
 
if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
Serial.println('!');
}
else{
// send the value of analog input 0:
Serial.println(analogRead(A0));
}

                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(t);
                             
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("ECG: ");
                             Serial.print(t);
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);
}
