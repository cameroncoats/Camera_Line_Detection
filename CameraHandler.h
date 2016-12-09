// Cameron Coats / Group 3
// EN0627 / NXP Car
//
// Linescan Camera Handler (High Level)
#include <stdbool.h>
#ifndef CameraHandler
  #define CameraHandler


int getLineOffset(void);
extern void startImageCapture(void);
extern void LED_SetOut(unsigned int);
extern void Timer0_DelaymS(int);
extern unsigned short int image[2][256];
extern unsigned char safeBuffer;

bool CalcInProgress = false;
#endif
