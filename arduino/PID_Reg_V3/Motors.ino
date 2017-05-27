float velocity;                    //velocities
Servo a,ser;

void updateMotor(){

 a.writeMicroseconds(velocity);
    
}



void arm(){

  a.write(70);
 
   
  delay(ESC_ARM_DELAY);

}


void disarm(){

  a.write(0);

   set_speed(0);
  delay(ESC_ARM_DELAY);

}

void initESCs(){


  a.attach(ESC);
  ser.attach(serv);
 
  
  delay(100);
  
 disarm();

}

void updateservo(int value){

 ser.write(value);
    
}

