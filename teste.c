#include <stdio.h>
#include <ncurses.h>

int main(void) {
    int x, y;
    initscr();
    getmaxyx(stdscr, x, y);
    endwin();
    printf("%d %d\n", x, y);
    return 0;
}