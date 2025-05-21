void sms(String msg,String num)
{
  Serial2.print("AT+CMGS=\""+num+"\"\r\n");
  delay(300);
  Serial2.print(msg);
  Serial2.write(26);
  delay(1000);
  mc60_read();
}
