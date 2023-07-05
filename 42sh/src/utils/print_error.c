/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** print_error.c
*/

#include "mysh.h"

int print_error(char *str)
{
    write(2, str, my_strlen(str));
    return 1;
}
