#include <PS2X_lib.h>
#include "CytronMotorDriver.h"

#define PS2_DAT       26     
#define PS2_CMD       28  
#define PS2_SEL       30  
#define PS2_CLK       32  

int nJoyRy;
int nJoyRx;
int nJoyLy;
int nJoyLx;

const int pwm1 = 9;
const int pwm2 = 8;
const int pwm3 = 7;
const int pwm4 = 6;
const int dir1 = 40;
const int dir2 = 42;
const int dir3 = 44;
const int dir4 = 46;

// Configure the motor driver.
CytronMD motor1(PWM_DIR, 5, 41);  // PWM 1 = Pin 5, DIR 1 = Pin 41.
CytronMD motor2(PWM_DIR, 4, 43); // PWM 2 = Pin 4, DIR 2 = Pin 43.
CytronMD motor3(PWM_DIR, 3, 45); // PWM 2 = Pin 3, DIR 2 = Pin 45.
CytronMD motor4(PWM_DIR, 2, 47); // PWM 2 = Pin 2, DIR 2 = Pin 47.

#define pressures   false
#define rumble      false

int error = 0;
byte type = 0;
byte vibrate = 0;

PS2X ps2x;

void setup(){
  
  Serial.begin(9600);
  
  delay(100);

  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);

  if(error == 0){
    Serial.print("Found Controller, configured successful ");
    Serial.print("pressures = ");
    
    if (pressures){
      Serial.println("true ");
    }
    
    else{
      Serial.println("false");
    }
    
    Serial.print("rumble = ");
    if (rumble){
      Serial.println("true)");
    }
    else{
      Serial.println("false");
      Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
      Serial.println("holding L1 or R1 will print out the analog stick values.");
      Serial.println("Note: Go to www.billporter.info for updates and to report bugs.");
    }
  }  
  
  if(error == 1){
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
  }
  else if(error == 2){
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
  }
  else if(error == 3){
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
  }
//  Serial.print(ps2x.Analog(1), HEX);
  
  type = ps2x.readType(); 
  switch(type) {
    case 0:
      Serial.print("Unknown Controller type found ");
      break;
    case 1:
      Serial.print("DualShock Controller found ");
      break;
    case 2:
      Serial.print("GuitarHero Controller found ");
      break;
    case 3:
      Serial.print("Wireless Sony DualShock Controller found ");
      break;
   }

  pinMode(pwm1,OUTPUT); //COnfigure output pins
  pinMode(pwm2,OUTPUT);
  pinMode(pwm3,OUTPUT);
  pinMode(pwm4,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);
}

void loop(){
  
  delay(50);
  
  if(error == 1) //skip loop if no controller found
    return; 
  
  if(type == 2){ //Guitar Hero Controller
    ps2x.read_gamepad();          //read controller 
   
    if(ps2x.ButtonPressed(GREEN_FRET))
      Serial.println("Green Fret Pressed");
    if(ps2x.ButtonPressed(RED_FRET))
      Serial.println("Red Fret Pressed");
    if(ps2x.ButtonPressed(YELLOW_FRET))
      Serial.println("Yellow Fret Pressed");
    if(ps2x.ButtonPressed(BLUE_FRET))
      Serial.println("Blue Fret Pressed");
    if(ps2x.ButtonPressed(ORANGE_FRET))
      Serial.println("Orange Fret Pressed"); 

    if(ps2x.ButtonPressed(STAR_POWER))
      Serial.println("Star Power Command");
    
    if(ps2x.Button(UP_STRUM))          //will be TRUE as long as button is pressed
      Serial.println("Up Strum");
    if(ps2x.Button(DOWN_STRUM))
      Serial.println("DOWN Strum");
 
    if(ps2x.Button(PSB_START))         //will be TRUE as long as button is pressed
      Serial.println("Start is being held");
    if(ps2x.Button(PSB_SELECT))
      Serial.println("Select is being held");
    
    if(ps2x.Button(ORANGE_FRET)) {     // print stick value IF TRUE
      Serial.print("Wammy Bar Position:");
      Serial.println(ps2x.Analog(WHAMMY_BAR), DEC); 
    } 
  }
  
  else { //DualShock Controller
    ps2x.read_gamepad(false, vibrate); //read controller and set large motor to spin at 'vibrate' speed
    
    if(ps2x.Button(PSB_START)){         //will be TRUE as long as button is pressed
      Serial.println("Start is being held");
    }
    
    if(ps2x.Button(PSB_SELECT)){
      Serial.println("Select is being held"); 
    }     

    if(ps2x.Button(PSB_PAD_UP)){      //will be TRUE as long as button is pressed
      Serial.print("Up held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
      Up();
    }
    
    if(ps2x.Button(PSB_PAD_RIGHT)){
      Serial.print("Right held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
      Right();
    }

    if(ps2x.Button(PSB_PAD_LEFT)){
      Serial.print("LEFT held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
      Left();
    }
    
    if(ps2x.Button(PSB_PAD_DOWN)){
      Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
      Down();
    }
    
    vibrate = ps2x.Analog(PSAB_CROSS);  //this will set the large motor vibrate speed based on how hard you press the blue (X) button
    if (ps2x.NewButtonState()) {        //will be TRUE if any button changes state (on to off, or off to on)
      if(ps2x.Button(PSB_L3))
        Serial.println("L3 pressed");
      if(ps2x.Button(PSB_R3))
        Serial.println("R3 pressed");
      if(ps2x.Button(PSB_L2))
        Serial.println("L2 pressed");
      if(ps2x.Button(PSB_R2))
        Serial.println("R2 pressed");
      if(ps2x.Button(PSB_TRIANGLE))
        Serial.println("Triangle pressed");  
    }

    if(ps2x.ButtonPressed(PSB_CIRCLE)){               //will be TRUE if button was JUST pressed
      Serial.println("Circle just pressed");
      Thirdspeed();
    }
      
    if(ps2x.ButtonPressed(PSB_CROSS)){             //will be TRUE if button was JUST pressed OR released
      Serial.println("X just changed");
      Stopshooting();
    }
      
    if(ps2x.ButtonPressed(PSB_SQUARE)){              //will be TRUE if button was JUST released
      Serial.println("Square just released"); 
      Secondspeed();
    }

    if(ps2x.ButtonPressed(PSB_TRIANGLE)){
      Serial.print("Triangle pressed");
      fullspeed();
    }

    if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) { //print stick values if either is TRUE
      Serial.print("Stick Values:");
      Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX  
      Serial.print(",");
      Serial.print(ps2x.Analog(PSS_LX), DEC); 
      Serial.print(",");
      Serial.print(ps2x.Analog(PSS_RY), DEC); 
      Serial.print(",");
      Serial.println(ps2x.Analog(PSS_RX), DEC); 
      Stop();
    } 

    ReadJoystick();
    
    //left stick
    
    if((nJoyRy==514)&&(nJoyRx==0)){
      Serial.println("Clockwise");
      TurnClockwise();
    }
    
    else if((nJoyRy==514)&&(nJoyRx==1023)){
      Serial.println("Counter clockwise");
      TurnCClockwise();
    }
  }
  
  motor1.setSpeed(254);   // Motor 1 runs forward at full speed.
  motor2.setSpeed(-254);  // Motor 2 runs backward at full speed.
  motor3.setSpeed(-254);  // Motor 2 runs backward at full speed.
  motor4.setSpeed(254);   // Motor 1 runs forward at full speed.
  //delay(1000);
  
}

void ReadJoystick(){
  nJoyRy = map((ps2x.Analog(PSS_RY)),0,255,1023,0);
  nJoyRx = map((ps2x.Analog(PSS_RX)),0,255,1023,0);
  nJoyLy = map((ps2x.Analog(PSS_LY)),0,255,1023,0);
  nJoyLx = map((ps2x.Analog(PSS_LX)),0,255,1023,0);
}

void Direction(int a, int b, int c, int d){
  digitalWrite(dir1,a);
  digitalWrite(dir2,b);
  digitalWrite(dir3,c);
  digitalWrite(dir4,d);
}

void Speed(int e, int f, int g, int h){
  analogWrite(pwm1,e);
  analogWrite(pwm2,f);
  analogWrite(pwm3,g);
  analogWrite(pwm4,h);
}

void Stop(){
  Direction(0,0,0,0);
  Speed(0,0,0,0);
}

void Up(){
  Direction(1,0,1,0); 
  Speed(255, 255, 255, 255);
}

void Down(){
  Direction(0,1,0,1);
  Speed(255, 255, 255, 255);
}

void Left(){
  Direction(0,0,1,1);
  Speed(255, 255, 255, 255);
}

void Right(){
  Direction(1,1,0,0);
  Speed(255, 255, 255, 255);
}

void TurnClockwise(){
  Direction(1,1,1,1);
  Speed(255, 255, 255, 255);
}

void TurnCClockwise(){
  Direction(0,0,0,0);
  Speed(255, 255, 255, 255);
}

void fullspeed() {

  motor1.setSpeed(254);   // Motor 1 runs forward at full speed.
  motor2.setSpeed(-254);  // Motor 2 runs backward at full speed.
  motor3.setSpeed(-254);  // Motor 2 runs backward at full speed.
  motor4.setSpeed(254);   // Motor 1 runs forward at full speed.
  delay(1000);
  
}

void Secondspeed() {

  motor1.setSpeed(254);   // Motor 1 runs forward at full speed.
  motor2.setSpeed(-254);  // Motor 2 runs backward at full speed.
  motor3.setSpeed(-254);  // Motor 2 runs backward at full speed.
  motor4.setSpeed(254);   // Motor 1 runs forward at full speed.
  //delay(1000);
}

void Thirdspeed() {

  motor1.setSpeed(254);   // Motor 1 runs forward at full speed.
  motor2.setSpeed(-254);  // Motor 2 runs backward at full speed.
  motor3.setSpeed(-254);  // Motor 2 runs backward at full speed.
  motor4.setSpeed(254);   // Motor 1 runs forward at full speed.
  //delay(1000);
}

void Stopshooting(){

  motor1.setSpeed(0);   
  motor2.setSpeed(0);  
  motor3.setSpeed(0);  
  motor4.setSpeed(0);
  
}
