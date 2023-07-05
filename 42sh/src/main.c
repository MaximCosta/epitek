/*
** EPITECH PROJECT, 2021
** minishell2
** File description:
** main.c
*/

#include "mysh.h"

void handler(int n)
{
    char pwd[1024] = {0};

    if (isatty(0))
        my_printf("\n%s $ ", getcwd(pwd, 1024));
}

static int parse_command(minishell_t *minishell)
{
    if (minishell_parse_commands(minishell)) {
        minishell->exit_status = 1;
        minishell_clear_command(minishell);
        return 1;
    }
    return 0;
}

int main(int ac, char **av, char **ev)
{
    minishell_t *minishell = minishell_init(ev);
    int status = 0;

    signal(SIGINT, &handler);
    if (!minishell)
        return 84;
    while (minishell->exit) {
        minishell_clear_input(minishell);
        minishell_input(minishell);
        if (parse_command(minishell))
            continue;
        minishell_exec(minishell);
        minishell_clear_command(minishell);
    }
    if (isatty(0))
        my_printf("exit\n");
    status = minishell->exit_status;
    minishell_destroy(minishell);
    return status;
}
