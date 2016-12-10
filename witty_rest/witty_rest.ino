/*
   REST for WITTY
   Copyright (C) 2016 Esteban Familiar Rey

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

ESP8266WebServer server(80);

// Constants pins
int const LED_RED = 15;
int const LED_GREEN = 12;
int const LED_BLUE = 13;
int const PHOTO = A0;

// Static IP
IPAddress ip(192, 168, 1, 99);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

void handleLed() {
        String json = server.arg("plain");
        StaticJsonBuffer<200> jsonBuffer;

        JsonObject& root = jsonBuffer.parseObject(json);
        if (!root.success()) {
                server.send(500, "text/plain", "Error parsing json");
                return;
        }

        int red = root["red"];
        int green = root["green"];
        int blue = root["blue"];

        analogWrite(LED_RED, red);
        analogWrite(LED_GREEN, green);
        analogWrite(LED_BLUE, blue);

        server.send(200, "text/plain", "OK");
}

void handlePhoto() {
        int photo = analogRead(PHOTO);
        String result;
        StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();

        root["photoResistor"] = photo;

        root.printTo(result);
        server.send(200, "text/json", result);
}

void setup() {
        Serial.begin(115200);
        Serial.setDebugOutput(true);


        pinMode(LED_RED, OUTPUT);
        pinMode(LED_GREEN, OUTPUT);
        pinMode(LED_BLUE, OUTPUT);
        pinMode(PHOTO, INPUT);

        WiFi.config(ip, gateway, subnet);
        WiFi.begin("MYSSID", "MYPASSWORD");

        // Wait for connection
        while (WiFi.status() != WL_CONNECTED) {
                delay(500);
                Serial.print(".");
        }
        // Handles
        server.on("/led", HTTP_POST, handleLed);
        server.on("/photo", HTTP_GET, handlePhoto);

        server.begin();
        Serial.println("HTTP server started");
}

void loop() {
        server.handleClient();
}
