// Cameron Coats / Group 3
// EN0627 NXP Car
//
// Main (Centerline detection only)

#include "MKL25Z4.h"
#include "stdio.h"
#include "main.h"
#include "TFCHandler.h"
#include "UARTHandler.h"

// set initial state
MainState State = INIT;

int main(void){
  while(1) {
    switch(State) {
      case INIT:
      // Enable ports etc
      initPorts();
      // Setup UART
      initialiseUART0();
      // Setup Camera
      initCameraDriver();
      // setup PIT
      PITInit();
      // Send power on message
      sendString("Hello\n>");
      // Go to wait state
      State = WAIT_PRESS;
      break;
      case WAIT_PRESS:
      // Wait for pushbutton A
      if((GPIOC_PDIR & 1<<13) != 0) {
        // Do line detection
        State = DO_LINESCAN;
      }
      break;
      case DO_LINESCAN:
      // Get line position (CameraHandler.c)
      linePos = getLineOffset();
      // Format into string
      sprintf(stringBuffer,"Line Offset: %d \nPot 0: %d\nPot 1: %d\nBatt: %d\n",linePos,POT0_Value,POT1_Value,BATT_Value);
      // Send string over UART
      sendString(stringBuffer);
      // Return to wait state
      State = WAIT_RELEASE;
      break;
      case WAIT_RELEASE:
      if((GPIOC_PDIR & 1<<13) == 0) {
        State = WAIT_PRESS;
      }
      break;
      default:
      State = WAIT_PRESS;
      break;
    }
  }
}
