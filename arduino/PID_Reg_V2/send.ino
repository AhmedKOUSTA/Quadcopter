
void sendX(int value)
{
  int Xs=value;
   if(Xs>100)
    {
      
      Serial.print("X");
    Serial.println("100");
    
     
    }
    else if(Xs<0)
    {
       Serial.print("X");
    Serial.println("0");
    }
    
    else
    {
       Serial.print("X");
    Serial.println(Xs);
      }
  }
  
