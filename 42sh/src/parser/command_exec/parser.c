/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-bsminishell2-kilyan.cotten
** File description:
** parser.c
*/

#include "mysh.h"

static int count_to_end(char *str, char c)
{
    int in_quotes = c == '"' || c == '\'' ? 1 : 0;
    int i = 0;

    for (i = 0; str[i]; i++) {
        if (!in_quotes && (str[i] == ' ' || str[i] == '\t'))
            break;
        if (in_quotes && str[i] == c && i != 0) {
            in_quotes = 0;
            continue;
        }
        if (!in_quotes && (str[i] == '"' || str[i] == '\'')) {
            in_quotes = 1;
            c = str[i];
        }
    }
    if (in_quotes)
        return -1 * c;
    return i;
}

static char *split_str(char *str, int c, int in_quotes)
{
    char *s = malloc(sizeof(char) * (count_to_end(str, *str) + 1));
    char *tmp = s;

    for (int i = 0; str[i]; i++) {
        if (!in_quotes && (str[i] == ' ' || str[i] == '\t'))
            break;
        if (in_quotes && str[i] == c && i != 0) {
            in_quotes = 0;
            continue;
        }
        if (!in_quotes && (str[i] == '"' || str[i] == '\'')) {
            in_quotes = 1;
            c = str[i];
            continue;
        }
        *s++ = str[i];
    }
    *s = '\0';
    return tmp;
}

static int parsing_count_words(char *str)
{
    int count = 0;
    int len = 0;

    while (*str) {
        len = count_to_end(str, *str);
        if (len < 0)
            return len;
        str += len;
        if (*str == ' ' || *str == '\t')
            str++;
        count++;
    }
    return count;
}

static int count_quotes(char *s)
{
    int count = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '"' || s[i] == '\'')
            count++;
    }
    return count % 2;
}

char **minishell_parser(char *str)
{
    int len_tab = parsing_count_words(str);
    char **tab = NULL;
    char **tmp = NULL;
    int len = 0;
    char c = len_tab * -1;

    if (len_tab < 0)
        return minishell_parser_error(c);
    tab = my_calloc(sizeof(char *) * (len_tab + 1));
    tmp = tab;
    while (*str) {
        len = count_to_end(str, *str);
        if (len)
            *tab++ = split_str(str, 0, 0);
        str += len;
        if (*str == ' ' || *str == '\t')
            str++;
    }
    *tab = NULL;
    return tmp;
}
