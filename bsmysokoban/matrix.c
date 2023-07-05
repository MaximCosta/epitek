#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

// STEP 1 fill init() function
// STEP 2 fill exit_matrix() function
// STEP 3 fill matrix_getchr() function
// STEP 4 fill writecolumn() function

void exit_matrix(void)
{
    erase();
    endwin();
    exit(0);
}

void matrix_getchr(void)
{
    if (getch() == ' ')
        exit_matrix();
}

void init(void)
{
    initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    noecho();
    cbreak();
    start_color();
    init_pair(1,COLOR_GREEN, COLOR_BLACK);
}

void writecolumn(int ascii_range)
{
    struct timespec start;
    struct timespec end;
    int ascii_char = 0;
    int vertical_length = rand() % 80 + 20;
    int basex = rand() % COLS + 20;
    int basey = 0;

    start.tv_sec = 0;
    for (int counter = 0; counter < vertical_length ;counter++) {
        matrix_getchr();
        start.tv_nsec = 50000000;
        ascii_char = rand() % ascii_range + 32;
        attron(COLOR_PAIR(1) | A_BOLD);
        mvaddch(basey, basex, ascii_char);
        attroff(A_BOLD | A_UNDERLINE);
        refresh();
        if (nanosleep(&start, &end) < 0)
            exit_matrix();
        basey++;
        if (basey > LINES)
            break;
    }
}

int main()
{
    init();
    while (1) {
        matrix_getchr();
        writecolumn(127);
    }
    exit_matrix();
}
