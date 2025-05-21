String mc60_read()
{
  String response="";
  while(Serial2.available())
  {
    response = Serial2.readString();
  }
  Serial.println(response);
  return response;
}
