/*
** EPITECH PROJECT, 2022
** tetris [WSL: Ubuntu]
** File description:
** lib
*/

#include "../include/tetris.h"

void map_size(input_t *input)
{
    char *str = my_strdup(optarg);
    char *sy = strtok(str, ",");
    char *sx = strtok(NULL, ",");
    int y = my_atoi(sy);
    int x = my_atoi(sx);

    if (x < 1 || y < 1)
        my_exit(84, "Error: invalid map size\n");
    input->size.x = x;
    input->size.y = y;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        if (-nb / 10 != 0)
            my_put_nbr((nb / 10) * -1);
        my_putchar(-1 * (nb % 10) + 48);
    } else if (nb <= 9) {
        my_putchar(nb + 48);
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
}

int flags(char *str, int *i, va_list list)
{
    if (str[*i] == 'c')
        my_putchar((char) va_arg(list, int));
    if (str[*i] == 's')
        my_putstr(va_arg(list, char *));
    if (str[*i] == 'd' || str[*i] == 'i')
        my_put_nbr(va_arg(list, long long));
    if (str[*i] == '\n')
        my_putchar('\n');
    (*i)++;
    return (*str);
}

int my_printf(char *str, ...)
{
    va_list list;
    int i = 0;

    va_start(list, str);
    while (str[i] != '\0') {
        if (str[i] == '%') {
            i++;
            flags(str, &i, list);
        } else {
            my_putchar(str[i]);
            i++;
        }
    }
    va_end(list);
    return (*str);
}
