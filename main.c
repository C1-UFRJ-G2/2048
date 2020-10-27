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
#include <locale.h>
#include "controles.h"
#include "interface.h"
#include "game.h"
#include "handle.h"

int main(void) {
    static int matrix[SIZE][SIZE];
    char controle;

    setlocale(LC_ALL, ""); /* Para poder imprimir os caracteres acentuados corretamente */

    /* Impede que o jogo pare sem desativar a interface, desativando o comportamento
    padrão do Ctrl + C e do Ctrl + Z*/
    signal(SIGINT, killHandle);
    signal(SIGTSTP, killHandle);

    novoJogo(matrix);
    verificaTamanhoDoTerminal();

    /*Enquanto a função oJogoContinua continuar retornando true, imprime a interface de jogo
    e recebe input de novos movimentos*/
    while (oJogoContinua(matrix)) {
        printInterface(matrix);
        controle = getch();
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
                return 0;
            
            default:
                break;
        }
    }

    /*Encerra o processo do jogo caso não tenha sido feito anteriormente, 
    geralmente o programa será encerrado antes de chegar aqui*/
    fimDeJogo();
    return 0;
}
