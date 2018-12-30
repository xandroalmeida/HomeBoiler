#include <Arduino.h>
#include <ESP8266WiFi.h> 
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h> 
#include <Ticker.h>
#include <WiFiManager.h> 
#include <OneWire.h>
#include "TemperatureSensors.h"
#include "SoftRTC.h"

#define GPIO00  D3
#define GPIO02  D4
#define GPIO04  D2
#define GPIO05  D1
#define GPIO12  D6
#define GPIO13  D7
#define GPIO14  D5
#define GPIO15  D8
#define GPIO16  D0
#define GPIO17  A0

OneWire oneWire(D1);
TemperatureSensors sensors(&oneWire);
SoftRTC softRTC();

void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  //if you used auto generated SSID, print it
  Serial.println(myWiFiManager->getConfigPortalSSID());
}

void measureTemperatures() {
  Serial.println("....");
}

void setup() {
  Serial.begin(9600);
  pinMode(D3, INPUT);
  pinMode(D4, OUTPUT);

  String serverName = "HomeBoiler_";
  serverName += String(ESP.getChipId(), HEX);

  Serial.println("\n Starting ");
  Serial.println(serverName);

   WiFiManager wifiManager;
   //wifiManager.resetSettings();
   wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));
   wifiManager.setAPCallback(configModeCallback);

  if(!wifiManager.autoConnect(serverName.c_str())) {
    Serial.println("failed to connect and hit timeout");
    //reset and try again, or maybe put it to deep sleep
    ESP.reset();
    delay(1000);
  } 

  //if you get here you have connected to the WiFi
  Serial.println("connected...yeey :)");

  MDNS.begin(serverName.c_str());
  MDNS.addService("smartboiler", "tcp", 80);
  MDNS.addServiceTxt("smartboiler", "tcp", "vr", "1");
  MDNS.addServiceTxt("smartboiler", "tcp", "pt", "http");

}

void loop() {
}