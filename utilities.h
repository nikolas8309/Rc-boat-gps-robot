#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <Arduino.h>

#include <TinyGPS.h>

#include <Wire.h>
#include <MechaQMC5883.h>
#include <Servo.h>

#define RC_CH4_INPUT  2

#define TO_BUFFER_PIN 11 
#define GPS_CURRENT_POTITION_LED_PIN 12

#define SERVO_CENTER 110
#define SERVO_RIGHT 10
#define SERVO_LEFT 170

#define FULL_THROTTLE 130
#define ZERO_THROTTLE 0

// pou sindeetai to servo gia to pidalio
#define ARDUINO_TO_DIRECTION_SERVO_PIN 9

// pou sindeetai to speed controller
#define ARDUINO_TO_ESC_PIN 10

// se moires poso +- theoreitai oti einai idia i kateythinsi
#define TZOGOS 10

#define GPS_SERIAL_PORT Serial1

struct Point {
   float latitude;
   float longitude;
};


enum DIRECTION { LEFT,RIGHT,CENTER};

enum CONTROLHOLDER {RECEIVER, MICROCONTROLLER};


#endif

