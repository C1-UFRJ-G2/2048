#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include "game.h"
#include "handle.h"

#define MIN_X_SIZE 15
#define MIN_Y_SIZE 22

/*Dá handle nos comandos SIGKILL e SIGINT, impedindo que o jogo pare
inesperadamente*/
void killHandle(void) {
    fimDeJogo();
    system("clear");
    system("echo -e \"Obrigado por jogar!\n\"");
    exit(0);
}

/*No inicio do jogo, será chamada para verificar o tamanho do terminal e disparará um erro
se ele estiver muito pequeno para comportar o jogo */
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
