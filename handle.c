#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include "game.h"
#include "handle.h"

#define MIN_X_SIZE 10
#define MIN_Y_SIZE 34

/*Dá handle caso o usuário aperte Control + C ou Control + Z, realizando o processo
padrão de fim de jogo antes, e o agradecendo por jogar, importante porque evita que
o terminal do usuário fique bugado caso ele pare o jogo "do nada"*/
void killHandle(void) {
    fimDeJogo();
    system("clear");
    system("echo -e \"Obrigado por jogar!\n\"");
    exit(0);
}

/*Confere se o terminal do usuário tem tamanho suficiente para comportar o jogo,
encerrando o jogo e o pedindo para aumentar seu terminal e tentar novamente caso
não*/
void verificaTamanhoDoTerminal(void) {
    short int x, y;
    getmaxyx(stdscr, x, y);
    if (x < MIN_X_SIZE || y < MIN_Y_SIZE) {
        fimDeJogo();
        system("clear");
        system("echo -e \"Aumente o tamanho do seu emulador de terminal e tente novamente!\n\"");
        exit(1);
    }
}
