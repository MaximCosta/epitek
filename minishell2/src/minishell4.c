/*
** EPITECH PROJECT, 2022
** minishell1 [WSL: Ubuntu]
** File description:
** minishell4
*/

#include "minishell.h"
#include <errno.h>

int my_env(env_t *fenv)
{
    env_shw(fenv->env);
    return 1;
}

int my_setnev(env_t *fenv)
{
    if (fenv->cmd[1] == NULL)
        return 1;
    if (fenv->cmd[2] == NULL)
        fenv->cmd[2] = my_strdup("");
    if (fenv->cmd[3] != NULL) {
        write(2, "setenv: Too many arguments.\n", 28);
        return 1;
    }
    env_set(fenv, fenv->cmd[1], fenv->cmd[2]);
    return 1;
}

int my_unsetenv(env_t *fenv)
{
    for (int i = 1; fenv->cmd[i]; i++)
        env_del(fenv->env, fenv->cmd[i]);
    return 1;
}

int error_cd(env_t *fenv, char *serr[40], int code)
{
    if (code == 0) {
        write(2, fenv->cmd[1], my_strlen(fenv->cmd[1]));
        write(2, serr[errno], my_strlen(serr[errno]));
        write(2, "\n", 1);
    }
    if (code == 1) {
        write(2, "cd: Too many arguments.\n", 24);
    }
    if (code == 2) {
        write(2, ": No such file or directory.\n", 29);
    }
    return 1;
}

int my_cd(env_t *fenv)
{
    char buf[PATH_MAX];
    char *serr[40];

    serr[ENOENT] = ": No such file or directory.";
    serr[EACCES] = ": Permission denied.";
    serr[ENOTDIR] = ": Not a directory.";
    serr[ENAMETOOLONG] = ": File name too long.";
    serr[ELOOP] = ": Too many levels of symbolic links";
    if (fenv->cmd[2] != NULL)
        return error_cd(fenv, serr, 1);
    if (fenv->cmd[1] == NULL)
        fenv->cmd[1] = fenv->puser;
    if (my_strncmp(fenv->cmd[1], "-", 1) == 0)
        fenv->cmd[1] = env_get(fenv->env, "OLDPWD=");
    if (fenv->cmd[0] == 0)
        return error_cd(fenv, serr, 2);
    if (chdir(fenv->cmd[1]) == -1)
        return error_cd(fenv, serr, 0);
    return my_cd_exec(fenv, buf);
}
