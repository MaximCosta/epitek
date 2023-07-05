/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** pwd.c
*/

#include "mysh.h"

int minishell_pwd(minishell_t *minishell)
{
    char buff[1024] = {0};

    my_printf("%s\n", getcwd(buff, 1024));
    return 1;
}
