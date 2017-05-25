/*
 * SysConfig.h
 *
 *  Created on: Apr 11, 2017
 *      Author: zachary.heater
 */

#ifndef SYSCONFIG_H_
#define SYSCONFIG_H_

#include <stdint.h>
#include <stdbool.h>

#define SET_OFFSET      0x8
#define CLR_OFFSET      0x4
#define INV_OFFSET      0xC


/****************************************************
 *Interrupt Register Addresses
 ****************************************************/
//
#define INTCON_BASE 		(0xBF881000)    
#define INTCON 				*(volatile uint32_t *)(INTCON_BASE)         //Interrupt Control Register
#define INTCONSET			*(volatile uint32_t *)(INTCON_BASE + SET_OFFSET)
#define INTCONCLR			*(volatile uint32_t *)(INTCON_BASE + CLR_OFFSET)
#define INTCONINV			*(volatile uint32_t *)(INTCON_BASE + INV_OFFSET)
#define INTSTAT_BASE 		(0xBF881010)
#define INTSTAT 			*(volatile uint32_t *)(INTSTAT_BASE)        //Interrupt Status Register
#define INTSTATSET			*(volatile uint32_t *)(INTSTAT_BASE + SET_OFFSET)
#define INTSTATCLR			*(volatile uint32_t *)(INTSTAT_BASE + CLR_OFFSET)
#define INTSTATINV			*(volatile uint32_t *)(INTSTAT_BASE + INV_OFFSET)
#define IPTMR_BASE          (0xBF881020)
#define IPTMR               *(volatile uint32_t *)(IPTMR_BASE)        //Interrupt Proximity Timer Register
#define IPTMRSET			*(volatile uint32_t *)(IPTMR_BASE + SET_OFFSET)
#define IPTMRCLR			*(volatile uint32_t *)(IPTMR_BASE + CLR_OFFSET)
#define IPTMRINV			*(volatile uint32_t *)(IPTMR_BASE + INV_OFFSET)
#define IFS0_BASE           (0xBF881030)
#define IFS0                *(volatile uint32_t *)(IFS0_BASE)        //Interrupt Flag Status Register
#define IFS0SET             *(volatile uint32_t *)(IFS0_BASE + SET_OFFSET)
#define IFS0CLR             *(volatile uint32_t *)(IFS0_BASE + CLR_OFFSET)
#define IFS0INV             *(volatile uint32_t *)(IFS0_BASE + INV_OFFSET)
#define IFS1_BASE           (0xBF881040)
#define IFS1                *(volatile uint32_t *)(IFS1_BASE)        //Interrupt Flag Status Register
#define IFS1SET             *(volatile uint32_t *)(IFS1_BASE + SET_OFFSET)
#define IFS1CLR             *(volatile uint32_t *)(IFS1_BASE + CLR_OFFSET)
#define IFS1INV             *(volatile uint32_t *)(IFS1_BASE + INV_OFFSET)
#define IEC0_BASE           (0xBF881060)
#define IEC0                *(volatile uint32_t *)(IEC0_BASE)        //Interrupt Enable Control Register
#define IEC0SET             *(volatile uint32_t *)(IEC0_BASE + SET_OFFSET)
#define IEC0CLR             *(volatile uint32_t *)(IEC0_BASE + CLR_OFFSET)
#define IEC0INV             *(volatile uint32_t *)(IEC0_BASE + INV_OFFSET)
#define IEC1_BASE           (0xBF881070)
#define IEC1                *(volatile uint32_t *)(IEC1_BASE)        //Interrupt Enable Control Register
#define IEC1SET             *(volatile uint32_t *)(IEC1_BASE + SET_OFFSET)
#define IEC1CLR             *(volatile uint32_t *)(IEC1_BASE + CLR_OFFSET)
#define IEC1INV             *(volatile uint32_t *)(IEC1_BASE + INV_OFFSET)
#define IPC0_BASE           (0xBF881090)
#define IPC0                *(volatile uint32_t *)(IPC0_BASE)        //Interrupt Priority Control Register
#define IPC0SET             *(volatile uint32_t *)(IPC0_BASE + SET_OFFSET)
#define IPC0CLR             *(volatile uint32_t *)(IPC0_BASE + CLR_OFFSET)
#define IPC0INV             *(volatile uint32_t *)(IPC0_BASE + INV_OFFSET)
#define IPC1_BASE           (0xBF8810A0)
#define IPC1                *(volatile uint32_t *)(IPC1_BASE)        //Interrupt Priority Control Register
#define IPC1SET             *(volatile uint32_t *)(IPC1_BASE + SET_OFFSET)
#define IPC1CLR             *(volatile uint32_t *)(IPC1_BASE + CLR_OFFSET)
#define IPC1INV             *(volatile uint32_t *)(IPC1_BASE + INV_OFFSET)
#define IPC2_BASE           (0xBF8810B0)
#define IPC2                *(volatile uint32_t *)(IPC2_BASE)        //Interrupt Priority Control Register
#define IPC2SET             *(volatile uint32_t *)(IPC2_BASE + SET_OFFSET)
#define IPC2CLR             *(volatile uint32_t *)(IPC2_BASE + CLR_OFFSET)
#define IPC2INV             *(volatile uint32_t *)(IPC2_BASE + INV_OFFSET)
#define IPC3_BASE           (0xBF8810C0)
#define IPC3                *(volatile uint32_t *)(IPC3_BASE)        //Interrupt Priority Control Register
#define IPC3SET             *(volatile uint32_t *)(IPC3_BASE + SET_OFFSET)
#define IPC3CLR             *(volatile uint32_t *)(IPC3_BASE + CLR_OFFSET)
#define IPC3INV             *(volatile uint32_t *)(IPC3_BASE + INV_OFFSET)
#define IPC4_BASE           (0xBF8810D0)
#define IPC4                *(volatile uint32_t *)(IPC4_BASE)        //Interrupt Priority Control Register
#define IPC4SET             *(volatile uint32_t *)(IPC4_BASE + SET_OFFSET)
#define IPC4CLR             *(volatile uint32_t *)(IPC4_BASE + CLR_OFFSET)
#define IPC4INV             *(volatile uint32_t *)(IPC4_BASE + INV_OFFSET)
#define IPC5_BASE           (0xBF8810E0)
#define IPC5                *(volatile uint32_t *)(IPC5_BASE)        //Interrupt Priority Control Register
#define IPC5SET             *(volatile uint32_t *)(IPC5_BASE + SET_OFFSET)
#define IPC5CLR             *(volatile uint32_t *)(IPC5_BASE + CLR_OFFSET)
#define IPC5INV             *(volatile uint32_t *)(IPC5_BASE + INV_OFFSET)
#define IPC6_BASE           (0xBF8810F0)
#define IPC6                *(volatile uint32_t *)(IPC6_BASE)        //Interrupt Priority Control Register
#define IPC6SET             *(volatile uint32_t *)(IPC6_BASE + SET_OFFSET)
#define IPC6CLR             *(volatile uint32_t *)(IPC6_BASE + CLR_OFFSET)
#define IPC6INV             *(volatile uint32_t *)(IPC6_BASE + INV_OFFSET)
#define IPC7_BASE           (0xBF881100)
#define IPC7                *(volatile uint32_t *)(IPC7_BASE)        //Interrupt Priority Control Register
#define IPC7SET             *(volatile uint32_t *)(IPC7_BASE + SET_OFFSET)
#define IPC7CLR             *(volatile uint32_t *)(IPC7_BASE + CLR_OFFSET)
#define IPC7INV             *(volatile uint32_t *)(IPC7_BASE + INV_OFFSET)
#define IPC8_BASE           (0xBF881110)
#define IPC8                *(volatile uint32_t *)(IPC8_BASE)        //Interrupt Priority Control Register
#define IPC8SET             *(volatile uint32_t *)(IPC8_BASE + SET_OFFSET)
#define IPC8CLR             *(volatile uint32_t *)(IPC8_BASE + CLR_OFFSET)
#define IPC8INV             *(volatile uint32_t *)(IPC8_BASE + INV_OFFSET)
#define IPC9_BASE           (0xBF881120)
#define IPC9                *(volatile uint32_t *)(IPC9_BASE)        //Interrupt Priority Control Register
#define IPC9SET             *(volatile uint32_t *)(IPC9_BASE + SET_OFFSET)
#define IPC9CLR             *(volatile uint32_t *)(IPC9_BASE + CLR_OFFSET)
#define IPC9INV             *(volatile uint32_t *)(IPC9_BASE + INV_OFFSET)
#define IPC11_BASE          (0xBF881140)
#define IPC11               *(volatile uint32_t *)(IPC11_BASE)        //Interrupt Priority Control Register
#define IPC11SET            *(volatile uint32_t *)(IPC11_BASE + SET_OFFSET)
#define IPC11CLR            *(volatile uint32_t *)(IPC11_BASE + CLR_OFFSET)
#define IPC11INV            *(volatile uint32_t *)(IPC11_BASE + INV_OFFSET)


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/****************************************************
 *GPIO Port Addresses
 ****************************************************/  
   
//Port A    
#define TRISA_BASE      (0xBF886000)
#define TRISA           *(volatile uint32_t *)TRISA_BASE      //Tri-State Function register -- If data bit is a '1', corresponding I/O port pin is an input, If data bit is a '0', corresponding I/O port pin is an output
#define TRISASET       *(volatile uint32_t *)(TRISA_BASE + SET_OFFSET)
#define TRISACLR       *(volatile uint32_t *)(TRISA_BASE + CLR_OFFSET)
#define TRISAINV       *(volatile uint32_t *)(TRISA_BASE + INV_OFFSET)
#define PORTA_BASE      (0xBF886010)
#define PORTA           *(volatile uint32_t *)PORTA_BASE      //Port register -- Allows I/O pins to be accessed.
#define PORTASET       *(volatile uint32_t *)(PORTA_BASE + SET_OFFSET)
#define PORTACLR       *(volatile uint32_t *)(PORTA_BASE + CLR_OFFSET)
#define PORTAINV       *(volatile uint32_t *)(PORTA_BASE + INV_OFFSET)
#define LATA_BASE       (0xBF886020)
#define LATA            *(volatile uint32_t *)LATA_BASE       //Latch register -- Holds data written to I/O port.
#define LATASET        *(volatile uint32_t *)(LATA_BASE + SET_OFFSET)
#define LATACLR        *(volatile uint32_t *)(LATA_BASE + CLR_OFFSET)
#define LATAINV        *(volatile uint32_t *)(LATA_BASE + INV_OFFSET)
#define ODCA_BASE       (0xBF886030)
#define ODCA            *(volatile uint32_t *)ODCA_BASE       //Open-Drain Configuration register -- If ODCx bit is a '1' the I/O pin acts as an open-drain output.
#define ODCASET        *(volatile uint32_t *)(ODCA_BASE + SET_OFFSET)
#define ODCACLR        *(volatile uint32_t *)(ODCA_BASE + CLR_OFFSET)
#define ODCAINV        *(volatile uint32_t *)(ODCA_BASE + INV_OFFSET)
    
/* On-board BTN Bits */
#define BTN1            6
#define BTN2            7
#define BTN_MASK        0x000000C0
    
    
//Port B    
#define TRISB_BASE      (0xBF886040)
#define TRISB           *(volatile uint32_t *)TRISB_BASE      //Tri-State Function register -- If data bit is a '1', corresponding I/O port pin is an input, If data bit is a '0', corresponding I/O port pin is an output
#define TRISBSET       *(volatile uint32_t *)(TRISB_BASE + SET_OFFSET)
#define TRISBCLR       *(volatile uint32_t *)(TRISB_BASE + CLR_OFFSET)
#define TRISBINV       *(volatile uint32_t *)(TRISB_BASE + INV_OFFSET)
#define PORTB_BASE      (0xBF886050)
#define PORTB           *(volatile uint32_t *)PORTB_BASE      //Port register -- Allows I/O pins to be accessed.
#define PORTBSET       *(volatile uint32_t *)(PORTB_BASE + SET_OFFSET)
#define PORTBCLR       *(volatile uint32_t *)(PORTB_BASE + CLR_OFFSET)
#define PORTBINV       *(volatile uint32_t *)(PORTB_BASE + INV_OFFSET)
#define LATB_BASE       (0xBF886060)
#define LATB            *(volatile uint32_t *)LATB_BASE       //Latch register -- Holds data written to I/O port.
#define LATBSET        *(volatile uint32_t *)(LATB_BASE + SET_OFFSET)
#define LATBCLR        *(volatile uint32_t *)(LATB_BASE + CLR_OFFSET)
#define LATBINV        *(volatile uint32_t *)(LATB_BASE + INV_OFFSET)
#define ODCB_BASE       (0xBF886070)
#define ODCB            *(volatile uint32_t *)ODCB_BASE       //Open-Drain Configuration register -- If ODCx bit is a '1' the I/O pin acts as an open-drain output.
#define ODCBSET        *(volatile uint32_t *)(ODCB_BASE + SET_OFFSET)
#define ODCBCLR        *(volatile uint32_t *)(ODCB_BASE + CLR_OFFSET)
#define ODCBINV        *(volatile uint32_t *)(ODCB_BASE + INV_OFFSET)
    
/* On-board LED Bits */
#define LED1            10
#define LED2            11
#define LED3            12
#define LED4            13
#define LED_MASK        0x00003C00 
#define LED_ON(x)      (LATBSET = (1 << x))
#define LED_OFF(x)     (LATBCLR = (1 << x))
 
    
//Port C
#define TRISC_BASE      (0xBF886080)
#define TRISC           *(volatile uint32_t *)TRISC_BASE      //Tri-State Function register -- If data bit is a '1', corresponding I/O port pin is an input, If data bit is a '0', corresponding I/O port pin is an output
#define TRISCSET       *(volatile uint32_t *)(TRISC_BASE + SET_OFFSET)
#define TRISCCLR       *(volatile uint32_t *)(TRISC_BASE + CLR_OFFSET)
#define TRISCINV       *(volatile uint32_t *)(TRISC_BASE + INV_OFFSET)
#define PORTC_BASE      (0xBF886090)
#define PORTC           *(volatile uint32_t *)PORTC_BASE      //Port register -- Allows I/O pins to be accessed.
#define PORTCSET       *(volatile uint32_t *)(PORTC_BASE + SET_OFFSET)
#define PORTCCLR       *(volatile uint32_t *)(PORTC_BASE + CLR_OFFSET)
#define PORTCINV       *(volatile uint32_t *)(PORTC_BASE + INV_OFFSET)
#define LATC_BASE       (0xBF8860A0)
#define LATC            *(volatile uint32_t *)LATC_BASE       //Latch register -- Holds data written to I/O port.
#define LATCSET        *(volatile uint32_t *)(LATC_BASE + SET_OFFSET)
#define LATCCLR        *(volatile uint32_t *)(LATC_BASE + CLR_OFFSET)
#define LATCINV        *(volatile uint32_t *)(LATC_BASE + INV_OFFSET)
#define ODCC_BASE       (0xBF8860B0)
#define ODCC            *(volatile uint32_t *)ODCC_BASE       //Open-Drain Configuration register -- If ODCx bit is a '1' the I/O pin acts as an open-drain output.
#define ODCCSET        *(volatile uint32_t *)(ODCC_BASE + SET_OFFSET)
#define ODCCCLR        *(volatile uint32_t *)(ODCC_BASE + CLR_OFFSET)
#define ODCCINV        *(volatile uint32_t *)(ODCC_BASE + INV_OFFSET)

    
    
//Port D    
#define TRISD_BASE      (0xBF8860C0)
#define TRISD           *(volatile uint32_t *)TRISD_BASE      //Tri-State Function register -- If data bit is a '1', corresponding I/O port pin is an input, If data bit is a '0', corresponding I/O port pin is an output
#define TRISDSET       *(volatile uint32_t *)(TRISD_BASE + SET_OFFSET)
#define TRISDCLR       *(volatile uint32_t *)(TRISD_BASE + CLR_OFFSET)
#define TRISDINV       *(volatile uint32_t *)(TRISD_BASE + INV_OFFSET)
#define PORTD_BASE      (0xBF8860D0)
#define PORTD           *(volatile uint32_t *)PORTD_BASE      //Port register -- Allows I/O pins to be accessed.
#define PORTDSET       *(volatile uint32_t *)(PORTD_BASE + SET_OFFSET)
#define PORTDCLR       *(volatile uint32_t *)(PORTD_BASE + CLR_OFFSET)
#define PORTDINV       *(volatile uint32_t *)(PORTD_BASE + INV_OFFSET)
#define LATD_BASE       (0xBF8860E0)
#define LATD            *(volatile uint32_t *)LATD_BASE       //Latch register -- Holds data written to I/O port.
#define LATDSET        *(volatile uint32_t *)(LATD_BASE + SET_OFFSET)
#define LATDCLR        *(volatile uint32_t *)(LATD_BASE + CLR_OFFSET)
#define LATDINV        *(volatile uint32_t *)(LATD_BASE + INV_OFFSET)
#define ODCD_BASE       (0xBF8860F0)
#define ODCD            *(volatile uint32_t *)ODCD_BASE       //Open-Drain Configuration register -- If ODCx bit is a '1' the I/O pin acts as an open-drain output.
#define ODCDSET        *(volatile uint32_t *)(ODCD_BASE + SET_OFFSET)
#define ODCDCLR        *(volatile uint32_t *)(ODCD_BASE + CLR_OFFSET)
#define ODCDINV        *(volatile uint32_t *)(ODCD_BASE + INV_OFFSET)

    
    
//Port E    
#define TRISE_BASE      (0xBF886100)
#define TRISE           *(volatile uint32_t *)TRISE_BASE      //Tri-State Function register -- If data bit is a '1', corresponding I/O port pin is an input, If data bit is a '0', corresponding I/O port pin is an output
#define TRISESET       *(volatile uint32_t *)(TRISE_BASE + SET_OFFSET)
#define TRISECLR       *(volatile uint32_t *)(TRISE_BASE + CLR_OFFSET)
#define TRISEINV       *(volatile uint32_t *)(TRISE_BASE + INV_OFFSET)
#define PORTE_BASE      (0xBF886110)
#define PORTE           *(volatile uint32_t *)PORTE_BASE      //Port register -- Allows I/O pins to be accessed.
#define PORTESET       *(volatile uint32_t *)(PORTE_BASE + SET_OFFSET)
#define PORTECLR       *(volatile uint32_t *)(PORTE_BASE + CLR_OFFSET)
#define PORTEINV       *(volatile uint32_t *)(PORTE_BASE + INV_OFFSET)
#define LATE_BASE       (0xBF886120)
#define LATE            *(volatile uint32_t *)LATE_BASE       //Latch register -- Holds data written to I/O port.
#define LATESET        *(volatile uint32_t *)(LATE_BASE + SET_OFFSET)
#define LATECLR        *(volatile uint32_t *)(LATE_BASE + CLR_OFFSET)
#define LATEINV        *(volatile uint32_t *)(LATE_BASE + INV_OFFSET)
#define ODCE_BASE       (0xBF886130)
#define ODCE            *(volatile uint32_t *)ODCE_BASE       //Open-Drain Configuration register -- If ODCx bit is a '1' the I/O pin acts as an open-drain output.
#define ODCESET        *(volatile uint32_t *)(ODCE_BASE + SET_OFFSET)
#define ODCECLR        *(volatile uint32_t *)(ODCE_BASE + CLR_OFFSET)
#define ODCEINV        *(volatile uint32_t *)(ODCE_BASE + INV_OFFSET)
  
    
    
//Port F    
#define TRISF_BASE      (0xBF886140)
#define TRISF           *(volatile uint32_t *)TRISF_BASE      //Tri-State Function register -- If data bit is a '1', corresponding I/O port pin is an input, If data bit is a '0', corresponding I/O port pin is an output
#define TRISFSET       *(volatile uint32_t *)(TRISF_BASE + SET_OFFSET)
#define TRISFCLR       *(volatile uint32_t *)(TRISF_BASE + CLR_OFFSET)
#define TRISFINV       *(volatile uint32_t *)(TRISF_BASE + INV_OFFSET)
#define PORTF_BASE      (0xBF886150)
#define PORTF           *(volatile uint32_t *)PORTF_BASE      //Port register -- Allows I/O pins to be accessed.
#define PORTFSET       *(volatile uint32_t *)(PORTF_BASE + SET_OFFSET)
#define PORTFCLR       *(volatile uint32_t *)(PORTF_BASE + CLR_OFFSET)
#define PORTFINV       *(volatile uint32_t *)(PORTF_BASE + INV_OFFSET)
#define LATF_BASE       (0xBF886160)
#define LATF            *(volatile uint32_t *)LATF_BASE       //Latch register -- Holds data written to I/O port.
#define LATFSET        *(volatile uint32_t *)(LATF_BASE + SET_OFFSET)
#define LATFCLR        *(volatile uint32_t *)(LATF_BASE + CLR_OFFSET)
#define LATFINV        *(volatile uint32_t *)(LATF_BASE + INV_OFFSET)
#define ODCF_BASE       (0xBF886170)
#define ODCF            *(volatile uint32_t *)ODCF_BASE       //Open-Drain Configuration register -- If ODCx bit is a '1' the I/O pin acts as an open-drain output.
#define ODCFSET        *(volatile uint32_t *)(ODCF_BASE + SET_OFFSET)
#define ODCFCLR        *(volatile uint32_t *)(ODCF_BASE + CLR_OFFSET)
#define ODCFINV        *(volatile uint32_t *)(ODCF_BASE + INV_OFFSET)
    
    
    
//Port G    
#define TRISG_BASE      (0xBF886180)
#define TRISG           *(volatile uint32_t *)TRISG_BASE      //Tri-State Function register -- If data bit is a '1', corresponding I/O port pin is an input, If data bit is a '0', corresponding I/O port pin is an output
#define TRISGSET       *(volatile uint32_t *)(TRISG_BASE + SET_OFFSET)
#define TRISGCLR       *(volatile uint32_t *)(TRISG_BASE + CLR_OFFSET)
#define TRISGINV       *(volatile uint32_t *)(TRISG_BASE + INV_OFFSET)
#define PORTG_BASE      (0xBF886190)
#define PORTG           *(volatile uint32_t *)PORTG_BASE      //Port register -- Allows I/O pins to be accessed.
#define PORTGSET       *(volatile uint32_t *)(PORTG_BASE + SET_OFFSET)
#define PORTGCLR       *(volatile uint32_t *)(PORTG_BASE + CLR_OFFSET)
#define PORTGINV       *(volatile uint32_t *)(PORTG_BASE + INV_OFFSET)
#define LATG_BASE       (0xBF8861A0)
#define LATG            *(volatile uint32_t *)LATG_BASE       //Latch register -- Holds data written to I/O port.
#define LATGSET        *(volatile uint32_t *)(LATG_BASE + SET_OFFSET)
#define LATGCLR        *(volatile uint32_t *)(LATG_BASE + CLR_OFFSET)
#define LATGINV        *(volatile uint32_t *)(LATG_BASE + INV_OFFSET)
#define ODCG_BASE       (0xBF8861B0)
#define ODCG            *(volatile uint32_t *)ODCG_BASE       //Open-Drain Configuration register -- If ODCx bit is a '1' the I/O pin acts as an open-drain output.
#define ODCGSET        *(volatile uint32_t *)(ODCG_BASE + SET_OFFSET)
#define ODCGCLR        *(volatile uint32_t *)(ODCG_BASE + CLR_OFFSET)
#define ODCGINV        *(volatile uint32_t *)(ODCG_BASE + INV_OFFSET)




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/****************************************************
 *I2C Register Config
 ****************************************************/  
//I2C1
#define I2C1CON_BASE    (0xBF805000)
#define I2C1CON         *(volatile uint32_t *)I2C1CON_BASE          //Control Register -- Enables operational control of the I2C module.
#define I2C1CONSET     *(volatile uint32_t *)(I2C1CON_BASE + SET_OFFSET)
#define I2C1CONCLR     *(volatile uint32_t *)(I2C1CON_BASE + CLR_OFFSET)
#define I2C1CONINV     *(volatile uint32_t *)(I2C1CON_BASE + INV_OFFSET)
#define I2C1STAT_BASE   (0xBF805010)
#define I2C1STAT        *(volatile uint32_t *)I2C1STAT_BASE         //Status Register -- Contains status flags indicating the state of the I2C module during operation
#define I2C1STATSET    *(volatile uint32_t *)(I2C1STAT_BASE + SET_OFFSET)
#define I2C1STATCLR    *(volatile uint32_t *)(I2C1STAT_BASE + CLR_OFFSET)
#define I2C1STATINV    *(volatile uint32_t *)(I2C1STAT_BASE + INV_OFFSET)    
#define I2C1ADD_BASE    (0xBF805020)
#define I2C1ADD         *(volatile uint32_t *)I2C1ADD_BASE         //Slave Address Register -- Holds the slave device address
#define I2C1ADDSET     *(volatile uint32_t *)(I2C1ADD_BASE + SET_OFFSET)
#define I2C1ADDCLR     *(volatile uint32_t *)(I2C1ADD_BASE + CLR_OFFSET)
#define I2C1ADDINV     *(volatile uint32_t *)(I2C1ADD_BASE + INV_OFFSET) 
#define I2C1MSK_BASE    (0xBF805030)
#define I2C1MSK         *(volatile uint32_t *)I2C1MSK_BASE         //Address Mask Register -- Designates the bit  positions in the I2CxADD register that can be ignored, which allows for multiple address support
#define I2C1MSKSET     *(volatile uint32_t *)(I2C1MSK_BASE + SET_OFFSET)
#define I2C1MSKCLR     *(volatile uint32_t *)(I2C1MSK_BASE + CLR_OFFSET)
#define I2C1MSKINV     *(volatile uint32_t *)(I2C1MSK_BASE + INV_OFFSET)
#define I2C1BRG_BASE    (0xBF805040)
#define I2C1BRG         *(volatile uint32_t *)I2C1BRG_BASE         //Baud Rate Generator Register -- Holds the Baud Rate Generator (BRG) reload value for the I2C module BRG
#define I2C1BRGSET     *(volatile uint32_t *)(I2C1BRG_BASE + SET_OFFSET)
#define I2C1BRGCLR     *(volatile uint32_t *)(I2C1BRG_BASE + CLR_OFFSET)
#define I2C1BRGINV     *(volatile uint32_t *)(I2C1BRG_BASE + INV_OFFSET)
#define I2C1TRN_BASE    (0xBF805050)
#define I2C1TRN         *(volatile uint32_t *)I2C1TRN_BASE         //Transmit Data Register -- This read-only register is the transmit register. Bytes are written to this register during a transmit operation.
#define I2C1TRNSET     *(volatile uint32_t *)(I2C1TRN_BASE + SET_OFFSET)
#define I2C1TRNCLR     *(volatile uint32_t *)(I2C1TRN_BASE + CLR_OFFSET)
#define I2C1TRNINV     *(volatile uint32_t *)(I2C1TRN_BASE + INV_OFFSET)
#define I2C1RCV_BASE    (0xBF805060)    //Note: I THINK the is the correct address. Reference manual lists this address as 5260 but this overlaps with the I2C2 receive register. Pretty sure it's a typo...
#define I2C1RCV         *(volatile uint32_t *)I2C1RCV_BASE         //Receive Data Register -- This read-only register is the buffer register from which data bytes can be read.
#define I2C1RCVSET     *(volatile uint32_t *)(I2C1RCV_BASE + SET_OFFSET)
#define I2C1RCVCLR     *(volatile uint32_t *)(I2C1RCV_BASE + CLR_OFFSET)
#define I2C1RCVINV     *(volatile uint32_t *)(I2C1RCV_BASE + INV_OFFSET)
    

//I2C2
#define I2C2CON_BASE    (0xBF805200)
#define I2C2CON         *(volatile uint32_t *)I2C2CON_BASE          //Control Register -- Enables operational control of the I2C module.
#define I2C2CONSET     *(volatile uint32_t *)(I2C2CON_BASE + SET_OFFSET)
#define I2C2CONCLR     *(volatile uint32_t *)(I2C2CON_BASE + CLR_OFFSET)
#define I2C2CONINV     *(volatile uint32_t *)(I2C2CON_BASE + INV_OFFSET)
#define I2C2STAT_BASE   (0xBF805210)
#define I2C2STAT        *(volatile uint32_t *)I2C2STAT_BASE         //Status Register -- Contains status flags indicating the state of the I2C module during operation
#define I2C2STATSET    *(volatile uint32_t *)(I2C2STAT_BASE + SET_OFFSET)
#define I2C2STATCLR    *(volatile uint32_t *)(I2C2STAT_BASE + CLR_OFFSET)
#define I2C2STATINV    *(volatile uint32_t *)(I2C2STAT_BASE + INV_OFFSET)    
#define I2C2ADD_BASE    (0xBF805220)
#define I2C2ADD         *(volatile uint32_t *)I2C2ADD_BASE         //Slave Address Register -- Holds the slave device address
#define I2C2ADDSET     *(volatile uint32_t *)(I2C2ADD_BASE + SET_OFFSET)
#define I2C2ADDCLR     *(volatile uint32_t *)(I2C2ADD_BASE + CLR_OFFSET)
#define I2C2ADDINV     *(volatile uint32_t *)(I2C2ADD_BASE + INV_OFFSET) 
#define I2C2MSK_BASE    (0xBF805230)
#define I2C2MSK         *(volatile uint32_t *)I2C2MSK_BASE         //Address Mask Register -- Designates the bit  positions in the I2CxADD register that can be ignored, which allows for multiple address support
#define I2C2MSKSET     *(volatile uint32_t *)(I2C2MSK_BASE + SET_OFFSET)
#define I2C2MSKCLR     *(volatile uint32_t *)(I2C2MSK_BASE + CLR_OFFSET)
#define I2C2MSKINV     *(volatile uint32_t *)(I2C2MSK_BASE + INV_OFFSET)
#define I2C2BRG_BASE    (0xBF805240)
#define I2C2BRG         *(volatile uint32_t *)I2C2BRG_BASE         //Baud Rate Generator Register -- Holds the Baud Rate Generator (BRG) reload value for the I2C module BRG
#define I2C2BRGSET     *(volatile uint32_t *)(I2C2BRG_BASE + SET_OFFSET)
#define I2C2BRGCLR     *(volatile uint32_t *)(I2C2BRG_BASE + CLR_OFFSET)
#define I2C2BRGINV     *(volatile uint32_t *)(I2C2BRG_BASE + INV_OFFSET)
#define I2C2TRN_BASE    (0xBF805250)
#define I2C2TRN         *(volatile uint32_t *)I2C2TRN_BASE         //Transmit Data Register -- This read-only register is the transmit register. Bytes are written to this register during a transmit operation.
#define I2C2TRNSET     *(volatile uint32_t *)(I2C2TRN_BASE + SET_OFFSET)
#define I2C2TRNCLR     *(volatile uint32_t *)(I2C2TRN_BASE + CLR_OFFSET)
#define I2C2TRNINV     *(volatile uint32_t *)(I2C2TRN_BASE + INV_OFFSET)
#define I2C2RCV_BASE    (0xBF805260)    //Note: I THINK the is the correct address. Reference manual lists this address as 5260 but this overlaps with the I2C2 receive register. Pretty sure it's a typo...
#define I2C2RCV         *(volatile uint32_t *)I2C2RCV_BASE         //Receive Data Register -- This read-only register is the buffer register from which data bytes can be read.
#define I2C2RCVSET     *(volatile uint32_t *)(I2C2RCV_BASE + SET_OFFSET)
#define I2C2RCVCLR     *(volatile uint32_t *)(I2C2RCV_BASE + CLR_OFFSET)
#define I2C2RCVINV     *(volatile uint32_t *)(I2C2RCV_BASE + INV_OFFSET)


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/****************************************************
 *SPI - Peripheral base addresses
 ****************************************************/
// Peripheral SPI1 base address
#define SPI1_BASE		(0xBF805800u)
// Peripheral SPI1 base pointer
#define SPI1			((SPI_Type *)SPI1_BASE)
// Peripheral SPI2 base address
#define SPI2_BASE		(0xBF805A00u)
// Peripheral SPI2 base pointer
#define SPI2			((SPI_Type *)SPI2_BASE)


/* SPI Register Masks */
//SPIxCON Bit Field
#define SPIxCON_FRMEN_MASK				0x80000000;		//Framed SPI Support -- 1 = enable, 0 = disable
#define SPIxCON_FRMSYNC_MASK			0x40000000;		//Frame Sync Pulse Direction Control (Framed SPI mode only) -- 1 = slave mode, 0 = master mode
#define SPIxCON_FRMPOL_MASK				0x20000000;		//Frame Sync Polarity bit (Framed SPI mode only) -- 1 = frame pulse is active-high, 0 = frame pulse is active low
#define SPIxCON_SPIFE_MASK				0x00020000;		//Frame Sync Pulse Edge Select -- 1 = frame synchronization pulse coincides with the first bit clock, 0 = frame synchronization pulse precedes the first bit clock
#define SPIxCON_ON_MASK					0x00008000;		//SPI Peripheral ON -- 1 = SPI peripheral is enabled, 0 = SPI peripheral is disabled
#define SPIxCON_SIDL_MASK				0x00002000;		//Stop in Idle Mode -- 1 = discontinue operation when CPU enters idle mode, 0 = continue operation in idle mode
#define SPIxCON_DISSDO_MASK				0x00001000;		//Disable SDOx Pin -- 1 = SDOx pin is not used by the module, 0 = SDOx pin is controlled by the module
#define SPIxCON_MODE_MASK				0x00000C00;		//32/16-bit Communication Select -- 10/11 = 32-bit communication, 01 = 16-bit communication, 00 = 8-bit communication
#define SPIxCON_SMP_MASK				0x00000200;		//SPI Data Input Sample Phase (Master mode only: MSTEN = 1) -- 1 = input data sampled at end of data output time, 0 = input data sampled at middle of data output time
#define SPIxCON_CKE_MASK				0x00000100;		//SPI Clock Edge Select -- 1 = Serial output data changes on transition from active clock state to idle clock state, 0 = Serial output data changes on transition from idle clock state to active clock state
#define SPIxCON_SSEN_MASK				0x00000080;		//Slave Select Enable (Slave mode) -- 1 = !SSx pin used for slave mode, 0 = !SSx pin not used for Slave mode, pin controlled by port function
#define SPIxCON_CKP_MASK				0x00000040;		//Clock Polarity Select -- 1 = idle state for clock is a high level; active state is a low level, 0 = idle state for clock is a low level; active state is a high level
#define SPIxCON_MSTEN_MASK				0x00000020;		//Master Mode Enable -- 1 = master mode, 0 = mlave mode
//SPIxSTAT Bit Field
#define SPIxSTAT_SPIBUSY_MASK			0x00000800;		//SPI Activity Status -- 1 = SPI peripheral is currently busy with some transactions, 0 = SPI peripheral is currently idle
#define SPIxSTAT_SPIROV_MASK			0x00000040;		//Receive Overflow Flag -- 1 = a new data is completely received and discarded (the user software has not read the previous data in the SPIxBUF register), 0 = no overflow has occurred
#define SPIxSTAT_SPITBE_MASK			0x00000008;		//SPI Transmit Buffer Empty Status -- 1 = transmit buffer SPIxTXB is empty, 0 = transmit buffer SPIxTXB is not empty
#define SPIxSTAT_SPIRBF_MASK			0x00000001;		//SPI Receive Buffer Full Status -- 1 = receive buffer SPIxRXB is full, 0 = receive buffer SPIxRXB is not full
//SPIxBRG Bit Field
#define SPIxBRG_BRG_MASK				0x000001FF;		//Baud Rate Divisor bits


//SPI - Register Layout
typedef struct {
	uint32_t CON;
	uint32_t STAT;
	uint32_t BUF;
	uint32_t BRG;
} SPI_Type;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/****************************************************
 *Timer base addresses
 ****************************************************/
//Timer 1
#define T1CON_BASE			(0xBF800600)
#define T1CON 				*(volatile uint32_t *)(T1CON_BASE)
#define T1CONSET			*(volatile uint32_t *)(T1CON_BASE + SET_OFFSET)
#define T1CONCLR			*(volatile uint32_t *)(T1CON_BASE + CLR_OFFSET)
#define T1CONINV			*(volatile uint32_t *)(T1CON_BASE + INV_OFFSET)
#define TMR1_BASE			(0xBF800610)
#define TMR1 				*(volatile uint32_t *)(TMR1_BASE)
#define TMR1SET				*(volatile uint32_t *)(TMR1_BASE + SET_OFFSET)
#define TMR1CLR				*(volatile uint32_t *)(TMR1_BASE + CLR_OFFSET)
#define TMR1INV				*(volatile uint32_t *)(TMR1_BASE + INV_OFFSET)
#define PR1_BASE			(0xBF800620)
#define PR1 				*(volatile uint32_t *)(PR1_BASE)
#define PR1SET				*(volatile uint32_t *)(PR1_BASE + SET_OFFSET)
#define PR1CLR				*(volatile uint32_t *)(PR1_BASE + CLR_OFFSET)
#define PR1INV				*(volatile uint32_t *)(PR1_BASE + INV_OFFSET)

//Timer 2
#define T2CON_BASE			(0xBF800800)
#define T2CON 				*(volatile uint32_t *)(T2CON_BASE)
#define T2CONSET			*(volatile uint32_t *)(T2CON_BASE + SET_OFFSET)
#define T2CONCLR			*(volatile uint32_t *)(T2CON_BASE + CLR_OFFSET)
#define T2CONINV			*(volatile uint32_t *)(T2CON_BASE + INV_OFFSET)
#define TMR2_BASE			(0xBF800810)
#define TMR2 				*(volatile uint32_t *)(TMR2_BASE)
#define TMR2SET				*(volatile uint32_t *)(TMR2_BASE + SET_OFFSET)
#define TMR2CLR				*(volatile uint32_t *)(TMR2_BASE + CLR_OFFSET)
#define TMR2INV				*(volatile uint32_t *)(TMR2_BASE + INV_OFFSET)
#define PR2_BASE			(0xBF800820)
#define PR2 				*(volatile uint32_t *)(PR2_BASE)
#define PR2SET				*(volatile uint32_t *)(PR2_BASE + SET_OFFSET)
#define PR2CLR				*(volatile uint32_t *)(PR2_BASE + CLR_OFFSET)
#define PR2INV				*(volatile uint32_t *)(PR2_BASE + INV_OFFSET)


//Timer 3
#define T3CON_BASE			(0xBF800A00)
#define T3CON 				*(volatile uint32_t *)(T3CON_BASE)
#define T3CONSET			*(volatile uint32_t *)(T3CON_BASE + SET_OFFSET)
#define T3CONCLR			*(volatile uint32_t *)(T3CON_BASE + CLR_OFFSET)
#define T3CONINV			*(volatile uint32_t *)(T3CON_BASE + INV_OFFSET)
#define TMR3_BASE			(0xBF800A10)
#define TMR3 				*(volatile uint32_t *)(TMR3_BASE)
#define TMR3SET				*(volatile uint32_t *)(TMR3_BASE + SET_OFFSET)
#define TMR3CLR				*(volatile uint32_t *)(TMR3_BASE + CLR_OFFSET)
#define TMR3INV				*(volatile uint32_t *)(TMR3_BASE + INV_OFFSET)
#define PR3_BASE			(0xBF800A20)
#define PR3 				*(volatile uint32_t *)(PR3_BASE)
#define PR3SET				*(volatile uint32_t *)(PR3_BASE + SET_OFFSET)
#define PR3CLR				*(volatile uint32_t *)(PR3_BASE + CLR_OFFSET)
#define PR3INV				*(volatile uint32_t *)(PR3_BASE + INV_OFFSET)


//Timer 4
#define T4CON_BASE			(0xBF800C00)
#define T4CON 				*(volatile uint32_t *)(T4CON_BASE)
#define T4CONSET			*(volatile uint32_t *)(T4CON_BASE + SET_OFFSET)
#define T4CONCLR			*(volatile uint32_t *)(T4CON_BASE + CLR_OFFSET)
#define T4CONINV			*(volatile uint32_t *)(T4CON_BASE + INV_OFFSET)
#define TMR4_BASE			(0xBF800C10)
#define TMR4 				*(volatile uint32_t *)(TMR4_BASE)
#define TMR4SET				*(volatile uint32_t *)(TMR4_BASE + SET_OFFSET)
#define TMR4CLR				*(volatile uint32_t *)(TMR4_BASE + CLR_OFFSET)
#define TMR4INV				*(volatile uint32_t *)(TMR4_BASE + INV_OFFSET)
#define PR4_BASE			(0xBF800C20)
#define PR4 				*(volatile uint32_t *)(PR4_BASE)
#define PR4SET				*(volatile uint32_t *)(PR4_BASE + SET_OFFSET)
#define PR4CLR				*(volatile uint32_t *)(PR4_BASE + CLR_OFFSET)
#define PR4INV				*(volatile uint32_t *)(PR4_BASE + INV_OFFSET)


//Timer 5
#define T5CON_BASE			(0xBF800E00)
#define T5CON 				*(volatile uint32_t *)(T5CON_BASE)
#define T5CONSET			*(volatile uint32_t *)(T5CON_BASE + SET_OFFSET)
#define T5CONCLR			*(volatile uint32_t *)(T5CON_BASE + CLR_OFFSET)
#define T5CONINV			*(volatile uint32_t *)(T5CON_BASE + INV_OFFSET)
#define TMR5_BASE			(0xBF800E10)
#define TMR5 				*(volatile uint32_t *)(TMR5_BASE)
#define TMR5SET				*(volatile uint32_t *)(TMR5_BASE + SET_OFFSET)
#define TMR5CLR				*(volatile uint32_t *)(TMR5_BASE + CLR_OFFSET)
#define TMR5INV				*(volatile uint32_t *)(TMR5_BASE + INV_OFFSET)
#define PR5_BASE			(0xBF800E20)
#define PR5 				*(volatile uint32_t *)(PR5_BASE)
#define PR5SET				*(volatile uint32_t *)(PR5_BASE + SET_OFFSET)
#define PR5CLR				*(volatile uint32_t *)(PR5_BASE + CLR_OFFSET)
#define PR5INV				*(volatile uint32_t *)(PR5_BASE + INV_OFFSET)

#define TMR_START           0x00008000
#define TMR5INIT            0x0
#define TMR5INTFLAG         20


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/****************************************************
 *UART base addresses
 ****************************************************/
//UART1
#define U1MODE_BASE         (0xBF086000)
#define U1MODE              *(volatile uint32_t *)(U1MODE_BASE)
#define U1MODESET           *(volatile uint32_t *)(U1MODE_BASE + SET_OFFSET)
#define U1MODECLR			*(volatile uint32_t *)(U1MODE_BASE + CLR_OFFSET)
#define U1MODEINV			*(volatile uint32_t *)(U1MODE_BASE + INV_OFFSET)
#define U1STA_BASE          (0xBF086010)
#define U1STA               *(volatile uint32_t *)(U1STA_BASE)
#define U1STASET            *(volatile uint32_t *)(U1STA_BASE + SET_OFFSET)
#define U1STACLR			*(volatile uint32_t *)(U1STA_BASE + CLR_OFFSET)
#define U1STAINV			*(volatile uint32_t *)(U1STA_BASE + INV_OFFSET)
#define U1TXREG_BASE        (0xBF086020)
#define U1TXREG             *(volatile uint32_t *)(U1TXREG_BASE)
#define U1TXREGSET          *(volatile uint32_t *)(U1TXREG_BASE + SET_OFFSET)
#define U1TXREGCLR			*(volatile uint32_t *)(U1TXREG_BASE + CLR_OFFSET)
#define U1TXREGINV			*(volatile uint32_t *)(U1TXREG_BASE + INV_OFFSET)
#define U1RXREG_BASE        (0xBF086030)
#define U1RXREG             *(volatile uint32_t *)(U1RXREG_BASE)
#define U1RXREGSET          *(volatile uint32_t *)(U1RXREG_BASE + SET_OFFSET)
#define U1RXREGCLR			*(volatile uint32_t *)(U1RXREG_BASE + CLR_OFFSET)
#define U1RXREGINV			*(volatile uint32_t *)(U1RXREG_BASE + INV_OFFSET)
#define U1BRG_BASE          (0xBF086040)
#define U1BRG               *(volatile uint32_t *)(U1BRG_BASE)
#define U1BRGSET            *(volatile uint32_t *)(U1BRG_BASE + SET_OFFSET)
#define U1BRGCLR			*(volatile uint32_t *)(U1BRG_BASE + CLR_OFFSET)
#define U1BRGINV			*(volatile uint32_t *)(U1BRG_BASE + INV_OFFSET)

//UART2
#define U2MODE_BASE         (0xBF086200)
#define U2MODE              *(volatile uint32_t *)(U2MODE_BASE)
#define U2MODESET           *(volatile uint32_t *)(U2MODE_BASE + SET_OFFSET)
#define U2MODECLR			*(volatile uint32_t *)(U2MODE_BASE + CLR_OFFSET)
#define U2MODEINV			*(volatile uint32_t *)(U2MODE_BASE + INV_OFFSET)
#define U2STA_BASE          (0xBF086210)
#define U2STA               *(volatile uint32_t *)(U2STA_BASE)
#define U2STASET            *(volatile uint32_t *)(U2STA_BASE + SET_OFFSET)
#define U2STACLR			*(volatile uint32_t *)(U2STA_BASE + CLR_OFFSET)
#define U2STAINV			*(volatile uint32_t *)(U2STA_BASE + INV_OFFSET)
#define U2TXREG_BASE        (0xBF086220)
#define U2TXREG             *(volatile uint32_t *)(U2TXREG_BASE)
#define U2TXREGSET          *(volatile uint32_t *)(U2TXREG_BASE + SET_OFFSET)
#define U2TXREGCLR			*(volatile uint32_t *)(U2TXREG_BASE + CLR_OFFSET)
#define U2TXREGINV			*(volatile uint32_t *)(U2TXREG_BASE + INV_OFFSET)
#define U2RXREG_BASE        (0xBF086230)
#define U2RXREG             *(volatile uint32_t *)(U2RXREG_BASE)
#define U2RXREGSET          *(volatile uint32_t *)(U2RXREG_BASE + SET_OFFSET)
#define U2RXREGCLR			*(volatile uint32_t *)(U2RXREG_BASE + CLR_OFFSET)
#define U2RXREGINV			*(volatile uint32_t *)(U2RXREG_BASE + INV_OFFSET)
#define U2BRG_BASE          (0xBF086240)
#define U2BRG               *(volatile uint32_t *)(U2BRG_BASE)
#define U2BRGSET            *(volatile uint32_t *)(U2BRG_BASE + SET_OFFSET)
#define U2BRGCLR			*(volatile uint32_t *)(U2BRG_BASE + CLR_OFFSET)
#define U2BRGINV			*(volatile uint32_t *)(U2BRG_BASE + INV_OFFSET)


#define U1RXINT             27
#define U1TXINT             28
#define U1RXINT             41
#define U1TXINT             42



#endif /* SYSCONFIG_H_ */
