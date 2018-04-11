#include <dht.h>

dht dht1;

#define DHT11_PIN 52

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = dht1.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(dht1.temperature);
  Serial.print("Humidity = ");
  Serial.println(dht1.humidity);
  delay(1000);
}
