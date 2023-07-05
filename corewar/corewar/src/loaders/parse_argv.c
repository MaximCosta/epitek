/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** parse_argv.c
*/

#include "../../include/corewar.h"

void parse_argv_flag_a(int *i, int ac, char **av, options_t *opt)
{
    int tmp = 0;

    if (opt->a != -1)
        exit(84);
    *i += 1;
    if (*i >= ac)
        exit(84);
    tmp = my_getnbr(av[*i]);
    opt->a = tmp;
    *i += 1;
    if (*i >= ac)
        exit(84);
    if (av[*i][0] == '-')
        return parse_argv_flag(i, ac, av, opt);
}

void parse_argv_flag_dump(int *i, int ac, char **av, options_t *opt)
{
    int tmp = 0;

    if (opt->dump != -1)
        exit(84);
    *i += 1;
    if (*i >= ac)
        exit(84);
    tmp = my_getnbr(av[*i]);
    if (tmp < 0)
        exit(84);
    opt->dump = tmp;
    *i += 1;
    if (*i >= ac)
        return;
    if (av[*i][0] == '-')
        return parse_argv_flag(i, ac, av, opt);
}

void parse_argv_flag(int *i, int ac, char **av, options_t *opt)
{
    int tmp = 0;

    if (av[*i][0] != '-')
        return;
    if (!my_strcmp(av[*i], "-n"))
        return parse_argv_flag_n(i, ac, av, opt);
    if (!my_strcmp(av[*i], "-a"))
        return parse_argv_flag_a(i, ac, av, opt);
    if (!my_strcmp(av[*i], "-dump"))
        return parse_argv_flag_dump(i, ac, av, opt);
    exit(84);
}

void create_new_champ(corewar_t *corewar, options_t *options, char *path)
{
    int nbr = 1;

    while (options->champions[nbr - 1])
        nbr++;
    nbr = options->n != -1 ? options->n : nbr;
    if (options->champions[nbr - 1])
        exit(84);
    options->champions[nbr - 1] = load_champion(corewar, path);
    if (!options->champions[nbr - 1])
        return;
    options->champions[nbr - 1]->id = nbr;
    options->champions[nbr - 1]->padding = options->a != -1 ? options->a : 0;
    list_insert_end(&corewar->champions, options->champions[nbr - 1]);
}

void parse_argv(corewar_t *corewar, int ac, char **av)
{
    options_t options = {0};

    options.dump = -1;
    options.a = -1;
    options.n = -1;
    for (int i = 1; i < ac;) {
        if (*av[i] == '-') {
            parse_argv_flag(&i, ac, av, &options);
            continue;
        }
        create_new_champ(corewar, &options, av[i]);
        options.a = -1;
        options.n = -1;
        i++;
    }
    corewar->vm->dump_time = options.dump;
}
