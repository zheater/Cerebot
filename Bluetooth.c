#include "Bluetooth.h"

void bt_init(Bluetooth *bt)
{
    bt->name = MYBTNAME;
    bt->address = MYBTADDR
            
            
    //Enable UART1
    uart1_enable();
    //Disable bluetooth reset (RST, active low)
    LATESET = (1 << RST_PTE);
    
    
    return;
}
