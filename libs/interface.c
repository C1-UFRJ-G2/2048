#include "interface.h"
#include "game.h"

extern int score, high_score;

void clear(void) {
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void printInterface(int matrix[SIZE][SIZE]) {
    /*Deve imprimir a interface do jogo, incluindo o score atual do jogador e o
    high score do jogo, que estará guardado em int high_score", a interface
    fica a escolha de quem criar essa função, mas lembre-se que ela tem ser um grid
    4x4 para comportar e em cada espaço devem caber valores de até 4 dígitos mantendo
    o alinhamento.
    */
}
