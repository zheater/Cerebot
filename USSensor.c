#include "USSensor.h"

void usSensorInit(void)
{
	//Assign sensor IDs
	usLeft.id = USLEFTID;
	usCenter.id = USCENTERID;
	usRight.id = USRIGHTID;
	
	//Assign sensor port pins
	usLeft.pin = USLEFTPIN;
	usCenter.pin = USCENTERPIN;
	usRight.pin = USRIGHTPIN;
	
	//Initialize distance
	usLeft.dist = 0;
	usCenter.dist = 0;
	usRight.dist = 0;
	
	//Clear error bits
	usLeft.err = FALSE;
	usCenter.err = FALSE;
	usRight.err = FALSE;
	
	return;
}

void usTrigger(usSensor * sensorPtr)
{
	usSensor * pt = sensorPtr;
	
	TRISGCLR = (1 << pt->pin);
    LATGSET = (1 << pt->pin);
    usDelay();
    LATGCLR = (1 << pt->pin);
	return;
}

void usMeasure(usSensor * sensorPtr)
{
	usSensor * pt = sensorPtr;
	uint16_t tmrValue;
	uint8_t i = 0;
    uint8_t j = 0;
	
	usTrigger(pt);
	TRISGSET = (1 << pt->pin);
		
	while(!readSensorPin(pt)) {
		if(i >= MAXMEASTIME) {
			pt->dist = 0;
			pt->err = TRUE;	//Set error bit
            LED_ON(LED1);
            LED_OFF(LED2);
            LED_OFF(LED3);
            LED_OFF(LED4);
			return;
		}
		i++;
	}
	j=i;
	//TODO: Start a timer
	
	i = 0;	//Reset i
	while(readSensorPin(pt)) {
		if(i >= MAXMEASTIME) {
			pt->dist = 0;
			pt->err = TRUE;	//Set error bit
            
            LED_ON(LED1);
            LED_ON(LED2);
            LED_OFF(LED3);
            LED_OFF(LED4);
			return;
		}
		i++;
	}
	
	//TODO: Stop timer and write its value into tmrValue
	
    tmrValue = i;
	//Apply calibration
	pt->dist = CAL_MULTERM * tmrValue + CAL_ADDTERM;
	pt->err = FALSE;	//Successful measurement: Clear error bit
    LED_ON(LED1);
    LED_ON(LED2);
    LED_ON(LED3);
    LED_OFF(LED4);
	return;
}

void usDelay(void)
{
	int i;
    
    for(i = 0;i < USDELAY;i++) {
        __asm__("NOP");
    }
    
    return;
}

bool readSensorPin(usSensor * sensorPtr)
{   
    return ((PORTG & (1 << sensorPtr->pin)) >> sensorPtr->pin);
}