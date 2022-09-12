#include <asf.h>
#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "musica.h"
#include "sysfont.h"


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
#define LED_PIO_ID        ID_PIOA                    // ID do periférico PIOC (controla LED)
#define LED_PIO_IDX       0                    // ID do LED no PIO
#define LED_PIO_IDX_MASK  (1 << LED_PIO_IDX)   // Mascara para CONTROLARMOS o LED


// change this to make the song slower or faster
/*#define tempo 200*/
int wholenote = (60000 * 4) / 200; //
int divider = 0, noteDuration = 0;

int song_number = 1;

int notes_mario;
int notes_asa;

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
//void play_song_not_working(int melody[], int tempo);
void play_song_mario(Musica musicas);
void play_song_asa_branca(Musica musicas);
//void musicasArray(Musica *musicas[]);


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
	// Configura PIO para lidar com o pino do botão como entrada
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
	
	// Configura interrupção no pino referente ao botao e associa
	// função de callback caso uma interrupção for gerada
	// a função de callback é a: but_callback()
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
	
	// Ativa interrupção e limpa primeira IRQ gerada na ativacao
	pio_enable_interrupt(START_PIO, START_PIO_IDX_MASK);
	pio_get_interrupt_status(START_PIO);
	pio_enable_interrupt(SELECAO_PIO, SELECAO_PIO_IDX_MASK);
	pio_get_interrupt_status(SELECAO_PIO);
	
	// Configura NVIC para receber interrupcoes do PIO do botao
	// com prioridade 4 (quanto mais próximo de 0 maior)
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

// void play_song_not_working(int melody[], int tempo){ //futuramente passar a musica aqui (nome da op??o)
// 	// this calculates the duration of a whole note in ms
// 	int wholenote = (60000 * 4) / tempo; //
// 	int divider = 0, noteDuration = 0;
// 	
// 	// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// 	// there are two values per note (pitch and duration), so for each note there are four bytes
// 	int notes = sizeof(melody) / sizeof(melody[0]) / 2; //tamanho total/tamanho int *0.5 (pq metade ? o tempo das notas)
// 	for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
// 		// calculates the duration of each note
// 		divider = melody[thisNote + 1];
// 		noteDuration = (wholenote) / abs(divider);
// 		if (divider < 0) {
// 			noteDuration *= 1.5; // increases the duration in half for dotted notes
// 		}
// 		// we only play the note for 90% of the duration, leaving 10% as a pause
// 		tone(melody[thisNote], noteDuration * 0.9);
// 
// 		// Wait for the specief duration before playing the next note.
// 		delay_ms(noteDuration*0.1);
// 	}
// }

void play_song_mario(Musica mario){ //futuramente passar a musica aqui (nome da op??o)
	//int notes = sizeofMario/sizeofMarioFirst/2; //tamanho total/tamanho int *0.5 (pq metade ? o tempo das notas)
	for (int thisNote = 0; thisNote < notes_mario * 2; thisNote = thisNote + 2) {
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

void play_song_asa_branca(Musica asa_branca){ //futuramente passar a musica aqui (nome da op??o)
	//Musica asa_branca = musicas[1];
	// this calculates the duration of a whole note in ms
	int wholenote = (60000 * 4) / 120; //
	int divider = 0, noteDuration = 0;
	
	// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
	// there are two values per note (pitch and duration), so for each note there are four bytes
	//int notes = sizeofAsa/sizeofAsaFirst/2; //sizeof(asa_branca.notas) / sizeof(asa_branca.notas[0]) / 2; //tamanho total/tamanho int *0.5 (pq metade ? o tempo das notas)
	for (int thisNote = 0; thisNote < notes_asa * 2; thisNote = thisNote + 2) {
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
// 	Musica musicas[2];
// 	Musica *ponteiro_musicas;
// 	ponteiro_musicas = &musicas;
// 	musicasArray(ponteiro_musicas);
	Musica mario_song;
	Musica *p_mario;
	p_mario = &mario_song;
	mario(p_mario);
	
	Musica asa_song;
	Musica *p_asa;
	p_asa = &asa_song;
	asa(p_asa);
	
	notes_mario = sizeofMario/sizeofMarioFirst/2;
	notes_asa = sizeofAsa/sizeofAsaFirst/2;
	gfx_mono_draw_string("mario bros", 0,16, &sysfont);
	int toca = 0;
	
  /* Insert application code here, after the board has been initialized. */
	while(1) {
		//ALÔ, CORSI. HELP HERE:
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
				play_song_mario(mario_song);
			}
			if (song_number == 2)
			{
				atualiza_display();
				play_song_asa_branca(asa_song);
			}
		}
	}
}
	
