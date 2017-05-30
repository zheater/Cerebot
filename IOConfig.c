#include "IOConfig.h"
#include "OLEDrgb.h"


#define TIMER_LIMIT     12000



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
    
    //Using Port F for UART to LCD -- U1TX/RF8
    TRISF = 0x0;
    
    //Using Port D for OLED SPI
    //TRISD = 0x0;  -- DELETE
    
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
        
    return;
}

void uart1_enable(void)
{
    U1MODESET = UARTON;
    U1STASET = TXEN;
    U1STASET = RXEN;
    return;
}

void uart1_disable(void)
{
    U1MODECLR = UARTOFF;
    U1STACLR = TXDIS;
    U1STACLR = RXDIS;
    return;
}

void uart1_putc(unsigned char c)
{
    while(U1_TRMT != 1){}     //Wait until transmit shift register is empty
    //U1TXREG = c;
    U1TXREG = 'A';
    
        
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
    SPI1CON = SPI_1_CON;
    SPI1BRG = SPI_1_BRG;

	return;
}

void oled_poweron()
{
    /* Per OLED reference material
     * 
     * Apply power to VCC
     * Send Display Off command
     * Initialize display to default settings
     * Clean screen
     * Apply power to VCCEN
     * Delay 100ms
     * Send Display On command
     *
     */
    
    //Display Off command
    while(SPIBUSY(SPI1CON));
    SPI1BUF = CMD_DISPLAYOFF;
    
    //Initialize display/default settings -- TODO
    
    //Clear screen
    while(SPIBUSY(SPI1CON));
    SPI1BUF = CMD_CLEARWINDOW;
    
    //Apply power to VCCEN
    PORTDSET = (1 << 10);   //Fix this up a bit
    
    //Delay
    delay();
    
    //Send Display On command
    while(SPIBUSY(SPI1CON));
    SPI1BUF = CMD_DISPLAYON;
    
    
    return;
}
void oled_powerdown()
{
    /* Per OLED reference material
     * 
     * Send Display Off command
     * Power off VCCEN
     * Delay 100ms
     * Power off VCC
     *
     */
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
    while(SEN(I2C1CON) || PEN(I2C1CON) || RCEN(I2C1CON) || RSEN(I2C1CON) || ACKEN(I2C1CON) || TRSTAT(I2C1CON) || t--);
    
    return;
}


uint8_t i2c_start(void)
{
    i2c_idle();
    
    // Enable the Start condition    
    I2C1CONSET = 1 << SENSHFT;    

    // Check for collisions
    if (BCL(I2C1STAT)) 
    {
        return (FALSE);
    } 
    else 
    {
        i2c_idle();
        return (TRUE);
    }
    return;
}


void i2c_stop(void)
{
    uint8_t x = 0;
    
    // wait for module idle
    i2c_idle();
    
	//initiate stop bit
    I2C1CONSET = (1 << PENSHFT);
    
    //wait for hardware clear of stop bit
    while (PEN(I2C1CON)) 
    {
        if (x++ > 50) 
            break;
    }
    
    I2C1CONSET = (1 << RCENSHFT);
    I2C1STATSET = (1 << IWCOLSHFT);
    I2C1STATSET = (1 << BCLSHFT);
    
    return;
}


void i2c_rx(unsigned short chipAddress, unsigned short int address, unsigned char * buffer, int numBytesToRead)
{
    uint8_t i;
	// 7 Bit addresses only
    char icAddr = (char) chipAddress & 0x00FF;

    i2c_start();
    
    I2C1TRN = (icAddr << 1);// | WRITE_OP;         // Address of EEPROM - Write      
    while(TRSTAT(I2C1STAT)); // wait until write cycle is complete
    i2c_idle();
    
    I2C1TRN = address >> 8;;
    while(TRSTAT(I2C1STAT)); // wait until write cycle is complete
    i2c_idle();
    
    I2C1TRN = address & 0x00FF;
    while(TRSTAT(I2C1STAT)); // wait until write cycle is complete
    
    i2c_start();
    
    I2C1TRN = (icAddr << 1);// | READ_OP;
    while(TRSTAT(I2C1STAT)); // wait until write cycle is complete
    i2c_idle();	// Might not need
    
    for(i=0; i< numBytesToRead; i++)
    {
        i2c_idle();

        I2C1CONSET = (1 << RCENSHFT); // enable master read
        while (RCEN(I2C1CON)); // wait for byte to be received !(I2CSTATbits.RBF)
        i2c_idle();

        I2C1STATSET = (1 << I2COVSHFT);
        i2c_idle();
        
        buffer[i] = I2C1RCV;
        
        if(i+1 == numBytesToRead)
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
    }
    return;
}


void i2c_tx(unsigned short chipAddress,unsigned short int address, unsigned char * dataToWrite, int numBytesToWrite)
{
    uint8_t i;
    
    char icAddr = (char) chipAddress & 0x00FF;    

    // Set the start Bit
    i2c_start();
    
    I2C1TRN = (icAddr << 1);// | WRITE_OP;         // Address of EEPROM - Write      
    while(TRSTAT(I2C1STAT)); // wait until write cycle is complete
    i2c_idle();
    
    I2C1TRN = address >> 8;
    while(TRSTAT(I2C1STAT)); // wait until write cycle is complete
    i2c_idle();
    
    I2C1TRN = address & 0x00FF;
    while(TRSTAT(I2C1STAT)); // wait until write cycle is complete
    
    for(i=0; i<numBytesToWrite; i++)
    {
        i2c_idle();
        I2C1TRN = dataToWrite[i];
    }
        
    i2c_stop();
}




void delay(void) {
    
    int i;
    
    for(i = 0;i < (TIMER_LIMIT);i++) {
        __asm__("NOP");
    }
    
    return;
}