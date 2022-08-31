#include<Wire.h>
#include<Timer.h>
#define IMU_ADDRESS 0x68
#define Gyro_ZOUT_H 0x47
#define Gyro_CONFIG 0x1B
int16_t gyro_z=0;
int16_t gyro_offset_z=0;
int nsamples=3000;
long previoustime=0;
long currenttime=0;
long time1=0;
long time2=0;
long elapsed=0;
long yaw=0;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
  Gyro_config();
  calibration();
}

void loop() {
  time1=time2;
  time2=millis();
  elapsed=(time2-time1)/1000;
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(Gyro_ZOUT_H);
  Wire.endTransmission();
  Wire.requestFrom(IMU_ADDRESS,2);
  while(Wire.available()<2);
  gyro_z = Wire.read()<<8 | Wire.read();
  int z=gyro_z+gyro_offset_z;
  z= gyro_z*2000/32786;
  yaw=yaw+z*elapsed;
  currenttime=millis();
  if((currenttime-previoustime)>1000){
    previoustime=currenttime;
    Serial.print("Z : ");
    Serial.println(yaw);
  }
}
void Gyro_config(){
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(Gyro_CONFIG);
  Wire.write(0x18);
  Wire.endTransmission();
}
void calibration(){
  for(int i=0;i<nsamples;i++){
    Wire.beginTransmission(IMU_ADDRESS);
    Wire.write(Gyro_ZOUT_H);
    Wire.endTransmission();
    Wire.requestFrom(IMU_ADDRESS,2);
    while(Wire.available()<2);
    gyro_z = Wire.read()<<8 | Wire.read();
    gyro_offset_z+=gyro_z;
    }
  gyro_offset_z/=nsamples;
  }
