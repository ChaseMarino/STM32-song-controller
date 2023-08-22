/*
 * tone.c
 *
 *  Created on: May 14, 2022
 *      Author: bruce
 */


#include "tone.h"
#include "demo.h"
#include "printf.h"
#define TICK_SPEED (100000) // Recommended SysTick speed, adjust if using something different.
#define MAX_TONES (1)

static float notes[] = {
/* Octave -1 */			   8.18,    8.66,    9.18,    9.73,   10.30,   10.92,   11.56,   12.25,   12.98,   13.75,   14.57,   13.44,
/* Octave  0 */           16.35,   17.32,   18.35,   19.45,   20.60,   21.83,   23.12,   24.50,   25.96,   27.50,   29.14,   30.87,
/* Octave  1 use */  	      32.70,   34.65,   36.71,   38.89,   41.20,   43.65,   46.25,   49.00,   51.91,   55.00,   58.27,   61.74,
/* Octave  2 use*/			  65.41,   69.30,   73.42,   77.78,   82.41,   87.31,   92.50,   98.00,  103.83,  110.00,  116.54,  123.47,
/* Octave  3 */			 130.81,  138.59,  146.83,  155.56,  164.81,  174.61,  185.00,  196.00,  207.65,  220.00,  233.08,  246.94,
/* Octave  4 */			 261.63,  277.18,  293.66,  311.13,  329.63,  349.23,  369.99,  392.00,  415.30,  440.00,  466.16,  493.88,
/* Octave  5 */          523.25,  554.37,  587.33,  622.25,  659.25,  698.46,  739.99,  783.99,  830.61,  880.00,  932.33,  987.77,
/* Octave  6 */         1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22, 1760.00, 1864.66, 1975.53,
/* Octave  7 */         2093.00, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44, 3520.00, 3729.31, 3951.07,
/* Octave  8 */         4186.01, 4434.92, 4698.63, 4978.03, 5274.04, 5587.65, 5919.91, 6271.93, 6644.88, 7040.00, 7458.62, 7902.13,
/* Octave  9 */         8372.02, 8869.84, 9397.26, 9956.06,10548.08,11175.30,11839.82,12543.86};

typedef struct {
	uint16_t duration;
	uint16_t power;
} tone_info;




static tone_info tones[MAX_TONES] = {{0, 0}};
int note_c = 0;

//finds where event track begins, takes in song and length, returns index
int find_mtrk(unsigned char* song, int length){
	for (int i = 0; i < length; i++){
			if (i + 4 < length){
				if (song[i] == 0x4d && song[i + 1] == 0x54 && song[i + 2] == 0x72 && song[i + 3] == 0x6b){
					return i+3;
				}
		}
	}
	return 0;
}

int play = 0;

//pause handler
void cut_music(){
	play = 0;
}

//pause handler
void play_music(){
	play = 1;
}

/**
 * INPUT
 * song char ar and length
 * output
 * none
 */
void parse_song_t(unsigned char* song, int length){

	int event_index = find_mtrk(song, length);
	while (event_index < length){
		if (play == 0){
			break;
		}
		if (song[event_index] == 0x90){ //find on event
			add_tone(song[event_index + 1], song[event_index + 2]); //add note and power to tones
			int j = 0;
			while (j < 200000){
					j++;
					play_tones ();
			}
		}

		else if (song[event_index] == 0x74){ //find off event
			if (second_elapsed()){
				remove_tone (song[event_index + 1]); //remove notes from tones
			}
			else{
				int i = 0;
				while (i < 10000){
					i++;
					play_tones ();
				}
				remove_tone (song[event_index + 1]);
			}
		}
		event_index ++;
		play_tones (); //play tone
	}

}


// Convert from hertz to ticks
uint16_t hertz_to_duration (float hertz) {
	if (hertz == 0)
		return 0;
	float duration = 1 / hertz;
	return (uint16_t) (duration * TICK_SPEED);
}

//uint32_t counter = 0;
uint32_t duration = 0;
// Accessor for the counter
uint32_t get_counter () {
	return 2;
}

// Add a tone to the tones array
uint8_t add_tone (int note, uint8_t velocity) {
	//mainprintf("\n\r npte" + note);

	duration = hertz_to_duration(notes[note]);
//mainprintf("duration " + duration);
	tones[note_c].duration = duration;

	tones[note_c].power = velocity * 40;

	return 1;
}

// Remove a tone from the tones array
uint8_t remove_tone (uint8_t note) {
	tones[note_c].duration = 0;
	tones[note_c].power = 0;
	return 1;
}


//plays current tone in note array
void play_tones () {

	if ((get_millis() % tones[note_c].duration) < (tones[note_c].duration >> 1)){
		DAC_Set_Value (tones[note_c].power);
   	}
	else{
		DAC_Set_Value (0);
	}

}

