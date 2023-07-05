/*
** EPITECH PROJECT, 2022
** duostumper05
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef MY_H_
    #define MY_H_
    #define MAX(x, y) (x > y ? x : y)
typedef struct game_s {
    char **board;
    char pl[2];
    int size;
} game_t;
int check_win_line(game_t *gm, int y, int x, char p);
int check_win_diag(game_t *gm, int y, int x, char p);
int check_win_hori(game_t *gm, int y, int x, char p);
int check_win_rev_diag(game_t *gm, int y, int x, char p);
int check_win2(game_t *gm, int x, int y);
int check_win(game_t *gm);
void board_template(game_t *game);
void put_pl(game_t *game, int x, int y);
void print_board(game_t *gm);
game_t *check_args(int ac, char *av[]);
void init_board(game_t *game);
void free_all(game_t *game);
int is_digit(char *str);
int main(int ac, char *av[]);
#endif
