/*
** EPITECH PROJECT, 2023
** ftrace [WSL: Ubuntu]
** File description:
** troll
*/

#include "ftrace.h"

char *my_func[] = {
    "my_putchar","my_putchar_err","my_strstr","my_isneg","my_strcmp",
    "my_put_nbr","my_strncmp","my_swap","my_strupcase","my_putstr",
    "my_putstr_err","my_strlowcase","my_strlen","my_strcapitalize",
    "my_getnbr","my_str_isalpha","my_sort_int_array","my_str_isnum",
    "my_compute_power_rec","my_str_islower","my_compute_square_root",
    "my_str_isupper","my_is_prime","my_str_isprintable","my_exit",
    "my_find_prime_sup","my_showstr","my_strcpy","my_showmem","my_strncpy",
    "my_strcat","my_revstr","my_strncat","my_str_to_word_array", "main",
    "my_putnbr_base","my_max","my_min","my_abs","my_strswap","my_calloc",
    "calloc", "malloc", "main", "printf", "my_printf",
    "should_i_stay_or_should_i_go", NULL
};

char *my_sig[] = {
    "SIGWINCH","SIGTSTP","SIGCONT","SIGINT","SIGQUIT","SIGILL","SIGTRAP",
    "SIGABRT","SIGFPE","SIGKILL","SIGSEGV","SIGPIPE","SIGALRM","SIGTERM",
    "SIGUSR1","SIGUSR2","SIGCHLD","SIGCONT","SIGSTOP","SIGTSTP","SIGTTIN",
    "SIGTTOU","SIGURG","SIGXCPU","SIGXFSZ","SIGVTALRM","SIGPROF","SIGWINCH",
    "SIGIO","SIGPWR","SIGSYS","SIGRTMIN", NULL
};

void execute_ftrace(void)
{
    for (int i = 0; my_func[i]; i++) {
        int *ptr = malloc(sizeof(int));
        printf("Entering function %s at %p\n", my_func[i], ptr);
        printf("Leaving function %s\n", my_func[i]);
    }
    for (int i = 0; i < 330; i++) {
        printf("Syscall %s(0x1, 0xff3210123, 0x1) = 0x1\n", table[i].name);
    }
    for (int i = 0; my_sig[i]; i++) {
        printf("Received signal %s\n", my_sig[i]);
    }
    for (int i = 0; i < 1000000; i++) {
        printf("I'm a troll = %p\n", i);
    }
}
