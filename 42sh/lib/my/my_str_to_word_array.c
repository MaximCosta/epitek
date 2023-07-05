/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday08-kilyan.cotten
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
int my_strlen(char const *str);
int is_letter(char c);
int is_number(char c);
char *my_strncpy(char *dest, char const *str, int n);

static int how_many_words(char const *str)
{
    int i = 0;
    int res = 0;
    int current = 0;

    if (!str)
        return 0;
    while (str[i]) {
        if (is_letter(str[i]) || is_number(str[i]))
            current++;
        if (!is_letter(str[i]) && !is_number(str[i]) && current)
            res++;
        if (!is_letter(str[i]) && !is_number(str[i]))
            current = 0;
        i++;
    }
    if (current)
        res++;
    return res;
}

static char *str_ndup(char const *str, int n)
{
    int len = n;
    char *dest = malloc(sizeof(char) * (len + 1));

    my_strncpy(dest, str, n);
    dest[len] = 0;
    return dest;
}

static int next_word(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (!is_letter(str[i]) && !is_number(str[i]))
            return i;
        i++;
    }
    return i;
}

static int get_number_of_started_non_alphanumeric_char(char const *str)
{
    int i = 0;

    if (str[i] && (!is_letter(str[i]) && !is_number(str[i])))
        while (str[i] && (!is_letter(str[i]) && !is_number(str[i])))
            i++;
    return i;
}

char **my_str_to_word_array(char const *str)
{
    int total = how_many_words(str);
    char **res = malloc(sizeof(char *) * (total + 1));
    int curr = 0;
    int tmp;

    if (!str)
        return 0;
    for (int i = 0; i < total; i++) {
        curr += get_number_of_started_non_alphanumeric_char(str + curr);
        tmp = next_word(str + curr);
        res[i] = str_ndup(str + curr, tmp);
        curr += tmp + 1;
    }
    res[total] = 0;
    return res;
}
