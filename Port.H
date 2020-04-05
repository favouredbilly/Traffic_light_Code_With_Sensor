/*-------------------------------------------------------------*-
Port.H
--------------------------------------------------------
Header file for porth definitions
-*-------------------------------------------------------------*/
#ifndef _PORT_H
#define _PORT_H
#include <reg52.h>


//PORTS FOR MAIN ROAD

sbit Red		= P2^0;
sbit Green 		= P2^1;
sbit Amber 		= P2^2;

//PORTS FOR SIDE ROAD

sbit Red1 = P2^5;
sbit Amber2 = P2^6; 
sbit Green3 = P2^7; 

//Switch to indicate car sensor on lane 2

sbit car_sensor = P3^1;
#endif
/*-------------------------------------------------------------*-
---- END OF FILE ---------------------------------------
-*-------------------------------------------------------------*/