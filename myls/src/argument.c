/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** argument
*/

#include "my_ls.h"
#include "my_printf.h"

void add_param(char **param, char **av, int i)
{
    for (int x = 1; av[i][x]; x += 1)
        if (param[(int)av[i][x]] != NULL)
            *param[(int)av[i][x]] = 1;
}

void file_or_err(option_t *opt, char *filename)
{
    if (lstat(filename, &opt->fcil[opt->f[1]].st) != -1) {
        opt->fcil[opt->f[1]].filename = filename;
        opt->fcil[opt->f[1]].path = filename;
        opt->fcil[opt->f[1]].flpath = filename;
        opt->f[1]++;
    } else
        opt->error[opt->f[2]++] = filename;
}

void add_folder_file(option_t *opt, char *filename)
{
    opt->fcol[opt->f[0]].dp = opendir(filename);
    if (opt->fcol[opt->f[0]].dp == NULL) {
        opt->fcol[opt->f[0]].dp = NULL;
        if (errno == ENOTDIR) file_or_err(opt, filename);
        else opt->error[opt->f[2]++] = filename;
    } else {
        opt->fcol[opt->f[0]].path = filename;
        opt->f[0]++;
    }
}

void option_stat(char **av, option_t *opt)
{
    char *param[255] = { NULL };

    param['l'] = &opt->l;
    param['r'] = &opt->r;
    param['t'] = &opt->t;
    param['R'] = &opt->recursive;
    param['d'] = &opt->d;
    param['a'] = &opt->a;
    param['h'] = &opt->h;
    for (int i = 1; av[i]; i += 1)
        if (av[i][0] == '-') add_param(param, av, i);
        else add_folder_file(opt, av[i]);
}
