/*
 * printf.c
 *
 */
#include <stdio.h>
#include <stdarg.h>
#include<printf.h>
#include "UART.h"

char buffer[80];

int mainprintf(const char * format, ...){
	char buffer [256];
	    int len = 0;
	    va_list args;
	    va_start (args, format);
	    len = vsprintf (buffer, format, args);
	    perror (buffer);
	    va_end (args);
	    USART_Write (USART2, (uint8_t *)buffer, len);
	    return len;
}

int putchar (int chr) {
    USART_Write (USART2, (uint8_t *)&chr, 1);
    return 0;
}
