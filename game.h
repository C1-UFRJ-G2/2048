#ifndef GAME_H
#define GAME_H

#define SIZE 4

int restart(int matrix[SIZE][SIZE]);
void novoJogo(int matrix[SIZE][SIZE]);
void fimDeJogo(void);
void novoHighScore(int score);
void getHighScore(void);
void adicionaNovoValor(int matrix[SIZE][SIZE]);
int oJogoContinua(int matrix[SIZE][SIZE]);

#endif
