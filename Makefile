default: build

build:
	$(CC) $(C_FLAGS) $(C_FILES) $(TARGET)

run:
	make build && ./jogo

clean:
	make build && ./jogo && rm jogo

teste:
	gcc -lncurses -o teste teste.c && ./teste && rm teste

TARGET=-o jogo

CC=gcc

C_FILES=main.c      \
		game.c      \
		interface.c \
		controles.c	\
		handle.c

C_FLAGS=-lncurses  \
        -W         \
        -Wall      \
        -ansi      \
        -pedantic