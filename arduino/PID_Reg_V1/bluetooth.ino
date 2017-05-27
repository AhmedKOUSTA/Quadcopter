
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String valueString = "";  

void init_communication()
{  
     Serial.begin(9600);
     inputString.reserve(4);
     valueString.reserve(3);
  }

void readStr(){
  
    
           
           
  if (stringComplete) {
        
         if(inputString[0]=='a')
                    {
                    arm();
                     Serial.println("a");
                    }
        else if(inputString[0]=='d')
                   {
                    disarm();
                     Serial.println("d");
                    }
                    
         else if(inputString[0]=='T')
                   {
                      inputString[0]='0';
                     int value = inputString.toInt();
                     set_speed(value);
                     Serial.println(value);
                    
                    }
         else if(inputString[0]=='P'){
           }
         else if(inputString[0]=='I'){
           }
         else if(inputString[0]=='T'){
           }
             
            inputString = "";
            stringComplete = false;
          }
}

void serialEvent(){
    while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
}
}

