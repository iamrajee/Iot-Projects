#include<ESP8266WiFi.h>
#include "Adafruit_MQTT_Client.h"
#include <DHT.h>

DHT = dht1;

#define DHT11_PIN 3
//#define ldr A0
#define wifi "VIRUS"
#define password "raj12345"
#define server "io.adafruit.com"
#define port 1883
#define username "i_am_rajee"
#define key "14e1d82cac804c5cbe5377905ca95a0a"

//#define temp
//#define humidity

WiFiClient esp;

Adafruit_MQTT_Client mqtt(&esp, server, port, username, key);                                     //connecting Client to server //espuk :)
Adafruit_MQTT_Publish feed1 = Adafruit_MQTT_Publish(&mqtt, username"/feeds/ldr");              //giving location to publish data
Adafruit_MQTT_Publish feed2 = Adafruit_MQTT_Publish(&mqtt, username"/feeds/tempsen");              //giving location to publish data


void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println("Adafruit MQTT demo");
  Serial.print("Connecting to ");
  Serial.println(wifi);


  WiFi.begin(wifi, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println("WiFi.localIP()");
  Serial.print("Connecting to MQTT");


  while (mqtt.connect())                                                //printing while connecting
  {
    Serial.print(".");
  }

}



void loop()
{
  if (mqtt.connected())                     //only if connected
  {

    int chk = dht1.read11(DHT11_PIN);
    int temp = dht1.readtemperature();
    int humi = dht1.humidity();

    Serial.print("Temperature = ");
    Serial.print(temp);
    Serial.print("\t");
    Serial.print("Humidity = ");
    Serial.println(humi);
    delay(1200);


    // int data = analogRead(ldr);
    //Serial.print("\nSending LDR val");
    //Serial.print(data);
    //Serial.print("...");


    if (feed2.publish(temp))                                                       //publish the data and checking if published or not
    {
      Serial.println("Success temp");
    }
    else
    {
      Serial.println("Fail! temp");
    }

    if (feed1.publish(humi))                                                       //publish the data and checking if published or not
    {
      Serial.println("Success humidity");
    }
    else
    {
      Serial.println("Fail! humidity");
    }
    delay(1101);                                                         //*************************
  }
}

