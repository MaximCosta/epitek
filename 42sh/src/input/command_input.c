/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** minishell_input.c
*/

#include "mysh.h"

void minishell_clear_input(minishell_t *minishell)
{
    SH_SETERROR(0);
    for (int i = 0; i < minishell->input_size; i++)
        minishell->input[i] = 0;
}

void minishell_input_too_long(minishell_t *minishell)
{
    char *tmp = malloc(sizeof(char) * (minishell->input_size * 2));

    my_strcpy(tmp, minishell->input);
    free(minishell->input);
    minishell->input = tmp;
    minishell->input_size *= 2;
}

void minishell_input_print_inter(int *i)
{
    if (isatty(0))
        my_printf("? ");
    *i--;
}

void minishell_input(minishell_t *minishell)
{
    int i = 0;
    char c = 0;
    char pwd[1024] = {0};

    if (isatty(0))
        my_printf("%s $ ", getcwd(pwd, 1024));
    while (read(0, &c, 1) && c) {
        if (c == '\n' && (!i || minishell->input[i - 1] != '\\'))
            break;
        if (c == '\n')
            minishell_input_print_inter(&i);
        minishell->input[i++] = c;
        if (i >= minishell->input_size - 1)
            minishell_input_too_long(minishell);
    }
    if (!i && !c)
        minishell->exit = 0;
}
