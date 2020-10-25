#include <stdio.h>
#include "game.h"

int high_score, score = 0;

void novoHighScore(int score) {
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
    /*Deve conferir se o jogo tem algum movimento possível, basicamente, pra cada valor
    confira se ao redor dele há um valor de mesmo número, se em pelo menos um tiver,
    o jogo não está perdido, e você retorna 1, se não achar nada, retorna 0 e a gente printa
    game over*/
}

int adicionaNovosQuadrados(int matrix[SIZE][SIZE]) {
    /*Adiciona novos quadrados
    * 2 = 90% de chance
    * 4 = 10% de chance*/
}

int restart(int matrix[SIZE][SIZE]) {
    /*Quando a pessoa perder, dá a opção de dar
    restart no jogo, recomeçando completamente o jogo.*/
}
