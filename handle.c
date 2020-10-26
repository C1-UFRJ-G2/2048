#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "interface.h"
#include "handle.h"

void killHandle(int sig) {
    int ignore = 1;
    signal(sig, SIG_IGN);
    puts("Voce realmente deseja sair? [S/n]");

    while (ignore) {
        #if defined(_WIN32) || defined(_WIN64)
            char input = getch();
        #else
            char input = getchar();
        #endif

        switch (input) {
            case 's': case 'S':
                fimDeJogo();
                exit(0);

            case 'n': case 'N':
                ignore = 0;
                signal(SIGINT, killHandle);

            default:
                break;
        }
    }
}