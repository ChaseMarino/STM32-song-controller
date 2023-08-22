#include <stdio.h>
#include <string.h>
#include "printf.h"
#include "inputHandler.h"
#include "commands.h"

//Takes user input as param, calls appropriate handler or invalid statement
void command_handler(char* input){

	if(strcmp(input, "HELP") == 0) help_handler();

	else if(strcmp(input, "PLAY") == 0){
		mainprintf("\n\rPLAY called\n\r");
		play_handler();
	}
	else if(strcmp(input, "NEXT") == 0) {
		mainprintf("\n\rNEXT called\n\r");
		next_handler();
	}
	else if(strcmp(input, "PAUSE") == 0) {
		mainprintf("\n\rPAUSE called\n\r");
		pause_handler();
	}
	else if(strcmp(input, "STOP") == 0) {
		mainprintf("\n\rSTOP called\n\r");
		stop_handler();
	}
	else {
		mainprintf("\n\rInvalid Command, try running help to see list of available commands.\n\r");
	}
}
