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

#endif/* !MY_H_ */
