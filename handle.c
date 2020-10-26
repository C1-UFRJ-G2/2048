#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "interface.h"
#include "handle.h"

void killHandle(int sig) {
    int ignore = 1;
    signal(sig, SIG_IGN);
    printw("Voce realmente deseja sair? [S/n]\n");

    while (ignore) {
        char input = getch();

        switch (input) {
            case 's': case 'S':
                fimDeJogo();
                exit(0);

            case 'n': case 'N':
                ignore = 0;
                signal(SIGINT, killHandle);
                signal(SIGTSTP, killHandle);
            break;

            default:
                break;
        }
    }
}