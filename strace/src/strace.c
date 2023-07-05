/*
** EPITECH PROJECT, 2023
** B-PSU-400-MPL-4-1-strace-maxim.costa
** File description:
** strace
*/

#include "syscall.h"

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

void loop_strace(strace_t *st)
{
    while (st->pRes = ptrace(PTRACE_SINGLESTEP, st->child, NULL, NULL) != -1) {
        wait4(st->child, &st->status, 0, NULL);
        if (st->pRes < 0) {
            perror("singlestep error");
            exit(84);
        }
        st->orig_eax = ptrace(PTRACE_PEEKUSER, st->child, 8 * ORIG_RAX, NULL);
        if (st->orig_eax < 0 || st->orig_eax >= 333)
            continue;
        ptrace(PTRACE_GETREGS, st->child, NULL, &st->regs);
        print_strace(st);
    }
}

void exit_msg(char *msg)
{
    dprintf(STDERR_FILENO, "%s", msg);
    exit(84);
}

void execute_fork(strace_t *st, char **av)
{
    int pid = 0;
    int i = 1;
    struct stat sb;

    for (; av[i][0] == '-'; i++)
        ;
    if (st->p_flag) {
        pid = atoi(av[i + 1]);
        if (pid == 0)
            exit_msg("strace: invalid pid\n");
        ptrace(PTRACE_ATTACH, pid, NULL, NULL);
    } else {
        if (stat(av[i], &sb) == -1)
            exit_msg("strace: exec: No such file or directory\n");
        if (!(sb.st_mode & S_IXUSR))
            exit_msg("strace: exec: Permission denied\n");
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execve(av[i], av + i, NULL);
    }
}

void execute_strace(strace_t *st, char **av)
{
    int exit_status = 0;

    st->child = fork();
    if (st->child == 0) {
        execute_fork(st, av);
    } else {
        wait4(st->child, &st->status, 0, NULL);
        loop_strace(st);
        exit_status = WEXITSTATUS(st->status);
        dprintf(STDERR_FILENO, "exit_group(%d) = ?\n", exit_status);
        dprintf(STDERR_FILENO, "+++ exited with %d +++\n", exit_status);
    }
}
