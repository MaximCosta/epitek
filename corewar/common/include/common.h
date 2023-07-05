/*
** EPITECH PROJECT, 2021
** template
** File description:
** template
*/

#ifndef COMMON_H
    #define COMMON_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <time.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include "op.h"
    #include "list/list.h"

// UTILS
int my_strcmp(char const *s1, char const *s2);
int my_printf(char *str, ...);
void my_putnbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strcat_malloc(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strdup(char const *src);
bool has_file_extension(char *file_name, char *extension);
char *lstrip(char *str);
char *rstrip(char *str);
char *remove_after_char(char *str, char c);
char **split(char *str, char *delim);
int my_strncmp(char *s1, char *s2, int n);
void *my_calloc(size_t size);
char *my_strcat_char_malloc(char **dest, char src);
void free_2d_array(char **array);
char *my_strndup(char const *src, int n);
int is_little_endian(void);
long long int little_to_big_endian(long long int x);
char *my_itoa(int nb, int base);
char *my_revstr(char *str);
bool str_contains(char *str, char c);
int my_getnbr(char const *str);
int count_2d_array_size(char **array);
bool str_contains_only_number(char *str);
int bin_to_dec(char *bytes);
long long int my_getnbr_long(char const *str);
bool is_char_delimiter(char c, char *delimiters);
char *get_next_word(char *str, char *delim, int i);
void exit_if_condition(bool condition, int code);
long long int swap_int32(long long int n);

#endif // COMMON_H
