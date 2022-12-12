#include<Servo.h> 
const int num_of_motors  = 3; 
Servo motor[num_of_motors], motor4; 
int p,n, i=0; 
int onstate=0; 
int turn = 0; 

void setup() { 
  for (i  = 0; i < num_of_motors; i++) { 
    motor[i].attach(9  + i); 
  } 
  motor4.attach(6); 
  Serial.begin(9600); 
}

void loop(){ 
 if (Serial.available()) 
 { 
  char data=Serial.read(); 
  data == '1' ? onstate = 1 : onstate = 0; 
 } 
  if (onstate && turn == 0) 
  { 
    for (p=0;p<90;p++) 
    { 
      n = 90 - p; 
      motor[0].write(p); 
      motor[1].write(n); 
      motor[2].write(p); 
      motor4.write(n); 
      delay(5);   
      } 
      turn  = 1; 
  } 
  else if (onstate && turn == 1) { 
    for (p=90;p>=1;p--) 
    { 
      n = 90 - p; 
      motor[0].write(p); 
      motor[1].write(n); 
       motor[2].write(p); 
        motor4.write(n); 
         delay(5);  
      } 
    turn = 0; 
  } 
  else if (!onstate) 
  { 
    //motor.write(p); 
  } 
}
