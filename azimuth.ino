
/**
 * returns current heading in degrees from compass
 */
float getAzimuth()
{
 uint16_t x, y, z;
  float azimuth;
  //float azimuth; //is supporting float too
  qmc.read(&x,&y,&z);
  //azimuth = qmc.azimuth(&y,&x);//you can get custom azimuth
  //Converter;
  Converter.u=x;
  int16_t xInt=Converter.i;

  Converter.u=y;
  int16_t yInt=Converter.i;

  Converter.u=z;
  int16_t zInt=Converter.i;

  azimuth=azi((float)yInt,(float)xInt);
  
}


float azi(float a, float b){
  float azimuth = atan2(a,b) * 180.0/PI;
  return azimuth < 0?360 + azimuth:azimuth;
}

