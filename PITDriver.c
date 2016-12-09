// Cameron Coats / Group 3
// EN0627 / NXP Car
//
// Periodic Interrupt Timer Driver
#include "MKL25Z4.h"
#include "PITDriver.h"
extern void startImageCapture(void);

extern unsigned short int POT0_Value;

void PITInit(){


  // Disable all interrupts before configuring
  __disable_irq();

  // Disable IRQ 22 (PIT)
  NVIC->ICER[0] = 1 << 22;

  // Enable PIT Clock
  SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;

  // Turn on PIT
  PIT_MCR = 0x00;

  // Set start value
  // this is POT 0 * 244, at a maximum value of 4096 and timer interval of 10ns this is 0-100ms
  PIT_LDVAL0 = 800000;

  // Enable clock & freeze timer when debugging
  PIT_MCR = PIT_MCR_FRZ_MASK;

  // Enable interrupt & Start timer
  PIT_TCTRL0 = PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK;

  // Enable IRQ 22 (PIT) once configured
  NVIC->ISER[0] |= 1u<<22;

  // Enable all interrupts
  __enable_irq();

}


void PIT_IRQHandler(){
  // Disable PIT
  PIT_TCTRL0 = 0;
  // Clear timer overflow interrupt
  PIT_TFLG0 |= PIT_TFLG_TIF_MASK;

  startImageCapture();

  // Start timer again
  PIT_TCTRL0 |= PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK;
}
