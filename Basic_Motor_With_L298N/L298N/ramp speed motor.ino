void forwardfx(){
  //----forward
  //motor1 clockwise/anticlockwise
  digitalWrite(8, HIGH);
  digitalWrite(9,LOW);
  //motor2 clockwise/anticlockwise
  digitalWrite(13, HIGH);
  digitalWrite(12,LOW);
  for (int spd = 0; spd < 200; spd += 5) { 
    analogWrite(10, spd);
    analogWrite(11, spd);
    delay(70);
  }
}

void backwardsfx(){
//----backwards
  //motor1 anticlockwise/clockwise
  digitalWrite(8, LOW);
  digitalWrite(9,HIGH);
  //motor2 anticlockwise/clockwise
  digitalWrite(13, LOW);
  digitalWrite(12,HIGH);
  for (int spd = 0; spd < 200; spd += 5) { 
    analogWrite(10, spd);
    analogWrite(11, spd);
    delay(70);
  }
}

void rightfx(){
  //----right
  //motor1 anticlockwise/clockwise
  digitalWrite(8, LOW);
  digitalWrite(9,HIGH);
  //motor2 anticlockwise/clockwise
  digitalWrite(13, HIGH);
  digitalWrite(12,LOW);
  for (int spd = 0; spd < 200; spd += 5) { 
    analogWrite(10, spd);
    analogWrite(11, spd);
    delay(70);
  }
} 

void leftfx(){
  //----left
  //motor1 anticlockwise/clockwise
  digitalWrite(8, HIGH);
  digitalWrite(9,LOW);
  //motor2 anticlockwise/clockwise
  digitalWrite(13, LOW);
  digitalWrite(12,HIGH);
  for (int spd = 0; spd < 200; spd += 5) { 
    analogWrite(10, spd);
    analogWrite(11, spd);
    delay(70);
  }
}

void stopfx(){
  //----stop
  //motor1 stop
  digitalWrite(8, LOW);
  digitalWrite(9,HIGH);
  analogWrite(10, 0);
  //motor2 stop
  digitalWrite(13, LOW);
  digitalWrite(12,HIGH);
  analogWrite(11, 0);  
}

void setup() {
  pinMode(8, OUTPUT);   //in1
  pinMode(9, OUTPUT);   //in2
  pinMode(10, OUTPUT);   //enA
  pinMode(11, OUTPUT);   //enB
  pinMode(13, OUTPUT);   //in3
  pinMode(12, OUTPUT);   //in4
}

void loop() {
  forwardfx();
  delay(3000);          //motor1 and motor2 moves forward for 3s
  stopfx();
  delay(1000);          //motor1 and motor2 stops for 1s
  backwardsfx();
  delay(3000);          //motor1 and motor2 moves backwards for 3s
  stopfx();
  delay(1000);          //motor1 and motor2 stops for 1s
  rightfx();
  delay(1000);          //motor1 and motor2 turns right for 1s
  stopfx();
  delay(1000);          //motor1 and motor2 stops for 1s
  leftfx();
  delay(1000);          //motor1 and motor2 turns left for 1s
  stopfx();
  delay(1000);          //motor1 and motor2 stops for 1s
}
