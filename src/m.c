#include <stdio.h>
#include <stdlib.h>
#include "m.h"

char cond;

/* Função para tocar a música, selecionando uma das duas
* aleatoriamente */
int mp () {
    short unsigned int random = rand() % 2;
    if (random == 0) {
            if (cond == '1' || cond == '2') return 1;
            cond = '1';
            system("paplay theme1.ogg &");
    }
    else if (random != 0) {
            if (cond == '1' || cond == '2') return 1;
            cond = '2';
            system("paplay theme2.ogg &");
    }
    return 0;
}

/* Função para parar de tocar a música */
void ms () {
    if (cond == '1') {
        system("pkill -f \"paplay theme1.ogg\"");
        cond = '5';
    }
    else if (cond == '2') {
        system("pkill -f \"paplay theme2.ogg\"");
        cond = '5';
    }
}