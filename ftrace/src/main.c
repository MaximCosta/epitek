/*
** EPITECH PROJECT, 2023
** B-PSU-400-MPL-4-1-ftrace-hugo.eschlimann
** File description:
** main
*/

#include "../include/ftrace.h"

bool exit_message(const char *message)
{
    fprintf(stderr, "%s", message);
    return false;
}

ftrace_t *init_ftrace_struct(void)
{
    ftrace_t *ftrace = malloc(sizeof(ftrace_t));

    if (ftrace == NULL)
        return NULL;

    ftrace->opt = 0;
    ftrace->opt_idx = 0;
    ftrace->no_flag = false;
    ftrace->s_flag = false;
    ftrace->p_flag = false;
    ftrace->i_flag = false;
    ftrace->n_flag = false;
    ftrace->o_flag = false;
    ftrace->h_flag = false;
    ftrace->status = 0;
    ftrace->child = 0;
    return ftrace;
}

int main(int ac, char **av)
{
    nm_t *nm = NULL;
    ftrace_t *st = NULL;

    if (ac != 2) {
        fprintf(stderr, "Usage: ftrace <command>\n");
        return EXIT_EPITECH;
    }

    nm = init_nm_struct();
    st = init_ftrace_struct();
    if (!start_nm(nm, av[1])) {
        return EXIT_EPITECH;
    }
    execute_ftrace();

    free(nm);
    free(st);
    return 0;
}
