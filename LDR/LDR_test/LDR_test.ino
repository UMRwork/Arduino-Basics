const int ldrPin    = A1;

void setup()
{
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int ldrStatus = analogRead(ldrPin);
  Serial.print ("LDR reading      : ");                                
  Serial.println (ldrStatus);
  delay(200);
}
