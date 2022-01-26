int trigPin = 9;                              
int echoPin = 10;                 
int led = 6;                             //led

void setup()
{
Serial.begin(9600);                 
pinMode(trigPin, OUTPUT);          
pinMode(echoPin, INPUT);          
pinMode(led, OUTPUT);                     //led
}
void loop() {
  long duration, distance;                  
  digitalWrite(trigPin, HIGH);          
  delayMicroseconds(1000);               
  digitalWrite(trigPin, LOW);            
  duration = pulseIn(echoPin, HIGH);       
  distance = (duration/2) / 29.1;          
  Serial.print(distance);                
  Serial.println("cm");             
  delay(10);                              
  
  if((distance<=50)) {                  
    digitalWrite(led, HIGH);             //led
    delay(1000);                         //led
  }
  else if(distance>50) {                     
    digitalWrite(led, LOW);              //led
    delay(1000);                         //led
  }
}

