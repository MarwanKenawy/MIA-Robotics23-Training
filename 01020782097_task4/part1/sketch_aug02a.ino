// C++ code
//
int msensor=A0,fsensor=A1,led=10,button=2,button2=11;
int motorcontrol=9;
int counter=0;
unsigned long previoustime=0,delaytime=10000;


void setup()
{
  
  pinMode(motorcontrol,OUTPUT);
  pinMode(button2,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2),ISR_Button,RISING);
}

void loop()
{
  if(digitalRead(button2)==HIGH){
    if((millis()-previoustime)>=delaytime){
      digitalWrite(button2,LOW);}
  }
  int soil=analogRead(msensor);
  int force=analogRead(fsensor);
  int motorspeed=map (soil,0,876,255,0);
  int ledbrightness=map(force,0,914,255,0);
  analogWrite(motorcontrol,motorspeed);
  analogWrite(led,ledbrightness);
}
void ISR_Button(){
counter++;
  Serial.print("Number of button pressed:");
  Serial.println(counter);
  digitalWrite(button2,HIGH);
  previoustime=millis();
}
