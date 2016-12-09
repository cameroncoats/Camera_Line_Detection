// Cameron Coats / Group 3
// EN0627 / NXP Car
// 
// Hardware Timer Driver

#ifndef TimerDriver
  #define TimerDriver
  
	#define FRQ_MCGFLLCLK 20971520
	#define ClockGating_Timer0 0x01<<24
	#define ClockSource_MCGFLL 0x01<<24
	#define TOF_Mask 0xBF
	
	void initialiseTimer0(void);
	void Timer0_DelayuS(int);
	void Timer0_DelaymS(int);
	
#endif

