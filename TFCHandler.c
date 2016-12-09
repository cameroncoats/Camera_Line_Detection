// Cameron Coats / Group 3
// EN0627 / NXP Car
//
// TFC Shield Handler

#include "MKL25Z4.h"

void initPorts(void){
  // enable clock to PORTA,B, C, D, E
  SIM->SCGC5 |= ((1U<<9)|(1U<<10)|(1U<<11)|(1U<<12)|(1U<<11));

  PORTC->PCR[13]=(1U << 8); // SW1, PTC13, digital IO
  PORTC->PCR[17]=(1U << 8); // SW2, PTC17, digital IO
  PORTC->ISFR &= (1U << 13);
  PORTC->ISFR &= (1U << 17);
  GPIOC->PDDR &=  (0U << 13);
  GPIOC->PDDR &=  (0U << 17);

}
