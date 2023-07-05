/*
** EPITECH PROJECT, 2022
** sokoban [WSL: Ubuntu]
** File description:
** my
*/
#ifndef MY_H_
    #define MY_H_
    #include <curses.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>
    #include <unistd.h>
    #include <sys/param.h>
typedef struct game_s {
    char **maps;
    int *boxs;
    int *boys;
    int box;
    int w;
    int h;
    int px;
    int py;
} game_t;
void loop_main(game_t *game, char *argv[]);
void maps_condi(game_t *game, int i, int j, int *bi);
void print_condi(game_t *game, int y);
int my_strcmp(char const *s1, char const *s2);
void countlines(char *filename, game_t *game);
void check_chr(char c);
void **my_calloc_2d(int type, int size);
void *my_calloc(int type, int r, int size);
void my_exit_ncurses(int code);
int get_box(int x, int y, game_t *game);
int verif_move(int x, int y, game_t *g);
int my_getchr(game_t *game);
void print_map(game_t *game);
void init(void);
void get_maps(game_t *game, char *filename);
game_t *load_game(char *argv[]);
int check_win(game_t *game);
int main(int args, char *argv[]);
bool check_space(char s);
bool check_loose1(int x, int y, game_t *g);
void check_loose(game_t *game);
#endif /* !MY_H_ */
