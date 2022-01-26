int segA = 11;
int segB = 10;
int segC = 9;
int segD = 8;
int segE = 7;
int segF = 6;
int segG = 5;
int segdp = 4;
int segcom = 12;

void setup() {
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segdp, OUTPUT);
  pinMode(segcom, OUTPUT);
}

void loop() {
digitalWrite(segcom, 0);
for (int i = 0; i < 10; i++){
  
  case0:
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 0);
  digitalWrite(segdp, 0);
  break;

  case1:
  digitalWrite(segA, 0);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 0);
  digitalWrite(segE, 0);
  digitalWrite(segF, 0);
  digitalWrite(segG, 0);
  digitalWrite(segdp, 0);
  break;
 
  
  case2:
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 0);
  digitalWrite(segD, 1);
  digitalWrite(segE, 1);
  digitalWrite(segF, 0);
  digitalWrite(segG, 1);
  digitalWrite(segdp, 0);
  break;
  
  case3:
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 0);
  digitalWrite(segF, 0);
  digitalWrite(segG, 1);
  digitalWrite(segdp, 0);
  break;
  
  case4:
  digitalWrite(segA, 0);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 0);
  digitalWrite(segF, 0);
  digitalWrite(segG, 1);
  digitalWrite(segdp, 0);
  break;
  
  case5:
  digitalWrite(segA, 1);
  digitalWrite(segB, 0);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 0);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
  digitalWrite(segdp, 0);
  break;
  
  case6:
  digitalWrite(segA, 1);
  digitalWrite(segB, 0);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
  digitalWrite(segdp, 0);
  break;
  
  case7:
  digitalWrite(segA, 1);
  digitalWrite(segB, 0);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
  digitalWrite(segdp, 0);
  break;
  
  case8:
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 1);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
  digitalWrite(segdp, 0);
  break;
  
  case9:
  digitalWrite(segA, 1);
  digitalWrite(segB, 1);
  digitalWrite(segC, 1);
  digitalWrite(segD, 1);
  digitalWrite(segE, 0);
  digitalWrite(segF, 1);
  digitalWrite(segG, 1);
  digitalWrite(segdp, 0);
  break;

  delay(1000);
}
}
