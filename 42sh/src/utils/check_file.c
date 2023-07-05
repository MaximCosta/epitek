/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** check_file_or_folder.c
*/

#include "mysh.h"

int is_file_or_is_folder(char *s)
{
    struct stat stats = {0};

    if (stat(s, &stats) == -1)
        return 0;
    return 1;
}

int isit_file(char *s)
{
    struct stat stats = {0};

    if (stat(s, &stats) == -1)
        return 0;
    return S_ISREG(stats.st_mode);
}
