void setup() {
pinMode(12, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
}

void loop() {
digitalWrite(8, HIGH);
//delay(1000);
digitalWrite(10,HIGH);
//delay(1000);
digitalWrite(9,HIGH);
//delay(1000);
digitalWrite(12,HIGH);
delay(1000);
digitalWrite(8,HIGH);
//delay(1000);
digitalWrite(10,LOW);
//delay(1000);
digitalWrite(9,LOW);
//delay(1000);
digitalWrite(12,LOW);
//delay(1000);
}
