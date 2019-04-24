
#include "utilities.h"


uint16_t rc_values;
uint32_t rc_start;
volatile uint16_t rc_shared;
int minLimit = 1350;
int maxLimit = 1450;

void rc_read_values() {
    noInterrupts();
    rc_values=rc_shared;
    interrupts();
}

void calc_input() {
    if (digitalRead(RC_CH4_INPUT) == HIGH) {
        rc_start = micros();
    } else {
        uint16_t rc_compare = (uint16_t)(micros() - rc_start);
        rc_shared = rc_compare;
    }
}

// returns TRUE if it has signal, otherwise FALSE.
bool hasSignal(){
  
    bool isInLimit=true;
    for(int i=0;i<10;i++){
        delay(100);
        rc_read_values();
        if(rc_values != constrain(rc_values, minLimit,maxLimit )){
          //Serial.println (rc_values);
            isInLimit=false;
            break;
        }
    }
    
  return isInLimit;
  
}


