
#include <BlynkSimpleEsp8266.h>


char auth[] = "cf9193981ce4477d9833524b1f649e37";
char WiFiNetwork[] = "wifi_sid";
char WiFiPassword[] = "@wifipassword";


void setup() {
  Blynk.begin(auth, WiFiNetwork, WiFiPassword);
}

void loop() {
  Blynk.run(); 
}
