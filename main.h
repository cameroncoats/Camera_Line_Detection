// Cameron Coats / Group 3
// EN0627 / NXP Car
// 
// Main
#include <stdbool.h>
#ifndef Main
  #define Main

	extern signed short getLineOffset(void);
	extern short int getExposureScore(void);
	extern void initCameraDriver(void);
	extern void initPIT(void);
	extern void initServo(void);
	extern void initMotors(void);
	extern void initTimer0(void);
	extern void setLEDs(unsigned char);
	
	extern void enableMotors(void);
	extern void disableMotors(void);
	
	extern void setTorqueVectors(int);
	extern void setSteeringAngle(int);
	extern void setCenter(void);
	
	extern void Timer0_DelaymS(int);
	int main(void);

	typedef enum {INIT, WAIT_PRESS, CAMERA_FAULT, START, STOP, RUN, WAIT_RUN} MainState;

	extern bool cameraFault;
	bool doAutoExposure = false;
	extern bool autoexposureDone;
	short signed int linePos;
	
	extern int bestExposureTime;
	extern unsigned int bestScore;
	extern unsigned short int POT0_Value, POT1_Value, BATT_Value;
	extern short int maxValue,minValue;
	short int linePos;
	short int score;
	bool runMainLoop = false;
#endif
