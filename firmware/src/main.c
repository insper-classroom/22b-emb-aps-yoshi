#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "notes.h"
#include "sysfont.h"
#include "mario.h"
#include "asabranca.h"
#include "jigglypuff.h"
#include "harrypotter.h"
#include "happybirthday.h"
#include "merrychristmas.h"

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

int esta_pausado = 0;
int aguardando_play_again = 0;
int song_number = 1;

/* flag */
volatile char but_play_flag; //
volatile char but_change_song_flag; //


typedef struct  {
	int *notas;
	int tempo;
	int notes;
} Musica;

void init(void);
int get_startstop(void);
void set_buzzer(void);
void clear_buzzer(void);
int get_selecao(void);
void play_song(Musica musica);

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
		gfx_mono_draw_rect(i, 0, 2, 15, GFX_PIXEL_CLR);
	}
}

void play_song(Musica musica){ 
	int wholenote = (60000 * 4) / musica.tempo; //
	int divider = 0, noteDuration = 0; 
	for (int thisNote = 0; thisNote < musica.notes * 2 ; thisNote = thisNote + 2) {
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
		divider = musica.notas[thisNote + 1];
		noteDuration = (wholenote) / abs(divider);
		unsigned int progress = 124*thisNote / (musica.notes*2);
		gfx_mono_draw_filled_rect(2, 2, progress, 10, GFX_PIXEL_SET);
		if (divider < 0) {
			noteDuration *= 1.5; // increases the duration in half for dotted notes
		}
		// we only play the note for 90% of the duration, leaving 10% as a pause
		tone(musica.notas[thisNote], noteDuration * 0.9);
		pio_clear(LED_PIO, LED_PIO_IDX_MASK);
		// Wait for the specief duration before playing the next note.
		delay_ms(noteDuration*0.1);
		pio_set(LED_PIO, LED_PIO_IDX_MASK);
	}
}


int atualiza_display(){
	if(song_number == 1){
		limpa_barra();
		gfx_mono_draw_string("             ", 0,16, &sysfont);
		gfx_mono_draw_string("1. Mario Bros", 0,16, &sysfont);
	}
	if (song_number == 2){	
		limpa_barra();
		gfx_mono_draw_string("             ", 0,16, &sysfont);
		gfx_mono_draw_string("2. Asa Branca", 0,16, &sysfont);
		}
	if (song_number == 3){
		limpa_barra();
		gfx_mono_draw_string("             ", 0,16, &sysfont);
		gfx_mono_draw_string("3. Jigglypuff", 0,16, &sysfont);
		}
	if (song_number == 4){
		limpa_barra();
		gfx_mono_draw_string("             ", 0,16, &sysfont);
		gfx_mono_draw_string("4.HarryPotter", 0,16, &sysfont);
		}
	if (song_number == 5){
		limpa_barra();
		gfx_mono_draw_string("             ", 0,16, &sysfont);
		gfx_mono_draw_string("5. HappyB", 0,16, &sysfont);
	}
	if (song_number == 6){
		limpa_barra();
		gfx_mono_draw_string("             ", 0,16, &sysfont);
		gfx_mono_draw_string("6. MerryC", 0,16, &sysfont);
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
	gfx_mono_draw_string("Botao 1", 0,4, &sysfont);
	gfx_mono_draw_string("para tocar!", 0,16, &sysfont);

	int toca = 0;
	Musica mario, asabranca, jigglypuff, harrypotter, happybirthday, merrychristmas;
	
	mario.notas = &melody_mario;
	mario.tempo = 200;
	mario.notes = sizeof(melody_mario) / sizeof(melody_mario[0]) / 2;
	
	asabranca.notas = &melody_asa_branca;
	asabranca.tempo = 120;
	asabranca.notes = sizeof(melody_asa_branca) / sizeof(melody_asa_branca[0]) / 2;
	
	jigglypuff.notas = &melody_jigglypuff;
	jigglypuff.tempo = 85;
	jigglypuff.notes = sizeof(melody_jigglypuff) / sizeof(melody_jigglypuff[0]) / 2;
	
	harrypotter.notas = &melody_harrypotter;
	harrypotter.tempo = 144;
	harrypotter.notes = sizeof(melody_harrypotter) / sizeof(melody_harrypotter[0]) / 2;
	
	happybirthday.notas = &melody_happybirthday;
	happybirthday.tempo = 140;
	happybirthday.notes = sizeof(melody_happybirthday) / sizeof(melody_happybirthday[0]) / 2;
	
	merrychristmas.notas = &melody_merrychristmas;
	merrychristmas.tempo = 140;
	merrychristmas.notes = sizeof(melody_merrychristmas) / sizeof(melody_merrychristmas[0]) / 2;
	
  /* Insert application code here, after the board has been initialized. */
	while(1) {
	
		if(but_change_song_flag){
			but_change_song_flag = 0;
			if(song_number < 7){
				song_number += 1;
			}else{
				song_number = 1;
			}
			atualiza_display();
		}
		if(but_play_flag) { 
			but_play_flag = 0;
			if (song_number==1){
				atualiza_display();
				play_song(mario);
			}
			if (song_number == 2)
			{
				atualiza_display();
				play_song(asabranca);
			}
			if (song_number == 3)
			{
				atualiza_display();
				play_song(jigglypuff);
			}
			if (song_number == 4)
			{
				atualiza_display();
				play_song(harrypotter);
			}
			if (song_number == 5)
			{
				atualiza_display();
				play_song(happybirthday);
			}
			if (song_number == 6)
			{
				atualiza_display();
				play_song(merrychristmas);
			}
		}
	}
}
	
