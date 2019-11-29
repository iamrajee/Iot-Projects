//#include <GSM3MobileNetworkRegistry.h>
//#include <GSM3ShieldV1.h>
//#include <GSM3ShieldV1BaseProvider.h>
//#include <GSM3MobileVoiceProvider.h>
//#include <GSM3ShieldV1AccessProvider.h>
//#include <GSM3MobileCellManagement.h>
//#include <GSM3MobileDataNetworkProvider.h>
//#include <GSM3MobileSMSProvider.h>
//#include <GSM3ShieldV1VoiceProvider.h>
//#include <GSM3ShieldV1SMSProvider.h>
//#include <GSM3MobileMockupProvider.h>
//#include <GSM3ShieldV1BandManagement.h>
//#include <GSM3SoftSerial.h>
//#include <GSM3ShieldV1ScanNetworks.h>
//#include <GSM3ShieldV1DirectModemProvider.h>
//#include <GSM3MobileClientService.h>
//#include <GSM3ShieldV1ClientProvider.h>
//#include <GSM3MobileAccessProvider.h>
//#include <GSM3ShieldV1ModemVerification.h>
//#include <GSM3MobileClientProvider.h>
//#include <GSM3VoiceCallService.h>
//#include <GSM3MobileServerService.h>
//#include <GSM3CircularBuffer.h>
//#include <GSM3MobileServerProvider.h>
//#include <GSM3ShieldV1PinManagement.h>
//#include <GSM3MobileNetworkProvider.h>
//#include <GSM3ShieldV1ModemCore.h>
//#include <GSM3ShieldV1CellManagement.h>
//#include <GSM3ShieldV1MultiClientProvider.h>
//#include <GSM3SMSService.h>
//#include <GSM.h>
//#include <GSM3ShieldV1MultiServerProvider.h>
//#include <GSM3ShieldV1ServerProvider.h>
//#include <GSM3ShieldV1DataNetworkProvider.h>

//ERFINDER CODE
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10); // RX, TX

void setup()
{
  Serial.begin(9600);
}

void loop() // run over and over
{
//  Serial.println("Calling through GSM Modem");

// set the data rate for the SoftwareSerial port
mySerial.begin(9600);
delay(1500);
 mySerial.println("ATD8146474671;");// ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!

//Serial.println("Called ATD7073091997");

//if(Serial.available()){
//  mySerial.write(Serial.read());
//}

// print response over serial port
if (mySerial.available())
{
  Serial.write(mySerial.read());
}
//else
//{
//  Serial.print("mySerial.available() not available");
//}

}
