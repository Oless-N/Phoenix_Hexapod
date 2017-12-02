#include "Poda.h"
#include <Arduino.h>

Poda::Poda()
{};

void Poda::init(int pinx, int initAngleX, int piny,int initAngleY, int pinz, int initAngleZ)
{

xServo;
yServo;
zServo;
xServo.attach(pinx);
yServo.attach(piny);
zServo.attach(pinz);

this->set_initPos(initAngleX,initAngleY,initAngleZ);

init_Servo(initAngleX, xServo);
init_Servo(initAngleY, yServo);
init_Servo(initAngleZ, zServo);


}

  void Poda::set_Position(int xXx, int yYy, int zZz)
  {
    xServo.write(xXx);
    yServo.write(yYy);
    zServo.write(zZz);
  }
  void Poda::set_initPos(int xX, int yY, int zZ)
  {
      init_x=xX;
      init_y=yY;
      init_z=zZ;
  }

  void Poda::init_Servo(int set_angle, Servo active)
  {
      if (active.read()>set_angle)
      {
                  for (int pos = active.read(); pos > set_angle; pos -= 1) {  // goes from 180 degrees to 0 degrees
                      active.write(pos);                          // tell servo to go to position in variable 'pos'
                      //delay(1);                                  // waits 15ms for the servo to reach the position
                    }
      }
      else
      {
                  for (int pos2 = active.read(); pos2 < set_angle; pos2 += 1) {  // goes from 180 degrees to 0 degrees
                      active.write(pos2);                          // tell servo to go to position in variable 'pos'
                     // delay(1);                                  // waits 15ms for the servo to reach the position
                    }
      }
  }
