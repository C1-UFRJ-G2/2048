# 2048
Um clone do jogo 2048 feito usando ncurses como projeto final da matéria Computação I

# Tabela de conteúdo

- [Como Jogar](#como-jogar)
- [Dependências](#dependências)
  - [Debian](#debian-e-derivados)
  - [Arch](#arch-linux-e-derivados)
  - [Fedora](#fedora-e-derivados)
- [Instalação](#instalação)

# Como Jogar

O jogo consiste em um grid 4x4 e começa com dois valores, podendo cada um ser 2 ou 4, você pode pressionar W para mover todos os valores o máximo possível para cima, S para baixo, A para esquerda ou D para a direita. Se durante o movimento dois valores iguais se tocarem, eles se tornam em um só valor equivalente a sua soma. O objetivo do jogo é chegar a 2048 e você perde caso preencha o grid 4x4 e não hajam mais movimentos possíveis

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

# Instalação
```
git clone https://github.com/C1-UFRJ-G2/2048.git
cd 2048
make
```
