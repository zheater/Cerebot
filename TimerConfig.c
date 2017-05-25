#include "TimerConfig.h"


void timer_init(void)
{
    T5CON = 0x0;
    TMR5 = TMR5INIT;
    
    T5CON = T_5_CON;    //Set control register
    PR5 = PR_5;
    T5CON |= TMR_START;  //Turn timer on
    
    return;
}