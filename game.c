#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "game.h"
#include "interface.h"

int high_score, score = 0;

void novoHighScore(void) {
    FILE *score_data = fopen("high_score.bin", "w");
    high_score = score;
    fwrite(&score, sizeof(int), 1, score_data);
    fclose(score_data);
}

void getHighScore(void) {
    FILE *score_data = fopen("high_score.bin", "r");
    if (!score_data) {
        novoHighScore();
    } else {
        fread(&high_score, sizeof(int), 1, score_data);
        fclose(score_data);
    }
}

int oJogoContinua(int matrix[SIZE][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 2048) {
                printw("Você venceu!\n");
                return restart(matrix);
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

    printw("Você perdeu!\n");
    return restart(matrix);
}

/*Percorre a matriz equivalente ao grid do jogo, encontrando os valores iguais a zero
e guardando seus endereços, depois disso, adiciona um novo valor (90% de chance de ser
um 2 e 10% de ser um 4) em um valor igual a zero aleatório*/
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
    printInterface(matrix);
}

/*Define o novo high_score caso o jogador o tenha batido e encerra a interface*/
void fimDeJogo(void) {
    if (score > high_score) novoHighScore();
    encerraInterface();
}

/*Inicia a interface, pega o high_score guardado e adiciona os valores
do inicio do jogo*/
void novoJogo(int matrix[SIZE][SIZE]) {
    int i, j;
    score = 0;
    iniciaInterface();
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = 0;
        }
    }

    getHighScore();
    adicionaNovoValor(matrix);
    adicionaNovoValor(matrix);
}

/*Pergunta se o jogador deseja encerrar o jogo iniciando um novo jogo caso
sim, ou realizando os processos de fim de jogo caso não, geralmente é chamado pela função
oJogoContinua(), que recebe o valor que ela retornará o valor que ela retornar, entre 0 e 1,
definindo se o jogo continuará ou não*/
int restart(int matrix[SIZE][SIZE]) {
    printw("Pressione r para jogar novamente ou q para sair\n");
    
    while (1) {
        char input = getch();

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