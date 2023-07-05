/*
** EPITECH PROJECT, 2022
** minishell1 [WSL: Ubuntu]
** File description:
** minishell5
*/

#include "minishell.h"

int my_isalnum(char *s1, int size)
{
    for (int i = 0; s1[i] && i < size; i++)
        if (!IS_ALNUM(s1[i]) && s1[i] != '_')
            return 0;
    return 1;
}

char *concat(char *s1, char *s2)
{
    char *s3 = my_calloc(1, 0, my_strlen(s1) + my_strlen(s2) + 1);

    my_strcpy(s3, s1);
    my_strcat(s3, s2);
    return s3;
}

char **my_strdump2d(char **str, int i)
{
    int len = my_strlen_2d(str);
    char **res = (char **) my_calloc_2d(8UL, len + i + 1);

    for (int i = 0; str[i]; i++)
        res[i] = my_strdup(str[i]);
    return res;
}

int exit_code(char **strs)
{
    int code;

    if (strs[1] == NULL)
        exit(0);
    if (my_str_isnum(strs[1]) == 0) {
        if ('0' <= strs[1][0] && strs[1][0] <= '9')
            write(2, "exit: Badly formed number.\n", 27);
        else
            write(2, "exit: Expression Syntax.\n", 25);
        return 1;
    }
    if (strs[2] != NULL) {
        write(2, "exit: Expression Syntax.\n", 25);
        return 1;
    }
    code = my_getnbr(strs[1]);
    exit(code);
}