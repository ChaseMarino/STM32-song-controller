/***
 * Handles user commands
 */

#include "LED.h"

#include "printf.h"

#include "songParser.h"
#include "Song.h"
#include "demo.h"
#include "tone.h"
int flag = 0;
int led = 0;
int song_c = 0;
int local = 0;
int local_c = 0;

int s1_flag = 0;

int press_flag = 0;
int press_start = 0;
int curr = 0;

//'plays' song by turning on led
void play_handler() {
  play_music();
  flag = 0;
  LED_On();
  parse_song_t(songs[song_c].p_song, songs[song_c].size);

}
//broken code hack since playing music from button doesnt work
void button_play(){
	flag = 0;
	LED_On();
}

//'pause' song by turning on flash flag
void pause_handler() {
  cut_music();

  flag = 1;
}

//'stops' song by turning off led
void stop_handler() {
  flag = 0;
  LED_Off();
}

//'next' song by calling song parser
//keeps track of song count, and sends appropriate song to parser
void next_handler() {
  flag = 0;

  if (song_c++ > 4) {
    song_c = 0;
  }
  parse_song(songs[song_c].p_song, songs[song_c].size);

  mainprintf("Song %d info \n\r", song_c);

}

//get flash flag
int get_flag() {
  return flag;
}

//get flash flag
int get_local() {
  return local;
}

/**
 * performs the on start, prints help commands to user.
 */
void help_handler() {
  mainprintf("\n\r***REMOTE LED CONTROL MENU***\n\r");
  mainprintf("Available User Commands\n\r");
  mainprintf("NEXT – Show next song info\n\r");
  mainprintf("PLAY – Play the song (LED on)\n\r");
  mainprintf("PAUSE – Pause the song (LED flash)\n\r");
  mainprintf("STOP – Stop the song (LED off)\n\r");
}

//handle blue button click
void toggle_local() {
  local = 1 - local;
  if (local == 0) {
    help_handler();
    stop_handler();
  } else {
	stop_handler();
    mainprintf("\n\r***LOCAL LED CONTROL***\n\r");
  }
}

//handle s1 button click
void local_command() {
  if (local == 1) {

    curr = get_millis();

    if (press_flag == 0) {
      // ignore bounce
      if (curr - press_start > 15000) { //ignore bounce, see what command was
        press_start = curr;
        press_flag++;

        //see if pause or play
        if (local_c == 0) {
          button_play();

          mainprintf("play\n\r");

        } else if (local_c == 1) {
          pause_handler();
          mainprintf("pause\n\r");
        }
        local_c = 1 - local_c;

      }
    }

    else {
      if (curr - press_start > 15000) { //ignore bounce, see what command was
        if (curr - press_start < 100000) {//if multiple click with one second than next command
          next_handler();
          mainprintf("next\n\r");
          press_flag = 0;
        } else {
          if (local_c == 0) {
        	mainprintf("play\n\r");
        	button_play();


          } else if (local_c == 1) {
        	mainprintf("pause\n\r");
            pause_handler();
          }
          press_flag = 1;
          local_c = 1 - local_c;
        }
        press_start = curr;
      }
    }
  }
}
