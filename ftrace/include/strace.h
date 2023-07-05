/*
** EPITECH PROJECT, 2023
** B-PSU-400-MPL-4-1-ftrace-maxim.costa
** File description:
** ftrace
*/

#ifndef ftrace_H_
    #define ftrace_H_

    #include <ctype.h>
    #include <getopt.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/ptrace.h>
    #include <sys/reg.h>
    #include <sys/stat.h>
    #include <sys/syscall.h>
    #include <sys/types.h>
    #include <sys/user.h>
    #include <sys/wait.h>
    #include <unistd.h>

    typedef struct ftrace_s {
        int opt;
        int opt_idx;
        bool no_flag;
        bool s_flag;
        bool p_flag;
        bool i_flag;
        bool n_flag;
        bool o_flag;
        bool h_flag;

        pid_t child;
        long orig_eax;
        int status;
        int syscall_nr;
        struct user_regs_struct regs;
        int pRes;
    } ftrace_t;

    ftrace_t *init_ftrace_struct(void);
    void usage(ftrace_t *st);
    void handle_flag(ftrace_t *ftrace, int ac, char **av);
    void execute_ftrace(ftrace_t *ftrace, char **av);
    int print_string(pid_t child, struct user_regs_struct *regs, int i);
    int detailled_print(ftrace_t *st, int i);
    void flag_print(ftrace_t *st, int orig_eax);
    void print_ftrace(ftrace_t *st);
    void print_return_value(ftrace_t *st);
    unsigned long long syscall_table(struct user_regs_struct *regs, int i);
#endif /* !ftrace_H_ */
