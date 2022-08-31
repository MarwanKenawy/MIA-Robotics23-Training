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
long elapsed=0;
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
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(Gyro_ZOUT_H);
  Wire.endTransmission();
  Wire.requestFrom(IMU_ADDRESS,2);
  while(Wire.available()<2);
  gyro_z = Wire.read()<<8 | Wire.read();
  int z=gyro_z-gyro_offset_z;
  z= gyro_z*2000/32.786;
  currenttime=millis();
  if(elapsed=(currenttime-previoustime)>1000){
    previoustime=currenttime;
    Serial.print("Z : ");
    Serial.println(z*elapsed);
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
