/*
 * inputHandler.h
 *
 */

#ifndef INC_SONGPARSER_H_
#define INC_SONGPARSER_H_

void parseHeader(unsigned char* song);
void parse_meta_events(unsigned char* song, int length);
void parse_song(unsigned char* song, int length);


#endif /* INC_SONGPARSER_H_ */
