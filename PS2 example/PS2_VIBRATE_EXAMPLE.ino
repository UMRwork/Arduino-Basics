#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
Cytron_PS2Shield ps2(2,3);
void setup()
{
ps2.begin(9600);
}
void loop()
{
/* Function: vibrate(motor, value);
motor = 0; value = 0 to 255 //bigger vibrator
motor = 1; value = 0 or 1 //smaller vibrator
*/
ps2.vibrate(1,1);
delay(500);
ps2.vibrate(1,0);
delay(500);
}
