
int trig = 12; 
int echo = 11; 
long lecture_echo; 
long cm;

void updateUltraSon()
{
   digitalWrite(trig, HIGH); 
 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 
  lecture_echo = pulseIn(echo, HIGH); 
  cm = lecture_echo / 58; 

}

void sendu()
{
    updateUltraSon();
     Serial.print("U");
            Serial.println(cm);
   delay(10);
  }
  
void SetupUltraSon()
{
    pinMode(echo, INPUT); 
    pinMode(trig, OUTPUT); 
}
