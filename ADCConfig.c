#include "ADCConfig.h"


void adc_init(void)
{
    AD1CON1 = _AD1CON1;
    AD1CON2 = _AD1CON2;
    AD1CON3 = _AD1CON3;
    AD1CHS = _AD1CHS;
    AD1PCFG = _AD1PCFG;
    AD1CSSL = _AD1CSSL;
    
    
    //Enable ADC
    AD1CON1SET = (1 << ADCON);
    
    return;
}