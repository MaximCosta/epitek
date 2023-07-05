/*
** EPITECH PROJECT, 2023
** B-PSU-400-MPL-4-1-ftrace-maxim.costa
** File description:
** ftrace
*/

#include "ftrace.h"

unsigned long long syscall_table(struct user_regs_struct *regs, int i)
{
    unsigned long long ret = (unsigned long long[]){
        regs->rdi,
        regs->rsi,
        regs->rdx,
        regs->r10,
        regs->r8,
        regs->r9,
    }[i];
    return ret;
}

void print_syscall(ftrace_t *st)
{
    dprintf(STDERR_FILENO, "Syscall %s(", table[st->orig_eax].name);
    for (size_t i = 0; i < table[st->orig_eax].nargs; i++) {
        detailled_print(st, i);
        if (i < table[st->orig_eax].nargs - 1)
            dprintf(STDERR_FILENO, ", ");
    }
    if (st->regs.rax == VOID)
        dprintf(STDERR_FILENO, ")\t = ?\n");
    else if (st->regs.rax == 0)
        dprintf(STDERR_FILENO, ")\t = %s\n", st->s_flag == 0 ? "0x00" : "0");
    else
        print_return_value(st);
}

void exit_msg(char *msg)
{
    dprintf(STDERR_FILENO, "%s", msg);
    exit(84);
}

void execute_fork(ftrace_t *st, char **av)
{
    struct stat sb;

    if (stat(av[1], &sb) == -1)
        exit_msg("ftrace: exec: No such file or directory\n");
    if (!(sb.st_mode & S_IXUSR))
        exit_msg("ftrace: exec: Permission denied\n");
    ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    execve(av[1], av + 1, NULL);
}

void execute_strace(ftrace_t *st, nm_t *nm, char **av)
{
    st->child = fork();
    if (st->child == 0) {
        execute_fork(st, av);
    } else {
        dprintf(
            STDERR_FILENO, "exit_group(%d) = ?\n", WEXITSTATUS(st->status));
        dprintf(STDERR_FILENO, "+++ exited with %d +++\n",
            WEXITSTATUS(st->status));
    }
}
