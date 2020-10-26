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
    int i, j;
    getHighScore();
    clean();
    printf("\nScore: %d  High Score: %d   Aperte 0 para sair\n\n", score, high_score);

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("|%4.d", matrix[i][j]);
        }
        printf("|\n");
    }
}
