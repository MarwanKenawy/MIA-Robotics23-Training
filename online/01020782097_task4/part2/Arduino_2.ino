int msensor=A0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
 int soil=analogRead(msensor);
 Serial.write(soil / 256);
      
  Serial.write(soil % 256);
   delay(50);
}
