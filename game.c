#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "interface.h"

int high_score, score = 0;

void novoHighScore(int score) {
    high_score = score;
    FILE *score_data = fopen("high_score.bin", "w");
    fwrite(&score, sizeof(int), 1, score_data);
    fclose(score_data);
}

void getHighScore(void) {
    FILE *score_data = fopen("high_score.bin", "r");
    fread(&high_score, sizeof(int), 1, score_data);
    fclose(score_data);
}

int oJogoContinua(int matrix[SIZE][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 2048) {
                clean();
                puts("                            Você venceu!");
                puts("Pressione 1 para jogar novamente ou qualquer tecla para sair");
                char input = getch();
                if (input == '1') {
                    fimDeJogo();
                    novoJogo(matrix);
                    return 1;
                } else exit(0);
            }
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 0) 
                return 1;
            else if (matrix[i][j] == matrix[i][j + 1] || matrix[i][j] == matrix[i][j - 1])
                return 1;
            else if ( matrix[i][j] == matrix[i + 1][j] || matrix[i][j] == matrix[i - 1][j])
                return 1;
        }
    }

    puts("                            Você perdeu!");
    puts("Pressione 1 para jogar novamente ou qualquer tecla para sair");
    char input;
    scanf("%c", &input);
    if (input == '1') {
        novoJogo(matrix);
        return 1;
    } else fimDeJogo();
}

void adicionaNovosQuadrados(int matrix[SIZE][SIZE]) {
    /*Adiciona novos quadrados
    * 2 = 90% de chance
    * 4 = 10% de chance*/
}

void fimDeJogo(void) {
    if (score > high_score) novoHighScore(score);
    exit(0);
}

void novoJogo(int matrix[SIZE][SIZE]) {
}