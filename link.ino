String _link(String lon, String lat)
{
  String link = "";
  link=lon.substring(0,2);
  float xf_lon=atof(link.c_str());
  
  link=lat.substring(1,3);
  float xf_lat=atof(link.c_str());
  Serial.println(lon);
  link=lon.substring(2);
  float f_lon = atof(link.c_str()) / 60;
  link=lat.substring(3);
  float f_lat = atof(link.c_str()) / 60;
  f_lon=f_lon+xf_lon;
  f_lat=f_lat+xf_lat;
  char buffer1[20];
  char buffer2[20];
  dtostrf(f_lon, 8, 6, buffer1);
  dtostrf(f_lat, 8, 6, buffer2);
  link = String(buffer1)+","+String(buffer2);
  Serial.println(link);
  return link;
}
