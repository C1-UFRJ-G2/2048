#include <stdlib.h>
#include "music.h"

static unsigned short int tocando = 3;

/* Função para tocar a música, selecionando uma das duas
* aleatoriamente */
void play(void) {
    if (tocando == 3) {
        char *plays[] = {"paplay theme1.ogg &", "paplay theme2.ogg &"};
        tocando = rand() % 2;
        system(plays[tocando]);
    }
}

/* Função para parar de tocar a música */
void stop(void) {
    if (tocando < 2) {
        char *pauses[] = {"pkill -f \"paplay theme1.ogg\"", "pkill -f \"paplay theme2.ogg\""};
        system(pauses[tocando]);
        tocando = 3;
    }
}
