/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-kilyan.cotten
** File description:
** my_printf.h
*/

#ifndef PRINTF_H
    #define PRINTF_H

    #include <stdio.h> //! To supress
    #include <stdarg.h>
    #include <unistd.h>
    #include <stdlib.h>

//! PRINTF

typedef struct printf_s {
    va_list *arg;
    char *format;
    int len_f;
    int n;
    int c;
} printf_t;

typedef struct flag_s {
    char c;
    void (*func)(printf_t *pr);
} flag_t;

typedef struct len_flag_s {
    char c;
    int (*func)(printf_t *pr);
} len_flag_t;

int my_printf(char *format, ...);
void do_flags(printf_t *pr);
void error(printf_t *pr);

//! FLAGS

void flag_c(printf_t *pr);
void flag_i(printf_t *pr);
void flag_s(printf_t *pr);
void flag_o(printf_t *pr);
void flag_x(printf_t *pr);
void flag_xm(printf_t *pr);
void flag_b(printf_t *pr);
void flag_u(printf_t *pr);
void flag_p(printf_t *pr);
void flag_sm(printf_t *pr);
void flag_plus(printf_t *pr);
void flag_purcent(printf_t *pr);
void flag_hash(printf_t *pr);
void flag_minus(printf_t *pr);
void flag_zero(printf_t *pr);
void flag_number(printf_t *pr);

//! LEN_FLAG

int len_flags(printf_t *pr);

int len_flag_c(printf_t *pr);
int len_flag_i(printf_t *pr);
int len_flag_s(printf_t *pr);
int len_flag_o(printf_t *pr);
int len_flag_x(printf_t *pr);
int len_flag_xm(printf_t *pr);
int len_flag_b(printf_t *pr);
int len_flag_u(printf_t *pr);
int len_flag_p(printf_t *pr);
int len_flag_sm(printf_t *pr);

//! LIB

int my_strlen(char const *s);
int my_putchar(char c);
int my_putstr(char *s);
int my_putnbr_base(long long int n, char const *base_tab, int minus);
int my_putunbr_base(unsigned long long int n, char const *base_tab);

int len_nbr(long long int n, int minus);
int len_unbr(unsigned long long int n, char *base);

#endif /* PRINTF_H */
