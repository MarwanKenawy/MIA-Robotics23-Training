#include <Timer.h>
int spstswitch=4;
int motor1a=2;
int motor1b=3;
int motor2a=10;
int motor2b=11;
long count1=0;
long count2=0;
long previoustime=0;
long currenttime=0;
void setup()
{
  Serial.begin(9600);
  pinMode(motor1a, INPUT_PULLUP);
  pinMode(motor1b, INPUT_PULLUP);
  pinMode(motor2a, INPUT);
  pinMode(motor2b, INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(spstswitch,INPUT);
  attachInterrupt(digitalPinToInterrupt(motor1a), MOTOR1A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(motor1b), MOTOR1B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(motor2a), MOTOR2A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(motor2b), MOTOR2B, CHANGE);

}

void loop()
{
  if(digitalRead(spstswitch)){
    if(count2<600){
      digitalWrite(12,LOW);
      digitalWrite(13,HIGH);}
      else {
        digitalWrite(12,LOW);
        digitalWrite(13,LOW);
        }
        }
    else{
      if(count2>=600){
        digitalWrite(12,HIGH);
      digitalWrite(13,LOW);}
      if(count2<=0){
        digitalWrite(12,LOW);
      digitalWrite(13,LOW);}
      }
  if(count1>=400){
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
 }
  else{
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);}
  
  currenttime=millis();
  if(currenttime-previoustime>1000){
  previoustime=currenttime;
    Serial.print("motor1 count=");
    Serial.print(count1);
    Serial.print(" degree=");
    Serial.println(count1*360/2400);
    Serial.print("motor2 count=");
    Serial.print(count2);
    Serial.print(" degree=");
    Serial.println(count2*360/2400);
    
  }
}
void MOTOR1A(){
  if(digitalRead(motor1a)!=digitalRead(motor1b))
    count1++;
}
void MOTOR1B(){
  if(digitalRead(motor1a)!=digitalRead(motor1b))
    count1++;
  
}
void MOTOR2A(){
  if(digitalRead(motor2a)!=digitalRead(motor2b))
    count2++;
    else
    count2--;
}
void MOTOR2B(){
  if(digitalRead(motor2a)!=digitalRead(motor2b))
    count2++;
    else
    count2--;
  
}
