#include<ESP8266WiFi.h>
#include "Adafruit_MQTT_Client.h"

#define wifi "IS57i"
#define password "donkey@7"
#define server "io.adafruit.com"
#define port 1883
#define username "i_am_rajee"
#define key "14e1d82cac804c5cbe5377905ca95a0a"
//String data;
//#define data 
int data[5];
WiFiClient esp;

Adafruit_MQTT_Client mqtt(&esp,server, port, username, key);                                      //connecting Client to server //espuk :)

Adafruit_MQTT_Publish feed1 = Adafruit_MQTT_Publish(&mqtt, username"/feeds/ldr"); 
Adafruit_MQTT_Publish feed2 = Adafruit_MQTT_Publish(&mqtt, username"/feeds/tempsen");              //giving location to publish data 
Adafruit_MQTT_Publish feed3 = Adafruit_MQTT_Publish(&mqtt, username"/feeds/mois"); 
Adafruit_MQTT_Publish feed4 = Adafruit_MQTT_Publish(&mqtt, username"/feeds/fence"); 
//Adafruit_MQTT_Publish feed5 = Adafruit_MQTT_Publish(&mqtt, username"/feeds/tank"); 
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
         while(Serial.available() == 0)
         {
         }

         for(int i = 0; i<4; i++)
         {
            data[i] = Serial.read();
          Serial.print(data[i]);
            Serial.print("\t");
         }
         Serial.print("\n");
         Serial.print("\nSending DTH val");
         //Serial.print(data);
         Serial.print("\t ...");


         if(feed1.publish(data[0]))                                                        //publish the data and checking if published or not
          {
             Serial.println("Success of feed1 data");
          }
         else
          {
            Serial.println("Fail! of feed1 data");  
          }
          

          if(feed2.publish(data[1]))                                                        //publish the data and checking if published or not
          {
             Serial.println("Success of feed2 data");
          }
         else
          {
            Serial.println("Fail! of feed2 data");  
          }

          if(feed3.publish(data[2]))                                                        //publish the data and checking if published or not
          {
             Serial.println("Success of feed3 data");
          }
         else
          {
            Serial.println("Fail! of feed3 data");  
          }

          if(feed4.publish(data[3]))                                                        //publish the data and checking if published or not
          {
             Serial.println("Success of feed4 data");
          }
         else
          {
            Serial.println("Fail! of feed4 data");  
          }

          /*if(feed5.publish(data[0]))                                                        //publish the data and checking if published or not
          {
             Serial.println("Success of feed5 data");
          }
         else
          {
            Serial.println("Fail! of feed5 data");  
          }*/

          delay(4000);                                                        //*************************
  }
}









/*

#include<ESP8266WebServer.h>
ESP8266WebServer server;


const char username[] = "Rajeesingh27";         //acess point const
const char password[] = "1234567890";


#define pin 16

void setup() {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  Serial.begin(115200);

  WiFi.softAP(username, password);                  //acess point
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address:");
  Serial.println(myIP);


  server.begin();
  server.on("/led", led);
  
}
void loop() {
  server.handleClient();
}

void led()
{
  String myhtml = "<html><head><title>I'M RAJEE</title></head><body   style =  \"background-color : palegreen \"><h1><center>Conect with me on following socials!!</center></h1><h5><center>wwww.wixsite.com/rajeesingh27</center></h5><form><center><button  type = \"submit\"  name = \"state\" value = \"0\">LED ON</button><button  type = \"submit\"  name = \"state\" value = \"1\">LED OFF</button></center></form></body></html>";
  
  server.send(200, "text/html", myhtml);     //send okey

  if(server.arg("state") == "1")
  {
    digitalWrite(pin, HIGH);
  }
  else
  {
    digitalWrite(pin, LOW);
  }
}
*/
