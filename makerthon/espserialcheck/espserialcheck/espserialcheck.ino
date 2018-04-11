#include<ESP8266WiFi.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
int data[5];

void setup()
{
  Serial.begin(9600);
  delay(10);
}

void loop()
{
     while(Serial.available() == 0)
         {
         }

         for(int i = 0; i<5; i++)
         {
            data[i] = mySerial.read();
          Serial.print(data[i]);
            Serial.print("\t");
         }
         Serial.print("\n");
         Serial.print("\nSending DTH val");
         //Serial.print(data);
         Serial.print("\t ...");

          delay(1200);                                                        //*************************
}
