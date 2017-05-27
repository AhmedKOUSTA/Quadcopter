#include <Wire.h>
#include <Servo.h> 
#include <PID_v1.h>
#include "config.h"


int X;      // Sonsor value           
double x_axe;
// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup()
{
    
   init_communication();
   
  // Serial.begin(9600);
    while (!Serial);
    
    MPU_init();
  
   init_PID();
   initESCs();
}


void loop()
{
   
readStr();
getYPR();

updatePID();
updateMotor();
delay (update_time);
 
}


