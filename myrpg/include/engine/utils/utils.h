/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef UTILS_H
    #define UTILS_H
    #include <stdlib.h>

void *my_memcpy(void *dest, const void *src, unsigned int bytes);

void *my_realloc(void *ptr, size_t old_size, size_t size);

char *my_strdup(char *src);

char *my_strcat_char(char *dest, char src);

char *my_strcpy(char *dest, char const *src);

char *my_strcat(char *dest, char *src);

char **to_2d_array(char *str);

int my_strlen(char *str);

bool equal(char *s1, char *s2);

char *my_itoa(int number, int space);

sfVector2f i_to_f(sfVector2i val);

int my_getnbr(char *str);

int charnfind(char *str, char find);

bool charfind(char *str, char find);

bool nequal(char *s1, char *s2, int n);

int strnfind(char *str, char *find);

bool strfind(char *str, char *find);

void *my_calloc(size_t size);

int get_index(char *str, char c);
int my_strcmp(char *s1, char *s2);

#endif // UTILS_H
