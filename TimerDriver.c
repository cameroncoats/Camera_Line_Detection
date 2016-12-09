// Cameron Coats / Group 3
// EN0627 / NXP Car
//
// Hardware Timer Driver

#include "MKL25Z4.h"
#include "TimerDriver.h"


void initialiseTimer0(void){
  // Enable clock
  SIM->SCGC6 |= ClockGating_Timer0;
  // Set clock source
  SIM->SOPT2 |= ClockSource_MCGFLL;
  // Disable timer before configuring
  TPM0->SC = 0;
  // Maximum modulo until otherwise configured
  TPM0->MOD = 0xFFFF;
  // Clear Flag
  TPM0->SC &= TOF_Mask;

  // Enable clock
  SIM->SCGC6 |= ClockGating_Timer0<<1;
}

void Timer0_DelayuS(int time)
{
  int t;
  TPM0->SC = 0; // diable timer when configuring

  //Figure out how many clocks we need for for the delay time
  t=time*20; //MOD value for delay

  TPM0->MOD = (unsigned int) t;
  TPM0->SC|=0x80; // clear TOF
  TPM0->SC|=0x08; // enable timer free-rnning mode
  while((TPM0->SC & 0x80) == 0) { } // wait until the TOF is set
  TPM0->SC = 0; // diable timer when configuring
}

void Timer0_DelaymS(int time)
{
  int t;
  TPM0->SC = 0; // diable timer when configuring

  //Figure out how many clocks we need for for the delay time
  t=time*20971; //MOD value for delay

  TPM0->MOD = (unsigned int) t;
  TPM0->SC|=0x80; // clear TOF
  TPM0->SC|=0x08; // enable timer free-rnning mode
  while((TPM0->SC & 0x80) == 0) { } // wait until the TOF is set
  TPM0->SC = 0; // diable timer when configuring
}
