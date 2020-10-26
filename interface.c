#include <signal.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "game.h"
#include "handle.h"

extern int score, high_score;

<<<<<<< HEAD
=======
void clean(void) {
    /*#if defined(_WIN32) || defined(_WIN64)*/
        system("cls");
    /*#else
        system("clear");
    #endif*/
}

>>>>>>> origin/main
void printInterface(int matrix[SIZE][SIZE]) {
    int i, j;

    clear();
    printw("Score: %5.d High Score: %5.d\n\n", score, high_score);

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printw("|%4.d", matrix[i][j]);
        }
        printw("|\n");
    }
}