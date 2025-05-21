void call()
{
  Serial.println(NUM_CALL);
  Serial2.print("ATD"+NUM_CALL);
  delay(300);
  mc60_read();
}
