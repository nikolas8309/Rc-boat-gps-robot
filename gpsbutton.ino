
/**
 * epistrefei true sthn metavash apo low se high
 * epistrefei false sthn metavash apo high se low
 */
bool checkSetWaypointButton ()
{
  bool buttonState;
  static bool previousState = false;
  
  buttonState = digitalRead(setWaypointButtonPin);

  
  if(buttonState==HIGH && previousState==LOW){//patima
    previousState=buttonState;
    return true;
  }
  
  else{ //se kathe alli periptosi
    previousState=buttonState;
    return false;
  }
}



/**
 * Delay while keeping track of gps activity
 */
static void smartdelay(unsigned long ms)
{
	unsigned long start = millis();
	do 
	{
		while (GPS_SERIAL_PORT.available())
		gps.encode(GPS_SERIAL_PORT.read());
	} while (millis() - start < ms);
}


//----------------------------------------------------------
  //pernei tis trexouses suntetagmenes
Point getGpsCurrentPosition (){
  Point currentPoint;  
  
  gps.f_get_position(&currentPoint.latitude, &currentPoint.longitude);

  return currentPoint;
  
}

//---------------------------------------------------------------
  //vlepei ama h apostash einai kato apo 20 metra kai anavei to led

//  bool  wayPointCoordinatesAreSet(){
//    
//        if (dist<20){
//    return true;
//    }
//    else return false;
//    
//  }



