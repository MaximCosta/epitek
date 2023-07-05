/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-bsnavy-maxim.costa [WSL: Ubuntu]
** File description:
** main
*/

#include "my.h"
#include <sys/types.h>
#include <unistd.h>

// write a function who display pid process information
int main(void)
{
    pid_t pid = getpid();
    pid_t ppid = getppid();
    pid_t pgid = getpgid(pid);

    my_printf("PID : %d\n", pid);
    my_printf("PPID : %d\n", ppid);
    my_printf("PGID : %d\n", pgid);
}