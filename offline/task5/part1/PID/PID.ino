#include <Timer.h>
Timer mytime;
int kp=2;
int ki=5;
int kd=1;
long previoustime=0;
long currenttime=0;
long elapsedtime=0;
int setpoint;
long error;
long lasterror;
long interror;
long rateerror;
int yaw;
long output;
int pwm=3;
int dir=2;

void setup() {
  pinMode(pwm,OUTPUT);
  pinMode(dir,OUTPUT);
  Serial.begin(9600);
  setpoint=60;//or 90
  mytime.every(1000,routine);
}
void routine(){
  while(Serial.available()==0);
  yaw=Serial.parseInt();
   output=pid(yaw);
  if(output<=2&&output>=-2){
    analogWrite(pwm,0);}
  else if(output>2){
    analogWrite(pwm,output);
    digitalWrite(dir,LOW);}
    else{
      analogWrite(pwm,abs(output));
      digitalWrite(dir,HIGH);}
  }

void loop() {

mytime.update();
  
}
long pid(int x){
  currenttime=millis();
  elapsedtime=(currenttime-previoustime);
  error=setpoint-x;
  interror+=error*elapsedtime;
  rateerror=(error-lasterror)/elapsedtime;
  long y=kp*error+ki*interror+kd*rateerror;
  lasterror=error;
  previoustime=currenttime;
  return y;
  }
