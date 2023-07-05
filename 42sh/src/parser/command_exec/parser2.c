/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-bsminishell2-kilyan.cotten
** File description:
** parser2.c
*/

#include "mysh.h"

char **minishell_parser_error(char c)
{
    write(2, &c, 1);
    return NULL;
}
