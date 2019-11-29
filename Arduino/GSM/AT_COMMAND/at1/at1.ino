#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10); // RX, TX


void setup()
{
  Serial.begin(19200);
}

void loop() // run over and over
{
  
  mySerial.begin(9600);
  delay(100);
 
  if(Serial.available()) //myserial.write
  {
    mySerial.write(Serial.read());
  }
      //Serial.write(mySerial.read());

  if (mySerial.available()) //myserial.read
  {
    Serial.write(mySerial.read());
  }
//  else //myserial.read
//  {
//    Serial.write("mySerial.read() not available\n");
//  }


}
