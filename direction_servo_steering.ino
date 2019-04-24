#include "utilities.h"



DIRECTION lookSameDirection (int heading1,int heading2)
{
  //vres ti diafora metaksi ton 2 heading
    int difference =  differenceBetweenHeadings( heading1, heading2);

//an i diafora einai mikroteri apo to tzogo girna true

    if (abs( difference) <= TZOGOS){
    return CENTER;
    }
    
//ama i diafora einai arnitiki stripse deksia
    else if (difference < 0){
    return RIGHT;
    }
//ama i diafora einai thetiki stripse aristera
    else return LEFT;
         
}



/*
 * return positive degrees if target is left from current (to go to target, we have to turn left)
 *        negative degrees if target is right from current
 */
int differenceBetweenHeadings(int current,int target){

  //--------stripse tous aksones oste to currentH na einai sto 0
  //current=0;
  target=target-current;
  if(target<-180)target+=360;

  if(target>180)target=-360+target;

  return target;
}
//---------------------------


void testDiffs(){
  Serial.print("expected +179 -> ");Serial.println(differenceBetweenHeadings(0,179));
  Serial.print("expected -179 -> ");Serial.println(differenceBetweenHeadings(0,181));
  Serial.print("expected -170 -> ");Serial.println(differenceBetweenHeadings(340,170));
  Serial.print("expected +179 -> ");Serial.println(differenceBetweenHeadings(180,359));
  Serial.print("expected -170 -> ");Serial.println(differenceBetweenHeadings(180,10));
  Serial.print("expected +110 -> ");Serial.println(differenceBetweenHeadings(90,200));
  Serial.print("expected -170 -> ");Serial.println(differenceBetweenHeadings(90,280));
  Serial.print("expected  -> ");Serial.println(differenceBetweenHeadings(0,180));
  Serial.print("expected  -> ");Serial.println(differenceBetweenHeadings(180,0));
}

