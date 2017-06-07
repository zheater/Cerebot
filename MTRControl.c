#include "MTRControl.h"


void mtr_init(void) {
    mtrLeft.mtrID = MTRLEFT;
    mtrLeft.mtrEnable = MTROFF;
    mtrLeft.dutyCycle = 0;
    
    mtrRight.mtrID = MTRRIGHT;
    mtrRight.mtrEnable = MTROFF;
    mtrRight.dutyCycle = 0;
        
    return;
}


void pwm_config(void) {
    pwmClock = 0;
    pwmPct = 0;

    return;
}


void pwm_main(void) {
    //Generate main pwm clock
    if(pwmClock == 0) {
        pwmClock = 1;
        
        if(pwmPct >= PWMMAX) {
            pwmPct = 1;
        } else {
            pwmPct++;
        }        
    } else {
        pwmClock = 0;
    }
    
    
    //Service mtrLeft
    if(pwmPct <= mtrLeft.dutyCycle) {
        mtrLeft.mtrOn = 1;
    } else {
        mtrLeft.mtrOn = 0;
    }
    
    //Service mtrLeft
    if(pwmPct <= mtrRight.dutyCycle) {
        mtrRight.mtrOn = 1;
    } else {
        mtrRight.mtrOn = 0;
    }
    
    if(pwmClock) {
        LATASET = (1 << 6);
    } else {
        LATACLR = (1 << 6);    
    }
    
    if(mtrLeft.mtrOn) {
        LATASET = (1 << 2);
    } else {
        LATACLR = (1 << 2);    
    }
    
    if(mtrRight.mtrOn) {
        LATASET = (1 << 3);
    } else {
        LATACLR = (1 << 3);    
    }
    
}


void pwm_ds_adjust(Motor *motor, uint8_t newDutyCycle) {
    if(newDutyCycle >= 0 && newDutyCycle <=100) {
        motor->rqstDutyCycle = newDutyCycle;
    } else {
        //TODO: Throw exception
    }
    
    if((motor->dutyCycle - motor->rqstDutyCycle) < MAXDSSTEP || (motor->rqstDutyCycle - motor->dutyCycle) < MAXDSSTEP)
    {
        motor->dutyCycle = motor->rqstDutyCycle;
    } else if (motor->dutyCycle > motor->rqstDutyCycle) {
        motor->dutyCycle = motor->dutyCycle - MAXDSSTEP;
    } else if (motor->dutyCycle < motor->rqstDutyCycle) {
        motor->dutyCycle = motor->dutyCycle + MAXDSSTEP;
    }
    return;
}

void enable_mtr(Motor *motor) {
    motor->mtrEnable = 1;
    return;
}