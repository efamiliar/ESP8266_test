/*
   Blynk IoT testing for ESP8266E Witty card
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
 
#include <BlynkSimpleEsp8266.h>

char auth[] = "your_auth_code";
char WiFiNetwork[] = "wifi_ssid";
char WiFiPassword[] = "@wifipassword";


void setup() {
  Blynk.begin(auth, WiFiNetwork, WiFiPassword);
}

void loop() {
  Blynk.run(); 
}
