/*
** EPITECH PROJECT, 2022
** minishell1 [WSL: Ubuntu]
** File description:
** minishell2
*/

#include "minishell.h"

int count_chars(char *c, char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (c[0] == str[i] || (c[1] && c[1] == str[i]))
            count++;
    return count;
}

char **str_split(char *c, char *str, int code)
{
    char **arr = (char **)my_calloc_2d(8UL, count_chars(c, str) + 3);
    char *rest = NULL;
    char *t;
    int i = 0;

    if ((str == NULL || str[0] == 0) && code == 1)
        exit(0);
    for (t = strtok_r(str, c, &rest); t; t = strtok_r(NULL, c, &rest))
        arr[i++] = t;
    --i;
    if (arr[i][my_strlen(arr[i]) - 1] == '\n')
        arr[i][my_strlen(arr[i]) - 1] = '\0';
    for (i = 0; arr[i]; i++)
        if (arr[i][0] == '\0' || arr[i][0] == '\n')
            arr[i] = NULL;
    return arr;
}

int lst(char *str)
{
    return my_strlen(str);
}

char *str_catcat(char *str1, char *str2, char *str3)
{
    char *full = my_calloc(1UL, 0, lst(str1) + lst(str2) + lst(str3) + 1);

    my_strcat(full, str1);
    my_strcat(full, str2);
    my_strcat(full, str3);
    return full;
}

void fork_process(env_t *fenv)
{
    if (get_execute(fenv) == NULL) {
        write(2, fenv->cmd[0], my_strlen(fenv->cmd[0]));
        write(2, ": Command not found.\n", 21);
        exit(1);
    }
    exit(0);
}
