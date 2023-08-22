/***
 *
 * converter.c
 *
 */

#include <stdio.h>
#include <string.h>

//converts to uint16
uint16_t convert_to_uint16 (uint8_t* p_value) {
	uint8_t first = p_value[0];
	uint8_t second = p_value[1];
	uint16_t val = (second << 8) + first;
	return val;
}
//converts to uint24
uint32_t convert_to_uint24 (unsigned char* ptr) {
    return (uint32_t) ((ptr[0] << 16) + (ptr[1] << 8) + ptr[2]);
}
//converts to uint32
uint32_t convert_to_uint32(uint8_t* p_value) {
	uint8_t first = p_value[0];
	uint8_t second = p_value[1];
	uint8_t third = p_value[2];
	uint8_t fourth = p_value[3];
	uint32_t val = ((fourth << 24)) + third + second + first;
	return val;
}

