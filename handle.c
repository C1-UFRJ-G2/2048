#include <string.h>
#include <stdio.h>
#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include "game.h"
#include "interface.h"
#include "handle.h"

#define MIN_X_SIZE 10
#define MIN_Y_SIZE 34

void killHandle(int sig) {
    int ignore = 0;
    signal(sig, SIG_IGN);
    printw("Voce realmente deseja sair? [S/n]\n");

    while (!ignore) {
        char input = getch();

        switch (input) {
            case 's': case 'S':
                fimDeJogo();
                exit(0);

            case 'n': case 'N':
                ignore = 1;
                signal(SIGINT, killHandle);
                signal(SIGTSTP, killHandle);
                
            break;

            default:
                break;
        }
    }
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