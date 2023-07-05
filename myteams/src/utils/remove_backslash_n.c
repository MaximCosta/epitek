/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myteams-hades.cuisinier
** File description:
** remove_backslash_r
*/

#include <stdio.h>

int remove_backslash_r(char *str)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\r' && str[i + 1] == '\n') {
            str[i] = '\0';
            return 0;
        }
    }
    str[i] = '\0';
    return 1;
}
