/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** libstr.h
*/

#ifndef LIBSTR_H
    #define LIBSTR_H

    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "utils.h"

    #define MIN(a, b) ((a) < (b) ? (a) : (b))
    #define MAX(a, b) ((a) > (b) ? (a) : (b))

    #define CSTR(x) x->str

typedef struct str_s str_t;

struct str_s {
    char *str;
    int len;
    int size;
};

str_t *str_create(char const *str);
void str_destroy(str_t *str);
str_t *str_create_size(int size);

str_t *str_create_from_file(char const *path);
str_t *str_create_from_fd(int fd);

str_t *str_dup_cstr(char const *str);
str_t *str_ndup_cstr(char const *str, int size);

void str_add_char(str_t *str, char c);
    #define str_add_chr(str, c) str_add_char(str, c)
void str_push_char(str_t *str, char c);
    #define str_push_chr(str, c) str_push_char(str, c)

void str_add_char_pos(str_t *str, char c, int pos);
    #define str_add_chr_pos(str, c, pos) str_add_char_pos(str, c, pos)

void str_add_str(str_t *str, str_t *add);
void str_add_cstr(str_t *str, char const *add);

void str_add_nstr(str_t *str, str_t *add, size_t size);
void str_add_ncstr(str_t *str, char const *add, size_t size);

void str_resize(str_t *str, int size);

void str_clear(str_t *str);

void str_add_char_pos(str_t *str, char c, int pos);

void str_add_nbr(str_t *str, int nbr);
void str_add_float(str_t *str, float nbr, int precision);

char str_remove_last(str_t *str);

void str_remove_char_pos(str_t *str, int pos);

#endif /* LIBSTR_H */