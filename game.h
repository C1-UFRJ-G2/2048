#ifndef GAME_H
#define GAME_H

#define SIZE 4

void novoHighScore(int score);
void getHighScore(void);
int oJogoContinua(int matrix[SIZE][SIZE]);
int adicionaNovosQuadrados(int matrix[SIZE][SIZE]);
int restart(int matrix[SIZE][SIZE]);

#endif
