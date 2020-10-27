#include <ncurses.h>
#include <stdio.h>
#include "interface.h"
#include "game.h"

extern int score, high_score;

void iniciaInterface(void) {
    initscr();
    noecho();
    curs_set(0);
}

void encerraInterface(void) {
    curs_set(1);
    clear();
    echo();
    endwin();
}

void printInterface(int matrix[SIZE][SIZE]) {
    int i, j;
    refresh();
    clear();

    if (has_colors()) {
        printw("Score: %5.d High Score: %5.d\n\n", score, high_score);

        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printw("|%4.d", matrix[i][j]);
            }
            printw("|\n");
        }
    } else {
        printw("Score: %5.d High Score: %5.d\n\n", score, high_score);

        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printw("|%4.d", matrix[i][j]);
            }
            printw("|\n");
        }
    }
}