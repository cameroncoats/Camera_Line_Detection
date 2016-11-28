#include <stdbool.h>

#ifndef CameraDriver
  #define CameraDriver
	
  // Definitions
	#define ADC_POT0 0
	#define ADC_POT1 1
	#define ADC_BAT  2
	#define PinMux_GPIO 0x100
	#define PinMux_ADC 0
	#define ClockGating_PortD 0x1<<12
	#define ClockGating_PortE 0x1<<13
	#define ClockGating_ADC0 0x08000000
	#define SingleEnded 0x00
  #define Differential (0x01<<5)
  #define EnableInterrupts (0x01<<6)
  #define SoftTriggerMask ~0x40
	#define ClockDiv_4 0x1<<6 
	#define SampleTme_Long 0x1<<4 
	#define SingleEndedBusClk 0x1<<2
	#define ADC0Mux_BSide (0x1<<4)
	
	
	// Macros
	#define SI_H PTD->PSOR=(0x01<<7);
  #define SI_L PTD->PCOR=(0x01<<7); 

  #define Clk_H PTE->PSOR=(0x01<<1);
  #define Clk_L PTE->PCOR=(0x01<<1); 
	
	// Functions
	void initialiseCamera(void);
	void intialiseCameraIRQ(void);
	
	// Define states
  typedef enum {IDLE,POT0,POT1,BATT,LINESCAN} CameraST;
	
	// This will hold pot values & battery voltage
  unsigned short int AnalogValues[3];
  // The current pixel (0-128)
  unsigned short int PixelCounter = 0;

  bool CaptureDone = false;

  int image[128];
	
#endif