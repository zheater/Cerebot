#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SysConfig.h"
#include "Util.h"


/* TODOs:
 * FIX SPI STUFF - according to the pinout I have to rewire the chip... SCK1 is mapped to VCCEN, no the data channel
 * //Note TODO: fix up macros... don't need a shift and a mask value
//Note TODO: Update all functions to camel case
 *
 */

int main(void) {   
  
    initAll();
    
    for(;;) {
    #if PASSIVE_LED        
    passiveLED();        
    #endif
        usMeasure(&usCenter);
        
        if(usCenter.dist < 10) {
            pwm_ds_adjust(&mtrLeft,usCenter.dist * 10);
            pwm_ds_adjust(&mtrRight,usCenter.dist * 10);
        }
    }
    
    return 0;
}