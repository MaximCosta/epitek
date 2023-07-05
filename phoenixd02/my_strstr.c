/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd02-maxim.costa [WSL: Ubuntu]
** File description:
** my_strstr
*/

char *my_strstr(char *str, char const *to_find)
{
    const char *a = str;
    const char *b = to_find;

    while (1) {
        if (!(*b))
            return str;
        if (!(*a))
            return 0;
        if (*a++ != *b++) {
            a = ++str;
            b = to_find;
        }
    }
}