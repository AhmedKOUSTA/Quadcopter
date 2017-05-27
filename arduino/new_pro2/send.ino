


void sendX()
{
  int Xs=map(X,-90,90,0,100);
   if(Xs<100)
    {
      Serial.print("X");
    Serial.println(Xs);
    }
    else
    {
      Serial.print("X");
    Serial.println("100");
    }
  }
  
  
  void sendY()
{
   int Ys=map(Y,-90,90,0,100);
   if(Ys<100)
    {
      Serial.print("Y");
    Serial.println(Ys);
    }
    
  }

