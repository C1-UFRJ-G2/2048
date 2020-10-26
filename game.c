#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "interface.h"

int high_score, score = 0;

void novoHighScore(void) {
    high_score = score;
    FILE *score_data = fopen("high_score.bin", "w");
    fwrite(&score, sizeof(int), 1, score_data);
    fclose(score_data);
}

void getHighScore(void) {
    FILE *score_data = fopen("high_score.bin", "r");
    if (score_data) {
        fread(&high_score, sizeof(int), 1, score_data);
        fclose(score_data);
    } else {
        novoHighScore();
    }
}

int oJogoContinua(int matrix[SIZE][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 2048) {
                printw("Voce venceu!\n");
                return 0;
            }
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 0) 
                return 1;
            if (i > 0 && i < SIZE - 1) {
                if (matrix[i][j] == matrix[i + 1][j] || matrix[i][j] == matrix[i - 1][j])
                    return 1;
            }

            if (j > 0 && j < SIZE - 1) {
                if (matrix[i][j] == matrix[i][j + 1] || matrix[i][j] == matrix[i][j - 1])
                    return 1;
            }
        }
    }

    printInterface(matrix);
    printw("Voce perdeu!\n");
    return restart(matrix);
}

void adicionaNovoValor(int matrix[SIZE][SIZE]) {
    int i, j, counter = 0,
    **vazios = (int **) malloc(sizeof(int *) * SIZE * SIZE);

    for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (matrix[i][j] == 0) {
				*(vazios + counter) = &matrix[i][j];
				counter++;
			}
		}
	}

    if (counter > 0) {
        int i = rand() % counter;
        int valor = (rand() % 100) >= 9 ? 2 : 4;
        *vazios[i] = valor;
    }

    free(vazios);
}

void fimDeJogo(void) {
    if (score > high_score) novoHighScore();
    curs_set(1);
    clear();
    echo();
    endwin();
}

void novoJogo(int matrix[SIZE][SIZE]) {
    curs_set(0);
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = 0;
        }
    }

    adicionaNovoValor(matrix);
    adicionaNovoValor(matrix);
}

int restart(int matrix[SIZE][SIZE]) {
    printw("Pressione r para jogar novamente ou q para sair\n");
    sleep(1000);
    
    while (1) {
        #if defined(_WIN32) || defined(_WIN64)
            char input = getch();
        #else
            char input = getchar();
        #endif

        switch (input) {
            case 'r': case 'R':
                fimDeJogo();
                novoJogo(matrix);
                return 1;

            case 'q': case 'Q':
                return 0;

            default:
                break;
        }
    }
}