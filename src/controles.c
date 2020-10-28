#include "controles.h"

extern unsigned int score;

/*Realiza o movimento para cima caso os controles w ou KEY_UP sejam ativados
e retorna > 0 caso ocorra um movimento ou 0 caso não ocorra nenhum movimentos*/
short int paraCima(short int matrix[SIZE][SIZE]) {
    short int i, j, k, movimentos = 0;
	/*Primeiro movimento para cima, até que o valor encontre outro valor diferente de 0*/
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

    /*junta valores que se tocaram*/
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

    /*mexe pra cima de novo por causa dos novos valores formados*/
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

/*Realiza o movimento para baixo caso os controles s ou KEY_DOWN sejam ativados
e retorna > 0 caso ocorra um movimento ou 0 caso não ocorra nenhum movimentos*/
short int paraBaixo(short int matrix[SIZE][SIZE]) {
	short int i, j, k, movimentos = 0;
	/*Primeiro movimento para baixo, até que o valor encontre outro valor diferente de 0*/
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

    /*junta valores que se tocaram*/
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

    /*mexe pra baixo de novo por causa dos novos valores formados*/
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

/*Realiza o movimento para esquerda caso os controles a ou KEY_LEFT sejam ativados
e retorna > 0 caso ocorra um movimento ou 0 caso não ocorra nenhum movimentos*/
short int paraEsquerda(short int matrix[SIZE][SIZE]) {
	/*Primeiro movimento para cima, até que o valor encontre outro valor diferente de 0*/
	short int i, j, k, movimentos = 0;
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

    /*junta valores que se tocaram*/
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

    /*mexe pra esquerda de novo por causa dos novos valores formados*/
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

/*Realiza o movimento para direita caso os controles d ou KEY_RIGHT sejam ativados
e retorna > 0 caso ocorra um movimento ou 0 caso não ocorra nenhum movimentos*/
short int paraDireita(short int matrix[SIZE][SIZE]) {
	/*Primeiro movimento para direita, até que o valor encontre outro valor diferente de 0*/
	short int i, j, k, movimentos = 0;
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

    /*junta valores que se tocaram*/
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

    /*mexe pra direita de novo por causa dos novos valores formados*/
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
