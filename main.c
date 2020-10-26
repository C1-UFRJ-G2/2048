/*
* 2048
* Autores: Eduardo, Jorge e Matheus;
* DREs: 120047675, 120063312, 120023786;
* Testado no GNU/Linux 5.9.1-arch1-1 e 4.19.101-2-lts;
* Esse software é licenciado sob licença MIT.
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "controles.h"
#include "interface.h"
#include "game.h"
#include "handle.h"

int main(void) {
    static int matrix[SIZE][SIZE];
    char controle;
    signal(SIGINT, killHandle);
    signal(SIGTSTP, killHandle);

    novoJogo(matrix);
    verificaTamanhoDoTerminal();

    while (oJogoContinua(matrix)) {
        printInterface(matrix);
        controle = getch();

        refresh();
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
            
            default:
                break;
        }
    }

    fimDeJogo();
    return 0;
}
