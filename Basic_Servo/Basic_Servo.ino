#include <Servo.h>

Servo servo;
int angle =10;

void setup() {
servo.attach(10);
servo.write(angle);
}

void loop() {
//for(angle = 10; angle < 90; angle++)
{
servo.write(0);
delay(1000);
}

//for(angle = 10; angle <90; angle--)
{
servo.write(180);
delay(1000);
}
}
