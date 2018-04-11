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
