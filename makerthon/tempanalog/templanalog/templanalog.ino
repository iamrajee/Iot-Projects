int dataPin = A0;
int data;
void setup() {
  Serial.begin(115200);
  //  pinMode(dataPin, INPUT);
}

void loop() {
  data = analogRead(dataPin);
  //Serial.print("data");
  Serial.println(data);
  delay(1200);
}
