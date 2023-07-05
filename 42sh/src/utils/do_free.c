/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-kilyan.cotten
** File description:
** do_free.c
*/

#include "mysh.h"

int do_free(void *ptra, void *ptrb)
{
    free(ptra);
    free(ptrb);
}
