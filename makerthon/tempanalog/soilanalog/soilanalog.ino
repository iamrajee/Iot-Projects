int dataPin = A0;
int data;
void setup(){
  Serial.begin(9600);
  pinMode(dataPin, INPUT);
}

void loop() {
  data = analogRead(dataPin);
  Serial.print("data");
  Serial.println(data);
  delay(1000);
}
