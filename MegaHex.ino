#include "Poda.h"
#include "Config_Hexa.h"
#include "Control_Kinematics.hpp"

#include <Arduino.h>

void setup()
{
Serial.begin(9600);
    //poda setUp
Poda_init();
    //motion cof setup
motionPod_Left.anglX=20;
motionPod_Left.anglY=30;
motionPod_Left.anglZ=35;

motionPod_Right.anglX=-20;
motionPod_Right.anglY=-30;
motionPod_Right.anglZ=-35;
    //

 //ultrasinic setUp
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)




}
void loop()
{
 int val = map(digitalRead(49),0,1023,0,255);
 Serial.write(val);
 delay(50);
 int input_line[18];
char rx_byte = 0;

if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
  
    // check if a number was received
    if ((rx_byte >= '0') && (rx_byte <= '9')) 
    {
      Serial.print("Number received: ");
      Serial.println(rx_byte);
    }
    else {
      Serial.println("Not a number.");
    }
}
 
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
  //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;

//Walk_Mode();
 
if  (distance<=60)
    {digitalWrite(LEDPin, HIGH);
    Rot_Mode();
    }
else{digitalWrite(LEDPin, LOW);
    Walk_Mode();
    }
  
//delay(1000);
  }
