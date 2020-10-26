#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "game.h"

extern int score, high_score;

void clean(void) {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else 
        system("clear");
    #endif
}

void printInterface(int matrix[SIZE][SIZE]) {
    int i, j, score = 0, high_score = 100;
    move(0, 0);
    printw("Score: %d  High Score: %d   Aperte 0 para sair\n\n", score, high_score);

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printw("|%4.d", matrix[i][j]);
        }
        printw("|\n");
    }
}