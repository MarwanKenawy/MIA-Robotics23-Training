#include <Wire.h>
byte motorpin1=5;
byte motorpin2=6;
byte enablepin=11;
int temp;
int soil=0;
char c[10];
void setup()
{
  pinMode(motorpin1,OUTPUT);
  pinMode(motorpin2,OUTPUT);
  pinMode(enablepin,OUTPUT);
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
int val;

      
      while (!Serial.available()){}
    //delay(100);
    byte b1 = Serial.read();
    while (!Serial.available()){}
    //delay(100);
    byte b2 = Serial.read();

    val = b1  + (b2 *256) ; 
  //Serial.print("soil moisture=");
    Serial.print(val);
  Serial.print(",");
  
  Wire.requestFrom(0x31,1);
  while(Wire.available()){
  temp=Wire.read();
  }
  Serial.println(temp);
  //Serial.println(temp);
  int motorspeed=map(temp,0,100,0,255);
  if(temp>40){
    digitalWrite(motorpin1,HIGH);
    analogWrite(enablepin,motorspeed);
    digitalWrite(motorpin2,LOW);}
  else if(temp<20){
  
  digitalWrite(motorpin2,HIGH);
    analogWrite(enablepin,255-motorspeed);
    digitalWrite(motorpin1,LOW);
  
  }
  else{
  digitalWrite(motorpin1,LOW);
    digitalWrite(motorpin2,LOW);
  
  }
}
