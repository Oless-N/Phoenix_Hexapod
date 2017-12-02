#ifndef CONTROLWITHKITEMATIC_H
#define CONTROLWITHKITEMATIC_H

#include "Config_Hexa.h"
#include<Arduino.h>


//kinematic///////////////////////////////////
            /////////////////
            ///  L1   R1  ///
            ///    \-/    ///
            /// L2_| |_R2 ///
            ///    / \    ///
            ///  L3   R3  ///
            /////////////////
            ///             /
            ///       z\    /
            ///      /  \   /
            /// x__y/    \  /
            ///             /
            /////////////////




// /////////////////////////////////////////////

//////////////////////
/// \Motion Mode's/\\\
//////////////////////

void Motion(Poda pPod, PodPosition pPos, int motionPeriod)
{
PodPosition Flag;

Flag.anglZ=pPod.zServo.read();
Flag.anglX=pPod.xServo.read();
Flag.anglY=pPod.yServo.read();

if ( motionPeriod==1){
pPod.zServo.write((Flag.anglZ+pPos.anglZ));
pPod.yServo.write((Flag.anglY+pPos.anglY));
pPod.xServo.write((Flag.anglX+pPos.anglX));


delay(300);
}
else if ( motionPeriod==2){
pPod.xServo.write((Flag.anglX+(pPos.anglX)));
/*
pPod.yServo.write((Flag.anglY-(2*pPos.anglY)));
pPod.zServo.write((Flag.anglZ-(2*pPos.anglZ)));*/

delay(300);}
else if ( motionPeriod==3){
pPod.zServo.write(Flag.anglZ);
pPod.yServo.write(Flag.anglY);
pPod.xServo.write(Flag.anglX);

delay(300);}

//delay(500);
  }
void Rot_Mode()
{

 /* Motion (podaL1,motionPod_Left);
  Motion (podaL2,motionPod_Left);
             delay(100);
  Motion (podaL3,motionPod_Left);
  Motion (podaR1,motionPod_Right);
             delay(100);
  Motion (podaR2,motionPod_Right);
  Motion (podaR3,motionPod_Right);
             delay(100);*/
}
void Walk_Mode()
{       //піднфмаємо перші 3 лапки
        podaL1.set_Position(90,40,(30-20));
        podaR2.set_Position(90,150,(160-20));
        podaL3.set_Position(90,40,(30-20));
        delay(100);
        podaL1.set_Position(90,(40+10),(30-20));
        podaR2.set_Position(90,(150+10),(160-20));
        podaL3.set_Position(90,(40+10),(30-20));
        delay(100);

        //зміщуємо 3 лапки
        podaL1.set_Position((90-20),(40+10),(30-20));
        podaR2.set_Position((90+20),(150+10),(160-20));
        podaL3.set_Position((90-20),(40+10),(30-20));
        delay(100);
        //опускаємо лапки
        podaL1.set_Position((90-20),(40),(30));
        podaR2.set_Position((90+20),(150),(160));
        podaL3.set_Position((90-20),(40),(30));
        delay(100);
//////////////підншмаємо 2і 3 лапки
        podaR1.set_Position((90),(150),(160+20));
        podaL2.set_Position((90),(40),(30+20));
        podaR3.set_Position((90),(150),(160+20));

        podaR1.set_Position((90),(150+10),(160-20));
        podaL2.set_Position((90),(40+10),(30-20));
        podaR3.set_Position((90),(150+10),(160-20));
        //зміщуємо 1і 3 лапки
        podaL1.set_Position((90-20),(40),(30));
        podaR2.set_Position((90+20),(150),(160));
        podaL3.set_Position((90-20),(40),(30));
        delay(300);
/////////////
        podaR1.set_Position((90+20),(150+10),(160-20));
        podaL2.set_Position((90+20),(40+10),(30-20));
        podaR3.set_Position((90+20),(150+10),(160-20));
//        
        podaR1.set_Position((90+20),(150),(160));
        podaL2.set_Position((90-20),(40),(30));
        podaR3.set_Position((90+20),(150),(160));        
        
}


#endif // CONTROLWITHKITEMATIC_H
