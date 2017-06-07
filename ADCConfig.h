/* 
 * File:   ADCConfig.h
 * Author: wiggleby
 *
 * Created on June 3, 2017, 10:08 AM
 */

#ifndef ADCCONFIG_H
#define	ADCCONFIG_H

#include "SysConfig.h"

/* ADC1 Control Register 1
 * 
 *   -    -    -    -    -    -    -    -    -    -    -    -    -    -    -    -
 * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
 *   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0       --> 0x0000
 *
 * ON: ADC Operating Mode Bit -- 1 = ADC module is operating; 0 = ADC is off
 * SIDL: Stop in Idle Mode Bit -- 1 = Discontinue operation when device enters idle mode; 0 = Continue operation in idle mode
 * FORM: Data Output Format Bits -- I'm not writing all this out... Just check the manual
 * SSRC: Conversion Trigger Source Select Bits -- Same as above
 * CLRASAM: Stop Conversion Sequence Bit -- 1 = Stop conversion when the first ADC interrupt is generated; 0 = Normal operation, buffer contents will be overwritten by the next conversion sequence
 * ASAM: ADC Sample Auto-Start Bit -- 1 = Sampling begins immediately after last conversion completes; 0 = Sampling begins when SAMP bit is set
 * SAMP: ADC Sample Enable Bit -- 1 = ADC SHA is sampling; 0 = ADC sample/hold amplifier is holding
 * DONE: ADC Status Bit -- 1 = ADC Conversion is done; 0 = ADC is not done
 *
 *  ON    -  SIDL   -    -  <--- FORM --->  <--- SSRC --->  CLRASAM    -   ASAM SAMP DONE
 * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7]  [ 6]  [ 5]   [ 4]   [ 3]  [ 2] [ 1] [ 0]
 *   0    0    1    0    0    1    0    0    1     1     1      0      0     1    1    0		--> 0x24E6
 */
#define _AD1CON1        0x000024E6

/* ADC1 Control Register 2
 * 
 *   -    -    -    -    -    -    -    -    -    -    -    -    -    -    -    -
 * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
 *   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0       --> 0x0000
 *
 * VCFG: Voltage Reference Configuration Bits -- See Manual
 * OFFCAL: Input Offset Calibration Mode Select Bit -- 1 = Enable offset calibration mode; 0 = Disable offset calibration mode
 * CSCNA: Scan Input Selections for CH0+ SHA Input for MUX A Input Multiplexer Setting Bit -- 1 = Scan inputs; 0 = Do not scan inputs
 * BUFS: Buffer Fill Status Bit: 1 = ADC is currently filling buffer 0x8-0xF; 0 = ADC is currently filling buffer 0x0-0x7
 * SMPI: Sample/Convert Sequences Per Interrupt Selection Bits - See Manual
 * BUFM: ADC Result Buffer Mode Select Bit -- 1 = Buffer configured as two 8-word buffers; 0 = Buffer configured as one 16-word buffer
 * ALTS: Alternate Input Sample Mode Select Bit -- 1 = Uses MUX A input multiplexer settings for first sample, then alternates between MUX B and MUX A input multiplexer settings; 0 = Always use MUX A input multiplexer settings
 *
 * <--- VCFG ---> OFFCAL   -  CSCNA   -    -  BUFS   -  <------ SMPI ---->  BUFM ALTS
 * [15] [14] [13]  [12]  [11]  [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
 *   0    0    0     0     0     0    0    0    0    0    1    1    1    1    0    0		--> 0x003C
 */
#define _AD1CON2        0x0000003C

#define _AD1CON3        0x0
#define _AD1CHS         0x0
#define _AD1PCFG        0x0
#define _AD1CSSL        0x0
#define ADCON           15


void adc_init(void);

#endif	/* ADCCONFIG_H */

