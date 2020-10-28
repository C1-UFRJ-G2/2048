default: build

build:
	@$(CC) $(C_FLAGS) $(C_FILES) -o $(TARGET)

run:
	@[ -f $(TARGET) ] && ./$(TARGET) || echo "Realize o build do jogo primeiramente"

clean:
	@[ -f $(TARGET) ] && rm $(TARGET) || exit

TARGET=2048

CC=gcc

C_FILES=src/main.c      \
		src/game.c      \
		src/interface.c \
		src/controles.c	\
		src/handle.c

C_FLAGS=-lncurses  \
		-O2		   \
        -W         \
        -Wall      \
        -ansi      \
        -pedantic
