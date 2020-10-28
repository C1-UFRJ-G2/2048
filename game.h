#ifndef GAME_H
#define GAME_H

#define SIZE 4

short int restart(short int matrix[SIZE][SIZE], int win);
void novoJogo(short int matrix[SIZE][SIZE]);
void fimDeJogo(void);
void novoHighScore(void);
void getHighScore(void);
void adicionaNovoValor(short int matrix[SIZE][SIZE]);
short int oJogoContinua(short int matrix[SIZE][SIZE]);

#endif
