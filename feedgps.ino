
/**
* 	returns true if new data is available, otherwise false
*/
bool feedgps()
{
	char ch;
	while (GPS_SERIAL_PORT.available())
	{
		ch=GPS_SERIAL_PORT.read();
		//Serial.print(ch);
		if (gps.encode(ch)){
			//Serial.println("returns true");
			return true;
		}
	}
	return false;

}


//typwnei ta trexonta dedomena toy gps
void gpsdump(TinyGPS &gps)
{
  long lat, lon;
  float flat, flon;
  unsigned long age, date, time, chars;
  unsigned short sentences, failed;

  gps.get_position(&lat, &lon, &age);
  Serial.print("Lat/Long(10^-5 deg): "); Serial.print(lat); Serial.print(", "); Serial.print(lon); 
  Serial.print(" Fix age: "); Serial.print(age); Serial.println("ms.");

  feedgps(); // If we don't feed the gps during this long routine, we may drop characters and get checksum errors

  gps.f_get_position(&flat, &flon, &age);
  Serial.print("Lat/Long(float): "); printFloat((double)flat, 5); Serial.print(", "); printFloat((double)flon, 5);
  Serial.print(" Fix age: "); Serial.print(age); Serial.println("ms.");

  feedgps();

  gps.stats(&chars, &sentences, &failed);
  Serial.print("Stats: characters: "); Serial.print(chars); Serial.print(" sentences: "); Serial.print(sentences); Serial.print(" failed checksum: "); Serial.println(failed);


  
}


