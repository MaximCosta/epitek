/*
** EPITECH PROJECT, 2021
** my_printf (copy of printf libC function)
** File description:
** Does almost what printf can do
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

char flag_finder(char **format, char flags[11][1])
{
    char stock = 'a';
    int counter2 = 0;

    while (*format) {
        counter2 = 0;
        while (flags[counter2][0] && flags[counter2][0] != *format[0])
            counter2 += *format[0] != flags[counter2][0] ? 1 : 0;
        *format += 1;
        stock = *format[0];
        if (counter2 != 10 || stock == '\0')
            break;
    }
    return stock;
}

void flag_check(char stock, va_list list)
{
    switch (stock)
    {
        case 'c':
            my_putchar(va_arg(list, int));
            break;
        case 's':
            my_putstr(va_arg(list, char *));
            break;
        case 'd': case 'i':
            my_put_nbr(va_arg(list, int));
            break;
        case 'o':
            my_put_octal(va_arg(list, int));
            break;
        case 'u':
            my_put_nbr_unsigned(va_arg(list, unsigned int));
            break;
        case '%':
            my_putchar(stock);
            break;
    }
}

int my_printf(char *format, ...)
{
    char stock = 'a';
    char flags[11][1] = {"c", "d", "e", "E", "i", "u", "s", "x", "X", "%", 0};
    va_list list;

    va_start(list, format);
    while (format[0]) {
        if (format[0] == '%') {
            stock = flag_finder(&format, flags);
            flag_check(stock, list);
        } else
            write(1, format, 1);
        format += 1;
    }
    return 0;
}
