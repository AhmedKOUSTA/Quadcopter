    
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

 
    
 X=map(accel_x_axis,Xmin,Xmax,-90,90);
 int Xs=map(X,-90,90,0,100);
 
 Y=map(accel_y_axis,Ymin,Ymax,-90,90);
 int Ys=map(Y,-90,90,0,100);
 
    
    if(Xs<100)
    {
      Serial.print("X");
    Serial.println(Xs);
    }
    delay (10);
     if(Ys<100)
    {
      Serial.print("Y");
    Serial.println(Ys);
    }
  
   delay (10);
        sendu();         
 }
 
 
void updateSensorVal()
{
   Wire.requestFrom (0x52, 6);
 
        while (Wire.available ()) {
            buffer[cnt] = nunchuk_decode_byte (Wire.read ());
            
            cnt++;
        }
 

  if (cnt >= 5)
    parse();
   cnt = 0;
  handshake();
  }
  

char nunchuk_decode_byte (char x)
{
    x = (x ^ 0x17) + 0x17;
    return x;
}
 
 
 
void handshake() // Handshack, merci captain obvious !
{
  Wire.beginTransmission (0x52);	
  Wire.write (0x00);	
  Wire.endTransmission ();
}

void nunchuck_init()
{
    Wire.beginTransmission (0x52);
    Wire.write (0x40);
    Wire.write (0x00);
    Wire.endTransmission ();
}
 
 void send_zero()
{
    Wire.beginTransmission (0x52);
    Wire.write (0x00);
    Wire.endTransmission ();
}
 
