const int ledpin=12;
const int soundpin=A2;
const int threshold=200;

void setup() {
Serial.begin(9600);
pinMode(ledpin, OUTPUT);
pinMode(soundpin, INPUT);
}

void loop() {
int soundsens=analogRead(soundpin);
if (soundsens>=threshold) {
  digitalWrite(ledpin ,HIGH);
  tone(11,20,10000);

  delay(1000);
}
else{
  digitalWrite(ledpin, LOW);
  }
}

