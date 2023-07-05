/*
** EPITECH PROJECT, 2021
** str_utils
** File description:
** str_utils.c
*/
#include "../../include/common.h"

bool is_char_delimiter(char c, char *delimiters)
{
    for (int i = 0; delimiters[i]; i++) {
        if (c == delimiters[i])
            return true;
    }
    return false;
}

char *get_next_word(char *str, char *delim, int i)
{
    int next_word_length = 0;
    char *next_word = NULL;

    for (; str[i] && !is_char_delimiter(str[i], delim); i++)
        next_word_length++;
    if (next_word_length == 0)
        return 0;
    next_word = malloc(sizeof(char) * (next_word_length + 1));
    for (int j = 0; j < next_word_length; j++)
        next_word[j] = str[j + i - next_word_length];
    next_word[next_word_length] = 0;
    return next_word;
}
