#include <Servo.h>

Servo servo1;

int joyX = 0;
int joyY = 1;

int joyVal;

void setup() {
servo1.attach(3);
Serial.begin(9600);
}

void loop() {
joyVal = analogRead(joyX);
joyVal = map (joyVal, 0, 1023, 0, 180);
servo1.write(joyVal);

joyVal = analogRead(joyY);
joyVal = map (joyVal, 0, 1023, 0, 180);
servo1.write(joyVal);
delay(15);
Serial.print(analogRead(joyX));
Serial.print(" || ");
Serial.print(analogRead(joyY));
Serial.println();
}
