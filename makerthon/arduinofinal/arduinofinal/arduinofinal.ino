
#include <dht.h>

dht DHT1;


int triggerfence = 6;
int echofence = 7;
int buzzerPin = 8; 

//int triggertank = 9;
//int echotank = 10;
//int ledtank = 13;


#define sensor_pin A0
int DHT11_PIN= A1;

int waterpump = 22; 
int fan = 23;
unsigned long distance, duration,dfence,dtank;
int temp, humi,mois;
int fixfencedist = 20;
//int fixtankdist = 22;

int ultraDistfence(){
 // Serial.print("ultrafence");
  digitalWrite(triggerfence, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerfence, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerfence, LOW);
  
  
  digitalRead(echofence);
  
  duration = pulseIn(echofence, HIGH);
  
  distance = duration*(0.034)/2;
  //Serial.print(distance);
  //Serial.print("distance:");
  //Serial.println(distance);
  return(distance);
}

/*int ultraDisttank(){
  
  digitalWrite(triggertank, LOW);
  delayMicroseconds(2);
  digitalWrite(triggertank, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggertank, LOW);
  
  
  digitalRead(echotank);
  
  duration = pulseIn(echotank, HIGH);
  
  distance = duration*(0.034)/2;
  //Serial.print("distance:");
  //Serial.println(distance);
  return(distance);
}*/


void setup(){
  Serial.begin(9600);

  pinMode(triggerfence, OUTPUT); //TO ULTRA SONIC SENSOR
  pinMode(echofence, INPUT);   //FORM uLTRA SONIC SENSOR
  pinMode(buzzerPin, OUTPUT); 
  digitalWrite(buzzerPin, LOW);
  
  //pinMode(triggertank, OUTPUT); //TO ULTRA SONIC SENSOR
  //pinMode(echotank, INPUT);   //FORM uLTRA SONIC SENSOR
  //pinMode(ledtank, OUTPUT); 
  //digitalWrite(ledtank, LOW);
  digitalWrite(waterpump, LOW);
  delay(1000);
  
  pinMode(fan, OUTPUT);
  digitalWrite(fan, LOW);
}

void loop()
{
  //temp,humi,mois, dfence, dtank;
  
  int chk = DHT1.read11(DHT11_PIN);                            //DHT
  temp = DHT1.temperature;
  humi = DHT1.humidity;

  /*
  //Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.print("\t");
  //Serial.print("Humidity = ");
  Serial.println(humi);
  delay(1200);*/
  


   mois= analogRead(sensor_pin);                                  //soilnoisture
   mois = map(mois,550,0,0,100);


   dfence = ultraDistfence();
   //dtank  = ultraDisttank();

  //Serial.print("Temperature = ");
  Serial.print(temp);

  delay(100);
  Serial.print("\t");
  //Serial.print("Humidity = ");
  Serial.print(humi);
  delay(100);
  Serial.print("\t");

  Serial.print(mois);
  delay(100);
  Serial.print("\t");
  
  Serial.println(dfence);
  delay(100);
  //Serial.print("\t");
  //Serial.print("tankdist = ");
  //Serial.println(dtank);

  if(dfence <= fixfencedist)
  {
    digitalWrite(buzzerPin, HIGH);
    delay(10);
    digitalWrite(buzzerPin, LOW);
  }

   /*if(dtank >= (fixtankdist-2))
  {
    digitalWrite(ledtank, HIGH);
    delay(10);
    digitalWrite(ledtank, LOW);
    //Serial.print(); 
  }*/

  if(mois >= 80)
  {
    digitalWrite(waterpump, HIGH); 
    delay(1000); 
    digitalWrite(waterpump, LOW);
    delay(10);
  }

  if(temp >= 40)
  {
    digitalWrite(fan, HIGH);
    delay(100); 
    digitalWrite(fan, LOW);
  }

  if(humi >= 60)
  {
    digitalWrite(fan, HIGH); 
    delay(100); 
    digitalWrite(fan, LOW);
  }
  
  delay(1000);
}

