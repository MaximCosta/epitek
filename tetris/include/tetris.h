/*
** EPITECH PROJECT, 2022
** tetris [WSL: Ubuntu]
** File description:
** tetris
*/

#ifndef TETRIS_H_
    #define TETRIS_H_
    #include <dirent.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <getopt.h>
    #include <locale.h>
    #include <ncurses.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <time.h>
    #include <unistd.h>
    #define MAX(p1, p2)  ((p1) > (p2) ? (p1) : (p2))
    #define MIN(p1, p2)  ((p1) < (p2) ? (p1) : (p2))
    #define RAND(p1, p2) (rand() % (p2 - p1 + 1) + p1)
typedef struct vec_s {
    int x;
    int y;
} vec_t;
typedef struct piece_s {
    vec_t cor;
    int piece;
    int ori;
} piece_t;
typedef struct api_s {
    char **tetrimino;
    char *name;
    int height;
    int valid;
    int width;
    int color;
} api_t;
typedef struct input_s {
    vec_t size;
    int level;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
    int next;
    int debug;
    int help;
} input_t;
typedef struct player_s {
    long int milliseconds;
    long int seconds;
    long int minutes;
    long int hours;
    int high_score;
    int score;
    int level;
    int lines;
} player_t;
typedef struct tetris_s {
    player_t *player;
    WINDOW *screen1;
    WINDOW *screen2;
    WINDOW *screen3;
    WINDOW *screen4;
    api_t **pieces;
    input_t *input;
    piece_t *piece;
    piece_t *next;
    int nb_pieces;
    clock_t time;
    clock_t old;
    char **wd;
    char *p1;
    char *p2;
    char *p3;
    int mx;
    int my;
    int sx;
    int sy;
} tetris_t;

// lib
void my_exit(int code, char *error);
void *my_calloc(size_t size1, size_t size2);
int my_strlen(char *str);
char *my_strcat(char *dest, char *src);
int isnbr(char *str);
int my_atoi(char *str);
int my_strcmp(char *str1, char *str2);
void my_putstr(char *str);
int my_strncmp(char *str1, char *str2, int n);
void **my_calloc2d(int height);
char *my_strdup(char *str);
void sort_struct_array(tetris_t *tet, int size);
char *my_strdump(char *str);
void verif_input(int args[3], int *input, char **av);
void map_size(input_t *input);
void helper(char *av[]);
int flags(char *str, int *i, va_list list);
int my_printf(char *str, ...);
void my_putchar(char c);
void my_put_nbr(int nb);
int flags(char *str, int *i, va_list list);
void verif_bool(int *input, char **av);
void init_input(input_t *input);
int check_pieces_line(char *line, int width);
char **free_return_shape(char **shape, int check);
char **check_pieces_char(FILE *fp, api_t *pieces);
int load_tetrimino_shape(FILE *fp, api_t *pieces);
int check_shape_param(char *line, api_t *pieces);
int closed_file(char *line, FILE *fp, int code);
int load_tetrimino_prop(char *filename, api_t *pieces);
int check_extension(char *file);
int count_file(char *path);
char *rm_ext(char *str);
int load_tetrimino(tetris_t *tetris, int count, DIR *dp, struct dirent *dirp);
void clear_unuzed_tetrimino(tetris_t *tetris);
int loader(tetris_t *tetris);
tetris_t *init_struct(void);
void free_all(tetris_t *tetris);
void flags_debug2(int opt, input_t *input, char **av);
void flags_debug(int opt, input_t *input, char **av);
void arguments(int ac, char **av, input_t *input);
void debug_print2(tetris_t *tetris);
void debug_print(tetris_t *tetris);
void init_ncurses(void);
void load_screen_p(tetris_t *tetris, char *filename, char **part);
void init_screen(tetris_t *tetris);
void clock_update(tetris_t *tetris);
void train_print(tetris_t *tetris, int x);
void train_tetris(tetris_t *tetris);
void get_next_piece(tetris_t *tetris);
void init_pieces(tetris_t *tetris);
void main_tetris(tetris_t *tetris);
char *remove_back(char *s);
void render_next(tetris_t *tetris);
int loop_game(tetris_t *tetris);
int game(tetris_t *tetris);
void verif_bool_rev(int *input, char **argv);
#endif /* !TETRIS_H_ */
