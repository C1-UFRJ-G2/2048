#include "controles.h"

extern unsigned int score;

/*Os nomes são bem auto-explicativos, só faz ai*/
short int paraCima(short int matrix[SIZE][SIZE]) {
/* sobe de cima p baixo, junta de cima pra baixo e sobe:
joga todo mundo pra cima começando pela linha 1, o debaixo vira zero;
avalia pela linha 0 ate 2 (inclusive) se o de baixo é igual, aí multiplica e o de baixo vira 0;*/
    short int i, j, k, movimentos = 0;  /*3*3*4 + 3*4+ 3*4=60 vezes*/
    for (k = 0; k < SIZE - 1; k++) {
        for (i = 1; i < SIZE; i++) {
			for (j = 0;j < SIZE; j++) {
				if (matrix[i][j] != 0 && matrix[i - 1][j] == 0) {
					matrix[i - 1][j] = matrix[i][j];
					matrix[i][j] = 0;
					movimentos++;
				}
			}
        }
    }

    /*junta*/
    for (i = 0; i < SIZE - 1; i++) {
		for (j = 0; j < SIZE; j++) {
			if (matrix[i][j] != 0 && matrix[i][j] == matrix[i + 1][j]) {
				matrix[i][j] += matrix[i + 1][j];
				matrix[i + 1][j] = 0;
				score += matrix[i][j];
				movimentos++;
			}
		}
    }
    /*mexe pra cima de novo por causa dos novos valores*/
    if (movimentos > 0) {
		for (i = 1; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				if(matrix[i][j] != 0 && matrix[i - 1][j] == 0) {
					matrix[i - 1][j] = matrix[i][j];
					matrix[i][j] = 0;
				}
			}
		}
	}
	return movimentos;
}

short int paraBaixo(short int matrix[SIZE][SIZE]) {
	short int i, j, k, movimentos = 0; /*3*3*4 + 3*4+ 3*4=60 vezes*/
    for (k = 0; k < SIZE - 1; k++) {
        for (i = SIZE - 2; i >= 0; i--) {
			for (j = 0; j < SIZE; j++) {
				if (matrix[i][j] != 0 && matrix[i + 1][j] == 0) {
					matrix[i + 1][j] = matrix[i][j];
					matrix[i][j] = 0;
					movimentos++;
				}
			}
        }
    }

    /*junta*/
	for (i = SIZE - 1; i > 0; i--) {
		for (j = 0; j < SIZE; j++) {
			if (matrix[i][j] != 0 && matrix[i][j] == matrix[i - 1][j]) {
				matrix[i][j] += matrix[i - 1][j];
				matrix[i - 1][j] = 0;
				score += matrix[i][j];
				movimentos++;
			}
		}
	}

    /*mexe pra baixo de novo por causa dos novos valores*/
	if (movimentos > 0) {
		for (i = SIZE - 2; i >= 0; i--) {
			for (j = 0; j < SIZE; j++) { 
				if (matrix[i][j] != 0 && matrix[i + 1][j] == 0) {
					matrix[i + 1][j] = matrix[i][j];
					matrix[i][j] = 0;
				}
			}
		}
	}
	return movimentos;
}

short int paraEsquerda(short int matrix[SIZE][SIZE]) {
	short int i, j, k, movimentos = 0; /*3*3*4 + 3*4+ 3*4=60 vezes*/
    for (k = 0; k < SIZE - 1; k++) {
        for (j = 1; j < SIZE; j++) {
			for (i = 0; i < SIZE; i++) {
				if (matrix[i][j] != 0 && matrix[i][j - 1] == 0) {
					matrix[i][j - 1] = matrix[i][j];
					matrix[i][j] = 0;
					movimentos++;
				}
			}
        }
    }

    /*junta*/
    for (j = 0; j < SIZE - 1; j++) {
		for (i = 0; i < SIZE; i++) {
			if (matrix[i][j] != 0 && matrix[i][j] == matrix[i][j + 1]) {
				matrix[i][j] += matrix[i][j + 1];
				matrix[i][j + 1] = 0;
				score += matrix[i][j];
				movimentos++;
			}
		}
    }
    /*mexe pra esquerda de novo por causa dos novos valores*/
	if (movimentos > 0) {
		for (j = 1; j < SIZE; j++) {
			for (i = 0;i < SIZE; i++) {
				if (matrix[i][j] != 0 && matrix[i][j - 1] == 0) {
					matrix[i][j - 1] = matrix[i][j];
					matrix[i][j] = 0;
				}
			}
		}
	}
	return movimentos;
}

short int paraDireita(short int matrix[SIZE][SIZE]) {
	/*anda p direita da direita p esquerda, junta da direita p esquerda e anda:*/
	short int i, j, k, movimentos = 0;	/*3*3*4 + 3*4+ 3*4=60 vezes*/
    for (k = 0; k < SIZE - 1; k++) {
        for (j = SIZE - 2; j >= 0; j--) {
			for (i = 0; i < SIZE; i++) {
				if (matrix[i][j] != 0 && matrix[i][j + 1] == 0) {
					matrix[i][j + 1] = matrix[i][j];
					matrix[i][j] = 0;
					movimentos++;
				}
			}
        }
    }

    /*junta*/
    for (j = SIZE - 1; j > 0; j--) {
		for (i = 0; i < SIZE; i++) {
			if (matrix[i][j] != 0 && matrix[i][j] == matrix[i][j - 1]) {
				matrix[i][j] += matrix[i][j - 1];
				matrix[i][j - 1] = 0;
				score += matrix[i][j];
				movimentos++;
			}
		}
    }
    /*mexe pra direita de novo por causa dos novos valores*/
	if (movimentos > 0) {
		for (j = SIZE - 2; j >= 0; j--) {
			for (i = 0; i < SIZE; i++) {
				if (matrix[i][j] != 0 && matrix[i][j + 1] == 0) {
					matrix[i][j + 1] = matrix[i][j];
					matrix[i][j] = 0;
				}
			}
		}
	}
	return movimentos;
}
