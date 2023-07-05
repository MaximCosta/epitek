/*
** EPITECH PROJECT, 2023
** strace [WSL: Ubuntu]
** File description:
** strace
*/

#include "syscall.h"

int main(int ac, char **av)
{
    strace_t *strace = NULL;

    if (ac < 2) {
        dprintf(STDERR_FILENO, "strace: must have PROG [ARGS] or -p PID\n");
        dprintf(STDERR_FILENO, "Try 'strace --help' for more information.\n");
        return 84;
    }
    strace = init_strace_struct();
    handle_flag(strace, ac, av);
    if (strace->h_flag == true)
        return 0;
    execute_strace(strace, av);
    free(strace);
    return 0;
}
