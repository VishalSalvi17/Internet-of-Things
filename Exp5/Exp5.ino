#include <ESP8266WiFi.h>
const char* ssid = "PMPMi";
const char* password = "";
int LED = 2;
WiFiServer server(80);
void setup()
{
Serial.begin(115200);
pinMode(LED, OUTPUT);
digitalWrite(LED, LOW);

Serial.print("Connecting to the Network");
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("WiFi connected");
server.begin();
Serial.println("Server started");
Serial.print("IP Address of network: ");
Serial.println(WiFi.localIP());
Serial.println("/");
}
void loop()
{
WiFiClient client = server.available();
if (!client)
{

return;
}
Serial.println("Waiting for new client");
while(!client.available())
{
delay(1);
}

#include <ESP8266WiFi.h>
const char* ssid = "PMPMi";
const char* password = "";
int LED = 2;
WiFiServer server(80);
void setup()
{
Serial.begin(115200);
pinMode(LED, OUTPUT);
digitalWrite(LED, LOW);
Serial.print("Connecting to the Network");

WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("WiFi connected");
server.begin();
Serial.println("Server started");
Serial.print("IP Address of network: ");
Serial.println(WiFi.localIP());
Serial.println("/");
}
void loop()
{
WiFiClient client = server.available();
if (!client)
{
return;

}
Serial.println("Waiting for new client");
while(!client.available())
{
delay(1);
}
String request = client.readStringUntil('\r');
Serial.println(request);
client.flush();
int value = LOW;
if(request.indexOf("/LED=ON") != -1)
{
digitalWrite(LED, HIGH);
value = HIGH;
}
if(request.indexOf("/LED=OFF") != -1)
{
digitalWrite(LED, LOW);
value = LOW;

}
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("");
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<body style='background-color:yellow;'>");
client.print(" CONTROL LED: ");
if(value == HIGH)
{
client.print("OFF");
client.println("<img src='' width=100 height=100><br>");
}
else
{
client.print("ON");
client.println("<img src='https://media.geeksforgeeks.org/wp-content/uploads/ONbulb.jpg'width=100 height=100><br>");
}

client.println("<br><br>");
client.println("<a href=\"/LED=ON\"\"><button>OFF</button></a>");
client.println("<a href=\"/LED=OFF\"\"><button>ON</button></a><br />");
client.println("</body>");
client.println("</html>");

delay(1);

Serial.println("Client disconnected");

Serial.println("");

}
