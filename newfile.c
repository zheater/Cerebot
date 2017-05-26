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


#define TIMER_LIMIT     6000

void delay(void);
//void pmodTempAndHumnity (unsigned char *readBuffer, int readSize ); //FROM LEE

int main(void) {   
    volatile int tmr = 0;
    int i = 0;
    int j;
    gpio_init();
    timer_init();
    interrupt_setup();
    mtr_init();
    pwm_config();
    //uart_init();
    
    LED_OFF(LED1);
    LED_OFF(LED2);
    LED_OFF(LED3);
    LED_OFF(LED4);
    
        
    for(;;) {
        
        //Passive LED pattern - because it's neat!
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


//FROM LEE
/*void pmodTempAndHumnity (unsigned char *readBuffer, int readSize )
{ 
    int i;
    I2CStart();
    
#if 1
    // Set Configuration Register First
    I2CTRN = 0x80;  // Hard coded address (0x40<<1) for this chip  
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    I2CIdle();
    
    I2CTRN = 2; // Hard coded address
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    I2CIdle();        
    
    // write config = 0x1000
    I2CTRN = 0x10;
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    I2CIdle();

    I2CTRN = 0x00;
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    I2CIdle();
#endif
    
    // Now read the data.
    I2CTRN = 0x80;  // Hard coded address (0x40<<1) for this chip  
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    I2CIdle();
    
    I2CTRN = 0; // Hard coded address
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    I2CIdle();        

    delayxMS(25); // requires hard delay.
    
    // Added this start / restart to try to fix repeated byte issue.
    I2C1CONbits.RSEN = 1;
    I2CIdle();
    
    I2CTRN = 0x81; // Hard coded address (0x40<<1) | 0x01) with read bit on.
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    I2CIdle();
     
 
    for (i=0; i< readSize; i++)
    {
        I2CCONbits.RCEN = 1; // enable master read
        while (I2CCONbits.RCEN); // wait for byte to be received !(I2CSTATbits.RBF)
        I2CIdle();

        I2CSTATbits.I2COV = 0;
        I2CIdle();
        
        readBuffer[i] = I2C1RCV;
        
        if (i+1 == readSize)
        {
            I2CCONbits.ACKDT = 1; // send nack on last read
            I2CCONbits.ACKEN = 1;            
            I2CStop();
        }
        else
        {
            I2CCONbits.ACKDT = 0; // send ack if more data to get
            I2CCONbits.ACKEN = 1;
        }
        I2CIdle();

    }
    return;
}*/