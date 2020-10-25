#include "controles.h"
#include "game.h"

extern int score;

/*Os nomes são bem auto-explicativos, só faz ai*/
void paraCima(int matrix[SIZE][SIZE]) {
/* sobe de cima p baixo, junta de cima pra baixo e sobe:
joga todo mundo pra cima começando pela linha 1, o debaixo vira zero;
avalia pela linha 0 ate 2 (inclusive) se o de baixo é igual, aí multiplica e o de baixo vira 0;*/

    int i, j, k;  /*3*3*4 + 3*4+ 3*4=60 vezes*/
    for (k = 0; k < SIZE - 1; k++) {
        for (i = 1; i < SIZE; i++) {
			for (j = 0;j < SIZE; j++) {
				if(matrix[i-1][j] == 0) {
					matrix[i-1][j]=matrix[i][j];
					matrix[i][j]=0;
				}
			}
        }
    }

    /*junta*/
    for (i = 0; i < SIZE - 1; i++){
		for (j = 0; j < SIZE; j++){
			if(matrix[i][j] == matrix[i+1][j]){
				matrix[i][j] += matrix[i+1][j];
				matrix[i+1][j]=0;
				score += matrix[i][j];
			}
		}
    }
    /*mexe pra cima de novo por causa dos novos valores*/
    /*for (k=0;k<3;k++){*/
	for (i = 1; i < SIZE; i++){
		for (j = 0; j < SIZE; j++){
			if(matrix[i-1][j] == 0){
				matrix[i-1][j]=matrix[i][j];
				matrix[i][j]=0;
			}
		}
	}
}

void paraBaixo(int matrix[SIZE][SIZE]){
	int i, j, k;  /*3*3*4 + 3*4+ 3*4=60 vezes*/
    for (k = 0; k < SIZE - 1; k++) {
        for (i = SIZE - 2; i >= 0; i--) {
			for (j = 0; j < SIZE; j++) {
				if(matrix[i+1][j] == 0) {
				matrix[i+1][j] = matrix[i][j];
					matrix[i][j] = 0;
				}
			}
        }
    }

    /*junta*/
	for (i = SIZE - 1; i > 0; i--) {
		for (j = 0; j < SIZE; j++) {
			if(matrix[i][j] == matrix[i-1][j]) {
				matrix[i][j] += matrix[i-1][j];
				matrix[i-1][j]=0;
				score += matrix[i][j];
			}
		}
	}

    /*mexe pra baixo de novo por causa dos novos valores*/
	for (i = SIZE - 2; i >= 0; i--) {
		for (j = 0; j < SIZE; j++) { 
			if(matrix[i+1][j] == 0) {
				matrix[i+1][j]=matrix[i][j];
				matrix[i][j]=0;
			}
		}
	}
}




void paraEsquerda(int matrix[SIZE][SIZE]) {
	int i, j, k;  /*3*3*4 + 3*4+ 3*4=60 vezes*/
    for (k = 0; k < SIZE - 1; k++) {
        for (j = 1; j < SIZE; j++) {
			for (i = 0; i < SIZE; i++) {
				if(matrix[i][j-1] == 0) {
					matrix[i][j-1]=matrix[i][j];
					matrix[i][j]=0;
				}
			}
        }
    }

    /*junta*/
    for (j = 0; j < SIZE - 1; j++){
		for (i = 0; i < SIZE; i++){
			if (matrix[i][j] == matrix[i][j+1]) {
				matrix[i][j] += matrix[i][j+1];
				matrix[i][j+1] = 0;
				score += matrix[i][j];
			}
		}
    }
    /*mexe pra esquerda de novo por causa dos novos valores*/
	for (j = 1; j < SIZE; j++){
		for (i = 0;i < SIZE; i++){
			if (matrix[i][j-1] == 0) {
				matrix[i][j-1]=matrix[i][j];
				matrix[i][j]=0;
			}
		}
	}   
}




void paraDireita(int matrix[SIZE][SIZE]) {
	/*anda p direita da direita p esquerda, junta da direita p esquerda e anda:*/
	int i, j, k;
	/*3*3*4 + 3*4+ 3*4=60 vezes*/
    for (k = 0; k < SIZE - 1; k++) {
        for (j = SIZE - 2; j >= 0; j--) {
			for (i = 0; i < SIZE; i++) {
				if (matrix[i][j+1] == 0) {
					matrix[i][j+1] = matrix[i][j];
					matrix[i][j] = 0;
				}
			}
        }
    }

    /*junta*/
    for (j = SIZE - 1; j > 0; j--){
		for (i = 0; i < SIZE; i++){
			if (matrix[i][j] == matrix[i][j-1]) {
				matrix[i][j] += matrix[i][j-1];
				matrix[i][j-1]=0;
				score += matrix[i][j];
			}
		}
    }
    /*mexe pra direita de novo por causa dos novos valores*/
    /*for (k=0;k<3;k++){*/
	for (j = SIZE - 2; j >= 0; j--) {
		for (i = 0; i < SIZE; i++) {
			if (matrix[i][j+1] == 0) {
				matrix[i][j+1]=matrix[i][j];
				matrix[i][j]=0;
			}
		}
	}
}

void giraMatriz(int matrix[SIZE][SIZE]);
