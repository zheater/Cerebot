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
    I2C1CON = 0x0;
    I2C1BRG = I2C1_BRG;
    I2C1STAT = 0x0;
    I2C1CON = I2C1_CON;
    
    return;
}


void i2c_idle(void)
{
    uint16_t t = 0x08FF;
    
    //While I2C Bus is active
    //while (I2CCONbits.SEN || I2CCONbits.PEN || I2CCONbits.RCEN ||
    //        I2CCONbits.RSEN || I2CCONbits.ACKEN || I2CSTATbits.TRSTAT || t--);
    
    return;
}


uint8_t i2c_start(void)
{
    i2c_idle();
    
    /*// Enable the Start condition
    I2CCONbits.SEN = 1;

    // Check for collisions
    if (I2CSTATbits.BCL) 
    {
        return (FALSE);
    } 
    else 
    {
        I2CIdle();
        return (TRUE);
    }*/
    return;
}


void i2c_stop(void)
{
    i2c_idle();
    
    /*// wait for module idle
    I2CIdle();
    
	//initiate stop bit
    I2CCONbits.PEN = 1;
    
    //wait for hardware clear of stop bit
    while (I2CCONbits.PEN) 
    {
        if (x++ > 50) 
            break;
    }
    
    I2CCONbits.RCEN = 0;
    I2CSTATbits.IWCOL = 0;
    I2CSTATbits.BCL = 0;*/
    return;
}


void i2c_rx(unsigned short chipAddress, unsigned short int address, unsigned char * buffer, int numBytesToRead)
{
    /*    int i;
	// 7 Bit addresses only
    char icAddr = (char) chipAddress & 0x00FF;

    I2CStart();
    
    I2CTRN = (icAddr << 1) | WRITE_OP;         // Address of EEPROM - Write      
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    I2CIdle();
    
    I2CTRN = address >> 8;;
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    I2CIdle();
    
    I2CTRN = address & 0x00FF;
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    
    I2CStart();
    
    I2CTRN = (icAddr << 1) | READ_OP;
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    I2CIdle();	// Might not need
    
    for (i=0; i< numBytesToRead; i++)
    {
        I2CIdle();

        I2CCONbits.RCEN = 1; // enable master read
        while (I2CCONbits.RCEN); // wait for byte to be received !(I2CSTATbits.RBF)
        I2CIdle();

        I2CSTATbits.I2COV = 0;
        I2CIdle();
        
        buffer[i] = I2C1RCV;
        
        if (i+1 == numBytesToRead)
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
    }
    return;*/
}


void i2c_tx(unsigned short chipAddress,unsigned short int address, unsigned char * dataToWrite, int numBytesToWrite)
{
    /*int i;
    
    char icAddr = (char) chipAddress & 0x00FF;    

    // Set the start Bit
    I2CStart();
    
    I2CTRN = (icAddr << 1) | WRITE_OP;         // Address of EEPROM - Write      
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    I2CIdle();
    
    I2CTRN = address >> 8;
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    I2CIdle();
    
    I2CTRN = address & 0x00FF;
    while (I2CSTATbits.TRSTAT); // wait until write cycle is complete
    
    for (i=0; i<numBytesToWrite; i++)
    {
        I2CIdle();
        I2CTRN = dataToWrite[i];
    }
        
    I2CStop();*/
}