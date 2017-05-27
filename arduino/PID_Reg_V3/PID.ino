
double PITCH_P_VAL=300;
double PITCH_I_VAL=1;
double PITCH_D_VAL=1;

float Vitesse=1000;    // global velocity
float Vmax=1200;
float Vmin=1600;


float bal_bd;  
double XSetpoint, XInput,XOutput;
float Erreur;

// correction selon axe Y
PID XPID(&XInput, &XOutput, &XSetpoint,PITCH_P_VAL,PITCH_I_VAL,PITCH_D_VAL, DIRECT);
//PID pitchReg(&x_axe, &motor_sp, &Setpoint, PITCH_P_VAL, PITCH_I_VAL, PITCH_D_VAL, REVERSE);


void set_speed(int value)
{
 Vitesse=value;
}

void init_PID(){
  

  XSetpoint=0;
     
  XPID.SetMode(AUTOMATIC);
 
  

  }
  
  void updatePID()
  {  
    
       double val= map(100*x_axe,-60,60,120,0);
       if (val>0&&val<120)
              XInput=val;
      XSetpoint=Vitesse;
       XPID.Compute();
       velocity=map(XOutput,0,120,1200,1800);
       
      
   
   
  }


  
  void set_P(int value)
{
  PITCH_P_VAL=(double)value;
set_pid_values();  

}
  
  void set_I(int value)
{
  PITCH_I_VAL=(double)value/100;
set_pid_values();  
}
  
  void set_D(int value)
{
  PITCH_D_VAL=(double)value/100;
  set_pid_values();
  }
  
  void set_pid_values(){
    XPID.SetTunings(PITCH_P_VAL, PITCH_I_VAL, PITCH_D_VAL);
  }
