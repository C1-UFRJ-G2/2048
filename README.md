# 2048
Uma versão do jogo 2048 feita usando ncurses como projeto final da matéria Computação I

# Tabela de conteúdo

- [Como Jogar](#como-jogar)
- [Dependências](#dependências)
  - [Debian](#debian-e-derivados)
  - [Arch](#arch-linux-e-derivados)
  - [Fedora](#fedora-e-derivados)
- [Compilação](#compilação)
- [Execução](#execução)
- [Troubleshooting](#troubleshooting)
  - [Interface](#interface)
  - [Build](#build)

# Como Jogar

O jogo consiste em um grid 4x4 e começa com dois valores, podendo cada um ser 2 ou 4, aleatoriamente. Você pode pressionar W para mover todos os valores o máximo possível para cima, S para baixo, A para esquerda ou D para a direita. Se durante o movimento dois valores iguais se tocarem, eles se tornam um só valor equivalente a sua soma. Todo movimento realizado adiciona um novo valor ao grid se houver espaço para tal, estes valores podendo ser 2 ou 4, aleatoriamente. O objetivo do jogo é conseguir um valor igual a 2048 no grid e você perde caso preencha o grid 4x4 e não hajam mais movimentos possíveis

# Dependências
```
gcc
make
ncurses
```
### Debian e derivados

`sudo apt-get install libncurses5-dev gcc make`

### Arch Linux e derivados
`sudo pacman -S make gcc ncurses`

### Fedora e derivados
 `yum install gcc make ncurses`

# Compilação
```
git clone https://github.com/C1-UFRJ-G2/Trabalho-1-de-Comp-1-2020-PLE---2048 2048
cd 2048
make ou gcc -lncurses -O2 -Wall -ansi -pedantic -Wno-unused-result src/*.c -o 2048
```

# Execução
Tendo compilado

`make run` ou `./2048`

# Troubleshooting

### Interface

Caso você experiencie problemas com a sua interface, significa que seu OS não está preparado para receber caracteres unicode, quando executar o jogo utilize a flag "--no-unicode" e uma interface sem caracteres unicode será disponibilizada Ex: `./2048 --no-unicode`

### Build

Os gerenciadores de pacotes instalam a biblioteca ncurses de maneira inconstante, caso o makefile não seja capaz de acessar a biblioteca já instalada (veja [dependências](#dependências)), utilize o comando `gcc -lncurses -O2 -Wall -ansi -pedantic -Wno-unused-result src/*.c -o 2048`.
