// Cameron Coats / Group 3
// EN0627 NXP Car
// 
// Centerline detection

#include "MKL25Z4.h"
#include "stdio.h"
#include "TFCHandler.h"
#include "UARTHandler.h"
#include "CameraHandler.h"


int main(void);

typedef enum {INIT, WAIT_PB, DO_LINESCAN} ST;

ST State = INIT;

short signed int linePos;
char stringBuffer[100];

int main(void){
		switch(State){
			case INIT:
				// Setup UART
				initialiseUART0();
			break;
		  case WAIT_PB:
				// Wait for pushbutton A
				if(PB_A){
					// Do line detection
				  State = DO_LINESCAN;
				}
			break;
			case DO_LINESCAN:
				// Get line position (CameraHandler.c)
				linePos = getLineOffset();
		    // Format into string
			  sprintf(stringBuffer,"Line Offset: %d",linePos);
			  // Send string over UART
			  sendString(stringBuffer);
				// Return to wait state
			  State = WAIT_PB;
			break;
			default:
				State = WAIT_PB;
			break;
		}

}
