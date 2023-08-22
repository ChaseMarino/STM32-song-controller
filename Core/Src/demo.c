/*
 * demo.c
 *
 *  Created on: Feb 14, 2021
 *      Author: larry kiser
 *  Updated on: Sept 6, 2021
 *      Author: Mitesh Parikh
 */

#include <stdio.h>
#include <string.h>

// Custom Include files
#include "systick.h"
#include "LED.h"
#include "inputHandler.h"
#include "printf.h"
#include "adc_demo.h"
#include "tone.h"

#define TIMEOUT (799) //1 ms
systick_t* sys = (systick_t*)0xE000E010;
static volatile uint8_t one_second_elapsed;


// This function is to Initialize SysTick registers
static void init_systick()
{
	sys->SYST_CSR = 0;
	sys->SYST_RVR = TIMEOUT;
	sys->SYST_CSR |= 1 << 2;
	sys->SYST_CSR |= 1 << 1;
	sys->SYST_CSR |= 1;
}

uint32_t millis = 0;

int get_millis(){
	return millis;
}

//counter
static uint32_t counter = 0;

//systick
void SysTick_Handler() {
	counter++;
	millis++;
	if(counter == 100000) { //90000
		one_second_elapsed = 1;
		counter = 0;
	}
}


//second elapsed getter
int second_elapsed(){
	return one_second_elapsed;
}

//reset second
void reset_second(){
	one_second_elapsed = 0;
}


//init systick call project handler
void run_demo(){
	init_systick() ;
	inputLoop();
}

