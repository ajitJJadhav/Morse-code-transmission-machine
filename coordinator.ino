#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3); // RX, TX
char morse[10],c;
int i=0;
String S="";
void setup()
{
    Serial.begin(9600);

    Serial.println( "Arduino started receiving bytes via XBee" );

    // Set the data rate for the SoftwareSerial port.
    xbee.begin(9600);
}

void loop()  {  
  if(xbee.available())
    {  
      c = xbee.read();
      
      if(c == ' ' || c == '\n')
        Serial.print(c);
      
      //Serial.println(c);
      else if(c != '~')
      {
        morse[i]=c;
        //Serial.println(morse[i]);
         i++;
      }
      else if( c == '~')
      {
         //Serial.println(c);
        morse[i] = '\0';
        i = 0;
        
        S="";
        while(morse[i] != '\0')
        {
          S = S +  morse[i];
         //Serial.print("1");
          //Serial.print(S);
          i++;
        }
       i=0;
      // Serial.println(S);
      printaj(S);
    }
    }
    //Serial.print("Character received:");
    //Serial.println(temp);
    //delay(1000);
}

void printaj(String prevodilac)   //ugly part of the code but it works fine
{                                 //compare morse string to known morse values and print out the letter or a number 
                                  //the code is written based on the international morse code, one thing i changed is that insted of typing a special string to end the line it happens with enough delay  
  if (prevodilac=="*-")
    Serial.print("A");
  else if (prevodilac=="-***")  
    Serial.print("B");
  else if (prevodilac=="-*-*")  
    Serial.print("C");
  else if (prevodilac=="-**")  
    Serial.print("D");
  else if (prevodilac=="*")  
    Serial.print("E");
  else if (prevodilac=="**-*")  
    Serial.print("F");
  else if (prevodilac=="--*")  
    Serial.print("G");
  else if (prevodilac=="****")  
    Serial.print("H");
  else if (prevodilac=="**")  
    Serial.print("I");
  else if (prevodilac=="*---")  
    Serial.print("J");
  else if (prevodilac=="-*-")  
    Serial.print("K");
  else if (prevodilac=="*-**")  
    Serial.print("L");
  else if (prevodilac=="--")  
    Serial.print("M");
  else if (prevodilac=="-*")  
    Serial.print("N");
  else if (prevodilac=="---")  
    Serial.print("O");
  else if (prevodilac=="*--*")  
    Serial.print("P");
  else if (prevodilac=="--*-")  
    Serial.print("Q");
  else if (prevodilac=="*-*")  
    Serial.print("R");
  else if (prevodilac=="***")  
    Serial.print("S");
  else if (prevodilac=="-")  
    Serial.print("T");
  else if (prevodilac=="**-")  
    Serial.print("U");
  else if (prevodilac=="***-")  
    Serial.print("V");
  else if (prevodilac=="*--")  
    Serial.print("W");
  else if (prevodilac=="-**-")  
    Serial.print("X");
  else if (prevodilac=="-*--")  
    Serial.print("Y");
  else if (prevodilac=="--**")  
    Serial.print("Z");

  else if (prevodilac=="*----")  
    Serial.print("1");
  else if (prevodilac=="**---")  
    Serial.print("2");
  else if (prevodilac=="***--")  
    Serial.print("3");
  else if (prevodilac=="****-")  
    Serial.print("4");
  else if (prevodilac=="*****")  
    Serial.print("5");
  else if (prevodilac=="-****")
    Serial.print("6");
  else if (prevodilac=="--***")  
    Serial.print("7");
  else if (prevodilac=="---**")  
    Serial.print("8");
  else if (prevodilac=="----*")  
    Serial.print("9");
  else if (prevodilac=="-----")  
    Serial.print("0");
    
  prevodilac=""; 
}
