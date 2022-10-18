#include <Arduino.h>
#include <WiFi.h>

const char* WIFI_SSID       = "HUAWEI nova 3i";
const char* WIFI_PASSWORD   = "2000-3322499";

void setup() {
  pinMode(12, OUTPUT);
  digitalWrite(12,LOW);
      Serial.begin(115200);
    

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();
    
    Serial.println("BonSoir :\tSalah Eddinne");
}

void loop() {
  digitalWrite(12,HIGH);
  Serial.println("Pin Allumé\n");
  delay(2000);
  digitalWrite(12,LOW);
  Serial.println("Pin Eteinte\n");
  delay(2000);
}