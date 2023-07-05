/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-evalexpr-flavio.moreno
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <stdarg.h>

//? printf
int my_printf(char *format, ...);

//? LibMY
char *my_strdup(char const *str);
char **my_str_to_word_array(char const *str);
int my_show_word_array(char * const *tab);

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
char *str_ndup(char const *str, int n);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);

int is_letter(char c);
int is_lower(char c);
int is_number(char c);

int get_nbr_get_start(char const *str);
int get_index(char const *str, char c);
int get_start(char const *str);
int is_equal(char c);
int my_getnbr_base(char const *str, char const *base_tab);
int my_putnbr_base(int n, char const *base_tab);

void *my_calloc(size_t size);

#endif /* MY_H*/
