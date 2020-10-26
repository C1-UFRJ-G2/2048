default: build

build:
	gcc -Wall -o jogo main.c game.c interface.c controles.c handle.c -lncurses

run:
	make build && ./jogo

clean:
	make build && ./jogo && rm jogo

teste:
	gcc -o teste teste.c -lncurses && ./teste && rm teste
