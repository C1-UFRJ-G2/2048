#include <ncurses.h>
#include <stdio.h>
#include "interface.h"
#include "game.h"

extern int score, high_score;

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
    static char *topo =  "╔════╦════╦════╦════╗",
                *base = "╚════╩════╩════╩════╝",
                *meio = "╠════╬════╬════╬════╣"; 

    refresh(); /*Reinicia a tela para expor novos valores*/
    clear(); /*Limpa a tela*/
    /*Verifica se a há suporte a cores no terminal e formata a interface de acordo com esse fato*/
    printw("Score: %5.d\nHigh Score: %5.d\n", score, high_score);
    printw("%s\n", topo);
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printw("║%4.d", matrix[i][j]);
        }
        printw("║\n");
        if (i < SIZE - 1) printw("%s\n", meio);
    }
    printw("%s\n", base);
    printw("Controles: WASD ou direcionais. 0 para sair");
}