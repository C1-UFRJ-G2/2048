default: build

build:
	gcc -lncurses -o jogo main.c game.c interface.c controles.c handle.c

run:
	make build && ./jogo

clean:
	make build && ./jogo && rm jogo

teste:
	gcc -lncurses -o teste teste.c && ./teste && rm teste
