#include "config.h"
void setup() 
{
  Serial.begin(115200);
  Serial2.begin(115200);
  delay(6000);
  pinMode(Button,INPUT_PULLUP);
  String resp="";
  Serial2.println("AT+CMGF=1");
  delay(300);
  resp=mc60_read();
  Serial2.println("AT+CNMI=2,2,0,0,0");
  delay(300);
  resp=mc60_read();
  Serial2.println("AT+CLIP=1\r\n");
  delay(300);
  resp=mc60_read();
  Serial2.write("AT+QGNSSC=1\r\n");
  delay(300);
  resp=mc60_read();
}

void loop() 
{
  int buttonState = digitalRead(Button);
  delay(100);
  //Serial.print("BUTTON STATE :");Serial.println(buttonState);
  while(Serial2.available())
  {
    receiver = Serial2.readStringUntil('\n');
    Serial.println(receiver);
    
    if(receiver.indexOf("+CMT:")>=0 )
    {
      incoming_message();
      receiver = "";
    }
  }
  if(buttonState == 0)
    {
      Serial.println("INSIDE IF");
      button_gps();
    }
}
