// Cameron Coats / Group 3
// EN0627 / NXP Car
//
// Main
#include <stdbool.h>
#ifndef Main
  #define Main

  extern signed short getLineOffset(void);
  extern void initCameraDriver(void);
  extern void PITInit(void);
  int main(void);

  typedef enum {INIT, WAIT_PRESS,WAIT_RELEASE, DO_LINESCAN} MainState;


  short signed int linePos;
  char stringBuffer[100];

  extern unsigned short int POT0_Value, POT1_Value, BATT_Value;

#endif
