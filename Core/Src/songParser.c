/***
 *
 * Song.c
 *
 * Classes for parsing midi file in byte[] format
 */

#include <stdint.h>
#include <printf.h>
#include "converter.h"
#include "songParser.h"

typedef struct {
	unsigned char chunk_type[4];
	uint32_t length;
	uint16_t format;
	uint16_t ntrk;
	uint16_t division;


}HeaderStruct;

void parse_meta_events(unsigned char* song, int length){
	for (int i = 0; i < length; i++){
		if (song[i] == 0xff){
			if (song[i+1] == 0x03){
				mainprintf("SONG TITLE\n\r");
				for (int j = 0; j < song[i+2]; j++){
					mainprintf("%c", song[i+3+j]);
				}
				mainprintf("\n\r");
			}
			else if (song[i+1] == 0x51){
				mainprintf("TEMPO\n\r");
				mainprintf("0x");
				for (int j = 0; j < song[i+2]; j++){
					mainprintf("%x", song[i+3+j]);
				}
				mainprintf("\n\r");
			}
			else if (song[i+1] == 0x02){
				mainprintf("COPYRIGHT\n\r");
				for (int j = 0; j < song[i+2]; j++){
					mainprintf("%c", song[i+3+j]);
				}
				mainprintf("\n\r");
			}
		}

	}
}

//Song parser entry point. Provde song and array length
//Calls handlers
void parse_song(unsigned char* song, int length) {
	//parseHeader(song);
	parse_meta_events(song, length);
}

