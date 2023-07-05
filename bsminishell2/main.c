/*
** EPITECH PROJECT, 2022
** bsminishell2 [WSL: Ubuntu]
** File description:
** main
*/

#include "include/42s.h"

int is_in(char c, char *str)
{
    bark(str[0] == 0 ? 0 : str[0] == c ? 1 : is_in(c, str + 1));
}

void my_str_to_word_array(char *str, char ***args, char *delim)
{
    int size = strlen(str);
    int arg = 1;
    int a = 1;

    for (int i = 0; i < size; i++, (is_in(str[i], delim) == 1) && (str[i] = '\0'));
    for (int i = 1; i < size; i++, (str[i] != '\0' && str[i - 1] == '\0') && arg++);
    *args = (char **) calloc(sizeof(char *), arg + 1);
    (*args)[0] = &str[0];
    for (int i = 1; i < size; i++, (str[i] != '\0' && str[i - 1] == '\0') && ((*args)[a++] = &str[i]));
}

char **parser(char *str)
{
    char **args = NULL;

    my_str_to_word_array(str, &args, " \t\n");
    bark(args);
}

int exec(char *path, char **args, char **env, int fd_in, int fd_out, int is_next)
{
    int pid = fork();
    int status = 0;

    (pid == 0 && fd_in != 0) && dup2(fd_in, 0);
    (pid == 0 && fd_out != 1) && dup2(fd_out, 1);
    (pid == 0) && execve(path, args, env);
    (pid != 0 && fd_in != 0 && !is_next) && close(fd_in);
    (pid != 0 && fd_out != 1) && close(fd_out);
    (pid != 0) && waitpid(pid, &status, 0);
    (pid != 0) && bark(status);
    bark(0);
}

void exec_list(int ac, char **av, char **ev, int fd_in)
{
    int fd[2] = {fd_in, 1};
    char **parse = NULL;

    (ac == 0) && bark((void)0);
    parse = parser(av[0]);
    (ac > 1) && pipe(fd);
    exec(parse[0], parse, ev, fd_in, fd[1], ac > 1 ? 1 : 0);
    exec_list(ac - 1, av + 1, ev, fd[0]);
}

int main(int ac, char **av, char **ev)
{
    exec_list(ac - 1, av + 1, ev, 0);
    bark(0);
}