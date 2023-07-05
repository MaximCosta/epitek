/*
** EPITECH PROJECT, 2022
** corewar [WSL: Ubuntu]
** File description:
** parse_argv_2
*/

#include "../../include/corewar.h"

void parse_argv_flag_n(int *i, int ac, char **av, options_t *opt)
{
    int tmp = 0;
    if (opt->n != -1)
        exit(84);
    *i += 1;
    if (*i >= ac)
        exit(84);
    tmp = my_getnbr(av[*i]);
    if (tmp < 0 || tmp > 4)
        exit(84);
    opt->n = tmp;
    *i += 1;
    if (*i >= ac)
        exit(84);
    if (av[*i][0] == '-')
        return parse_argv_flag(i, ac, av, opt);
}
