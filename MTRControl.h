/* 
 * File:   MTRControl.h
 * Author: Wiggleby
 *
 * Created on May 17, 2017, 8:17 AM
 */

#ifndef MTRCONTROL_H
#define	MTRCONTROL_H

#include "SysConfig.h"

#define MTRLEFT         0
#define MTRRIGHT        1
#define MTROFF          0
#define MTRON           1
#define PWMMAX          100
#define MAXDSSTEP       1



typedef struct {
    bool mtrID;
    bool mtrEnable;
    bool mtrOn;
    uint8_t dutyCycle;
    uint8_t rqstDutyCycle;
} Motor;

Motor mtrLeft;
Motor mtrRight;
bool pwmClock;
uint8_t pwmPct;

void mtr_init(void);
void pwm_config(void);
void pwm_main(void);
void pwm_ds_adjust(Motor *motor, uint8_t newDutyCycle);
void enable_mtr(Motor *motor);



#endif	/* MTRCONTROL_H */

