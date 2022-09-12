
/*
 * asabranca.h
 *
 * Created: 11/09/2022 19:14:09
 *  Author: lidia
 */ 
#include <asf.h>
#include "notes.h"

#ifndef ASABRANCA_H_
#define ASABRANCA_H_


const int melody_asa_branca[] = {

	// Asa branca - Luiz Gonzaga
	// Score available at https://musescore.com/user/190926/scores/181370

	NOTE_G4,8, NOTE_A4,8, NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_B4,4,
	NOTE_C5,4, NOTE_C5,2, NOTE_G4,8, NOTE_A4,8,
	NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_C5,4,

	NOTE_B4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
	NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8,
	NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,

	NOTE_A4,4, NOTE_B4,4, REST,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
	NOTE_G4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
	NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8,

	NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,
	NOTE_A4,4, NOTE_B4,4, REST,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
	NOTE_G4,4, NOTE_F5,8, NOTE_D5,8, NOTE_E5,8, NOTE_C5,8, NOTE_D5,8, NOTE_B4,8,

	NOTE_C5,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,8, NOTE_G4,8,
	NOTE_G4,4, NOTE_F5,8, NOTE_D5,8, NOTE_E5,8, NOTE_C5,8, NOTE_D5,8, NOTE_B4,8,
	NOTE_C5,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,8, NOTE_G4,8,
	NOTE_G4,-2, REST,4
	
};
#endif /* ASABRANCA_H_ */