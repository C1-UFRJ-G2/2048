default: build

build:
	@$(CC) $(C_FLAGS) $(C_FILES) -o $(TARGET)

run:
	@[ -f $(TARGET) ] && ./$(TARGET) || echo "Realize o build do jogo primeiramente"

clean:
	@[ -f $(TARGET) ] && rm $(TARGET) || exit

teste: 
	@$(CC) $(C_FLAGS) teste.c -o teste

TARGET=2048

CC=gcc

C_FILES=main.c      \
		game.c      \
		interface.c \
		controles.c	\
		handle.c

C_FLAGS=-lncurses  \
		-O2		   \
        -W         \
        -Wall      \
        -ansi      \
        -pedantic