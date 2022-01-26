void setup() {
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
}

void loop() {
digitalWrite(4, HIGH);
digitalWrite(5, LOW);

digitalWrite(10, HIGH);
digitalWrite(11, LOW);

analogWrite(9, 255);
delay(1000);
//--------------------------------------
digitalWrite(4, LOW);
digitalWrite(5, HIGH);

digitalWrite(10, LOW);
digitalWrite(11, HIGH);

analogWrite(9, 255);
delay(1000);
}
