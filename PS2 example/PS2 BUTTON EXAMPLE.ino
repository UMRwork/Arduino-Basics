#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
Cytron_PS2Shield ps2(2,3);
#define led 13
void setup()
{
ps2.begin(9600);
pinMode(led,OUTPUT);
digitalWrite(led,LOW);
}
void loop()
{
if(ps2.readButton(PS2_SELECT)==0)
{
digitalWrite(led,HIGH);
}
else
{
digitalWrite(led,LOW);
}
}