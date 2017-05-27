
#define PITCH_P_VAL 300
#define PITCH_I_VAL 1
#define PITCH_D_VAL 1

float Vitesse=1000;    // global velocity
float Vmax=1200;
float Vmin=1600;


float bal_bd;  
double XSetpoint, XInput,XOutput;
float Erreur;

// correction selon axe Y
PID XPID(&x_axe, &XOutput, &XSetpoint,PITCH_P_VAL,PITCH_I_VAL,PITCH_D_VAL, DIRECT);
//PID pitchReg(&x_axe, &motor_sp, &Setpoint, PITCH_P_VAL, PITCH_I_VAL, PITCH_D_VAL, REVERSE);


void set_speed(int value)
{
 Vitesse=map(value,0,120,800,2000);
}

void init_PID(){
  

  XSetpoint=0;
     
  XPID.SetMode(AUTOMATIC);
 
  

  }
  
  void updatePID()
  {  
    
    /* Erreur=Yaw-x_axe;
      Serial.print(x_axe);
      int x_axe = map(100*x_axe,-60 , 60, 0, 80);
      
      Serial.print("      ");
      XPID.Compute();
      Serial.println(100*XOutput);
      
*/



if(x_axe>0)
    {
     
     x_axe=-x_axe;
        XPID.Compute();
       
       velocity=Vitesse+XOutput;
     
         
      
     //  Serial.print("+");
       
      } 
      
 /*
 else
      {
          Serial.print(x_axe);
       Serial.print("      ");
        
         XPID.Compute();
         if ((Vitesse-(100*XOutput))>Vmin)
            velocity=Vitesse-(100*XOutput);
         else
             velocity=Vmin;
         Serial.println(XOutput);
        }
        */

   
  }


  
