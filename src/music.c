#include <stdio.h>
#include <stdlib.h>
#include "music.h"

unsigned short int tocando = 3;

/* Função para tocar a música, selecionando uma das duas
* aleatoriamente */
void play(void) {
    char *plays[] = {"paplay theme1.ogg &", "paplay theme2.ogg &"};
    if (tocando == 3) {
        tocando = rand() % 2;
        system(plays[tocando]);
    }
}

/* Função para parar de tocar a música */
void stop(void) {
    char *pauses[] = {"pkill -f \"paplay theme1.ogg\"", "pkill -f \"paplay theme2.ogg\""};
    if (tocando < 2) {
        system(pauses[tocando]);
        tocando = 3;
    }
}
