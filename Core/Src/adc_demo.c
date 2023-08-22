/*
 * adc_example.c
 *
 *  Created on: Apr 13, 2022
 *      Author: bruce
 */

#include "adc.h"
#include "dac.h"
#include "printf.h"
#include "adc_demo.h"
#include "demo.h"

uint8_t one_second_elapsed = FALSE;

void Error_Handler () {
	// Add error handler here if desired
}

void run_adc_demo()
{
	uint16_t counter = 0;
	mainprintf ("Start!\n\r");
	DAC_Init ();
	ADC_Init ();

	DAC_Start ();

	while (1)
	{

		//ADC_Start (); //broken
		//mainprintf ("test");
		if (second_elapsed() /*&& (old_adc_value != new_adc_value)*/) {
			//HAL_GPIO_WritePin(GPIOA, (uint16_t)0x0001, GPIO_PIN_SET);
			DAC_Set_Value (2000); //put in play tones

			//adc_value = ADC_Read_Value_Blocking ();
			//mainprintf ("ADC read: 0x%x\n\r", (unsigned int)adc_value);



			counter++;
			reset_second();
		}

	}
}

