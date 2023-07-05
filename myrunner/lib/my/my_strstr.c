/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** str
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
