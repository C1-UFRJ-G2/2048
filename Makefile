default: build

build:
	gcc -o jogo main.c game.c interface.c controles.c

clean:
	rm jogo
