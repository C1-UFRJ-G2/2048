#include <ncurses.h>
#include <stdio.h>
#include "interface.h"
#include "game.h"

extern unsigned int score, high_score;

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

    /*Verifica se a há suporte a cores no terminal e formata a interface de acordo com esse fato*/
    if (has_colors()) {
        printw("Score: %5.d High Score: %5.d\n\n", score, high_score);

        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printw("|%4.d", matrix[i][j]);
            }
            printw("|\n");
        }
    } else {
        printw("Score: %5.d High Score: %5.d\n\n", score, high_score);

        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printw("|%4.d", matrix[i][j]);
            }
            printw("|\n");
        }
    }
}