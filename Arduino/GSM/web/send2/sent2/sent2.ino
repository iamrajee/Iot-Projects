#include <SoftwareSerial.h>
SoftwareSerial SIM900(9, 10);


void setup() {
  SIM900.begin(9600);	/* Define baud rate for software serial communication */
  Serial.begin(9600);	/* Define baud rate for serial communication */
}



void loop() {
  
  SIM900.println("AT"); /* Check Communication */
  delay(5000);
  ShowSerialData();	/* Print response on the serial monitor */
  delay(5000);
  
  SIM900.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");	/* Connection type GPRS */
  delay(5000);
  ShowSerialData();
  delay(5000);
  
  SIM900.println("AT+SAPBR=3,1,\"APN\",\"bsnlnet\"");	/* APN of the provider */
  delay(5000);
  ShowSerialData();
  delay(5000);
  
  SIM900.println("AT+SAPBR=1,1");	/* Open GPRS context */
  delay(5000);
  ShowSerialData();
  delay(5000);
  
  SIM900.println("AT+SAPBR=2,1");	/* Query the GPRS context */
  delay(5000);
  ShowSerialData();
  delay(5000);
  
  SIM900.println("AT+HTTPINIT");	/* Initialize HTTP service */
  delay(5000); 
  ShowSerialData();
  delay(5000);
  
  SIM900.println("AT+HTTPPARA=\"CID\",1");	/* Set parameters for HTTP session */
  delay(5000);
  ShowSerialData();
  delay(5000);
  
  SIM900.println("AT+HTTPPARA=\"URL\",\"api.thingspeak.com/update\"");	/* Set parameters for HTTP session */
  delay(5000);
  ShowSerialData();
  delay(5000);
  
  SIM900.println("AT+HTTPDATA=33,10000");	/* POST data of size 33 Bytes with maximum latency time of 10seconds for inputting the data*/ 
  delay(2000);
  ShowSerialData();
  delay(2000);
  
  SIM900.println("api_key=C7JFHZY54GLCJY38&field1=1");
  delay(5000);
  ShowSerialData();
  delay(5000);
  
  SIM900.println("AT+HTTPACTION=1");	/* Start POST session */
  delay(5000);
  ShowSerialData();
  delay(5000);
  
  SIM900.println("AT+HTTPTERM");	/* Terminate HTTP service */
  delay(5000);
  ShowSerialData();
  delay(5000);
  
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
