
void printFloat(double number, int digits)
{
  // Handle negative numbers
  if (number < 0.0)
  {
    Serial.print('-');
    number = -number;
  }

  // Round correctly so that print(1.999, 2) prints as "2.00"
  double rounding = 0.5;
  for (uint8_t i=0; i<digits; ++i)
  rounding /= 10.0;

  number += rounding;

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;
  double remainder = number - (double)int_part;
  Serial.print(int_part);

  // Print the decimal point, but only if there are digits beyond
  if (digits > 0)
  Serial.print("."); 

  // Extract digits from the remainder one at a time
  while (digits-- > 0)
  {
    remainder *= 10.0;
    int toPrint = int(remainder);
    Serial.print(toPrint);
    remainder -= toPrint; 
  } 
}

//--------------------------------

void print_float(float val, float invalid, int len, int prec)
{
	if (val == invalid)
	{
		while (len-- > 1)
		Serial.print('*');
		Serial.print(' ');
	}
	else
	{
		Serial.print(val, prec);
		int vi = abs((int)val);
		int flen = prec + (val < 0.0 ? 2 : 1); // . and -
		flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
		for (int i=flen; i<len; ++i)
		Serial.print(' ');
	}
	smartdelay(0);
}

void print_int(unsigned long val, unsigned long invalid, int len)
{
	char sz[32];
	if (val == invalid)
	strcpy(sz, "*******");
	else
	sprintf(sz, "%ld", val);
	sz[len] = 0;
	for (int i=strlen(sz); i<len; ++i)
	sz[i] = ' ';
	if (len > 0) 
	sz[len-1] = ' ';
	Serial.print(sz);
	smartdelay(0);
}

void print_date(TinyGPS &gps)
{
	int year;
	byte month, day, hour, minute, second, hundredths;
	unsigned long age;
	gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &age);
	if (age == TinyGPS::GPS_INVALID_AGE)
	Serial.print("********** ******** ");
	else
	{
		char sz[32];
		sprintf(sz, "%02d/%02d/%02d %02d:%02d:%02d ",
		month, day, year, hour, minute, second);
		Serial.print(sz);
	}
	print_int(age, TinyGPS::GPS_INVALID_AGE, 5);
	smartdelay(0);
}

void print_str(const char *str, int len)
{
	int slen = strlen(str);
	for (int i=0; i<len; ++i)
	Serial.print(i<slen ? str[i] : ' ');
	smartdelay(0);
}


