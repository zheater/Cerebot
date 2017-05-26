/* 
 * File:   Bluetooth.h
 * Author: Wiggleby
 *
 * Created on May 19, 2017, 12:36 PM
 */

#ifndef BLUETOOTH_H
#define	BLUETOOTH_H

#include "SysConfig.h"
#include "IOConfig.h"

typedef struct {
    char* name;
    char* address;
} Bluetooth;

Bluetooth bt;

#define MYBTNAME            "Cerebot"
#define MYBTADDR            "xx:xx:xx:xx:xx:xx"

void bt_init(Bluetooth *bt);


#endif	/* BLUETOOTH_H */

