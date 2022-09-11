#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "musicas.h"
#include "sysfont.h"

// defini??es das notas
//#define NOTE_B0  31
//#define NOTE_C1  33
//#define NOTE_CS1 35
//#define NOTE_D1  37
//#define NOTE_DS1 39
//#define NOTE_E1  41
//#define NOTE_F1  44
//#define NOTE_FS1 46
//#define NOTE_G1  49
//#define NOTE_GS1 52
//#define NOTE_A1  55
//#define NOTE_AS1 58
//#define NOTE_B1  62
//#define NOTE_C2  65
//#define NOTE_CS2 69
//#define NOTE_D2  73
//#define NOTE_DS2 78
//#define NOTE_E2  82
//#define NOTE_F2  87
//#define NOTE_FS2 93
//#define NOTE_G2  98
//#define NOTE_GS2 104
//#define NOTE_A2  110
//#define NOTE_AS2 117
//#define NOTE_B2  123
//#define NOTE_C3  131
//#define NOTE_CS3 139
//#define NOTE_D3  147
//#define NOTE_DS3 156
//#define NOTE_E3  165
//#define NOTE_F3  175
//#define NOTE_FS3 185
//#define NOTE_G3  196
//#define NOTE_GS3 208
//#define NOTE_A3  220
//#define NOTE_AS3 233
//#define NOTE_B3  247
//#define NOTE_C4  262
//#define NOTE_CS4 277
//#define NOTE_D4  294
//#define NOTE_DS4 311
//#define NOTE_E4  330
//#define NOTE_F4  349
//#define NOTE_FS4 370
//#define NOTE_G4  392
//#define NOTE_GS4 415
//#define NOTE_A4  440
//#define NOTE_AS4 466
//#define NOTE_B4  494
//#define NOTE_C5  523
//#define NOTE_CS5 554
//#define NOTE_D5  587
//#define NOTE_DS5 622
//#define NOTE_E5  659
//#define NOTE_F5  698
//#define NOTE_FS5 740
//#define NOTE_G5  784
//#define NOTE_GS5 831
//#define NOTE_A5  880
//#define NOTE_AS5 932
//#define NOTE_B5  988
//#define NOTE_C6  1047
//#define NOTE_CS6 1109
//#define NOTE_D6  1175
//#define NOTE_DS6 1245
//#define NOTE_E6  1319
//#define NOTE_F6  1397
//#define NOTE_FS6 1480
//#define NOTE_G6  1568
//#define NOTE_GS6 1661
//#define NOTE_A6  1760
//#define NOTE_AS6 1865
//#define NOTE_B6  1976
//#define NOTE_C7  2093
//#define NOTE_CS7 2217
//#define NOTE_D7  2349
//#define NOTE_DS7 2489
//#define NOTE_E7  2637
//#define NOTE_F7  2794
//#define NOTE_FS7 2960
//#define NOTE_G7  3136
//#define NOTE_GS7 3322
//#define NOTE_A7  3520
//#define NOTE_AS7 3729
//#define NOTE_B7  3951
//#define NOTE_C8  4186
//#define NOTE_CS8 4435
//#define NOTE_D8  4699
//#define NOTE_DS8 4978
//#define REST      0
// fim das notas 

//melody
//int melody_mario[] = {
//
//	// Super Mario Bros theme
//	// Score available at https://musescore.com/user/2123/scores/2145
//	// Theme by Koji Kondo
//	
//	
//	NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
//	NOTE_G5,4, REST,4, NOTE_G4,8, REST,4,
//	NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
//	NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
//	NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
//	REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
//	NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
//	NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
//	NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
//	REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
//
//	
//	REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//7
//	REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
//	REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
//	NOTE_C5,2, REST,2,
//
//	REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//repeats from 7
//	REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
//	REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
//	NOTE_C5,2, REST,2,
//
//	NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,//11
//	NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
//
//	NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,//13
//	REST,1,
//	NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,
//	NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
//	NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
//	NOTE_G5,4, REST,4, NOTE_G4,4, REST,4,
//	NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 19
//	
//	NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
//	NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
//	REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
//
//	NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 19
//	NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
//	NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
//	REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
//
//	NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//23
//	NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
//	NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
//	
//	NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
//	NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
//	NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
//	NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
//	NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
//
//	NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//repeats from 23
//	NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
//	NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
//	
//	NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
//	NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
//	NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
//	NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
//	NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
//	NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,
//	REST,1,
//
//	NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4, //33
//	NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
//	NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
//	NOTE_G5,4, REST,4, NOTE_G4,4, REST,4,
//	NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
//	NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
//	NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
//	
//	NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //40
//	NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
//	NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
//	NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
//	NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
//	
//	//game over sound
//	NOTE_C5,-4, NOTE_G4,-4, NOTE_E4,4, //45
//	NOTE_A4,-8, NOTE_B4,-8, NOTE_A4,-8, NOTE_GS4,-8, NOTE_AS4,-8, NOTE_GS4,-8,
//	NOTE_G4,8, NOTE_D4,8, NOTE_E4,-2,
//
//};
// fim mellody mario
int esta_pausado = 0;
// mellody asa branca
//int melody_asa_branca[] = {
//
//	// Asa branca - Luiz Gonzaga
//	// Score available at https://musescore.com/user/190926/scores/181370
//
//	NOTE_G4,8, NOTE_A4,8, NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_B4,4,
//	NOTE_C5,4, NOTE_C5,2, NOTE_G4,8, NOTE_A4,8,
//	NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_C5,4,
//
//	NOTE_B4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
//	NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8,
//	NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,
//
//	NOTE_A4,4, NOTE_B4,4, REST,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
//	NOTE_G4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
//	NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8,
//
//	NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,
//	NOTE_A4,4, NOTE_B4,4, REST,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
//	NOTE_G4,4, NOTE_F5,8, NOTE_D5,8, NOTE_E5,8, NOTE_C5,8, NOTE_D5,8, NOTE_B4,8,
//
//	NOTE_C5,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,8, NOTE_G4,8,
//	NOTE_G4,4, NOTE_F5,8, NOTE_D5,8, NOTE_E5,8, NOTE_C5,8, NOTE_D5,8, NOTE_B4,8,
//	NOTE_C5,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,8, NOTE_G4,8,
//	NOTE_G4,-2, REST,4
//	
//};

#define BUZZER_PIO				PIOA
#define BUZZER_PIO_ID			ID_PIOA
#define BUZZER_PIO_IDX			21
#define BUZZER_PIO_IDX_MASK     (1 << BUZZER_PIO_IDX)

// Configuracoes do botao
#define START_PIO				PIOD
#define START_PIO_ID			ID_PIOD
#define START_PIO_IDX			28
#define START_PIO_IDX_MASK		(1 << START_PIO_IDX) 

#define SELECAO_PIO				PIOC
#define SELECAO_PIO_ID			ID_PIOC
#define SELECAO_PIO_IDX			31
#define SELECAO_PIO_IDX_MASK	(1 << SELECAO_PIO_IDX)

#define LED_PIO           PIOA                 // periferico que controla o LED
#define LED_PIO_ID        ID_PIOA                    // ID do perif�rico PIOC (controla LED)
#define LED_PIO_IDX       0                    // ID do LED no PIO
#define LED_PIO_IDX_MASK  (1 << LED_PIO_IDX)   // Mascara para CONTROLARMOS o LED

// 
// // change this to make the song slower or faster
// #define tempo 200;
int wholenote = (60000 * 4) / 200; //
int divider = 0, noteDuration = 0;

int aguardando_play_again = 0;
int song_number = 1;

/* flag */
volatile char but_play_flag; //
volatile char but_change_song_flag; //
/************************************************************************/
/* prototypes                                                           */
/************************************************************************/

void init(void);
int get_startstop(void);
void set_buzzer(void);
void clear_buzzer(void);
int get_selecao(void);
void play_song_not_working(int melody[], int tempo);
void play_song_mario(Musica musicas[]);
void play_song_asa_branca(Musica musicas[]);



// fun??es
void but_callback(void)
{
	but_play_flag += 1;  //apertou
}

void but_callback2(void){
	but_change_song_flag += 1;
}


// Fun??o de inicializa??o do uC
void init(void){
	// Initialize the board clock
	sysclk_init();

	// Desativa WatchDog Timer
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	// Ativa o PIO na qual o BUZZER foi conectado
	// para que possamos controlar o BUZZER.
	pmc_enable_periph_clk(BUZZER_PIO_ID);
	
	//Inicializa PA21 como sa?da
	pio_set_output(BUZZER_PIO, BUZZER_PIO_IDX_MASK, 0, 0, 0);
	
	// Inicializa PIO do botao start
	pmc_enable_periph_clk(START_PIO_ID);
	// Configura PIO para lidar com o pino do bot�o como entrada
  // com pull-up
	pio_configure(START_PIO, PIO_INPUT, START_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_set_debounce_filter(START_PIO, START_PIO_IDX_MASK, 60);
	
	 // Configura led
	pmc_enable_periph_clk(LED_PIO_ID);
	pio_configure(LED_PIO, PIO_OUTPUT_0, LED_PIO_IDX_MASK, PIO_DEFAULT);
	
	// Inicializa PIO do botao SELECAO
	pmc_enable_periph_clk(SELECAO_PIO_ID);
	// configura pino ligado ao bot?o start como entrada com um pull-up.
	pio_set_input(SELECAO_PIO, SELECAO_PIO_IDX_MASK, PIO_DEFAULT); //CHECK IT LATER
	pio_pull_up(SELECAO_PIO, SELECAO_PIO_IDX_MASK, 1);
	
	// Configura interrup��o no pino referente ao botao e associa
	// fun��o de callback caso uma interrup��o for gerada
	// a fun��o de callback � a: but_callback()
	pio_handler_set(START_PIO,
					START_PIO_ID,
					START_PIO_IDX_MASK,
					PIO_IT_FALL_EDGE,
					but_callback);
					
	pio_handler_set(SELECAO_PIO,
					SELECAO_PIO_ID,
					SELECAO_PIO_IDX_MASK,
					PIO_IT_FALL_EDGE,
					but_callback2);
	
	// Ativa interrup��o e limpa primeira IRQ gerada na ativacao
	pio_enable_interrupt(START_PIO, START_PIO_IDX_MASK);
	pio_get_interrupt_status(START_PIO);
	pio_enable_interrupt(SELECAO_PIO, SELECAO_PIO_IDX_MASK);
	pio_get_interrupt_status(SELECAO_PIO);
	
	// Configura NVIC para receber interrupcoes do PIO do botao
	// com prioridade 4 (quanto mais pr�ximo de 0 maior)
	NVIC_EnableIRQ(START_PIO_ID);
	NVIC_SetPriority(START_PIO_ID, 4); // Prioridade 4
	NVIC_EnableIRQ(SELECAO_PIO_ID);
	NVIC_SetPriority(SELECAO_PIO_ID, 5); // Prioridade 5S
}

int get_startstop(void){
	return pio_get(START_PIO, PIO_INPUT, START_PIO_IDX_MASK);
}

void set_buzzer(void){
	// coloca 1 no pino do BUZZER.
	pio_set(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
}

void clear_buzzer(void){
	// coloca 0 no pino do BUZZER
	pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
}

int get_selecao(void){
	return pio_get(SELECAO_PIO, PIO_INPUT, SELECAO_PIO_IDX_MASK);
}

/**
 * freq: Frequecia em Hz
 * time: Tempo em ms que o tom deve ser gerado
 */
void tone(int freq, int time){ // freq em Hz , time em ms
	//contar quantos pulsos (freq) existem dentro de um tempo (time) e
	//ent?o fazer um loop que gere a quantidade de pulsos (na frequ?ncia certa).
	float periodo = 1.0/freq;
	int quantidade_de_pulsos = (freq*time)/1000;
	for (int i = 0; i < quantidade_de_pulsos; i++){
		set_buzzer();
		delay_us(periodo*500000); //T*10^6/2
		clear_buzzer();
		delay_us(periodo*500000); //T*10^6/2
	}
}

void buzzer_test(int freq){
	float periodo = 1.0/freq;
	int time = 2000; 
	int quantidade_de_pulsos = (freq*time)/1000;
	for (int i = 0; i < quantidade_de_pulsos; i++){
		set_buzzer();
		delay_us(periodo*500000); //T*10^6/2
		clear_buzzer();
		delay_us(periodo*500000); //T*10^6/2
	}
}


void noTone(void){
	clear_buzzer();
}

void limpa_barra(){
	for(int i=120;i>=0;i-=1){
		gfx_mono_draw_rect(i, 5, 2, 10, GFX_PIXEL_CLR);
		//delay_ms(10);
	}
}

void play_song_not_working(int melody[], int tempo){ //futuramente passar a musica aqui (nome da op??o)
	// this calculates the duration of a whole note in ms
	int wholenote = (60000 * 4) / tempo; //
	int divider = 0, noteDuration = 0;
	
	// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
	// there are two values per note (pitch and duration), so for each note there are four bytes
	int notes = sizeof(melody) / sizeof(melody[0]) / 2; //tamanho total/tamanho int *0.5 (pq metade ? o tempo das notas)
	for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
		// calculates the duration of each note
		divider = melody[thisNote + 1];
		noteDuration = (wholenote) / abs(divider);
		if (divider < 0) {
			noteDuration *= 1.5; // increases the duration in half for dotted notes
		}
		// we only play the note for 90% of the duration, leaving 10% as a pause
		tone(melody[thisNote], noteDuration * 0.9);

		// Wait for the specief duration before playing the next note.
		delay_ms(noteDuration*0.1);
	}
}

void play_song_mario(Musica musicas[]){ //futuramente passar a musica aqui (nome da op??o)
	Musica mario = musicas[0];
	int notes = sizeof(mario.notas) / sizeof(mario.notas[0]) / 2; //tamanho total/tamanho int *0.5 (pq metade ? o tempo das notas)
	for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
		if (but_change_song_flag){
			break;
		}
		if (but_play_flag){
			while(but_play_flag == 1){
				if (but_change_song_flag){
					break;
				}
			}
			but_play_flag = 0;
		}
		if (but_change_song_flag){
			break;
		}
		// calculates the duration of each note
		divider = mario.notas[thisNote + 1];
		noteDuration = (wholenote) / abs(divider);
		if (divider < 0) {
			noteDuration *= 1.5; // increases the duration in half for dotted notes
		}
		// we only play the note for 90% of the duration, leaving 10% as a pause
		tone(mario.notas[thisNote], noteDuration * 0.9);
		pio_clear(LED_PIO, LED_PIO_IDX_MASK);
		// Wait for the specief duration before playing the next note.
		delay_ms(noteDuration*0.1);
		pio_set(LED_PIO, LED_PIO_IDX_MASK);
	}
}

void play_song_asa_branca(Musica musicas[]){ //futuramente passar a musica aqui (nome da op??o)
	Musica asa_branca = musicas[1];
	// this calculates the duration of a whole note in ms
	int wholenote = (60000 * 4) / 120; //
	int divider = 0, noteDuration = 0;
	
	// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
	// there are two values per note (pitch and duration), so for each note there are four bytes
	int notes = sizeof(asa_branca.notas) / sizeof(asa_branca.notas[0]) / 2; //tamanho total/tamanho int *0.5 (pq metade ? o tempo das notas)
	for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
		if (but_change_song_flag){
			break;
		}
		if (but_play_flag){
			while(but_play_flag == 1){
				if (but_change_song_flag){
					break;
				}
			}
			but_play_flag = 0;
		}
		if (but_change_song_flag){
			break;
		}
		

		// calculates the duration of each note
		divider = asa_branca.notas[thisNote + 1];
		noteDuration = (wholenote) / abs(divider);
		if (divider < 0) {
			noteDuration *= 1.5; // increases the duration in half for dotted notes
		}
		// we only play the note for 90% of the duration, leaving 10% as a pause
		tone(asa_branca.notas[thisNote], noteDuration * 0.9);
		pio_clear(LED_PIO, LED_PIO_IDX_MASK);

		// Wait for the specief duration before playing the next note.
		delay_ms(noteDuration*0.1);
		pio_set(LED_PIO, LED_PIO_IDX_MASK);
	}
}


int atualiza_display(){
	if(song_number == 1){
		gfx_mono_draw_string("             ", 0,16, &sysfont);
		gfx_mono_draw_string("mario bros", 0,16, &sysfont);
	}else{
		if (song_number == 2)
		{
			gfx_mono_draw_string("             ", 0,16, &sysfont);
			gfx_mono_draw_string("asa branca", 0,16, &sysfont);
		}
	}
}

int main (void)
{
	init();
	board_init();
	sysclk_init();
	
	delay_init();

  // Init OLED
	gfx_mono_ssd1306_init();
	Musica musicas[2];
	musicasArray(musicas);
	gfx_mono_draw_string("mario bros", 0,16, &sysfont);
	int toca = 0;
	
  /* Insert application code here, after the board has been initialized. */
	while(1) {
		//AL�, CORSI. HELP HERE:
		//play_song_not_working(melody_asa_branca, 120);
		//play_song_not_working(melody_mario, 200);
	
		if(but_change_song_flag){
			but_change_song_flag = 0;
			if(song_number <2){
				song_number += 1;
			}else{
				song_number = 1;
			}
			atualiza_display();
		}
		if(but_play_flag) {  //apertei?
			but_play_flag = 0;
			if (song_number==1){
				atualiza_display();
				play_song_mario(musicas);
			}
			if (song_number == 2)
			{
				atualiza_display();
				play_song_asa_branca(musicas);
			}
		}
	}
}
	
