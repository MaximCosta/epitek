/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-lemin-flavio.moreno [WSL: Ubuntu-20.04]
** File description:
** len_str.c
*/

#include <unistd.h>

int is_comment_after(char *str)
{
    while (*str == ' ')
        str++;
    if (*str == '#')
        return 1;
    return 0;
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i++]);
    return i - 1;
}

int str_len_without_comment(char *str)
{
    int len = 0;

    if (!str)
        return (0);
    for (; str[len] && str[len] != '#' && str[len] != '\n' &&
            !is_comment_after(&str[len]); len++);
    return len;
}

void put_str_c(char *str)
{
    write(1, str, str_len_without_comment(str));
    write(1, "\n", 1);
}
