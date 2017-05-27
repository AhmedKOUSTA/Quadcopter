

int Vitesse;    // global velocity


double XSetpoint,YSetpoint, XInput,YInput, XOutput,YOutput;


// correction selon axe X
PID XPID(&XInput, &XOutput, &XSetpoint,0.35,0.005,0.005, DIRECT);
// correction selon axe Y
PID YPID(&YInput, &YOutput, &YSetpoint,0.35,0.005,0.005, DIRECT);

void Yaw(int value){
   if((value>30)&&(value<60))
      XSetpoint=value;
   else if((value<-30)&&(value>-60))
      XSetpoint=value;
  }

void Roll(int value){
  
  }

void Pitch(int value){
   if((value>30)&&(value<60))
      YSetpoint=value;
   else if((value<-30)&&(value>-60))
      YSetpoint=value;
  }

void Throttle(int value){
   if((value<120)&&(value>0))
   Vitesse=map(value,0,120,0,2000);
  }

void init_PID(){
  
    YSetpoint = 0;
     XSetpoint = 0;
     YPID.SetMode(AUTOMATIC);
    
  }



void updatePID()
{
   if(X>0)
  {
    XInput=-X;
    XPID.Compute();
  va=Vitesse+XOutput;
   vb=Vitesse-XOutput;
  }
  else
  {
    XInput=X;
     XPID.Compute();
     va=Vitesse-XOutput;
      vb=Vitesse+XOutput;
  }
  
  if(Y>0)
  {
    YInput=-Y;
    YPID.Compute();
  vc=Vitesse+YOutput;
   vd=Vitesse-YOutput;
  }
  else
  {
    YInput=Y;
     YPID.Compute();
     vc=Vitesse-YOutput;
      vd=Vitesse+YOutput;
  }
  
 // vc=map(Y,-90,90,Vitesse-50,Vitesse+50);
    //vc=((ESC_MAX-ESC_MIN)/180)*Y+Vitesse;
    // vd=map(Y,-90,90,Vitesse+4,Vitesse-4);
 // vd=((ESC_MIN-ESC_MAX)/180)*Y+Vitesse;
 
  
  }
  
  
