#include<ESP8266WiFi.h>
#include "Adafruit_MQTT_Client.h"


#define ldr A0 
#define wifi "VIRUS"
#define password "raj12345"
#define server "IO.Adafruit.com"
#define port 1883
#define username "i_am_rajee"
#define key "14e1d82cac804c5cbe5377905ca95a0a"

WiFiClient esp;

Adafruit_MQTT_Client mqtt(&esp,server, port, username, key);                                      //connecting Client to server //espuk :)
Adafruit_MQTT_Publish feed = Adafruit_MQTT_Publish(&mqtt, username"/feeds/ldr");              //giving location to publish data 


void setup() {
  Serial.begin(115200);
  delay(10);

  
  Serial.println("Adafruit MQTT Demo");
  Serial.print("Connecting to  ");
  Serial.print(wifi);  

  WiFi.begin(wifi,password);                                                            //connect client to internet
  
  while(WiFi.status()!= WL_CONNECTED)
  {
       delay(500);
       Serial.print(".");
  }


  Serial.println("\nWiFi connected");
  Serial.print("IP address:");
  Serial.println(WiFi.localIP());


  
  Serial.print("Connecting to MQTT");
  while(mqtt.connect())                                                 //printing while connecting
  {
      Serial.print(".");
  }
 
}

void loop() {
  if(mqtt.connected())                      //only if connected
  {
      int data = analogRead(ldr);


      
      Serial.print("\nSending LDR val ");
      Serial.print(data);
      Serial.print("...");


      if(feed.publish(data))                                                        //publish the data and checking if published or not
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
