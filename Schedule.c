#include "Schedule.h"
#include "MTRControl.h"
#include "Util.h"


void interrupt_setup(void)
{
    /***************************************************************************
     * NOTE: timer_init() should have been called prior to interrupt setup
     * 
     * Timer in use - IRQ  VECTORNUMBER   FLAG     ENABLE   PRIORITY   SUBPRIORITY
     *  T5 - Timer5:   20       20      IFS0<20> <IEC0<20>  IPC5<4:2>   IPC5<1:0>
     **************************************************************************/
    __asm__ volatile("di");     //Disable all interrupts
    
    INTCON = _INTCON;       //Set interrupt control register
    
    //Using timer 5
    T5CON = 0x0;            //Disable Timer 5
    TMR5 = TMR5INIT;             //Clear Timer Register
    
    
    IPC5 |= 0x0000000D;   // Priority 3, Sub 1    
    IFS0 &= 0xFFEFFFFF;   // Clear Timer Int Flag 
    IEC0 |= 0x00100000;   // Enable Interrupts for Timer
    
    T5CON = _T5CON;
    T5CON |= TMR_START;      // Restart the Timer.
    
    
    __asm__ volatile("ei");     //Enable all interrupts
}

void motor_service(void)
{
    static int b1PrevVal;
    static int b2PrevVal;
    int button1;
    int button2;
    
    
    pwm_main();
    
    
    button1 = ((PORTA & 0x40) >> 6);
    button2 = ((PORTA & 0x80) >> 7);
    
    if(button1 == 1 & b1PrevVal == 0) {
        pwm_ds_adjust(&mtrLeft, (mtrLeft.dutyCycle + 10));
        numToLED(mtrLeft.dutyCycle / 10);
    }
    
    if(button2 == 1 & b2PrevVal == 0) {
        pwm_ds_adjust(&mtrLeft, (mtrLeft.dutyCycle - 10));
        numToLED(mtrLeft.dutyCycle / 10);
    }
    
    b1PrevVal = button1;
    b2PrevVal = button2;
    
    return;
}

// Interrupt stuff in single vector mode.
void __attribute__((interrupt(single),vector(0),nomips16)) isr_handler(void)
{
    __asm__ volatile("di");     //Disable all interrupts
    
    
    if(((IFS0 & TMR5INTMASK) >> TMR5INTFLAG) == 1) {                
        motor_service();
        IFS0CLR = (1 << TMR5INTFLAG);    //Clear interrupt flag
    }
    
    __asm__ volatile("ei");     //Enable all interrupts  
}
