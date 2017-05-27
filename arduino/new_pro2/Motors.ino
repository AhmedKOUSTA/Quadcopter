float va, vb, vc, vd;                    //velocities
Servo a,b,c,d;

void updateMotors(){

  a.writeMicroseconds(va);
  c.writeMicroseconds(vc);
  b.writeMicroseconds(vb);
  d.writeMicroseconds(vd);

}

void Motor_test(){

 
  a.write(ESC_TEST);
  b.write(0);
  c.write(0);
  d.write(0);
  
  delay(ESC_test_DELAY);
  a.write(0);
  b.write(ESC_TEST);
  c.write(0);
  d.write(0);
  
  delay(ESC_test_DELAY);
  a.write(0);
  b.write(0);
  c.write(ESC_TEST);
  d.write(0);
  
  delay(ESC_test_DELAY);
  a.write(0);
  b.write(0);
  c.write(0);
  d.write(ESC_TEST);
  
  delay(ESC_test_DELAY);
  delay(ESC_test_DELAY);
  delay(ESC_test_DELAY);
 
}

void spe(int value){

  a.write(value);
  b.write(value);
  c.write(value);
  d.write(value);
  

}


void arm(){

  a.write(ESC_MIN);
  b.write(ESC_MIN);
  c.write(ESC_MIN);
  d.write(ESC_MIN);
   
  delay(ESC_ARM_DELAY);

}


void disarm(){

  a.write(0);
  b.write(0);
  c.write(0);
  d.write(0);
   
  delay(ESC_ARM_DELAY);

}

void initESCs(){

  a.attach(ESC_A);
  b.attach(ESC_B);
  c.attach(ESC_C);
//  d.attach(ESC_D);
  
  delay(100);
  
 disarm();

}

