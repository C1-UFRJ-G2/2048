#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include "game.h"
#include "handle.h"

#define MIN_X_SIZE 10
#define MIN_Y_SIZE 34

void killHandle(void) {
    fimDeJogo();
    system("clear");
    system("echo -e \"Obrigado por jogar!\n\"");
    exit(0);
}

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
