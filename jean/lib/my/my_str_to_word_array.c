/*
** EPITECH PROJECT, 2021
** Pool Day08
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my_all.h"

static _Bool is_alpha_char(char c)
{
    if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123)) {
        return 1;
    } else {
        return 0;
    }
}

static int count_words(char const *str, int *max_len)
{
    int nb_word = 0;
    int cpt = 0;

    while (*str) {
        while (*str && !is_alpha_char(*str))
            str++;
        while (*str && is_alpha_char(*str)) {
            str++;
            cpt++;
        }
        if (is_alpha_char(*(str - 1))) {
            nb_word++;
        }
        *max_len = MAX(*max_len, cpt);
        cpt = 0;
    }
    *max_len = *max_len + 1;
    return nb_word;
}

static void integrate_strings(char **array, char const *str)
{
    int cpt = 0;
    int indice = 0;

    while (*str) {
        while (*str && !is_alpha_char(*str))
            str++;
        while (*str && is_alpha_char(*str)) {
            array[indice][cpt] = *str++;
            cpt++;
        }
        array[indice][cpt] = '\0';
        if (is_alpha_char(*(str - 1)))
            indice++;
        cpt = 0;
    }
}

char **my_str_to_word_array(char const *str)
{
    int max_len = 0;
    int nb_words;
    char **array;

    if (str == NULL)
        return NULL;
    nb_words = count_words(str, &max_len);
    array = (char**) malloc(sizeof(char*) * (nb_words + 1));
    for (int i = 0; i < nb_words + 1; i++)
        array[i] = (char*) malloc(sizeof(char) * max_len);
    integrate_strings(array, str);
    array[nb_words] = NULL;
    return array;
}
