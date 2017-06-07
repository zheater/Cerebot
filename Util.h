/* 
 * File:   Util.h
 * Author: wiggleby
 *
 * Created on June 3, 2017, 9:30 AM
 */

#ifndef UTIL_H
#define	UTIL_H

#include "SysConfig.h"
#include "IOConfig.h"
#include "ADCConfig.h"
#include "Schedule.h"
#include "MTRControl.h"
#include "Bluetooth.h"
#include "TimerConfig.h"
#include "USSensor.h"
#include <math.h>


/****************************************************
 * In an effort to de-clutter the rest of my code, 
 * here are all of the cluttery nonsense functions.
 ****************************************************/

#define TIMER_LIMIT     6000
#define PASSIVE_LED     FALSE

void initAll(void);
void delay(void);
void pmodTempAndHumidity (unsigned char *readBuffer, int readSize );
void numToLED(uint8_t val);
void passiveLED(void);

#endif	/* UTIL_H */

