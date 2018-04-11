#include<ESP8266WiFi.h>
#include "Adafruit_MQTT_Client.h"

//#define ldr A0
#define wifi "VIRUS"
#define password "raj12345"
#define server "io.adafruit.com"
#define port 1883
#define username "i_am_rajee"
#define key "14e1d82cac804c5cbe5377905ca95a0a"

int sensor_pin = A0;

int output_value ;

WiFiClient esp;

Adafruit_MQTT_Client mqtt(&esp,server, port, username, key);                                      //connecting Client to server //espuk :)
Adafruit_MQTT_Publish feed = Adafruit_MQTT_Publish(&mqtt, username"/feeds/ldr");              //giving location to publish data 


void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println("Adafruit MQTT demo");
  Serial.print("Connecting to ");
  Serial.println(wifi);
  
  
  WiFi.begin(wifi,password);
  while(WiFi.status()!= WL_CONNECTED)
    {
          delay(500);
           Serial.print(".");
    }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println("WiFi.localIP()");
  Serial.print("Connecting to MQTT");
  
  
  while(mqtt.connect())                                                 //printing while connecting
    {
          Serial.print(".");
    }

}



void loop()
{
  if(mqtt.connected())                      //only if connected
   {
        /* int data = analogRead(ldr);
         Serial.print("\nSending LDR val");
         Serial.print(data);
         Serial.print("...");*/

        output_value= analogRead(sensor_pin);

        output_value = map(output_value,550,0,0,100);

        Serial.print("Mositure : ");

        Serial.print(output_value);

        Serial.println("%");

        //delay(2000);

         if(feed.publish(output_value))                                                        //publish the data and checking if published or not
          {
             Serial.println("Success");
          }
         else
          {
            Serial.println("Fail!");  
        }
          delay(1101);                                                         //*************************
  }



}

