/*
** EPITECH PROJECT, 2021
** str_utils
** File description:
** str_utils.c
*/

#include "../../include/common.h"

bool has_file_extension(char *file_name, char *extension)
{
    int i = 0;
    int j = 0;

    while (file_name[i]) {
        if (file_name[i] == '.')
            j = i;
        i++;
    }
    return my_strcmp(file_name + j, extension) == 0;
}

char *lstrip(char *str)
{
    char *res = 0;
    int i = 0;
    int j = 0;

    if (!str)
        return 0;
    res = my_strdup(str);
    while (res[j] && (res[j] == ' ' || res[j] == '\t') || res[j] == '\n')
        j++;
    if (j == my_strlen(res))
        return 0;
    while (res[i] && (res[i] == ' ' || res[i] == '\t') && res[i] != '\n')
        i++;
    return res + i;
}

char *rstrip(char *str)
{
    char *res = 0;
    int i = my_strlen(str) - 1;
    int j = 0;

    if (!str)
        return 0;
    res = my_strdup(str);
    while (res[j] && (res[j] == ' ' || res[j] == '\t') || res[j] == '\n')
        j++;
    if (j == my_strlen(res))
        return 0;
    while (res[i] && (res[i] == ' ' || res[i] == '\t') || res[i] == '\n')
        i--;
    res[i + 1] = 0;
    return res;
}

char *remove_after_char(char *str, char c)
{
    char *res = 0;
    int i = 0;
    int j = 0;

    if (!str)
        return 0;
    res = my_strdup(str);
    if (res[0] == c)
        return NULL;
    while (res[j] && (res[j] == ' ' || res[j] == '\t') || res[j] == '\n')
        j++;
    if (j == my_strlen(res))
        return 0;
    while (res[i]) {
        if (res[i] == c)
            res[i] = 0;
        i++;
    }
    return res;
}

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (s1[i] && s2[i] && i < n) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return 0;
}
