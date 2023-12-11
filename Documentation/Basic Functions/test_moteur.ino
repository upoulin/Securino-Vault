#include <Servo.h>

Servo servo;
int angle = 0;
int moteur = 5;

void setup() {
  servo.attach(moteur);
  servo.write(angle);
}


void loop() 
{ 
 // scan from 0 to 180 degrees
  for(angle = 0; angle < 90; angle++)  
  {                                  
    servo.write(angle);               
    delay(20);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 90; angle > 0; angle--)    
  {                                
    servo.write(angle);           
    delay(20);       
  } 
}