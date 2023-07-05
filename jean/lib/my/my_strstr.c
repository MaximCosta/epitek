/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** My_strstr
*/

static int find_str(char const *str, char const *to_find)
{
    while (*str != '\0' && *to_find != '\0') {
        if (*str++ != *to_find++) {
            return (0);
        }
    }
    if (*str == '\0' && *to_find != '\0') {
        return (0);
    }
    return (1);
}

char *my_strstr(char *str, char const *to_find)
{
    char *begin = str;

    while (*str != '\0') {
        if (*str == *to_find && find_str(str, to_find)) {
            return (str);
        }
        str++;
    }
    if (*to_find == '\0') {
        return (begin);
    }
    return ((void*)0);
}
