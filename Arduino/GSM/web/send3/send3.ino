#include <SoftwareSerial.h>
SoftwareSerial SIM900(9, 10);

int Analog_data;
int Digital_data;

int Analog_out = A0;
int Digital_out = 2;

void setup() {
  SIM900.begin(9600);	/* Define baud rate for software serial communication */
  Serial.begin(9600);	/* Define baud rate for serial communication */
  pinMode(2, INPUT);
  pinMode(A0, INPUT); 
}

int tdelay = 2000;


void loop() {
  
  SIM900.println("AT"); /* Check Communication */
  delay(tdelay);
  ShowSerialData();	/* Print response on the serial monitor */
  delay(tdelay);
  
  SIM900.println("AT+CIPSHUT"); /* Check Communication */
  delay(tdelay);
  ShowSerialData();	/* Print response on the serial monitor */
  delay(tdelay);
  
  SIM900.println("AT+CIPMUX=0"); /* Check Communication */
  delay(tdelay);
  ShowSerialData();	/* Print response on the serial monitor */
  delay(tdelay);
  
  SIM900.println("AT+CGATT=1"); /* Check Communication */
  delay(tdelay);
  ShowSerialData();	/* Print response on the serial monitor */
  delay(tdelay);
  
  SIM900.println("AT+CSTT=\"bsnlnet\","","""); /* Check Communication */
  delay(tdelay);
  ShowSerialData();	/* Print response on the serial monitor */
  delay(tdelay);
  
  SIM900.println("AT+CIICR"); /* Check Communication */
  delay(tdelay);
  ShowSerialData();	/* Print response on the serial monitor */
  delay(tdelay);
  
  SIM900.println("AT+CIFSR"); /* Check Communication */
  delay(tdelay);
  ShowSerialData();	/* Print response on the serial monitor */
  delay(tdelay);
  
  SIM900.println("AT+CIPSTART=\"TCP\",\"184.106.153.149\",\"80\""); /* Check Communication */
  delay(tdelay);
  ShowSerialData();	/* Print response on the serial monitor */
  delay(tdelay);
  
  
  
  Analog_data = analogRead(Analog_out);
  
  
//  Digital_data = digitalRead(Digital_out);
//  Serial.print(Analog_data);
//  Serial.print("\t\t");
//  Serial.println(Digital_data);
  
  SIM900.println("AT+CIPSEND=45"); /* Check Communication */
  delay(tdelay);
  ShowSerialData();	/* Print response on the serial monitor */
  delay(tdelay);
  
  
  SIM900.print("GET /update?key=SWDSNA356HLE3E05&field3="); /* Check Communication */
  SIM900.println(Analog_data);
  delay(tdelay);
  ShowSerialData();	/* Print response on the serial monitor */
  delay(tdelay);
}

void ShowSerialData()
{
  while(SIM900.available()!=0)	/* If data is available on serial port */
  Serial.write(char (SIM900.read()));	/* Print character received on to the serial monitor */
}
