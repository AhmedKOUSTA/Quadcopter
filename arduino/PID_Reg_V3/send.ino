
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
  
  
void sendY(int value)
{
  int Ys=value;
   if(Ys>100)
    {
      
      Serial.print("Y");
    Serial.println("100");
    
     
    }
    else if(Ys<0)
    {
       Serial.print("Y");
    Serial.println("0");
    }
    
    else
    {
       Serial.print("Y");
    Serial.println(Ys);
      }
  }
  
