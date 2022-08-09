// C++ code
//
#include <Wire.h>
int tsensor=A0;
int readtemp;
void setup()
{
  Wire.begin(0x31);
  Wire.onRequest(requestevent);
}

void loop()
{
  readtemp=map(analogRead(tsensor),20,358,0,100);
}
void requestevent(){
Wire.write(readtemp);

}
