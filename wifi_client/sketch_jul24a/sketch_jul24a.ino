#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char *ssid = "CWFOCD";
const char *password = "1234567890";

void handleRoot();          
void handleOPEN(); 
void handleCLOSE();
void handleNotFound();

void setup(void){
  Serial.begin(115200); 
  delay(100);
  Serial.println("WEB SERVER STARTED \n");

   WiFi.softAP(ssid, password); 
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());  

  if (MDNS.begin("esp8266")) {       
    Serial.println("mDNS responder started");
  } else {
    Serial.println("Error setting up MDNS responder!");
  }

  server.on("/", HTTP_GET, handleRoot);  
  server.on("/OPEN", HTTP_POST, handleOPEN);
  server.on("/CLOSE", HTTP_POST, handleCLOSE);
  server.onNotFound(handleNotFound); 

  server.begin();                          
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();                
}

void handleRoot() {                         
  server.send(200, "text/html", "<h1>You are connected to car OPEN/CLOSE module!!!</h1>\n\r<form action=\"/OPEN\" method=\"POST\"><input type=\"submit\" value=\"OPEN DOORS\"></form>\n\r<form action=\"/CLOSE\" method=\"POST\"><input type=\"submit\" value=\"CLOSE DOORS\"></form>");
}

void handleOPEN() {                 
const byte miBufferON[] = {0xA0, 0x01, 0x01, 0xA2};
Serial.write(miBufferON, sizeof(miBufferON));
  delay(1000);
  
const byte miBufferOFF[] = {0xA0, 0x01, 0x00, 0xA1};
Serial.write(miBufferOFF, sizeof(miBufferOFF));
  server.sendHeader("Location","/");       
  server.send(303);                         
}

void handleCLOSE() {                 
const byte miBufferON[] = {0xA0, 0x02, 0x01, 0xA3};
Serial.write(miBufferON, sizeof(miBufferON));
  delay(1000);
  
const byte miBufferOFF[] = {0xA0, 0x02, 0x00, 0xA2};
Serial.write(miBufferOFF, sizeof(miBufferOFF));
  server.sendHeader("Location","/");       
  server.send(303);                         
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}






