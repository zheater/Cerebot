#include "IOConfig.h"



/****************************************************
 *GPIO Config
 ****************************************************/
void gpio_init(void)
{    
    //Configure Port B LED bits to write
    TRISB = 0x0;
    
    //Using Port E for Bluetooth interface
    TRISE = 0x00FF;
    
    //Using Port A for motor control
    TRISA = 0xF0; //2 & 3 are outputs for motor control, 6 & 7 are button inputs for speed adjust
    
    return;
}

int keypad(void)
{
    uint8_t hexValue = '\0';
    uint32_t portE;
    
    portE = (PORTE & 0x00FF);

    //Active Low
    switch(portE) {
        case 0xE7:
            hexValue = 0x0;
            break;
        case 0x77:
            hexValue = 0x1;
            break;
        case 0x7B:
            hexValue = 0x2;
            break;
        case 0x7D:
            hexValue = 0x3;
            break;
        case 0xB7:
            hexValue = 0x4;
            break;
        case 0xBB:
            hexValue = 0x5;
            break;
        case 0xBD:
            hexValue = 0x6;
            break;
        case 0xD7:
            hexValue = 0x7;
            break;
        case 0xDB:
            hexValue = 0x8;
            break;
        case 0xDD:
            hexValue = 0x9;
            break;
        case 0x7E:
            hexValue = 0xA;
            break;
        case 0xBE:
            hexValue = 0xB;
            break;
        case 0xDE:
            hexValue = 0xC;
            break;
        case 0xEE:
            hexValue = 0xD;
            break;
        case 0xED:
            hexValue = 0xE;
            break;
        case 0xEB:
            hexValue = 0xF;
            break;
        default:
            hexValue = '\0';    //Fix this
    };
    
    if(hexValue != '\0') {
        LATB = (hexValue << 10);   //Display hex value on LEDs
    }
    
    
    return hexValue;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/****************************************************
 *UART Config
 ****************************************************/
void uart_init(void)
{
    U1MODE = U1_MODE;
    U1STA = U1_STA;
    U1BRG = U1_BRG;
    
    
    U1MODESET = UARTON;
    
    return;
}

void uart1_enable(void)
{
    U1MODESET = (1 << 15);
    return;
}

void uart1_putc(unsigned char c)
{
    while(U1_TRMT != 1)     //Wait until transmit shift register is empty
    U1TXREG = c;
        
    return;
}

void uart1_puts(unsigned char *s)
{
    while(*s) {
        uart1_putc(*s);     //Tx character located at address s
        s++;                //Increment pointer
    }
    
    return;
}

void uart1_rx(void)
{
    
    return;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/****************************************************
 *SPI Config
 ****************************************************/
void spi_init()
{
	//Initialize SPI1 Control Register
	SPI1->CON = SPI_1_CON;

	//Initialize SPI1 Baud Rate Register
	SPI1->BRG = SPI_1_BRG;

	//Initialize SPI2 Control Register
	SPI2->CON = SPI_2_CON;

	//Initialize SPI2 Baud Rate Register
	SPI2->BRG = SPI_2_BRG;

	return;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/****************************************************
 *I2C Config
 ****************************************************/

void i2c_init(void)
{   
    
    return;
}


void i2c_delay(void)
{
    return;
}


void i2c_start(void)
{
    return;
}


void i2c_stop(void)
{
    return;
}


uint8_t i2c_rx(uint8_t databyte)
{
    uint8_t rx;
    
    return rx;
}


bool i2c_tx(uint8_t txbyte)
{
    bool ack;
    
    return ack;
}