/*
** EPITECH PROJECT, 2022
** bsminishell1 [WSL: Ubuntu]
** File description:
** main
*/

#include "my.h"
#include "my_printf.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv, char **env)
{
    // for (int i = 1; env[i] != 0; my_printf("%s\n", env[i++]));
    int status = 0;
    pid_t pid = fork();
    argv[0] = my_strdup(argv[1]);
    strtok(argv[1], " ");

    if (argc == 1 || env == NULL) return 84;
    if (pid == 0) {
        execve(argv[1], &argv[0], 0);
    } else {
        my_printf("Program name: %s %s\nPID: %d\nChild PID: %d\n", argv[1], argv[0], getpid(), pid);
        waitpid(pid, &status, 0);
        my_printf("Program terminated.\n");
        my_printf("Status: ");
        if (status == 0) {
            my_printf("OK\n");
        } else {
            my_printf("Segmentation fault\n");
        }
    }
}

// void ls()
// {
//     char *argv[] = {"/bin/ls"};
//     char *newargv[] = {NULL};
//     char *newenviron[] = {NULL};

//     execve(argv[0], newargv, newenviron);
//     perror("execve");
//     my_printf("j'ai fais ls!\n");
// }

// void print_arg(char **arg)
// {
//     char *str1;
//     char *token;
//     int j;

//     for (int j = 0;; j++) {
//         token = strtok(arg[1], " ");
//         if (token == NULL) break;
//         my_printf("%s\n", token);
//     }
// }
