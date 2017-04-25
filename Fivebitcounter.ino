// PROGRAM TO GIVE 5-BIT UP DOWN COUNTER 
int led[5];//
int buttonup = 11;
int buttondn = 12;
int presses = 0;
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
      pinMode(buttonup,INPUT);
  digitalWrite(buttonup,HIGH);
  pinMode(buttondn,INPUT);
  digitalWrite(buttondn,HIGH);
  attachInterrupt(11,countdn,LOW);
  attachInterrupt(12,countup,LOW);
    
}
void loop()
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
 


