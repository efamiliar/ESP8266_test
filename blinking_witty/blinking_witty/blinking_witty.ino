/*
   Blink testing for ESP8266E Witty card
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

int LED_R = 15;

void setup() {
  
   pinMode(LED_R, OUTPUT);

}

void loop() {
  
  analogWrite(LED_R, 255);
  delay(500);
  analogWrite(LED_R, 0);
  delay(500);
  
}
