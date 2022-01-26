#include <IRremote.h>
int RECV_PIN = 11;
int BLUE_LED = 12;
int RED_LED = 9;



IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(RECV_PIN, INPUT);  
  pinMode(BLUE_LED, OUTPUT); 
  pinMode(RED_LED, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
  Serial.begin(9600);
}
void loop() {
  int i=0;
   if (irrecv.decode(&results)) {
   
   translateIR();
      
     irrecv.resume(); // Receive the next value
    
   }   
 }

 void translateIR() // takes action based on IR code received describing Car MP3 IR codes 
{

  switch(results.value){
  case 0xFFA25D:  
    Serial.println("  RED_LED_ON           "); 
    digitalWrite(9, HIGH);
    break;
  case 0xFF629D:  
    Serial.println("  RED_LED_OFF            "); 
    digitalWrite(9, LOW);
    break;
  case 0xFFE21D:  
    Serial.println(" CH+            "); 
    break;
  case 0xFF22DD:  
    Serial.println(" blue LED off          "); //*****************************************************************************************
    digitalWrite(12,1);                         //*****************************************************************************************
    break;
  case 0xFF02FD:  
    Serial.println(" blue LED on        "); 
    digitalWrite(12, 0);
    break;
  case 0xFFC23D:  
    Serial.println(" PLAY/PAUSE     "); 
    break;
  case 0xFFE01F:  
    Serial.println(" VOL-           "); 
    break;
  case 0xFFA857:  
    Serial.println(" VOL+           "); 
    break;
  case 0xFF906F:  
    Serial.println(" EQ             "); 
    break;
  case 0xFF6897:  
    Serial.println(" 0              "); 
    break;
  case 0xFF9867:  
    Serial.println(" 100+           "); 
    break;
  case 0xFFB04F:  
    Serial.println(" 200+           "); 
    break;
  case 0xFF30CF:  
    Serial.println(" 1              "); 
    break;

  case 0xFF18E7:  
    Serial.println(" 2              "); 
    break;

  case 0xFF7A85:  
    Serial.println(" 3              "); 
    break;

  case 0xFF10EF:  
    Serial.println(" 4              "); 
    break;

  case 0xFF38C7:  
    Serial.println(" 5              "); 
    break;

  case 0xFF5AA5:  
    Serial.println(" 6              "); 
    break;

  case 0xFF42BD:  
    Serial.println(" 7              "); 
    break;

  case 0xFF4AB5:  
    Serial.println(" 8              "); 
    break;

  case 0xFF52AD:  
    Serial.println(" 9              "); 
    break;

  default: 
    Serial.print(" unknown button   ");
    Serial.println(results.value, HEX);

  }

  delay(500);


} 
                  
void unknownRemoter(){                       //this function is from an old remoter see video.
long RED_LED_OFF = 0xFF629D;
long RED_LED_ON =  0xFFA25D;
long LAST_BUTTON = 0xFFD02F;

if (results.value == RED_LED_OFF){
      Serial.println ("Red led off");
      digitalWrite(9,LOW);
      }
     else if (results.value == RED_LED_ON )
      {
       Serial.println ("Red led on");
      digitalWrite(9,HIGH);
      }
     else if (results.value == LAST_BUTTON )
      {
       Serial.println ("CAMERA IMAGE button");
      }else{
         Serial.print(" still an unknown button   ");
         Serial.println(results.value, HEX);
        }
}

