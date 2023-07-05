/*
** EPITECH PROJECT, 2021
** str_utils
** File description:
** str_utils.c
*/
#include "../../include/common.h"

int count_words_two(char *str, char *delim, int *i, int *count)
{
    if (is_char_delimiter(str[*i], delim)) {
        if (!str[*i + 1]) {
            (*i)++;
            return 1;
        }
        while (is_char_delimiter(str[*i], delim))
            (*i)++;
        if (str[*i])
            (*count)++;
    }
    return 0;
}

int count_words(char *str, char *delim)
{
    int i = 0;
    int count = 0;

    if (!str)
        return 0;
    if (!is_char_delimiter(str[i], delim))
        count++;
    while (str[i]) {
        if (count_words_two(str, delim, &i, &count))
            continue;
        i++;
    }
    return count;
}

int split_two(char *str, char *delim, char **splitted, int *vars[2])
{
    if (is_char_delimiter(str[*vars[0]], delim)) {
        if (!str[*vars[0] + 1])
            return 1;
        while (is_char_delimiter(str[*vars[0]], delim))
            (*vars[0])++;
        if (str[*vars[0]]) {
            splitted[*vars[1]] = get_next_word(str, delim, *vars[0]);
            (*vars[0]) += my_strlen(splitted[*vars[1]]) - 1;
            (*vars[1])++;
        }
    } else {
        splitted[*vars[1]] = get_next_word(str, delim, *vars[0]);
        (*vars[0]) += my_strlen(splitted[*vars[1]]) - 1;
        (*vars[1])++;
    }
    return 0;
}

char **split(char *str, char *delim)
{
    char **splitted = 0;
    int j = 0;
    int *arrays[2] = {0, 0};

    if (!str || !delim)
        return 0;
    splitted = malloc(sizeof(char *) * (count_words(str, delim) + 1));
    if (!splitted)
        return 0;
    for (int i = 0; str[i]; i++) {
        arrays[0] = &i;
        arrays[1] = &j;
        if (split_two(str, delim, splitted, arrays))
            break;
    }
    splitted[count_words(str, delim)] = 0;
    return splitted;
}
