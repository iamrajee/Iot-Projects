int Analog_data;
int Digital_data;

int Analog_out = A0;
int Digital_out = 2;

void setup()
{
 Serial.begin(9600);
 pinMode(2, INPUT);
 pinMode(A0, INPUT); 
}

void loop()
{
  Analog_data = analogRead(Analog_out);
  Digital_data = digitalRead(Digital_out);
  Serial.print(Analog_data);
  Serial.print("\t\t");
  Serial.println(Digital_data);
//  delay(1000);
}
