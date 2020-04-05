/*------------------------------------------------------------------*-
T_lights.C
------------------------------------------------------------------
Traffic light control program
-*------------------------------------------------------------------*/
#include "Main.H"
#include "Port.H"
#include "Traffic_Lights.H"
// ------ Private constants ----------------------------------------
// Easy to change logic here
#define ON 0
#define OFF 1
// Times in each of the (four) possible light states
// (Times are in seconds)
#define RED_DURATION 30
#define RED_AND_AMBER_DURATION 10
#define GREEN_DURATION 50
#define AMBER_DURATION 10
// ------ Private variables ----------------------------------------
// The state of the system
static State_st STATE;
// The time in that state
static tLong Time_in_state;
// Used by sEOS
static tByte Call_count_G = 0;


// ------ Main Road Lane ----------------------------------------
// This is the main road with High priority
 void MainRoad(unsigned char x, unsigned char y, unsigned char z){

	Red = x; 
Amber = y; 
Green = z; 

}

// ------ Second Road Lane ----------------------------------------
// This is the second road with lower priority
void SecondRoad(unsigned char a, unsigned char b, unsigned char c){

 Red1 = a; 
 Amber2 = b; 
 Green3 = c; 

}

/*------------------------------------------------------------------*-
TRAFFIC_LIGHTS_Init()
-*------------------------------------------------------------------*/
void TRAFFIC_LIGHTS_Init(const State_st START_STATE)
{
//making Port 3 input Port
P3 = 0xFF;
STATE = START_STATE; // Decide on initial state
}
/*------------------------------------------------------------------*-
TRAFFIC_LIGHTS_Update()
Must be called once per second. Priority given to Main Road
-*------------------------------------------------------------------*/

void TRAFFIC_LIGHTS_Update(void)
{
TF2 = 0;
switch (STATE)
{
case RED:
{
	
		MainRoad(0,1,1);
		SecondRoad(1,1,0);

if (++Time_in_state == RED_DURATION)
{
STATE = RED_AND_AMBER;
Time_in_state = 0;
}
break;
}

case RED_AND_AMBER:
{
	
	MainRoad(0,0,1);
	SecondRoad(1,0,0);

if (++Time_in_state == RED_AND_AMBER_DURATION)
{
STATE = GREEN;
Time_in_state = 0;
}
break;
}
case GREEN:
{
		MainRoad(1,1,0);
		SecondRoad(0,1,1);

if ((++Time_in_state >= GREEN_DURATION)& (car_sensor == ON)) //give priority to side road only if sensor is active and when minimum time duration given to main road is reached.
{
STATE = AMBER;
Time_in_state = 0;
}
break;
}

case AMBER:
{
	MainRoad(1,0,1);
	SecondRoad(1,0,1);

if (++Time_in_state == AMBER_DURATION)
{
STATE = RED;
Time_in_state = 0;
}
break;
}
}
}
/*------------------------------------------------------------------*-
---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

