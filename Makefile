default: build

build:
	gcc -Wall -o jogo main.c game.c interface.c controles.c

clean:
	rm jogo
