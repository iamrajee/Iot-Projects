#include<ESP8266WiFi.h>
#include "Adafruit_MQTT_Client.h"


#define ldr A0 
#define wifi "VIRUS"
#define password "raj12345"
#define server "IO.Adafruit.com"
#define port 1883
#define username "i_am_rajee"
#define key "14e1d82cac804c5cbe5377905ca95a0a"
#define pin 16

WiFiClient esp;

Adafruit_MQTT_Client mqtt(&esp,server, port, username, key);                                      //connecting Client to server //espuk :)
Adafruit_MQTT_Subscribe feed = Adafruit_MQTT_Subscribe(&mqtt, username"/feeds/ldr");              //giving location to publish data 


void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
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

  mqtt.subscribe(&feed);
  
  Serial.println("Connecting to MQTT");
  while(mqtt.connect())                                                 //printing while connecting
  {
      Serial.print(".");
  }
 
}

void loop() {
  if(mqtt.readSubscription(5000))                      //only if connected
  {
       Serial.print("Got:");
      Serial.print((char *)feed.lastread);
      int a = atoi((char *)feed.lastread);
      
      Serial.print(" - ");
      Serial.println(a);


      if(a == 0)                                                        //publish the data and checking if published or not
      {
        digitalWrite(pin, LOW);
      }
      else
      {
        digitalWrite(pin, HIGH); 
      }
      //delay(1101);                                                         //*************************
  }
}
