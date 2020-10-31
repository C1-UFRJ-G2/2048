#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "game.h"

short int unicode_status;
extern unsigned int score, high_score;

void iniciaUnicode(char *flag) {
    unicode_status = !strcmp(flag, "--no-unicode");
}

void iniciaInterface(void) {
    initscr(); /*Inicia a "tela do jogo"*/
    noecho(); /*Esconde os valores que o usuário está entrando dele*/
    curs_set(0); /*Desativa o cursor do terminal do usuário*/
}

void encerraInterface(void) {
    curs_set(1); /*Reativa o cursor do terminal do usuário*/
    clear(); /*Limpa a tela*/
    echo(); /*Volta a mostrar os inputs do usuário*/
    endwin(); /*Encerra a tela iniciada no começo*/
}
/*Função responsável por imprimir a interface de jogo*/
void printInterface(short int matrix[SIZE][SIZE]) {
    short int i, j;
    refresh(); /*Reinicia a tela para expor novos valores*/
    clear(); /*Limpa a tela*/
    printw("Score: %5.u\nHigh Score: %5.u\n", score, high_score > score ? high_score : score);

    if (!unicode_status) {
        static char *topo =  "╔════╦════╦════╦════╗",
                    *base = "╚════╩════╩════╩════╝",
                    *meio = "╠════╬════╬════╬════╣";

        printw("%s\n", topo);
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printw("║%4.i", matrix[i][j]);
            }
            printw("║\n");
            if (i < SIZE - 1) printw("%s\n", meio);
        }
        printw("%s\n", base);
    } else {
        static char *div =  "+----+----+----+----+";

        printw("%s\n", div);
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printw("|%4.i", matrix[i][j]);
            }
            printw("|\n");
            if (i < SIZE - 1) printw("%s\n", div);
        }
        printw("%s\n", div);
    }

    printw("Controles: WASD ou direcionais. 0 para sair");
}
