/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** str to word array
*/

#include <stdlib.h>

int my_str_isnum(char const *str);
int my_str_isalpha(char const *str);

int is_alnum_1(char c)
{
    if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
        return 1;
    if (48 <= c && c <= 57)
        return 1;
    return 0;
}

int next_nan_1(char const *str, int cur)
{
    while (is_alnum_1(str[cur]))
        cur++;
    return cur;
}

int count_word_1(char const *str)
{
    int i = 0;
    int old = 1;
    int count = 0;

    if (!str || !str[0])
        return 0;
    while (str[i]) {
        if (is_alnum_1(str[i])) {
            old = 0;
        } else if (old == 0) {
            count++;
            old = 1;
        }
        i++;
    }
    if (old == 0)
        count++;
    return count;
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int a = 0;
    int next = 1;
    int len = count_word_1(str);
    char **dest = dest = malloc(sizeof(char*) * (len + 2));

    if (len == 0)
        return dest;
    while (a < len) {
        while (is_alnum_1(str[i]) == 0)
            i++;
        next = next_nan_1(str, i) - i;
        dest[a] = malloc(sizeof(char) * (next));
        for (int j = 0; j < next; j++, i++)
            dest[a][j] = str[i];
        a++;
        i++;
    }
    dest[a] = 0;
    return dest;
}
