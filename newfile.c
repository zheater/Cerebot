#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TimerConfig.h"
#include "Schedule.h"
#include "SysConfig.h"
#include "MTRControl.h"
#include "Bluetooth.h"
#include "IOConfig.h"

/* TODOs:
 * Fix up SPI config stuff - make consistent with I2C and GPIO
 * Removed all the mask stuff. Move descriptions to bit assignment block
 * 
 * HIGH PRIORITY
 * Timer and prescaler behavior doesn't make much sense to me...
 * 
 *
 */


#define TIMER_LIMIT     5700

void delay(void);

int main(void) {   
    volatile int tmr = 0;
    int i = 0;
    int j;
    gpio_init();
    timer_init();
    interruptSetup();
    mtr_init();
    pwm_config();
    //uart_init();
    
    LED_OFF(LED1);
    LED_OFF(LED2);
    LED_OFF(LED3);
    LED_OFF(LED4);
    
        
    for(;;) {
        
        //Passive LED pattern
        delay();
        
        for(j = 0;j < 2;j++) {
            LED_ON(LED1);
            LED_OFF(LED2);
            LED_OFF(LED3);
            LED_OFF(LED4);
            delay();

            LED_OFF(LED1);
            LED_ON(LED2);
            LED_OFF(LED3);
            LED_OFF(LED4);
            delay();

            LED_OFF(LED1);
            LED_OFF(LED2);
            LED_ON(LED3);
            LED_OFF(LED4);
            delay();

            LED_OFF(LED1);
            LED_OFF(LED2);
            LED_OFF(LED3);
            LED_ON(LED4);
            delay();
        }
        
        LED_OFF(LED1);
        LED_OFF(LED2);
        LED_OFF(LED3);
        LED_OFF(LED4);
        delay();
        
        for(j = 0;j < 4;j++) {
            LED_ON(LED1);
            LED_ON(LED2);
            LED_ON(LED3);
            LED_ON(LED4);
            delay();

            LED_OFF(LED1);
            LED_OFF(LED2);
            LED_OFF(LED3);
            LED_OFF(LED4);
            delay();
        }
    }

    
    
    return;
}


void delay(void) {
    
    int i;
    
    for(i = 0;i < (TIMER_LIMIT);i++) {
        __asm__("NOP");
    }
    
    return;
}