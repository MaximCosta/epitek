/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** print_error.c
*/

#include "mysh.h"

static void too_long(int *i, char **str)
{
    char *tmp = my_calloc(sizeof(char) * (*i * 2));

    my_strcpy(*str, tmp);
    free(*str);
    *str = tmp;
    *i *= 2;
}

char *mein_get_line(void)
{
    char *line = my_calloc(256);
    size_t size = 256;
    int i = 0;
    char c = 0;

    while (read(0, &c, 1) && c) {
        if (c == '\n')
            break;
        line[i++] = c;
        if (i >= size)
            too_long(&i, &line);
    }
    if (!i && !c) {
        free(line);
        return NULL;
    }
    return line;
}

char *string_append(char *str, char *str2)
{
    char *new = my_calloc(sizeof(char) * (my_strlen(str) +
                                        my_strlen(str2) + 1));

    if (!new)
        return NULL;
    my_strcpy(new, str);
    my_strcat(new, str2);
    free(str);
    return new;
}
