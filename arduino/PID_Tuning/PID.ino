
double PITCH_P_VAL=300;
double PITCH_I_VAL=1;
double PITCH_D_VAL=1;

float Vitesse=1000;    // global velocity
float Vmax=1200;
float Vmin=1600;
float X_value=0;

float bal_bd;  
double XSetpoint, XInput,XOutput;
float Erreur;

// correction selon axe Y
PID XPID(&X_value, &XOutput, &XSetpoint,PITCH_P_VAL,PITCH_I_VAL,PITCH_D_VAL, DIRECT);
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
       X_value=map(100*x_axe,-60,60,0,2000);
        XSetpoint=Vitesse;
       XPID.Compute();
      
      // velocity=XOutput;
        
    Serial.println(velocity);
 //     }
     /* 
 else
      {       
        // XPID.Compute();
         velocity=Vitesse; //-XOutput;
         
        }*/
       

   
  }


  
