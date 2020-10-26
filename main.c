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
    //#include <ncurses.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "controles.h"
#include "interface.h"
#include "game.h"
#include "handle.h"

int main(void) {
    int matrix[SIZE][SIZE];
    char controle;
    signal(SIGINT, killHandle);
    // printf("Entre com os numeros\n");
    // for (i = 0; i < SIZE; i++) {
    //     for (j = 0; j < SIZE; j++) {
    //         scanf(" %d", &matrix[i][j]);
    //     }
    // }

    novoJogo(matrix);
    while (oJogoContinua(matrix)) {
        printInterface(matrix);
        #if defined(_WIN32) || defined(_WIN64)
            controle = getch();
        #else
            controle = getchar();
        #endif
        
        switch (controle){
            case 'w': case 'W':
                if (paraCima(matrix))
                    adicionaNovoValor(matrix);
            break;

            case 'a': case 'A':
                if (paraEsquerda(matrix))
                    adicionaNovoValor(matrix);
            break;

            case 's': case 'S':
                if (paraBaixo(matrix))
                    adicionaNovoValor(matrix);
            break;

            case 'd': case 'D':
                if (paraDireita(matrix))
                    adicionaNovoValor(matrix);
            break;

            case '0':
                fimDeJogo();
                exit(0);
            
            case EOF:
                fprintf(stderr, "Código de Erro 1: Usuário entrou EOF pelo teclado\n");
                exit(1);
            default:
                break;
        }
    }

    fimDeJogo();
    return 0;
}
