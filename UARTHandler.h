// Cameron Coats / Group 3
// EN0627 / NXP Car
// 
// UART Handler

#ifndef UARTHandler
  #define UARTHandler
	
	
	#define UART0_ClockMask 0x400
	#define BaudGenClockSource_MCGFLL 0x04000000
	#define Baudrate_115200H 0x0
	#define Baudrate_115200L 0x17
	#define Disable_TxRx 0
	#define Enable_TxRx 0x0C
	#define Oversampling_16x 0x0F
	#define Config_8N1 0x00
	#define Config_NFI 0x00
	#define ClockGating_PortA 0x0200
	#define PinMux_UART 0x0200
	
  void initialiseUART0(void);

  void sendString(char* string);
#endif
