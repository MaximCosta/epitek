/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>
    #define ALPHA(x) ('A' <= x && x <= 'Z') || ('a' <= x && x <= 'z')
typedef struct {
    int hash;
    int unsign;
    int longs;
    int shorts;
    int width;
    int width_par;
    int precision;
    int precision_par;
} str_struct_t;
void my_putchar(char c);
long long int my_put_nbr_pf(long long int nb);
long long int my_putnbr_base_pf(long long int nbr, char const *base);
int my_strncmp(char const* s1, char const* s2, int n);
int my_putstr(char const *str);
int param_use(char *buf, va_list ap, int i);
void my_printf(char *buf, ...);
void dictionary(void);
int my_strlen(char const *str);
void string_print(char *arg, va_list ap, int index, str_struct_t *str_t);
void string_sp_print(char *arg, va_list ap, int index, str_struct_t *str_t);
void char_print(char *arg, va_list ap, int index, str_struct_t *str_t);
void nbr_print(char *arg, va_list ap, int index, str_struct_t *str_t);
void nbr_base16x_print(char *arg, va_list ap, int index, str_struct_t *str_t);
void nbr_base16x_point(char *arg, va_list ap, int index, str_struct_t *str_t);
void nbr_bas16mx_print(char *arg, va_list ap, int index, str_struct_t *str_t);
void nbr_base8_print(char *arg, va_list ap, int index, str_struct_t *str_t);
void nbr_base2_print(char *arg, va_list ap, int index, str_struct_t *str_t);
void modulo_print(char *arg, va_list ap, int index, str_struct_t *str_t);
int my_showstr_octal(char *str);
void nbr_octal_print(int octal);
int convert_octal(int dec);
#endif
