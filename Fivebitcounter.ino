// PROGRAM TO GIVE 5-BIT UP DOWN COUNTER 
int led[5];//this is an array that is used for initializing the LED positions
int buttonup = 11;//the position for the UP-button
int buttondn = 12;//the position for the DOWN-button
int presses = 0;//the variable to store the number of presses
long t = 0;
long debounce = 50;
const byte numPins = 5;
int state;
void setup()
{
    int c=4;
    for(int i=0;i<5;i++)
    {
      led[i]=c++;
    }
    for(int i=0;i<5;i++)
    {
      pinMode(led[i],OUTPUT);
    }
      pinMode(buttonup,INPUT);//Set UP_button as Position
  digitalWrite(buttonup,HIGH);
  pinMode(buttondn,INPUT);//Set DOWN_button as Input position
  digitalWrite(buttondn,HIGH);
  attachInterrupt(11,countdn,LOW);
  attachInterrupt(12,countup,LOW);
    
}
void loop()//where the magic happens bitches
{
  String binNumber = String(presses, BIN);
  int binLength = binNumber.length(); 
  if(presses <= 31) 
  { 
                
    for(int i = 0, x = 1; i < binLength; i++, x+=2) 
    { 
      if(binNumber[i] == '0') state = LOW;
      if(binNumber[i] == '1') state = HIGH;
      digitalWrite(led[i] + binLength - x, state);
      if ((0 <= presses) && (presses <= 31)) 
      { 
      }
      else
      {
        if (presses > 31) presses = 31;
        if (presses < 0) presses = 0;
      }   
    } 
  }
  else 
  {
  }
}
void countup()
{ 
  if(millis() - t > debounce)  presses++;
  t = millis();
}
void countdn()
{  
  if (millis() - t > debounce)  presses--;
  t = millis();
}
