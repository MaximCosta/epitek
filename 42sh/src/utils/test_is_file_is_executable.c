/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-kilyan.cotten
** File description:
** test_is_file_is_executable.c
*/

#include "mysh.h"

int is_exec(char *s)
{
    struct stat statbuf;

    if (stat(s, &statbuf) == -1)
        return 0;
    return statbuf.st_mode & S_IXUSR && S_ISREG(statbuf.st_mode);
}
