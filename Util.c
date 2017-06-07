#include "Util.h"

/****************************************************
 * In an effort to de-clutter the rest of my code, 
 * here are all of the cluttery nonsense functions.
 ****************************************************/


void delay(void) {
    
    int i;
    
    for(i = 0;i < (TIMER_LIMIT);i++) {
        __asm__("NOP");
    }
    
    return;
}



void pmodTempAndHumidity (unsigned char *readBuffer, int readSize )
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

void passiveLED(void)
{
    int j;
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
        
    return;
}

void numToLED(uint8_t val)
{
    const uint8_t ledVal = val;
    
    if(ledVal >= 0 && ledVal <= 15) {
        switch(ledVal) {
            case 0:
                LED_OFF(LED1);
                LED_OFF(LED2);
                LED_OFF(LED3);
                LED_OFF(LED4);
                break;
            case 1:
                LED_ON(LED1);
                LED_OFF(LED2);
                LED_OFF(LED3);
                LED_OFF(LED4);
                break;
            case 2:
                LED_OFF(LED1);
                LED_ON(LED2);
                LED_OFF(LED3);
                LED_OFF(LED4);
                break;
            case 3:
                LED_ON(LED1);
                LED_ON(LED2);
                LED_OFF(LED3);
                LED_OFF(LED4);
                break;
            case 4:
                LED_OFF(LED1);
                LED_OFF(LED2);
                LED_ON(LED3);
                LED_OFF(LED4);
                break;
            case 5:
                LED_ON(LED1);
                LED_OFF(LED2);
                LED_ON(LED3);
                LED_OFF(LED4);
                break;
            case 6:
                LED_OFF(LED1);
                LED_ON(LED2);
                LED_ON(LED3);
                LED_OFF(LED4);
                break;
            case 7:
                LED_ON(LED1);
                LED_ON(LED2);
                LED_ON(LED3);
                LED_OFF(LED4);
                break;
            case 8:
                LED_OFF(LED1);
                LED_OFF(LED2);
                LED_OFF(LED3);
                LED_ON(LED4);
                break;
            case 9:
                LED_ON(LED1);
                LED_OFF(LED2);
                LED_OFF(LED3);
                LED_ON(LED4);
                break;
            case 10:
                LED_OFF(LED1);
                LED_ON(LED2);
                LED_OFF(LED3);
                LED_ON(LED4);
                break;
            case 11:
                LED_ON(LED1);
                LED_ON(LED2);
                LED_OFF(LED3);
                LED_ON(LED4);
                break;
            case 12:
                LED_OFF(LED1);
                LED_OFF(LED2);
                LED_ON(LED3);
                LED_ON(LED4);
                break;
            case 13:
                LED_ON(LED1);
                LED_OFF(LED2);
                LED_ON(LED3);
                LED_ON(LED4);
                break;
            case 14:
                LED_OFF(LED1);
                LED_ON(LED2);
                LED_ON(LED3);
                LED_ON(LED4);
                break;
            case 15:
                LED_ON(LED1);
                LED_ON(LED2);
                LED_ON(LED3);
                LED_ON(LED4);
                break;
            default:
                LED_OFF(LED1);
                LED_OFF(LED2);
                LED_OFF(LED3);
                LED_OFF(LED4);
        };
    } else {
        //throw exception
    }
    
    
    return;
}

void initAll(void)
{
    LED_OFF(LED1);
    LED_OFF(LED2);
    LED_OFF(LED3);
    LED_OFF(LED4);
    
    gpio_init();
    timer_init();
    interrupt_setup();
    mtr_init();
    pwm_config();
    uart_init();
    i2c_init();
    enable_mtr(&mtrLeft);
    enable_mtr(&mtrRight);
    
    usSensorInit();
    
    return;
}