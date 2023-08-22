#include <string.h>
#include "printf.h"
#include "UART.h"
#include "commands.h"
#include "led.h"
#include "demo.h"
#include "commandHandler.h"
#include "stm32l4xx.h"
#include "GPIO.h"
//Main Project Loop
//Continually read from input, handles backspace/enter, sends buffer off when enter is hit, handles flash if flag set
void inputLoop() {
	help_handler();

	int i = 0;
	char r;
	char inputBuffer[32];
	HAL_GPIO_WritePin(GPIOA, (uint16_t)0x0200, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, (uint16_t)0x2000, GPIO_PIN_RESET);

	memset(inputBuffer, 0, sizeof inputBuffer);
	while (1){

		r = USART_No_block_Read(USART2);
		if(r != '\0' && get_local() == 0) {
			//if enter was pressed, send to command handler
			if(r == '\r') {
				inputBuffer[i] = '\0';

				command_handler(inputBuffer);
				i = 0;
				memset(inputBuffer, 0, sizeof inputBuffer);
			}
			//if backspace, remove char from buffer, update display
			else if (r == 0x08 || r == 0x7F){
				inputBuffer[--i] = '\0';
				mainprintf("\r");
				mainprintf(inputBuffer);
				mainprintf(" ");
				mainprintf("\r");
				mainprintf(inputBuffer);

			}
			else{
				// if normal char, add to buffer and display
				inputBuffer[i++] = r;
				mainprintf("%c", r);
			}
		}

		//check and handle toggle if paused
		if (get_flag()){
			if(second_elapsed()) {
				LED_Toggle();
				reset_second();
			}
		}
	}

}
