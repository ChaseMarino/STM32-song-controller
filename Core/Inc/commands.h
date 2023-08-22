/***
 *
 * commands.h
 *
 */
#ifndef SRC_COMMANDS_H_
#define SRC_COMMANDS_H_

void play_handler();
void help_handler();
void pause_handler();
void stop_handler();
void next_handler();
int get_flag();
int get_local();
void toggle_local();
void local_run();
void local_command();
void button_play();
//void led_toggle();

#endif /* SRC_COMMANDS_H_ */
