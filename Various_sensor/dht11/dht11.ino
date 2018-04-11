#include <dht.h>



int humi;
int temp;
dht DHT1;

#define DHT11_PIN A1

void setup(){
  Serial.begin(9600);
  pinMode(DHT11_PIN, INPUT);
}

void loop()
{
  int chk = DHT1.read11(DHT11_PIN);                            //DHT
  temp = DHT1.temperature;
  humi = DHT1.humidity;
  
  //Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.print("\t");
  //Serial.print("Humidity = ");
  Serial.println(humi);
  delay(1200); 
}

