#include<GSM.h>  //gsm library

#define  PINNUMBER ""  //only if sim have pin

//variable in case login security of internet
#define GRPS_APN
#define GRPS_LOGIN
#define GRPS_PASSWORD

//we go need following class object
GSMClient client;
GPRS gprs;
GSM gsmAccess;


//variable for server path and port
char server[] = "arduino.cc";
char path[] = "/";
int port = 80;

void setup(void)
{

}

void loop(void)
{
  
}

