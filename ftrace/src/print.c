/*
** EPITECH PROJECT, 2023
** ftrace [WSL: Ubuntu]
** File description:
** print
*/

#include "ftrace.h"

int print_string(pid_t child, struct user_regs_struct *regs, int i)
{
    unsigned long long addr = syscall_table(regs, i);
    char c = 1;

    dprintf(STDERR_FILENO, "\"");
    for (int idx = 0; c; idx++) {
        c = ptrace(PTRACE_PEEKDATA, child, addr + idx, NULL);
        if (!c)
            break;
        if (c == '\n')
            dprintf(STDERR_FILENO, "\\n");
        else
            dprintf(STDERR_FILENO, "%c", c);
    }
    dprintf(STDERR_FILENO, "\"");
    return 1;
}

int detailled_print(ftrace_t *st, int i)
{
    if (syscall_table(&st->regs, i) == 0)
        return dprintf(STDERR_FILENO, "NULL");
    else
        return dprintf(
            STDERR_FILENO, "%p", (void *) syscall_table(&st->regs, i));
}

void flag_print(ftrace_t *st, int orig_eax)
{
    if (st->n_flag)
        dprintf(STDERR_FILENO, "[%4d] ", orig_eax);
    if (st->i_flag)
        dprintf(STDERR_FILENO, "[%016llx] ", st->regs.rip);
}

void print_ftrace(ftrace_t *st)
{
    flag_print(st, st->orig_eax);
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

void print_return_value(ftrace_t *st)
{
    if (st->s_flag)
        dprintf(STDERR_FILENO, ")\t = %d\n", st->regs.rax);
    else
        dprintf(STDERR_FILENO, ")\t = %p\n", st->regs.rax);
}
