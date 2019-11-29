#include <SoftwareSerial.h>
/* Create object named SIM900 of the class SoftwareSerial */
SoftwareSerial SIM900(9, 10);
void setup() {
  SIM900.begin(9600);	/* Define baud rate for software serial communication */
  Serial.begin(9600);	/* Define baud rate for serial communication */
}

void loop() {
  Serial.println("HTTP get method :");
  Serial.print("AT\\r\\n");
  SIM900.println("AT");	/* Check Communication */
  delay(5000);
  ShowSerialData();	/* Print response on the serial monitor */
  delay(5000);
  /* Configure bearer profile 1 */
  Serial.print("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"\\r\\n");		
  SIM900.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");	/* Connection type GPRS */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+SAPBR=3,1,\"APN\",\"bsnlnet\"\\r\\n");	
  SIM900.println("AT+SAPBR=3,1,\"APN\",\"bsnlnet\"");	/* APN of the provider */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+SAPBR=1,1\\r\\n");
  SIM900.println("AT+SAPBR=1,1");	/* Open GPRS context */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+SAPBR=2,1\\r\\n");
  SIM900.println("AT+SAPBR=2,1");	/* Query the GPRS context */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+HTTPINIT\\r\\n");
  SIM900.println("AT+HTTPINIT"); /* Initialize HTTP service */
  delay(5000); 
  ShowSerialData();
  delay(5000);
  Serial.print("AT+HTTPPARA=\"CID\",1\\r\\n");
  SIM900.println("AT+HTTPPARA=\"CID\",1");	/* Set parameters for HTTP session */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+HTTPPARA=\"URL\",\"api.thingspeak.com/channels/119922/feeds/last.txt\"\\r\\n");
  SIM900.println("AT+HTTPPARA=\"URL\",\"api.thingspeak.com/channels/119922/feeds/last.txt\"");	/* Set parameters for HTTP session */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+HTTPACTION=0\\r\\n");
  SIM900.println("AT+HTTPACTION=0");	/* Start GET session */
  delay(10000);
  ShowSerialData();
  delay(10000);
  Serial.print("AT+HTTPREAD\\r\\n");
  SIM900.println("AT+HTTPREAD");	/* Read data from HTTP server */
  delay(8000);
  ShowSerialData();
  delay(8000);
  Serial.print("AT+HTTPTERM\\r\\n");  
  SIM900.println("AT+HTTPTERM");	/* Terminate HTTP service */
  delay(5000);
  ShowSerialData();
  delay(5000);
  Serial.print("AT+SAPBR=0,1\\r\\n");
  SIM900.println("AT+SAPBR=0,1"); /* Close GPRS context */
  delay(5000);
  ShowSerialData();
  delay(5000);
}

void ShowSerialData()
{
  while(SIM900.available()!=0)	/* If data is available on serial port */
  Serial.write(char (SIM900.read()));	/* Print character received on to the serial monitor */
}
