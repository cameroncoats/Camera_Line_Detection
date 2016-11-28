// Cameron Coats / Group 3
// EN0627 / NXP Car
// 
// Linescan Camera Driver (Low Level)

#include "MKL25Z4.h"
#include "TimerDriver.h"
#include "CameraDriver.h"
#include <stdbool.h>

// set default state
CameraST CameraState = IDLE;

void intiialiseCamera(void){
		// Enable Port Clock
		SIM->SCGC5 |=(ClockGating_PortD | ClockGating_PortE); 
	
		// D7 -> Cam0 SI
    PORTD->PCR[7] = PinMux_GPIO;
    PTD->PDDR |= (0x1<<7);
	
		// E1 -> Cam0 CLK
    PORTE->PCR[1] = PinMux_GPIO;
    PTE->PDDR |= (0x1<<1);
	
		// C5 -> Cam0 AO
		PORTD->PCR[5] = PinMux_ADC;
	
		// Enable ADC Clock
	  SIM->SCGC6 |= ClockGating_ADC0;
	
		// Disable Interrupts
		ADC0->SC1[0] &= ~EnableInterrupts;
	
		// Single Ended Set Channel 31 (Disable)
	  ADC0->SC1[0] |= SingleEnded | ADC_SC1_ADCH(31);  
		
		// Software Trigger (When channel is set)
		ADC0->SC2 &= SoftTriggerMask;
		
		ADC0->CFG1 =(ClockDiv_4 | SampleTme_Long | SingleEndedBusClk);
		
		// B Side of Input Mux
		ADC0->CFG2 |= ADC0Mux_BSide;
}

void initialiseCameraIRQ(void){
  __disable_irq();    /* disable all IRQs */
	
	NVIC->ICER[0] = 1 << 15; // disable IRQ15 (ADC0) interrupt
	
	initialiseCamera();
  initialiseTimer0();
	
	NVIC->ISER[0] |= 1u<<15;    // enable IRQ15 (bit 15 of ISER[0]) for ADC0 interrupt
		
		
  __enable_irq();             /* global enable IRQs */
	
	CameraState = IDLE;
	
}

void ADC0_IRQHandler(void){

}