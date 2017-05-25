/* 
 * File:   Schedule.h
 * Author: Wiggleby
 *
 * Created on May 10, 2017, 12:43 PM
 */

#ifndef SCHEDULE_H
#define	SCHEDULE_H

#include <sys/attribs.h>
#include "SysConfig.h"
#include "TimerConfig.h"
#include "MTRControl.h"


/* Interrupt Control Register Setup
 * SS0: Single Vector Shadow Register Set bit -- 1 = Single vector is presented with a shadow register bit; 0 = Single vector is not presented with a shadow register bit
 * 
 *                                                                             SS0
 * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
 *   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0           	--> 0x0000
 *
 * MVEC: Multi Vector Configuration bit -- 1 = Interrupt Controller is configured for multi vectored mode; 0 = Interrupt Controller is configured for single vectored mode
 * TPC: Interrupt Proximity Timer Control bits -- Interrupts with priority x or lower start the Interrupt Proximity Timer, where x is equal to the bit field value in decimal. A value of 0 disables the Interrupt Proximity Timer
 * INTxEP: External Interrupt x Edge Polarity Control bit -- 1 = Rising edge; 0 = Falling edge
 *
 *                MVEC       <--- TPC --->                INT4EP INT3EP INT2EP INT1EP INT0EP
 * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5]  [ 4]   [ 3]   [ 2]   [ 1]   [ 0]
 *   0    0    0    0    0    0    0    0    0    0    0     0      0      0      0      0		--> 0x0000
 */
#define INT_CON				0x00000000



    
void interrupt_setup(void);
void motor_service(void);
void __attribute__((interrupt(single),vector(0),nomips16)) isr_handler(void);



#endif	/* SCHEDULE_H */

