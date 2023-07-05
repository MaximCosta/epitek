/*
** EPITECH PROJECT, 2021
** include/my
** File description:
** first header
*/

#define NUM(x) (x - '0')
#define ASC(x) (x + '0')
#define ISD(x) ('0' <= x && x <= '9')
#define POW(x) (x * 10)

#ifndef FOO_H_
    #define FOO_H_

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *str);
int find_minimum(float a[], int n);
int my_putnbr_base(int nbr, char const *base);
int my_max(int s1, int s2);
int my_min(int s1, int s2);
int my_abs(int val);
void my_strswap(char **str1, char **str2);
void *my_calloc(int type, int r, int size);
int my_strtol(char **str);
#endif
