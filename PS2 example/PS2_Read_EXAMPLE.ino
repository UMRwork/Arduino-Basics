#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
Cytron_PS2Shield ps2(2,3);
void setup()
{
ps2.begin(9600);
Serial.begin(9600);
}
void loop()
{
Serial.print("Y Axis val: ");
Serial.print(ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS));
Serial.print("  ||  ");
Serial.print("X Axis val: ");
Serial.print(ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS));
Serial.println();

delay(50);
}
