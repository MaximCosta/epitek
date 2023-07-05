/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** print_f
*/

#include "my_printf.h"

void (*entries[172])(char *arg, va_list ap, int index, str_struct_t *str_t);

str_struct_t *init_str_t(void)
{
    str_struct_t *str_t = malloc(sizeof(str_struct_t));

    str_t->hash = 0;
    str_t->unsign = 0;
    str_t->longs = 0;
    str_t->shorts = 0;
    str_t->width = 0;
    str_t->width_par = 0;
    str_t->precision = 0;
    str_t->precision_par = 0;
    return str_t;
}

int get_letter(str_struct_t *str_t, char letter)
{
    switch (letter) {
        case 'h':
            return 0;
        case 'l':
            str_t->longs += 1;
            return 0;
        case 'u':
            str_t->unsign += 1;
            return 0;
        case '#':
            str_t->hash += 1;
            return 0;
        default:
            return 1;
    }
}

int param_use(char *buf, va_list ap, int i)
{
    int diff = i;
    str_struct_t *str_t = init_str_t();
    while (1) {
        i++;
        if (entries[(int)buf[i]] != NULL) {
            entries[(int)buf[i]](buf, ap, i, str_t);
            free(str_t);
            return i;
        }
        if (buf[i] == '\0' || (get_letter(str_t, buf[i]) && (ALPHA(buf[i]))))
            break;
    }
    my_putchar('%');
    free(str_t);
    return diff;
}

void my_printf(char *buf, ...)
{
    va_list ap;
    dictionary();
    va_start(ap, buf);
    for (int i = 0; buf[i]; i++) {
        if (buf[i] == '%')
            i = param_use(buf, ap, i);
        else
            my_putchar(buf[i]);
    }
    va_end(ap);
}

void dictionary(void)
{
    entries['s'] = string_print;
    entries['S'] = string_sp_print;
    entries['c'] = char_print;
    entries['i'] = nbr_print;
    entries['d'] = nbr_print;
    entries['u'] = nbr_print;
    entries['x'] = nbr_base16x_print;
    entries['p'] = nbr_base16x_point;
    entries['X'] = nbr_base16X_print;
    entries['o'] = nbr_base8_print;
    entries['b'] = nbr_base2_print;
    entries['%'] = modulo_print;
}