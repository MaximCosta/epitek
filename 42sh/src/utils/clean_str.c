/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-kilyan.cotten
** File description:
** clean_str.c
*/

#include "mysh.h"

static int is_all_space_or_tab(char *s)
{
    for (int i = 0; s[i]; i++) {
        if (s[i] != ' ' && s[i] != '\t')
            return 0;
    }
    return 1;
}

char *clean_my_str(char *s)
{
    char *new = NULL;

    if (!s)
        return NULL;
    while (*s == ' ' || *s == '\t')
        s++;
    new = strdup(s);
    for (int i = 0; new[i]; i++) {
        if (is_all_space_or_tab(new + i)) {
            new[i] = '\0';
            break;
        }
    }
    return new;
}