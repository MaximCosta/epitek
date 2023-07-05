/*
** EPITECH PROJECT, 2022
** minishell1 [WSL: Ubuntu]
** File description:
** minishell6
*/

#include <errno.h>
#include <sys/wait.h>
#include "minishell.h"

void fork_wait(env_t *fenv, int *exit_code, char *line)
{
    pid_t pid;
    int wstat;

    fenv->cmd = str_split(" \t", line, 0);
    if (fenv->cmd[0] == NULL)
        return bash_print(fenv);
    if ((*exit_code = other_command(fenv)) == -1 && (pid = fork()) == 0)
        fork_process(fenv);
    waitpid(pid, &wstat, 0);
    *exit_code = WEXITSTATUS(wstat) == 1 ? WEXITSTATUS(wstat) : *exit_code;
    bash_print(fenv);
}

int env_set2(env_t *fenv, char *s1, char *s2, int i)
{
    for (i = 0; fenv->env[i]; i++) {
        if (my_strncmp(fenv->env[i], s1, my_strlen(s1)) == 0) {
            free(fenv->env[i]);
            s1 = concat(s1, "=");
            s1 = concat(s1, s2);
            fenv->env[i] = my_strdup(s1);
            return 1;
        }
    }
    return env_set1(fenv, s1, s2, i);
}

int my_cd_exec(env_t *fenv, char buf[PATH_MAX])
{
    env_set(fenv, "OLDPWD", env_get(fenv->env, "PWD="));
    getcwd(buf, PATH_MAX);
    env_set(fenv, "PWD", buf);
    return 1;
}