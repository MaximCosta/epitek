/*
** EPITECH PROJECT, 2021
** Day09 task02
** File description:
** name of every function in lib
*/

#ifndef MY_H_
    #define MY_H_
    #include <fcntl.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/dir.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
typedef struct pos_s {
    int x;
    int y;
} pos_t;
typedef struct solver_s {
    char **map;
    char *file;
    bool down;
    bool top;
    bool right;
    bool left;
    pos_t pos;
    pos_t size;
} solver_t;
//? LIB
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_atoi(char *str);
bool is_number(char c);
char *my_strdup(char const *src);
int my_printf(char *format, ...);
unsigned int my_put_octal(int n);
int my_put_nbr_octal(int nb);
int my_put_nbr_unsigned(unsigned int nb);
int my_strcmp(char const *s1, char const *s2);
char *my_strndup(char const *src, int n);
char *my_strcat(char *dest, char const *src);
//? LIB
void strsplit(solver_t *sol, char c);
void load_file(char *filename, solver_t *sol);
void check_move(solver_t *sol);
void is_blocked(solver_t *sol);
void move(solver_t *sol, char s);
void move_back(solver_t *sol, char s);
void turn_right(solver_t *sol, char s);
void turn_left(solver_t *sol, char s);
void top(solver_t *sol, char s);
void down(solver_t *sol, char s);
void print_map(solver_t *sol);
void free_all(solver_t *sol);
void check_loose(solver_t *sol);
void check_win(solver_t *sol);
void print_final(solver_t *sol);
void *my_calloc(int size, int size2);
void **my_calloc2d(int nb, int size);
#endif /* !MY_H_ */
