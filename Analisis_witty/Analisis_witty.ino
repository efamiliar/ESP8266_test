
int PHOTO_R = A0;
int BUTTON = 4;

void setup(){
  Serial.begin(115200);

  pinMode(PHOTO_R,INPUT);
  pinMode(BUTTON,INPUT);
   
}

void loop(){
  
    //Photoresistence read and print
    int photoResistence = analogRead(PHOTO_R);
    Serial.print(photoResistence);
    Serial.print(";");

    //Button read and print
    int buttonVal = digitalRead(BUTTON);
    Serial.print(buttonVal * 1024);
    Serial.print(";");

    //Calculated value and print
    int calc = photoResistence / ((buttonVal + 1) * 2);
    Serial.print(calc);
    Serial.print(";");

    //Time in milliseconds
    Serial.println(millis());

    delay(10);
    
}

