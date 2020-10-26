/*
* 2048
* Autores: Eduardo, Jorge e Matheus;
* DREs: 120047675, 120063312, 120023786;
* Testado no Windows 10 e GNU/Linux 5.9.1-arch1-1 e 4.19.101-2-lts;
* Esse software é licenciado sob licença MIT.
*/

#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>
#else
    #include <ncurses.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "controles.h"
#include "interface.h"
#include "game.h"

int main(void) {
    int matrix[SIZE][SIZE],i,j;
    extern int score, high_score;
    char controle;
    novoHighScore(100);

    printf("Entre com os numeros\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf(" %d", &matrix[i][j]);
        }
    }

    // novoJogo(matrix);
    while (oJogoContinua(matrix)) {
        printInterface(matrix);
        #if defined(_WIN32) || defined(_WIN64)
            controle = getch();
        #else
            controle = getchar();
        #endif
        
        switch (controle){
            case 'w': case 'W':
                paraCima(matrix);
            break;

            case 'a': case 'A':
                paraEsquerda(matrix);
            break;

            case 's': case 'S':
                paraBaixo(matrix);
            break;

            case 'd': case 'D':
                paraDireita(matrix);
            break;

            case '0':
                fimDeJogo();
            
            default:
                break;
        }
    }

    /*Aqui no main a gente chama todas as funções importantes, e também
    faz o switch case dos controles e demais coisas do gênero*/
    return 0;
}
