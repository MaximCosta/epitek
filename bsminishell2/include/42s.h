/*
** EPITECH PROJECT, 2022
** bsminishell2 [WSL: Ubuntu]
** File description:
** 42s
*/

#ifndef PIPES_H_
    #define PIPES_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #define bark(code) ({return code; 0;})
int exec(char *path, char **args, char **env, int fd_in, int fd_out, int is_next);
char **parser(char *str);


#endif /* !PIPES_H_ */
