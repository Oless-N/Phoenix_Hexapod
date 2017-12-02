#ifndef PODA_H
#define PODA_H

#include <Servo.h>

class Poda
{

    // ///////////////////////////////////////////////
    // згідно зворотнокінематичній моделі в об’єкні пода 3 сервоприводи
    //х-горизонтальний z-середній двигун у- крвйній
    //установка положення відбувається установкою структури позішн, ініціалізація поди шляхом предачі номерів пінів відповідно
private:
    int init_x;
    int init_y;
    int init_z;
  
   
     int Max_X;
     int Max_Y;
     int Max_Z;

     int Min_X;
     int Min_Y;
     int Min_Z;
 


public:
    Servo xServo;//Coxa;
     Servo yServo;//Femur;
     Servo zServo;//Tibia;


 Poda();
 void init(int pinx, int initAngleX, int piny,int initAngleY, int pinz, int initAngleZ);
    void set_Position(int xX, int yY, int zZ);
    void set_initPos(int xX, int yY, int zZ);
    void init_Servo(int set_angle, Servo active);


};

#endif // PODA_H
