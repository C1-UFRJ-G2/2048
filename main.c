/*
* 2048
* Autores: Eduardo, Jorge e Matheus;
* DREs: 120047675, 120063312, 120023786;
* Testado no GNU/Linux 5.9.1-arch1-1 e 4.19.101-2-lts;
* Esse software é licenciado sob licença MIT.
*/

<<<<<<< HEAD
#include <ncurses.h>
=======

/*#if defined(_WIN32) || defined(_WIN64)*/
    #include <conio.h>
/*#else
    #include <ncurses.h>
#endif*/

>>>>>>> origin/main
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

    signal(SIGINT, killHandle);
    signal(SIGTSTP, killHandle);

    novoJogo(matrix);
    verificaTamanhoDoTerminal();

    while (oJogoContinua(matrix)) {
        printInterface(matrix);
<<<<<<< HEAD
        controle = getch();

        refresh();
=======
        /*#if defined(_WIN32) || defined(_WIN64)*/
            controle = getch();
       /* #else
            controle = getchar();
        #endif*/
        
>>>>>>> origin/main
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
