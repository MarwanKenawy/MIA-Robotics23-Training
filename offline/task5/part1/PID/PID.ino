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
long time1=0;
long time2=0;
void setup() {
  pinMode(pwm,OUTPUT);
  Serial.begin(9600);
  setpoint=60;//or 90
}

void loop() {
while(Serial.available()==0);
yaw=Serial.parseInt();
output=pid(yaw);
time2=millis();
if((time2-time1)>1000){
  time1=time2;
  analogWrite(pwm,output); 
  }
  
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
