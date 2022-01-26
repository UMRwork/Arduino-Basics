#include <IRremote.h>

int RECV_PIN = 12;
int led1 = 2;
int led2 = 4;
int Pin1 = 8;
int Pin2 = 9;
int Pin3 = 10;
int Pin4 = 11;
int _step = 0;
boolean dir = false;
int itsONled[] = {0,0,0,0};
#define code1  12495
#define code2  6375
#define code3  45135
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
Serial.begin(9600);
irrecv.enableIRIn();
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
}

void loop() {
if (irrecv.decode(&results)){
  unsigned int value = results.value;
  switch(value)  {
    case code1:
    if(itsONled[1] == 1)  {
      digitalWrite(led1, LOW);
      itsONled[1] = 0;
    }else {
      
      digitalWrite(led1, HIGH);
      itsONled[1] = 1;
    }
    break;
        case code2:
    if(itsONled[2] == 1)  {
      digitalWrite(led2, LOW);
      itsONled[2] = 0;
    }else {
      digitalWrite(led2, HIGH);
      itsONled[2] = 1;
    }
    break;
        case code3:
    if(itsONled[3] == 1)  {
      switch(_step){
  case 0:
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, LOW);
  digitalWrite(Pin3, LOW);
  digitalWrite(Pin4, HIGH);
  break;
  case 1:
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, LOW);
  digitalWrite(Pin3, HIGH);
  digitalWrite(Pin4, HIGH);
  break;
  case 2:
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, LOW);
  digitalWrite(Pin3, HIGH);
  digitalWrite(Pin4, LOW);
  break;
  case 3:
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, HIGH);
  digitalWrite(Pin3, HIGH);
  digitalWrite(Pin4, LOW);
  break;
  case 4:
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, HIGH);
  digitalWrite(Pin3, LOW);
  digitalWrite(Pin4, LOW);
  break;
  case 5:
  digitalWrite(Pin1, HIGH);
  digitalWrite(Pin2, HIGH);
  digitalWrite(Pin3, LOW);
  digitalWrite(Pin4, LOW);
  break;
  case 6:
  digitalWrite(Pin1, HIGH);
  digitalWrite(Pin2, LOW);
  digitalWrite(Pin3, LOW);
  digitalWrite(Pin4, LOW);
  break;
  case 7:
  digitalWrite(Pin1, HIGH);
  digitalWrite(Pin2, LOW);
  digitalWrite(Pin3, LOW);
  digitalWrite(Pin4, HIGH);
  break;
  default:
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, LOW);
  digitalWrite(Pin3, LOW);
  digitalWrite(Pin4, LOW);
  break;
}
if(dir){
  _step++;
}else{
  _step--;
}
if(_step>7){
  _step=0;
}
if(_step<0){
  _step=7;
}
delay(1);
}
      itsONled[2] = 0;
    }}else {
      digitalWrite(led2, HIGH);
      itsONled[2] = 1;
    }
    Serial.begin(9600);
    }  irrecv.println(value);
  irrecv.resume(); 
}
}
