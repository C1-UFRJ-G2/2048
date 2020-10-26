#include <stdio.h>
#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include "game.h"
#include "handle.h"

#define MIN_X_SIZE 10
#define MIN_Y_SIZE 34

void killHandle(int sig) {
    int ignore = 0;
    fimDeJogo();
    system("echo -e \"Obrigado por jogar!\n\"");
    exit(0);
}

void verificaTamanhoDoTerminal(void) {
    int x, y;
    getmaxyx(stdscr, x, y);
    printf("%d %d\n", x, y);
    if (x < MIN_X_SIZE || y < MIN_Y_SIZE) {
        fimDeJogo();
        system("echo -e \"Aumente o tamanho do seu emulador terminal e tente novamente!\n\"");
        exit(1);
    }
}