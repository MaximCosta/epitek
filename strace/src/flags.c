/*
** EPITECH PROJECT, 2023
** B-PSU-400-MPL-4-1-strace-maxim.costa
** File description:
** flags
*/

#include "syscall.h"

void usage(strace_t *st)
{
    printf("USAGE: ./strace [-s] [-n] [-i] [-p <pid>|<command>]\n");
    st->h_flag = true;
}

void handle_flag(strace_t *st, int ac, char **av)
{
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'}, {0, 0, 0, 0}};

    while (true) {
        st->opt = getopt_long(ac, av, "hsniop:", long_options, &st->opt_idx);
        if (st->opt == -1)
            break;
        switch (st->opt) {
            case 'h': usage(st); break;
            case 's': st->s_flag = true; break;
            case 'n': st->n_flag = true; break;
            case 'i': st->i_flag = true; break;
            case 'o': st->o_flag = true; break;
            case 'p': st->p_flag = true; break;
        }
    }
    if (!st->s_flag && !st->p_flag && !st->i_flag && !st->n_flag
        && !st->o_flag)
        st->no_flag = true;
}
