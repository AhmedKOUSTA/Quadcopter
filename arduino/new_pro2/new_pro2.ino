  #include <Wire.h>
#include <Servo.h> 
#include <PID_v1.h>
#include "config.h"


int X,Y,Z;      // Sonsor value           


void setup()
{
    initESCs(); 
    init_communication();
    Wire.begin ();
    nunchuck_init ();
    SetupUltraSon();
    init_PID();

}


void loop()
{
   readStr();
  
updateSensorVal(); 
//updatePID();
//updateMotors();
delay (update_time);
 
}


