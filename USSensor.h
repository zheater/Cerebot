#include "SysConfig.h"


typedef struct {
	uint8_t id;
	uint8_t dist;
	uint8_t pin;
	bool err;
} usSensor;

usSensor usLeft;
usSensor usRight;
usSensor usCenter;

#define CAL_MULTERM			1//0.0055
#define CAL_ADDTERM			0//0.4091
#define USLEFTID			0
#define USCENTERID			1
#define USRIGHTID			2
#define USLEFTPIN			7
#define USCENTERPIN			8
#define USRIGHTPIN			9
#define MAXMEASTIME			0xFF
#define USDELAY				1000


void usSensorInit(void);
void usTrigger(usSensor * sensorPtr);
void usMeasure(usSensor * sensorPtr);
void usDelay(void);
bool readSensorPin(usSensor * sensorPtr);