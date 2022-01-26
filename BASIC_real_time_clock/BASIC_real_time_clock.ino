//This code is to use with DS1302 RTC module, it permits you to setup the actual time and date
//And you can visualize them on the LCD i2c screen
//This code is a modified version of the code provided in virtuabotixRTC library
//Refer to Surtrtech Youtube chhannel/Facebook page for more information
#include <Servo.h>

Servo servo;
int angle =10;
//const int ledPin = 12;
#include <virtuabotixRTC.h> //Libraries needed
/*#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27 //LCD i2c stuff
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
*/
//Wiring SCLK -> 6, I/O -> 7, CE -> 9
//Or CLK -> 6 , DAT -> 7, Reset -> 9

virtuabotixRTC myRTC(6, 7, 9); //If you change the wiring change the pins here also




void setup() {
 Serial.begin(9600);
/* lcd.begin (16,2); //Initialize the LCD
 lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
 lcd.setBacklight(HIGH);
 lcd.home ();*/
 //*******myRTC.setDS1302Time(0, 50, 21, 16, 7, 16, 2020); //Here you write your actual time/date as shown above-----------------------//SET TIME (SECONDS, MINUTES, HOURS, DATE, MONTH, YEAR)
 //but remember to "comment/remove" this function once you're done as I did
 //The setup is done only one time and the module will continue counting it automatically
   //pinMode(ledPin, OUTPUT);
   servo.attach(10);
servo.write(angle);
}

void loop() {
 //lcd.clear(); //Here after clearing the LCD we take the time from the module and print it on the screen with usual LCD functions
 myRTC.updateTime();
 //lcd.setCursor(0,0);
Serial.print(myRTC.dayofmonth);
Serial.print("/");
Serial.print(myRTC.month);
Serial.print("/");
 Serial.print(myRTC.year);
//lcd.setCursor(0,1);
Serial.print("  ");
Serial.print(myRTC.hours);
Serial.print(":");
Serial.print(myRTC.minutes);
Serial.print(":");
Serial.print(myRTC.seconds);
Serial.println();
 delay(1000);
 /////
 if (myRTC.hours == 6 && myRTC.minutes == 0 && myRTC.seconds == 0) {
  servo.write(0);
    //digitalWrite(ledPin, HIGH);
  } else {
    servo.write(180);
    //digitalWrite(ledPin, LOW);
  }

  // print the analog value:
  //Serial.println(analogValue);
  delay(10);        // delay in between reads for stability
}
