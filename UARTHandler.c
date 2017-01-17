// Cameron Coats / Group 3
// EN0627 / NXP Car
// 
// UART Handler

#include "UARTHandler.h"
#include "MKL25Z4.h"


void initialiseUART0(void){
	
	// Enable UART 0 Clock
  SIM->SCGC4 |= UART0_ClockMask;
	
	// Set Clock Source
  SIM->SOPT2 |= BaudGenClockSource_MCGFLL;
	
	// Disable UART before configuring
  UART0->C2 = Disable_TxRx;
	
	// Set baud rate
  UART0->BDH = Baudrate_115200H;
  UART0->BDL = Baudrate_115200L; 
	
	// Configure UART
  UART0->C1 = Config_8N1;
  UART0->C3 = Config_NFI;
	UART0->C4 = Oversampling_16x;
	
	// Enable UART once configured
	UART0->C2 = Enable_TxRx;
	
	// Configure Pins
  SIM->SCGC5 |= ClockGating_PortA;   /* enable clock for PORTA */
  PORTA->PCR[2] = PinMux_UART; /* make PTA2 UART0_Tx pin */
	PORTA->PCR[1] = PinMux_UART; /* make PTA1 UART0_Rx pin */
}

void sendString(char* string){
	// Start at char 0
  unsigned short int charPosition = 0;
	
	while(string[charPosition]){
		// Block until Tx vuffer is empty
		while(!(UART0->S1 & 0x80)) {} 
		// Add char to buffer
		UART0->D = string[charPosition];
		// Move to next char
		charPosition++;
	}
}
