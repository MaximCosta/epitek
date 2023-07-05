/*
** EPITECH PROJECT, 2021
** Day09 task02
** File description:
** name of every function in lib
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/dir.h>
    #include <sys/wait.h>
    #include <stddef.h>
    #include <time.h>

typedef struct generator_s {
    int **map;
    int width;
    int height;
} generator_t;

// * maze
generator_t *init_struct(int width, int height);
void free_all(generator_t *maze);

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
char *my_itoa(char *d, int n);
//? LIB

#endif/* !MY_H_ */
