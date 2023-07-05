/*
** EPITECH PROJECT, 2023
** B-PSU-400-MPL-4-1-strace-maxim.costa
** File description:
** init
*/

#include "syscall.h"

strace_t *init_strace_struct(void)
{
    strace_t *strace = malloc(sizeof(strace_t));

    if (strace == NULL)
        return NULL;

    strace->opt = 0;
    strace->opt_idx = 0;
    strace->no_flag = false;
    strace->s_flag = false;
    strace->p_flag = false;
    strace->i_flag = false;
    strace->n_flag = false;
    strace->o_flag = false;
    strace->h_flag = false;

    return strace;
}
