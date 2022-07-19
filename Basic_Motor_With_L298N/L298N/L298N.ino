void setup() {
pinMode(8, OUTPUT);   //in1
pinMode(9, OUTPUT);   //in2
pinMode(10, OUTPUT);   //enA
pinMode(11, OUTPUT);   //enB
pinMode(13, OUTPUT);   //in3
pinMode(12, OUTPUT);   //in4
}

void loop() {
//----forward
//motor1 clockwise/anticlockwise
digitalWrite(8, HIGH);
digitalWrite(9,LOW);
analogWrite(10, 255);
//motor2 clockwise/anticlockwise
digitalWrite(13, HIGH);
digitalWrite(12,LOW);
analogWrite(11, 255);
delay(3000);          //motor1 and motor2 moves clockwise/anticlockwise for 3s

//----backwards
//motor1 anticlockwise/clockwise
digitalWrite(8, LOW);
digitalWrite(9,HIGH);
analogWrite(10, 255);
//motor2 anticlockwise/clockwise
digitalWrite(13, LOW);
digitalWrite(12,HIGH);
analogWrite(11, 255);
delay(3000);          //motor1 and motor2 moves anticlockwise/clockwise for 3s

//----left
//motor1 anticlockwise/clockwise
digitalWrite(8, HIGH);
digitalWrite(9,LOW);
analogWrite(10, 255);
//motor2 anticlockwise/clockwise
digitalWrite(13, LOW);
digitalWrite(12,HIGH);
analogWrite(11, 255);
delay(1000);          //motor1 and motor2 turns left for 1s

//----right
//motor1 anticlockwise/clockwise
digitalWrite(8, LOW);
digitalWrite(9,HIGH);
analogWrite(10, 255);
//motor2 anticlockwise/clockwise
digitalWrite(13, HIGH);
digitalWrite(12,LOW);
analogWrite(11, 255);
delay(3000);          //motor1 and motor2 turns right for 3s

//----stop
//motor1 stop
digitalWrite(8, LOW);
digitalWrite(9,HIGH);
analogWrite(10, 0);
//motor2 stop
digitalWrite(13, LOW);
digitalWrite(12,HIGH);
analogWrite(11, 0);
delay(1000);          //motor1 and motor2 stops for 1s
}
