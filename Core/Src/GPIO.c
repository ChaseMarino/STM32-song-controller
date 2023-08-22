/*
 * gpio.c
 *
 *  Created on: Nov 4, 2021
 *      Author: Mitesh Parikh
 */


/* Includes ------------------------------------------------------------------*/
#include "GPIO.h"
#include <stdbool.h>
#include "stm32l4xx.h"
#include "printf.h"
#include "commands.h"
// External Global Variables that we will need access to


/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
void GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	HAL_GPIO_WritePin(GPIOA, (uint16_t)0x0200, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, (uint16_t)0x2000, GPIO_PIN_RESET);


	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = B1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = S1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(S1_GPIO_Port, &GPIO_InitStruct);


	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

//Callback function for button press
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){


	if (GPIO_Pin == (uint16_t)0x2000){
		toggle_local();
	}

	if (GPIO_Pin == (uint16_t)0x0200){
		local_command();
	}

}

//interrupt handler for blue button
void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(B1_Pin);
}

//interrupt handler for external button
void EXTI9_5_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(S1_Pin);
}
