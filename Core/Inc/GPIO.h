/*
 * gpio.h
 *
 *  Created on: Nov 4, 2021
 *      Author: Mitesh Parikh
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"

#define S1_Pin GPIO_PIN_9
#define S1_GPIO_Port GPIOA

void GPIO_Init(void);

void EXTI15_10_IRQHandler();
void EXTI9_5_IRQHandler();

#endif /* INC_GPIO_H_ */
