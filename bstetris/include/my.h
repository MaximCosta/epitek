/*
** EPITECH PROJECT, 2022
** Makedossier
** File description:
** my
*/

#ifndef MY_H_
	#define MY_H_
	#include <stdarg.h>
	#include <stdio.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <unistd.h>
	#include <assert.h>
	#include <string.h>
	#include <dirent.h>
	#include <stdlib.h>
	#include <pwd.h>
	#include <time.h>
	#include <errno.h>
	#include <ncurses.h>
	#include <fcntl.h>
	#include <signal.h>

void my_printf(char *str, ...);

void my_putchar(char c);

void my_putstr(char *str);

void my_put_nbr(int nb);

int my_getnbr(char const *str);

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest , char const *src, int n);

char *my_strcat(char *dest, char const *str);

char *my_strncat(char *dest , char const *src , int nb);

char *fill_in(int size);

char *destroy_string(char *str);

#endif /* !MY_H_ */
