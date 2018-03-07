#include <SoftwareSerial.h>
SoftwareSerial xbee(2,3); // RX, TX

const int buttonPin = 5;    

int buttonState = LOW;             
int lastButtonState = LOW;  

int pause_value = 250;  // depending on your skill and how fast your fingers are you can change this value to make typing a message faster or slower
long signal_length = 0;
long pause = 0;

String morse="";
String dash="-";
String dot="*";

boolean cheker = false;
boolean linecheker = false;
boolean spacechecker = false;

long lastDebounceTime = 0;  
long debounceDelay = 50;

char c;
    
void setup()
{
  Serial.begin(9600);
  xbee.begin(9600);
  pinMode(buttonPin, INPUT);
  
  while(!digitalRead(buttonPin))
    ;
  
}

void loop() {
 
  buttonState = digitalRead(buttonPin);

  if (buttonState && lastButtonState)       // basic state machine depending on the state of the signal from the button
  {
    ++signal_length;       
  }
  else if(!buttonState && lastButtonState)          //this part of the code happens when the button is released and it send either * or - into the buffer
  {
     if (signal_length>50 && signal_length<2*pause_value )
     {
       morse =  morse + dot;
     } 
      else if (signal_length>2*pause_value)
      {
        morse = morse +  dash;
      }
    signal_length=0; 
    }
  else if(buttonState && !lastButtonState)          // this part happens when the button is pressed and its use to reset several values
  {
    pause=0;
    cheker = true;
    linecheker = true;
    spacechecker = true;
  }
  else if (!buttonState && !lastButtonState)
  {  
    ++pause;
    if (( pause>3*pause_value ) && (cheker))
    { 
      //printaj(morse);
      //morse = morse + '\0';
      int i=0;
      
      while(morse[i] != '\0')
       {
        c = morse[i];
       // Serial.print(c);
        xbee.write(c);
        i++;
       }
       c = '~';
       xbee.write(c);
      cheker = false;
      morse = ""; 
      //xbee.write(morse);
    }
    
    if ((pause>6*pause_value) && (spacechecker))
    {
      //Serial.print(" ");
      c = ' ';
      xbee.write(c);
      spacechecker = false;
    }
    
    if ((pause>15*pause_value) && (linecheker))
    {
      //Serial.println();
      c = '\n';
      xbee.write(c);
      linecheker = false;
    }
  }
  lastButtonState=buttonState;
  delay(1);
  
  //Serial.println(morse);
}

