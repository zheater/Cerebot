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
 * FIX SPI STUFF - according to the pinout I have to rewire the chip... SCK1 is mapped to VCCEN, no the data channel
 * 
 * HIGH PRIORITY
 * Timer and prescaler behavior doesn't make much sense to me...
 * 
 *
 */


#define TIMER_LIMIT     6000

void delay(void);
void pmodTempAndHumnity (unsigned char *readBuffer, int readSize );

int main(void) {   
    volatile int tmr = 0;
    unsigned char uartChar = 'A';
    int i = 0;
    int j;
    gpio_init();
    timer_init();
    interrupt_setup();
    mtr_init();
    pwm_config();
    uart_init();
    
    LED_OFF(LED1);
    LED_OFF(LED2);
    LED_OFF(LED3);
    LED_OFF(LED4);
    
    uart1_enable();
    
    
    
        
    for(;;) {
        uart1_putc(uartChar);    //REMOVE
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



void pmodTempAndHumnity (unsigned char *readBuffer, int readSize )
{ 
    int i;
    i2c_start();
    
#if 1
    // Set Configuration Register First
    I2C1TRN = 0x80;  // Hard coded address (0x40<<1) for this chip  
    while(TRSTAT(I2C1STAT)); // wait until write cycle is complete
    i2c_idle();
    
    I2C1TRN = 2; // Hard coded address
    while (TRSTAT(I2C1STAT)); // wait until write cycle is complete
    i2c_idle();        
    
    // write config = 0x1000
    I2C1TRN = 0x10;
    while (TRSTAT(I2C1STAT)); // wait until write cycle is complete
    i2c_idle();

    I2C1TRN = 0x00;
    while (TRSTAT(I2C1STAT)); // wait until write cycle is complete
    i2c_idle();
#endif
    
    // Now read the data.
    I2C1TRN = 0x80;  // Hard coded address (0x40<<1) for this chip  
    while(TRSTAT(I2C1STAT)); // wait until write cycle is complete
    i2c_idle();
    
    I2C1TRN = 0; // Hard coded address
    while (TRSTAT(I2C1STAT)); // wait until write cycle is complete
    i2c_idle();        

    delay(); // requires hard delay.
    
    // Added this start / restart to try to fix repeated byte issue.
    I2C1CONSET = (1 << RSENSHFT);
    i2c_idle();
    
    I2C1TRN = 0x81; // Hard coded address (0x40<<1) | 0x01) with read bit on.
    while (TRSTAT(I2C1STAT)); // wait until write cycle is complete
    i2c_idle();
     
 
    for (i=0; i< readSize; i++)
    {
        I2C1CONSET = (1 << RCENSHFT); // enable master read
        while (RCEN(I2C1CON)); // wait for byte to be received
        i2c_idle();

        I2C1STATCLR = (1 << I2COVSHFT);
        i2c_idle();
        
        readBuffer[i] = I2C1RCV;
        
        if (i+1 == readSize)
        {
            I2C1CONSET = (1 << ACKDTSHFT); // send nack on last read
            I2C1CONSET = (1 << ACKENSHFT);            
            i2c_stop();
        }
        else
        {
            I2C1CONCLR = (1 << ACKDTSHFT); // send ack if more data to get
            I2C1CONSET = (1 << ACKENSHFT);
        }
        i2c_idle();

    }
    return;
}