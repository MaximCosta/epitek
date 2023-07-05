/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-lemin-flavio.moreno [WSL: Ubuntu-20.04]
** File description:
** parsing_utils.c
*/

#include "my.h"

int count_char(char *s, char c)
{
    int count = 0;

    for (; *s && *s != '#' && !is_comment_after(s);)
        count += (*s++ == c);
    return count;
}

void my_putstr_parsing(char *str)
{
    write(1, str, my_strlen(str));
}

int test_is_all_number_between(char *s, char c, int n)
{
    int i = 0;

    for (;s [i] && s[i] != '\n' && !is_comment_after(&s[i]); i++) {
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] == c))
            continue;
        return 1;
    }
    if (i == n)
        return 1;
    return 0;
}

char *my_strdup_p(char *s)
{
    char *new = my_calloc(sizeof(char), my_strlen(s) + 1);

    if (!new)
        return NULL;
    for (int i = 0; s[i]; i++)
        new[i] = s[i];
    return new;
}
