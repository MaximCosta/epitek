/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** All headers functions
*/

#ifndef MY_H
    #define MY_H
int char_in_str(char c, char *str);
char *concat_params(int argc, char **argv);
int get_color(unsigned char red, unsigned char green, unsigned char blue);
int is_digit(char c);
int my_advanced_sort_word_array(char **t,
    int (*c)(char const *, char const *));
int my_compute_power_it(int nb, int p);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_getnbr_base(char const *str, char const *base);
int my_isneg(int nb);
int my_nbrlen(int nb);
int my_is_prime(int nb);
int is_printable(char c);
void my_putchar_err(char c);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putnbr_base(int nbr, char const *base);
int my_putnbr_str(int nb, char *str);
char *my_putnbr_strnew(int nb);
int my_putstr_err(char const *str, int err);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
int my_show_word_array(char * const *tab);
void my_sort_int_array(int *tab, int size);
int my_sort_word_array(char **tab);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strndup(char const *src, int b, int n);
char *my_strstr(char *str, char const *to_find);
char **my_str_to_word_array(char const *str);
char *my_strupcase(char *str);
void my_swap_char(char *a, char *b);
void my_swap_string(char **str1, char **str2);
void my_swap_unsigned_char(unsigned char *a, unsigned char *b);
void my_swap(int *a, int *b);
int nbr_line_char_tab(char **words);
int swap_endian_color(int color);
#endif
