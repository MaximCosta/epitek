/*
** EPITECH PROJECT, 2023
** B-PSU-400-MPL-4-1-ftrace-maxim.costa
** File description:
** ftrace
*/

#ifndef ftrace_H_
    #define ftrace_H_
    #define EXIT_EPITECH 84

    #include <ctype.h>
    #include <fcntl.h>
    #include <gelf.h>
    #include <getopt.h>
    #include <libelf.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/ptrace.h>
    #include <sys/reg.h>
    #include <sys/resource.h>
    #include <sys/stat.h>
    #include <sys/syscall.h>
    #include <sys/time.h>
    #include <sys/types.h>
    #include <sys/user.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <signal.h>
    #include "syscall.h"

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

    typedef struct {
        int sig;
    } signals_t;

    static signals_t signals[] = {{SIGHUP}, {SIGINT}, {SIGQUIT}, {SIGILL},
        {SIGTRAP}, {SIGABRT}, {SIGBUS}, {SIGFPE}, {SIGKILL}, {SIGUSR1},
        {SIGSEGV}, {SIGUSR2}, {SIGPIPE}, {SIGALRM}, {SIGTERM}, {SIGSTKFLT},
        {SIGCHLD}, {SIGCONT}, {SIGSTOP}, {SIGTSTP}, {SIGTTIN}, {SIGTTOU},
        {SIGURG}, {SIGXCPU}, {SIGXFSZ}, {SIGVTALRM}, {SIGPROF}, {SIGWINCH},
        {SIGIO}, {SIGPWR}, {SIGSYS},
        {0}};

    typedef struct nm_list_s {
        int64_t address;
        char *name;
        struct nm_list_s *next;
    } nm_list_t;

    typedef struct nm_s {
        int fd;
        Elf *elf;
        Elf_Scn *scn;
        Elf64_Shdr *shdr;
        Elf_Data *data;
        Elf64_Sym *sym;
        char *name;
        nm_list_t *list;
        int symtab_end;
    } nm_t;

    void execute_strace(ftrace_t *st, nm_t *nm, char **av);
    void list_dump(nm_list_t *list);
    void list_clear(nm_list_t **list);
    bool list_is_empty(nm_list_t *list);
    bool list_add_elem_at_back(nm_list_t **list, char *name, int64_t address);
    nm_t *init_nm_struct(void);
    bool error_handling_elf_file(nm_t *nm, char *filename);
    bool start_nm(nm_t *nm, char *filename);
    bool exit_message(const char *message);

    int get_signal(int status);
    int detailled_print(ftrace_t *st, int i);
    void print_return_value(ftrace_t *st);
    ftrace_t *init_ftrace_struct(void);
    void execute_fork(ftrace_t *st, char **av);
    void execute_ftrace(void);
    void exit_msg(char *msg);
    void loop_ftrace(ftrace_t *st, nm_t *nm);
    void print_ftrace(ftrace_t *st);
    void print_return_value(ftrace_t *st);
    void flag_print(ftrace_t *st, int orig_eax);
    int print_string(pid_t child, struct user_regs_struct *regs, int i);
    int detailled_print(ftrace_t *st, int i);
    unsigned long long syscall_table(struct user_regs_struct *regs, int i);

#endif /* !ftrace_H_ */
