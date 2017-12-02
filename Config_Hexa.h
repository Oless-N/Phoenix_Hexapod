#ifndef CONFIGHEXA_H
#define CONFIGHEXA_H

#include "Poda.h"
#include <Arduino.h>
#define sqr(x) ((x)*(x))
#define PI 3.141592653589793238
#define rad2deg(x) ( (180.0 / PI) * (x) )
#define deg2rad(x) ( (PI / 180.0) * (x) )

/////////////////////////////////////////
//   ultrasonic pinout                 //
//                                     //
    #define echoPin 49 // Echo Pin
    #define trigPin 48 // Trigger Pin
    #define LEDPin 13 // Onboard LED
/////  ultrasonic       /////////////////
//
     int maximumRange = 200; // Maximum range needed
     int minimumRange = 0; // Minimum range needed
      long duration, distance; // Duration used to calculate distance
//
////////////////////////////////////////

///make Poda's from this shemm

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

int pin[]=
{36, 35, 34,
 33, 32, 31,
 30, 29, 28,

 45, 44, 43,
 42, 41, 40,
 39, 38, 37};
///pin out arduino (digital pins)
/// L1 46, 47, 39
/// L2 40, 41, 42
/// L3 43, 44, 45
///
/// R1 29, 28, 36
/// R2 35, 34, 33
/// R3 32, 31, 30
///
///
///
/// angle initialisation servo in grad
/// defailt to Phoenix hexapod
/// L1 90, 40, 30,
/// L2 490, 40, 30,
/// L3 90, 40, 30,
///
/// R1 90, 150, 160,
/// R2 90, 150, 160,
/// R3 90, 150, 160
///
int angle[]=
{
    90, 40, 30,
    90, 40, 30,
    90, 40, 30,
    
    90, 150, 160,
    90, 150, 160,
    90, 150, 160
};

//////Poda_init///////

Poda podaL1;
Poda podaL2;
Poda podaL3;

Poda podaR1;
Poda podaR2;
Poda podaR3;

void Poda_init()
{
podaL1.init ( pin[0],angle[0], pin[1],angle[1], pin[2],angle[2]);
delay(300);
podaL2.init (pin[3],angle[3], pin[4],angle[4], pin[5],angle[5] );
delay(300);
podaL3.init (pin[6],angle[6], pin[7],angle[7], pin[8],angle[8] );
delay(300);

podaR1.init (pin[9],angle[9], pin[10],angle[10], pin[11],angle[11] );
delay(300);
podaR2.init (pin[12],angle[12], pin[13],angle[13], pin[14],angle[14] );
delay(300);
podaR3.init (pin[15],angle[15], pin[16],angle[16], pin[17],angle[17]);
delay(300);
  
  }

struct PodPosition
{
    int anglX;
    int anglY;
    int anglZ;
};

PodPosition motionPod_Left;
PodPosition motionPod_Right;

#endif /// CONFIGHEXA_H
