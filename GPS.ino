void gps(String num)
{
  String resp="";
  String lon="";
  String lat="";
  String link="";
  Serial2.write("ATH\r\n");
  delay(300);
  mc60_read();
  Serial2.write("AT+QGNSSRD=\"NMEA/RMC\"\r\n");
  delay(500);
  resp=mc60_read();
  lon=resp.substring(resp.indexOf("A,")+2,resp.indexOf(",",55));
  lat=resp.substring(resp.indexOf("N,")+2,resp.indexOf("N,")+12);
  resp="LONGITUDE = "+lon+"LATITUDE = "+lat;
  link=_link(lon,lat);
  sms(link,NUM_MSG);
  delay(2000);mc60_read();
  //sms(resp,num);
}

void button_gps()
{
  String resp="";
  String lon="";
  String lat="";
  String link="";
  Serial2.write("ATH\r\n");
  delay(300);
  mc60_read();
  Serial2.write("AT+QGNSSRD=\"NMEA/RMC\"\r\n");
  delay(500);
  resp=mc60_read();
  lon=resp.substring(resp.indexOf("A,")+2,resp.indexOf(",",55));
  //lat=resp.substring(resp.indexOf("N,")+2,resp.indexOf("N,")+13);
  lat=resp.substring(resp.indexOf("N,")+2,resp.indexOf("N,")+12);
  resp="LONGITUDE = "+lon+"LATITUDE = "+lat;
  link=_link(lon,lat);
  sms(link,NUM_MSG);
  delay(2000);mc60_read();
//  sms(resp,NUM_MSG);
//  delay(2000);mc60_read();
  call();
}
