/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-kilyan.cotten
** File description:
** error.c
*/

#include "mysh.h"

static const char *list_error[] = {
    NULL,
    "Unmatched '`'.",
    "Unmatched '\"'.",
    "Unmatched '''.",
    "Too many ('s",
    "Too many )'s",
};

char *minishell_error(int n)
{
    static char *str = NULL;

    if (n != -1)
        str = (char *)list_error[n];
    return str;
}