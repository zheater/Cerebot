/* 
 * File:   IOConfig.h
 * Author: Wiggleby
 *
 * Created on May 19, 2017, 3:21 PM
 */

#ifndef IOCONFIG_H
#define	IOCONFIG_H

#include "SysConfig.h"



/****************************************************
 *GPIO Config
 ****************************************************/
void gpio_init(void);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/****************************************************
 *UART Config
 ****************************************************/
/* UART1 Mode Register
 * 
 *   -    -    -    -    -    -    -    -    -    -    -    -    -    -    -    -
 * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
 *   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0       --> 0x0000
 *
 * ON: UARTx Enable Bit -- 1 = UARTx is enabled; 0 = UARTx is disabled
 * SIDL: Stop in Idle Mode Bit -- 1 = Discontinue operation when device enters idle mode; 0 = Continue operation in idle mode
 * IREN: IrDA Encoder and Decoder Enable Bit -- 1 = IrDA is enabled; 0 = IrDA is disabled
 * RTSMD: Mode Selection for !UxRTS Pin Bit -- 1 = !UxRTS pin is in Simplex mode; 0 = !UxRTS pin is in Flow Control mode
 * UEN: UARTx Enable Bits -- 11 = UxTX, UxRX, UxBCLK pins are enabled and used. !UxCTS pin is controlled by the corresponding bits in the PORTx register; 10 = UxTX, UxRX, !UxCTS, and !UxRTS pins are enabled and used; 01 = UxTX, UxRX, !UxRTS pins are enabled and used. !UxCTS pin is controlled by the corresponding bits in the PORTx register; 00 = UxTX and UxRX pins are enabled and used. !UxCTS and !UxRTS/UxBCLK pins are controlled by the corresponding bits in the PORTx register
 * WAKE: Enable Wake-up On Start Bit Detect During Sleep Mode Bit -- 1 = Wake-up enabled; 0 = Wake-up disabled
 * LPBACK: UARTx Loopback Mode Select bit -- 1 = Loopback mode is enabled; 0 = Loopback mode is disabled
 * ABAUD: Auto-Baud Enable Bit -- 1 = Enable baud rate measurement on the next character; 0 = Baud rate measurement is disabled
 * RXINV: Receive Polarity Inversion Bit -- 1 = UxRX idle state is '0'; 0 = UxRX idle state is '1'
 * BRGH: High Baud Rate Enable Bit -- 1 = High-speed mode - 4x baud clock enabled; 0 = Standard speed mode - 16x baud clock enabled
 * PDSEL: Parity and Data Selection Bits -- 11 = 9-bit data, no parity; 10 = 8-bit data, odd parity; 01 = 8-bit data, even parity; 00 = 8-bit data, no parity
 * STSEL: Stop Selection Bit -- 1 = 2 stop bits; 0 = 1 stop bit
 *
 *  ON    -  SIDL IREN RTSMD  -  <- UEN -> WAKE LPBACK ABAUD RXINV BRGH <- PDSEL -> STSEL
 * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7]  [ 6]  [ 5]  [ 4]  [ 3]  [ 2] [ 1]  [ 0]
 *   0    0    0    0    0    0    0    0    0     0    0    0    0    0    0    0		--> 0x0000
 *
 */
#define _U1MODE                 0x00000000
#define UARTON                  (1 << 15)
#define UARTOFF                 (1 << 15)
#define TXEN                    (1 << 10)
#define TXDIS                   (1 << 10)
#define RXEN                    (1 << 12)
#define RXDIS                   (1 << 10)


/* UART1 Status and Control Register
 *
 * ADM_EN: Automatic Address Detect Mode Enable Bit -- 1 = Automatic address detect mode is enabled; 0 = Automatic address detect mode is disabled
 * ADDR: Automatic Address Mask Bits -- When ADM_EN bit is '1' this value defines the address character to use for automatic address detection
 * 
 *   -    -    -    -    -    -    -  ADM_EN  <--------------- ADDR --------------->    
 * [31] [30] [29] [28] [27] [26] [25]  [24]  [23] [22] [21] [20] [19] [18] [17] [16]
 *   0    0    0    0    0    0    0     1     0    1    0    0    1    0    0    0       --> 0x0148
 *
 * UTXISEL: TX Interrupt Mode Selection Bits -- 11 = Reserved; 10 = Interrupt is generated when the transmit buffer becomes empty; 01 = Interrupt is generated when all characters have been transmitted; 00 = Interrupt is generated when the transmit buffer contains at least one empty space
 * UTXINV: Transmit Polarity Inversion Bit -- 1 = UxTX idle state is '0'; 0 = UxTX idle state is '1'
 * URXEN: Receiver Enable Bit -- 1 = UARTx receiver is enabled; 0 = UARTx receiver is disabled
 * UTXBRK: Transmit Break Bit -- 1 = Send break on next transmission; 0 = Break transmission is disabled on completed
 * UTXEN: Transmit Enable Bit -- 1 = UARTx transmitter is enabled; 0 = UARTx transmitter is disabled
 * UTXBF: Transmit Buffer Full Status Bit (Read Only) -- 1 = Transmit buffer is full; 0 = Transmit buffer is not full
 * TRMT: Transmit Shift Register Bit (Read Only) -- 1 = Transmit shift register is empty and transmit buffer is empty; 0 = Transmit shift register is not empty (transmission in progress)
 * UTXISEL: Receive Interrupt Mode Selection Bits -- 11 = Interrupt flag bit is set when receive buffer becomes full; 10 = Interrupt flag bit is set when receive buffer becomes 3/4 full; 0x = Interrupt flag bit is set when a character is received
 * ADDEN: Address Character Detect Bit -- 1 = Address detect mode is enabled; 0 = Address detect mode is disabled
 * RIDLE: Receiver Idle Bit -- 1 = Receiver is idle; 0 = Data is being received
 * PERR: Parity Error Status Bit (Read Only) -- 1 = Parity error had been detected for current character; 0 = Parity error has not been detected
 * FERR: Framing Error Status Bit (Read Only) -- 1 = Framing error had been detected for current character; 0 = Framing error has not been detected
 * OERR: Receive Buffer Overrun Error Status Bit (Read Only) -- 1 = Receive buffer has overflowed; 0 = Receive buffer has not overflowed
 * URXDA: Receive Buffer Data Available bit (Read Only) -- 1 = Receive buffer has data, as least one character can be read; 0 = Receive buffer is empty
 *
 * <- UTXISEL -> UTXINV URXEN UTXBRK UTXEN UTXBF TRMT <- UTXISEL -> ADDEN RIDLE PERR FERR OERR URXDA
 *  [15]  [14]    [13]   [12]  [11]   [10] [ 9]  [ 8]  [ 7]  [ 6]    [ 5]  [ 4] [ 3] [ 2] [ 1]  [ 0]
 *    0     0       0      0     0      0    0     0     0     0       1     0    0    0    0     0		--> 0x0020
 *
 */
#define _U1STA                  0x01480020
#define U1_UTXBF                ((U1STA & 0x200) >> 9)
#define U1_TRMT                 ((U1STA & 0x100) >> 8)


/* UART1 Baud Rate Register
 *
  *   -    -    -    -    -    -    -    -    -    -    -    -    -    -    -    -
 * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
 *   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0       --> 0x0000
 *
 *  BRG: Baud Rate Divisor Bits -- Baud Rate = F_PB / (16 * (UxBRG + 1))
 *  F_PB = 4MHz; Desired Baud Rate = 9600;
 *  UxBRG = (4E6 / (9600 * 16)) - 1 = 25.042 ~= 25 = 0x19
 *  Final Baud Rate = 9615
 *
 * <----------------------------------- BRG ------------------------------------->
 * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
 *   0    0    0    0    0    0    0    0    0    0    0    1    1    0    0    1       --> 0x0019
 *
 */
#define _U1BRG                  0x00000019


void uart_init(void);
void uart1_enable(void);
void uart1_disable(void);
void uart1_putc(unsigned char c);
void uart1_puts(unsigned char *s);
void uart1_rx(void);

//Using PORTE for Bluetooth
#define RTS_PTE         0
#define RXD_PTE         1
#define TXD_PTE         2
#define CTS_PTE         3
#define STATUS_PTE      4
#define RST_PTE         5




#endif	/* IOCONFIG_H */



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/****************************************************
 *SPI Config
 ****************************************************/
/*SPI1 Control Register
 * 
 *FRMEN FRMSYNC FRMPOL														  SPIFE
 * [31]   [30]   [29]  [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18]  [17] [16]
 *   1      1      1     0    0    0    0    0    0    0    0    0    0    0     1    0		--> E002
 *
 *  ON       SIDL DISSDO MODE32 MODE16  SMP  CKE SSEN  CKP MSTEN
 * [15] [14] [13]  [12]   [11]   [10]  [ 9] [ 8] [ 7] [ 6] [ 5]  [ 4] [ 3] [ 2] [ 1] [ 0]
 *   0    0    1     1      0      0     0    0    0    0    1     0    0    0    0    0		--> 3820
 */
#define _SPI1CON       0xE0023020
#define SPION           15

/*SPI1 Baud Rate Register
 *
 * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
 *   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0		--> 0000
 *
 *                                     <-------- Baud Rate Divisor Bits -------->
 * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
 *   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0		--> 0000
 */
#define _SPI1BRG       0x00000000

//Status register macros
#define SPIBUSYSHFT     11  //SPI busy bit
#define SPIBUSY(x)      ((x & 0x00000800) >> SPIBUSYSHFT)
#define SREMPTYSHFT     7   //Shift register empty
#define SREMPTY(x)      ((x & 0x00000080) >> SREMPTYSHFT)
#define TBEMPTYSHFT     3   //Tx buffer empty
#define TBEMTPY(x)      ((x & 0x00000008) >> TBEMPTYSHFT)
#define TBFULLSHFT      1   //Tx buffer full
#define TBFULL(x)       ((x & 0x00000002) >> TBFULLSHFT)
#define RBFULLSHFT      0   //Rx buffer full
#define RBFULL(x)       ((x & 0x00000001) >> RBFULLSHFT)



/*SPI2 Control Register
 *FRMEN FRMSYNC FRMPOL														  SPIFE
 * [31]   [30]   [29]  [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18]  [17] [16]
 *   1      0      1     0    0    0    0    0    0    0    0    0    0    0     1    0		--> A002
 *
 *  ON       SIDL DISSDO    MODE    SMP  CKE SSEN  CKP MSTEN
 * [15] [14] [13]  [12]  [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5]  [ 4] [ 3] [ 2] [ 1] [ 0]
 *   1    0    1     1     1    0    0    0    0    0    1     0    0    0    0    0		--> B820
 */
#define _SPI2CON 0xA002B820

/*SPI2 Baud Rate Register
 *
 * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
 *   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0		--> 0000
 *
 *                                     <-------- Baud Rate Divisor Bits -------->
 * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
 *   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0		--> 0000
 */
#define _SPI2BRG 0xA002B820



void spi_init();
void oled_poweron();
void oled_powerdown();


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/****************************************************
 *I2C Config
 ****************************************************/

//NOTE TO SELF: SCL1/RG2: Pin H10
    //              SCL2/RA2: Pin H11
    //              SDA1/RG3: Pin J11
    //              SDA2/RA3: Pin G10
    
    /*I2C1 Control Register
    * PCIE: Stop condition interrupt bit (Slave-mode only) -- 1 = Enable interrupt on detection of Stop condition, 0 = Stop condition interrupts are disabled
    * SCIE: Start condition interrupt bit (Slave-mode only) -- 1 = Enable interrupt on detection of Start or Restart condition, 0 = Start condition interrupts are disabled
    * BOEN: Buffer overwrite enable bit (Slave-mode only) -- 1 = I2CxRCV is updated and !ACK is generated for received address/data byte ignoring the state of I2COV only if bit RBF = 0, 0 = I2CxRCV is only updated when I2COV is clear
    * SDAHT: SDAx holt time selection -- 1 = Minimum 300ns hold time after falling edge of SCLx, 0 = Minimum 100ns hold time after falling edge of SCLx
    * SBCDE: Slave-mode bus collision detect enable bit (Slave-mode only) -- 1 = Enable slave bus collision interrupts, 0 = Slave bus collision interrupts are disabled
    * AHEN: Address hold enable bit (Slave-mode only) -- 1 = Following the 8th falling edge of SCLx for a matching received address byte, slave hardware clears the I2CxCON.SCKREL bit and SCLx is held low, 0 = Address holding is disabled
    * DHEN: Data hold enable bit (Slave-mode only) -- 1 = Following the 8th falling edge of SCLx for a received data byte, slave hardware clears the I2CxCON.SCKREL bit and SCLx is held low, 0 = Data holding is disabled
    *
    *                                              PCIE SCIE BOEN SDAHT SBCDE AHEN DHEN
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20]  [19]  [18] [17] [16]
    *                                                0    0    0     0     0    0    0   ---> 0x0000
     * 
    * ON: I2C enable bit -- 1 = Enables the I2C module and configures the SDAx and SCLx pins as serial port pins, 0 = Disabled I2C; all I2C pins are controlled by PORT functions
    * SIDL: Stop in idle mode bit -- 1 = Discontinue module operation when the device enters idle mode, 0 = Continue module operation in idle mode
    * SCLREL: SCLx release control bit (Slave-mode only) -- 1 = Release clock, 0 = Forces clock low (clock stretch) if STREN = 0 or holds clock low (clock stretch) and user may program this bit to '0' to force a clock stretch at the next SCLx low is STREN = 1;
    * STRICT: Strict I2C reserved address rule enable bit -- 1 = Strict reserved addressing is enforced, 0 = Strict reserved addressing rule is not enabled
    * A10M: 10-bit slave address flag bit -- 1 = I2CxADD register is a 10-bit slave address, 0 = I2CxADD register is a 7-bit slave address
    * DISSLW: Slew rate control disable bit -- 1 = Slew rate control disabled for Standard Speed mode (100kHz); also disabled for 1 MHz mode, 0 = Slew rate control enabled for High Speed mode (400 kHz)
    * SMEN: SMBus input ievels disable bit -- 1 = Enable input logic so that thresholds are compliant with the SMBus specification, 0 = Disable SMBus specific inputs
    * GCEN: General call enable bit (Slave-mode only) -- 1 = Enable interrupt when a general call address is received in I2CSR. Module is enabled for reception, 0 = General call address disabled
    * STREN: SCLx clock stretch enable bit -- 1 = Enable clock stretching, 0 = Disabled clock stretching
    * ACKDT: Acknowledge data bit (Master-mode only, applicable during master receive). Value that will be transmitted when user initiates an Acknowledge sequence at the end of a receive -- 1 = A NACK is sent, 0 = A !ACK is sent
    * ACKEN: Acknowledge sequence enable bit (Master-mode only, applicable during master receive) -- 1 = Initiate Acknowledge sequence on SDAx and SCLx pins and transmit ACKDT data bit; cleared by module, 0 = Acknowledge sequence idle
    * RCEN: Receive enable bit (Master-mode only) -- 1 = Enables receive mode for I2C, automatically cleared by module at end of 8-bit receive data byte, 0 = Receive sequence not in progress
    * PEN: Stop condition enable bit (Master-mode only) -- 1 = Initiate Stop condition on SDAx and SCLx pins; cleared by module, 0 = Stop condition idle
    * RSEN: Restart condition enable bit (Master-mode only) -- 1 = Initiate Restart condition on SDAx and SCLx pins; cleared by module, 0 = Restart condition idle
    * SEN: Start condition enable bit (Master-mode only) -- 1 = Initiate Start condition on SDAx and SCLx pins; cleared by module, 0 = Start condition idle
    * 
    *  ON       SIDL SCLREL STRICT A10M DISSLW SMEN GCEN STREN ACKDT ACKEN RCEN  PEN RSEN  SEN
    * [15] [14] [13]  [12]   [11]  [10]  [ 9]  [ 8] [ 7]  [ 6]  [ 5]  [ 4] [ 3] [ 2] [ 1] [ 0]
    *   1    0    1     0      0     0     0     0    0     0     0     0    0    0    0    0
    */ 
#define _I2C1CON            0x0000A000



   /*I2C1 Status Register
    * 
    *                                              
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
    * 
    * ACKSTAT: Acknowledge status bit -- 1 = Acknowledge was not received, 0 = Acknowledge was received
    * TRSTAT: Transmit status bit (Master-mode only) -- 1 = Master transmit in progress (8 bits + !ACK), 0 = Master transmit not in progress
    * ACKTIM: Acknowledge time status bit (Master-mode only) -- 1 = I2C bus is in an Acknowledge sequence, set on the 8th falling edge of the SCLx clock, 0 = Not an Acknowledge sequence, cleared on the 9th rising edge of the SCLx clock
    * BCL: Master bus collision detect bit. Cleared when I2C module is disabled-- 1 = A bus collision has been detected during a master operation, 0 = No collision has been detected
    * GCSTAT: General call status bit. Cleared after Stop detection. -- 1 = General call address was received, 0 = Gernal call address was not received
    * ADD10: 10-bit address status bit. Cleared after Stop detection. -- 1 = 10-bit address was matched, 0 = 10-bit address was not matched
    * IWCOL: Write collision detect bit -- 1 = An attempt to write the I2CxTRN register collided because the I2C module is busy, 0 = No collision
    * I2COV: I2C receive overflow status bit -- 1 = A byte is received while the I2CxRCV register is still holding the previous byte. I2CxCOV is a "don't care" in transmit mode, 0 = No overflow
    * DA: Data/Address bit (Slave-mode only) -- 1 = Indicates that the last byte received or transmitted was data, 0 = Indicates that the last byte received or transmitted was address
    * P: Stop bit. Updated when Start, Reset, or Stop detected; cleared when I2C module is disabled -- 1 = Indicates that a Stop bit has been detected last, 0 = Stop bit was not detected last
    * S: Start bit. Updated when Start, Reset, or Stop detected; cleared when I2C module is disabled -- 1 = Indicates that a Start (or Restart) bit has been detected last, 0 = Start bit was not detected last
    * RW: Read/Write information bit (Slave-mode only) -- 1 = Read - indicates data transfer is output from slave, 0 = Write - indicates data transfer is input to slave
    * RBF: Receive buffer full status bit -- 1 = Receive complete; I2CxRCV register is full, 0 = Receive not complete; I2CxRCV register is empty
    * TBF: Transmit buffer full status bit -- 1 = Transmit in progress; I2CxTRN register is full (8-bits of data), 0 = Transmit complete; I2CxTRN register is empty
    *
    * ACKSTAT TRSTAT ACKTIM            BCL GCSTAT ADD10 IWCOL I2COV  DA    P    S   RW   RBF  TBF
    *   [15]   [14]   [13]  [12] [11] [10]  [ 9]   [ 8]  [ 7]  [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
    * 
    */


   /*I2C1 Slave Address Register
    * 
    *                                              
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
    *
    * ADD: I2C slave device address bits 
    *
    *                               <--------------------- ADD --------------------->
    * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
    * 
    */


   /*I2C1 Address Mask Register
    * 
    *                                              
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
    * 
    * MSK: I2C address mask bits -- 1 = Forces a "don't care" in the particular bit position on the incoming address match sequence, 0 = Address bit position must match the incoming I2C address match sequence.
    *
    *                               <--------------------- MSK --------------------->
    * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
    * 
    */


   /*I2C1 Baud Rate Generator Register
    * 
    *                                              
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
    * 
    * BRG: I2C baud rate generator value bits. These bits control the divider function of the peripheral clock.
    *
    * <------------------------------------ BRG ------------------------------------>
    * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
    * 
    */


   /*I2C1 Transmit Data Register
    * 
    *                                              
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
    *
    * TXDATA: I2C transmit data buffer bits 
    *
    *                                         <--------------- TXDATA -------------->
    * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
    * 
    */


   /*I2C1 Receive Data Register
    * 
    *                                              
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
    * 
    * RXDATA: I2C receive data buffer bits
    *
    *                                         <--------------- RXDATA -------------->
    * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
    * 
    */

    
    
        /*I2C1 Control Register
    * PCIE: Stop condition interrupt bit (Slave-mode only) -- 1 = Enable interrupt on detection of Stop condition, 0 = Stop condition interrupts are disabled
    * SCIE: Start condition interrupt bit (Slave-mode only) -- 1 = Enable interrupt on detection of Start or Restart condition, 0 = Start condition interrupts are disabled
    * BOEN: Buffer overwrite enable bit (Slave-mode only) -- 1 = I2CxRCV is updated and !ACK is generated for received address/data byte ignoring the state of I2COV only if bit RBF = 0, 0 = I2CxRCV is only updated when I2COV is clear
    * SDAHT: SDAx holt time selection -- 1 = Minimum 300ns hold time after falling edge of SCLx, 0 = Minimum 100ns hold time after falling edge of SCLx
    * SBCDE: Slave-mode bus collision detect enable bit (Slave-mode only) -- 1 = Enable slave bus collision interrupts, 0 = Slave bus collision interrupts are disabled
    * AHEN: Address hold enable bit (Slave-mode only) -- 1 = Following the 8th falling edge of SCLx for a matching received address byte, slave hardware clears the I2CxCON.SCKREL bit and SCLx is held low, 0 = Address holding is disabled
    * DHEN: Data hold enable bit (Slave-mode only) -- 1 = Following the 8th falling edge of SCLx for a received data byte, slave hardware clears the I2CxCON.SCKREL bit and SCLx is held low, 0 = Data holding is disabled
    *
    *                                              PCIE SCIE BOEN SDAHT SBCDE AHEN DHEN
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20]  [19]  [18] [17] [16]
    *                                                0    0    0     1     0    0    0   ---> 0x0008
     * 
    * ON: I2C enable bit -- 1 = Enables the I2C module and configures the SDAx and SCLx pins as serial port pins, 0 = Disabled I2C; all I2C pins are controlled by PORT functions
    * SIDL: Stop in idle mode bit -- 1 = Discontinue module operation when the device enters idle mode, 0 = Continue module operation in idle mode
    * SCLREL: SCLx release control bit (Slave-mode only) -- 1 = Release clock, 0 = Forces clock low (clock stretch) if STREN = 0 or holds clock low (clock stretch) and user may program this bit to '0' to force a clock stretch at the next SCLx low is STREN = 1;
    * STRICT: Strict I2C reserved address rule enable bit -- 1 = Strict reserved addressing is enforced, 0 = Strict reserved addressing rule is not enabled
    * A10M: 10-bit slave address flag bit -- 1 = I2CxADD register is a 10-bit slave address, 0 = I2CxADD register is a 7-bit slave address
    * DISSLW: Slew rate control disable bit -- 1 = Slew rate control disabled for Standard Speed mode (100kHz); also disabled for 1 MHz mode, 0 = Slew rate control enabled for High Speed mode (400 kHz)
    * SMEN: SMBus input ievels disable bit -- 1 = Enable input logic so that thresholds are compliant with the SMBus specification, 0 = Disable SMBus specific inputs
    * GCEN: General call enable bit (Slave-mode only) -- 1 = Enable interrupt when a general call address is received in I2CSR. Module is enabled for reception, 0 = General call address disabled
    * STREN: SCLx clock stretch enable bit -- 1 = Enable clock stretching, 0 = Disabled clock stretching
    * ACKDT: Acknowledge data bit (Master-mode only, applicable during master receive). Value that will be transmitted when user initiates an Acknowledge sequence at the end of a receive -- 1 = A NACK is sent, 0 = A !ACK is sent
    * ACKEN: Acknowledge sequence enable bit (Master-mode only, applicable during master receive) -- 1 = Initiate Acknowledge sequence on SDAx and SCLx pins and transmit ACKDT data bit; cleared by module, 0 = Acknowledge sequence idle
    * RCEN: Receive enable bit (Master-mode only) -- 1 = Enables receive mode for I2C, automatically cleared by module at end of 8-bit receive data byte, 0 = Receive sequence not in progress
    * PEN: Stop condition enable bit (Master-mode only) -- 1 = Initiate Stop condition on SDAx and SCLx pins; cleared by module, 0 = Stop condition idle
    * RSEN: Restart condition enable bit (Master-mode only) -- 1 = Initiate Restart condition on SDAx and SCLx pins; cleared by module, 0 = Restart condition idle
    * SEN: Start condition enable bit (Master-mode only) -- 1 = Initiate Start condition on SDAx and SCLx pins; cleared by module, 0 = Start condition idle
    * 
    *  ON       SIDL SCLREL STRICT A10M DISSLW SMEN GCEN STREN ACKDT ACKEN RCEN  PEN RSEN  SEN
    * [15] [14] [13]  [12]   [11]  [10]  [ 9]  [ 8] [ 7]  [ 6]  [ 5]  [ 4] [ 3] [ 2] [ 1] [ 0]
    * 
    */

#define SENSHFT         0
#define SEN(x)          ((x & 0x00000001) >> SENSHFT)
#define RSENSHFT        1
#define RSEN(x)         ((x & 0x00000002) >> RSENSHFT)
#define PENSHFT         2
#define PEN(x)          ((x & 0x00000004) >> PENSHFT)
#define RCENSHFT        3
#define RCEN(x)         ((x & 0x00000008) >> RCENSHFT)
#define ACKENSHFT       4
#define ACKEN(x)        ((x & 0x00000010) >> ACKENSHFT)
#define ACKDTSHFT       5
#define ACKDT(x)        ((x & 0x00000020) >> ACKDTSHFT)



   /*I2C1 Status Register
    * 
    *                                              
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
    * 
    * ACKSTAT: Acknowledge status bit -- 1 = Acknowledge was not received, 0 = Acknowledge was received
    * TRSTAT: Transmit status bit (Master-mode only) -- 1 = Master transmit in progress (8 bits + !ACK), 0 = Master transmit not in progress
    * ACKTIM: Acknowledge time status bit (Master-mode only) -- 1 = I2C bus is in an Acknowledge sequence, set on the 8th falling edge of the SCLx clock, 0 = Not an Acknowledge sequence, cleared on the 9th rising edge of the SCLx clock
    * BCL: Master bus collision detect bit. Cleared when I2C module is disabled-- 1 = A bus collision has been detected during a master operation, 0 = No collision has been detected
    * GCSTAT: General call status bit. Cleared after Stop detection. -- 1 = General call address was received, 0 = Gernal call address was not received
    * ADD10: 10-bit address status bit. Cleared after Stop detection. -- 1 = 10-bit address was matched, 0 = 10-bit address was not matched
    * IWCOL: Write collision detect bit -- 1 = An attempt to write the I2CxTRN register collided because the I2C module is busy, 0 = No collision
    * I2COV: I2C receive overflow status bit -- 1 = A byte is received while the I2CxRCV register is still holding the previous byte. I2CxCOV is a "don't care" in transmit mode, 0 = No overflow
    * DA: Data/Address bit (Slave-mode only) -- 1 = Indicates that the last byte received or transmitted was data, 0 = Indicates that the last byte received or transmitted was address
    * P: Stop bit. Updated when Start, Reset, or Stop detected; cleared when I2C module is disabled -- 1 = Indicates that a Stop bit has been detected last, 0 = Stop bit was not detected last
    * S: Start bit. Updated when Start, Reset, or Stop detected; cleared when I2C module is disabled -- 1 = Indicates that a Start (or Restart) bit has been detected last, 0 = Start bit was not detected last
    * RW: Read/Write information bit (Slave-mode only) -- 1 = Read - indicates data transfer is output from slave, 0 = Write - indicates data transfer is input to slave
    * RBF: Receive buffer full status bit -- 1 = Receive complete; I2CxRCV register is full, 0 = Receive not complete; I2CxRCV register is empty
    * TBF: Transmit buffer full status bit -- 1 = Transmit in progress; I2CxTRN register is full (8-bits of data), 0 = Transmit complete; I2CxTRN register is empty
    *
    * ACKSTAT TRSTAT ACKTIM            BCL GCSTAT ADD10 IWCOL I2COV  DA    P    S   RW   RBF  TBF
    *   [15]   [14]   [13]  [12] [11] [10]  [ 9]   [ 8]  [ 7]  [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
    * 
    */
#define TRSTATSHFT          14
#define TRSTAT(x)           ((x & 0x00004000) >> TRSTATSHFT)
#define BCLSHFT             10
#define BCL(x)              ((x & 0x00000400) >> BCLSHFT)
#define IWCOLSHFT           7
#define IWCOL(x)            ((x & 0x00000080) >> IWCOLSHFT)
#define I2COVSHFT           6
#define I2COV(x)            ((x & 0x00000040) >> I2COVSHFT)


   /*I2C1 Slave Address Register
    * 
    *                                              
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
    *
    * ADD: I2C slave device address bits 
    *
    *                               <--------------------- ADD --------------------->
    * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
    * 
    */


   /*I2C1 Address Mask Register
    * 
    *                                              
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
    * 
    * MSK: I2C address mask bits -- 1 = Forces a "don't care" in the particular bit position on the incoming address match sequence, 0 = Address bit position must match the incoming I2C address match sequence.
    *
    *                               <--------------------- MSK --------------------->
    * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
    * 
    */


   /*I2C1 Baud Rate Generator Register
    * 
    *                                              
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
    *   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    --> 0x0000
    * 
    * BRG: I2C baud rate generator value bits. These bits control the divider function of the peripheral clock.
    *
    * <------------------------------------ BRG ------------------------------------>
    * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
    *   0    0    0    0    0    0    0    0    0    0    0    0    1    0    1    0    --> 0x000A
    */
#define _I2C1BRG            0xA;    //400kHz


   /*I2C1 Transmit Data Register
    * 
    *                                              
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
    *
    * TXDATA: I2C transmit data buffer bits 
    *
    *                                         <--------------- TXDATA -------------->
    * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
    * 
    */


   /*I2C1 Receive Data Register
    * 
    *                                              
    * [31] [30] [29] [28] [27] [26] [25] [24] [23] [22] [21] [20] [19] [18] [17] [16]
    * 
    * RXDATA: I2C receive data buffer bits
    *
    *                                         <--------------- RXDATA -------------->
    * [15] [14] [13] [12] [11] [10] [ 9] [ 8] [ 7] [ 6] [ 5] [ 4] [ 3] [ 2] [ 1] [ 0]
    * 
    */

void i2c_init(void);
void i2c_delay(void);
uint8_t i2c_start(void);
void i2c_stop(void);
void i2c_rx(unsigned short chipAddress, unsigned short int address, unsigned char * buffer, int numBytesToRead);
void i2c_tx(unsigned short chipAddress,unsigned short int address, unsigned char * dataToWrite, int numBytesToWrite);