/*
 * TimeCFG.h
 *
 *  Created on: Apr 17, 2017
 *      Author: zachary.heater
 */
#ifndef TIMERCONFIG_H_
#define TIMERCONFIG_H_


#include "SysConfig.h"



/* Timer 5 Control Register Setup
 *
 * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
 *   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0		--> 0x0000
 *
 * ON: Timer On bit -- 1 = Module is enabled, 0 = Module is disabled
 * SIDL: Stop in idle mode bit -- 1 = Discontinue operation when device enters idle mode, 0 = Continue operation when device enters idle mode
 * TGATE: Timer gated time accumulation enable bit (Ignored when TCS = 1) -- 1 = Gated time accumulation is enabled, 0 = Gated time accumulation is disabled
 * TCKPS: Timer input clock prescale select bits -- Prescales timer 1:x where x = 2^y and y is the value of the 3-bit field in decimal
 * T32: 32-bit timer mode select bit -- 1 = TMRx and TMRy form a 32-bit timer, 0 = TMRx and TMRy form two separate 16-bit timers
 * TCS: Timer clock source select bit -- 1 = External clock from TxCK pin, 0 = Internal peripheral clock
 *
 *  ON       SIDL                          TGATE <--- TCKPS --->  T32       TCS
 * [15] [14] [13] [12] [11] [10] [ 9] [ 8]  [ 7]  [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
 *   0    0    1    0    0    0    0    0     0     0    0    0    0    0    0    0		--> 0x2000
 */
#define _T5CON				0x00002000	//Note: Timer is turned off during initialization



/* Timer 5 Period Register
 *
 * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
 *
 *  PR: Period register bits -- These bits represent the complete 16-bit period match (16-bit mode only)
 *  Desired 1ms period, internal peripheral clock is 8 MHz
 *  ((8E6 1/s) / 8) * (1E-3 s) = 1000 --> 0x03E8
 *
 * <------------------------------------ PR ------------------------------------->
 * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
 *   0    0    0    1    1    1    1    1    0    1    0    0    0    0    0    0		--> 0x1F40
 *
 */
#define _PR5				0x0000008F



/* Timer 5 Timer Register (Read Only)
 *
 * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
 *
 *  TMR: Timer count register bits -- These bits represent the complete 16-bit timer count (16-bit mode only)
 *
 * <------------------------------------ TMR ------------------------------------>
 * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
 */


void timer_init(void);

#endif /* TIMERCONFIG_H_ */
