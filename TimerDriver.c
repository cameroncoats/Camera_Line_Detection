// Cameron Coats / Group 3
// EN0627 / NXP Car
// 
// Hardware Timer Driver

#include "MKL25Z4.h"
#include "TimerDriver.h"

void Timer0_DelayuS(float time)
{
  float t;	
	TPM0->SC = 0; // diable timer when configuring
	
	//Figure out how many clocks we need for for the delay time
	t=time*(float)(FRQ_MCGFLLCLK)/1000000.0; //MOD value for delay
	
	TPM0->MOD = (unsigned int) t;
	TPM0->SC|=0x80; // clear TOF
	TPM0->SC|=0x08; // enable timer free-rnning mode
	while((TPM0->SC & 0x80) == 0) { } // wait until the TOF is set
	TPM0->SC = 0; // diable timer when configuring
}

void Timer0_DelaymS(float time)
{
  float t;	
	TPM0->SC = 0; // diable timer when configuring
	
	//Figure out how many clocks we need for for the delay time
	t=time*(float)(FRQ_MCGFLLCLK)/1000.0; //MOD value for delay
	
	TPM0->MOD = (unsigned int) t;
	TPM0->SC|=0x80; // clear TOF
	TPM0->SC|=0x08; // enable timer free-rnning mode
	while((TPM0->SC & 0x80) == 0) { } // wait until the TOF is set
	TPM0->SC = 0; // diable timer when configuring
}