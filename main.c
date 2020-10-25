/*
* 2048
* Autores: Eduardo, Jorge e Matheus;
* DREs: 120047675, 120063312, 120023786;
* Testado no Windows 10 e GNU/Linux 5.9.1-arch1-1 e 4.19.101-2-lts;
* Esse software é licenciado sob licença MIT.
*/

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

    while (1) {
        printInterface(matrix);
        controle = getchar();
        switch(controle){
            case 'w':
                paraCima(matrix);
            break;

            case 'a':
                paraEsquerda(matrix);
            break;

            case 's':
                paraBaixo(matrix);
            break;

            case 'd':
                paraDireita(matrix);
            break;

            case '0':
                exit(0);
            
            default:
                break;
        }
    }

    /*Aqui no main a gente chama todas as funções importantes, e também
    faz o switch case dos controles e demais coisas do gênero*/
    return 0;
}
