// main.c with demo
// Updated and refactored Larry Kiser copyright 2021


// include project specific header files
#include "SysClock.h"
#include "LED.h"
#include "UART.h"
#include "demo.h"
#include "GPIO.h"
#include "dac.h"

int main(void){

	// initialization code
	System_Clock_Init(); // set System Clock = 80 MHz
	LED_Init();
	UART2_Init();
	GPIO_Init();
	DAC_Init ();
	DAC_Start ();

	// application run function
	run_demo() ;
}

