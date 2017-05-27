
int PITCH_P_VAL=300;
int PITCH_I_VAL=1;
int PITCH_D_VAL=1;

float Vitesse=1000;    // global velocity
float Vmax=1200;
float Vmin=1600;


float bal_bd;  
double XSetpoint, XInput,XOutput;
float Erreur;

// correction selon axe Y
PID XPID(&x_axe, &XOutput, &XSetpoint,PITCH_P_VAL,PITCH_I_VAL,PITCH_D_VAL, DIRECT);
//PID pitchReg(&x_axe, &motor_sp, &Setpoint, PITCH_P_VAL, PITCH_I_VAL, PITCH_D_VAL, REVERSE);

void set_P(int value)
{
  PITCH_P_VAL=value;
  }
  
  void set_I(int value)
{
  PITCH_I_VAL=value/100;
  }
  
  void set_D(int value)
{
  PITCH_D_VAL=value/100;
  }
  
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
   
//if(x_axe>0)
  //  {
       x_axe=-abs(x_axe);
       XPID.Compute();
       velocity=Vitesse+XOutput;
        
    Serial.println(velocity);
 //     }
     /* 
 else
      {       
        // XPID.Compute();
         velocity=Vitesse; //-XOutput;
         
        }*/
       

   
  }


  
