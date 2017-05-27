#include <Wire.h>
#include <Servo.h> 


/* ESC pin configuration
 *
 */
#define ESC_A 6
#define ESC_B 3
#define ESC_C 5
#define ESC_D 9


/* ESC configuration
 *
 */

#define ESC_MIN 40
#define ESC_MAX 120
#define ESC_TAKEOFF_OFFSET 50
#define ESC_ARM_DELAY 5000


#define update_time 10


#define Xmin 134
#define Xmax 550
#define X0 497

#define Ymin 144
#define Ymax 570
#define Y0 507  

#define Z0 241
#define Z1 520


Servo a,b,c,d;

int velocity,X,Y,Z;                          // global velocity

float bal_ac, bal_bd;                 // motor balances can vary between -100 & 100
float bal_axes;                       // throttle balance between axes -100:ac , +100:bd

int va, vb, vc, vd;                    //velocities
int v_ac, v_bd;                        // velocity of axes

int Vitesse=70;





void setup()
{
 
  initESCs(); 
  Serial.begin(9600);
  Wire.begin();

  Wire.beginTransmission (0x52); // Séquence d'initialisation
  Wire.write (0x40);
  Wire.write (0x00);
  Wire.endTransmission ();
}




void handshake() // Handshack, merci captain obvious !
{
  Wire.beginTransmission (0x52);	
  Wire.write (0x00);	
  Wire.endTransmission ();
}

byte buffer[6]; // Buffer contenant les 6 précieux octets qui nous intéresse
byte cnt = 0; // index courant de buffer

void parse()
{
  
  int accel_x_axis = buffer[2] * 4; // accéléromètre axe x
  int accel_y_axis = buffer[3] * 4; // accéléromètre axe y
  int accel_z_axis = buffer[4] * 4; // accéléromètre axe z

  if ((buffer[5] >> 2) & 1)
    accel_x_axis += 2;

  if ((buffer[5] >> 3) & 1)
    accel_x_axis += 1;

  if ((buffer[5] >> 4) & 1)
    accel_y_axis += 2;

  if ((buffer[5] >> 5) & 1)
    accel_y_axis += 1;

  if ((buffer[5] >> 6) & 1)
    accel_z_axis += 2;

  if ((buffer[5] >> 7) & 1)
    accel_z_axis += 1;


if(accel_x_axis<X0)
   X=map(accel_x_axis,Xmin,X0,-90,0);
  else
  X=map(accel_x_axis,X0,Xmax,0,90);
  if(accel_y_axis<Y0)
 Y=map(accel_y_axis,Ymin,Y0,-90,0);
 else
 Y=map(accel_y_axis,Y0,Ymax,0,90);
 
 }

void loop()
{
  
  Wire.requestFrom (0x52, 6);
  while (Wire.available ())
  {
    buffer[cnt] = Wire.read();
    cnt++;
  }

  if (cnt >= 5)
    parse();
   cnt = 0;
  handshake();


  vc=((ESC_MAX-ESC_MIN)/180)*Y+Vitesse;
  vd=((ESC_MIN-ESC_MAX)/180)*Y+Vitesse;

Serial.print (Y, DEC);
  Serial.print ("\t");

  Serial.print (vc, DEC);
  Serial.print ("\t");
  
  Serial.print (vd, DEC);
  Serial.print ("\t");

Serial.println();
  updateMotors();
 
  delay (update_time);
}




void updateMotors(){

  a.write(va);
  c.write(vc);
  b.write(vb);
  d.write(vd);

}


void arm(){

  a.write(ESC_MIN);
  b.write(ESC_MIN);
  c.write(ESC_MIN);
  d.write(ESC_MIN);
  
  delay(ESC_ARM_DELAY);

}

void initESCs(){

  a.attach(ESC_A);
  b.attach(ESC_B);
  c.attach(ESC_C);
  d.attach(ESC_D);
  
  delay(100);
  
  arm();

}

