
/*
 * happybirthday.h
 *
 * Created: 11/09/2022 22:26:34
 *  Author: lidia
 */ 

#include <asf.h>
#include "notes.h"

#ifndef HAPPYBIRTHDAY_H_
#define HAPPYBIRTHDAY_H_

int melody_happybirthday[] = {

	// Happy Birthday
	// Score available at https://musescore.com/user/8221/scores/26906

	NOTE_C4,4, NOTE_C4,8,
	NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4,
	NOTE_E4,-2, NOTE_C4,4, NOTE_C4,8,
	NOTE_D4,-4, NOTE_C4,-4, NOTE_G4,-4,
	NOTE_F4,-2, NOTE_C4,4, NOTE_C4,8,

	NOTE_C5,-4, NOTE_A4,-4, NOTE_F4,-4,
	NOTE_E4,-4, NOTE_D4,-4, NOTE_AS4,4, NOTE_AS4,8,
	NOTE_A4,-4, NOTE_F4,-4, NOTE_G4,-4,
	NOTE_F4,-2,
	
};

#endif /* HAPPYBIRTHDAY_H_ */