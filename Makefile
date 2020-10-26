default: build

build:
	gcc -Wall -o jogo main.c game.c interface.c controles.c handle.c

clean:
	rm jogo
