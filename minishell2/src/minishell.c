/*
** EPITECH PROJECT, 2022
** minishell1 [WSL: Ubuntu]
** File description:
** minishell
*/

#include "minishell.h"
#include <errno.h>
#include <sys/wait.h>

int other_command(env_t *fenv)
{
    if (my_strcmp(fenv->cmd[0], "exit") == 0)
        return exit_code(fenv->cmd);
    if (my_strcmp(fenv->cmd[0], "env") == 0)
        return my_env(fenv);
    if (my_strcmp(fenv->cmd[0], "setenv") == 0)
        return my_setnev(fenv);
    if (my_strcmp(fenv->cmd[0], "unsetenv") == 0)
        return my_unsetenv(fenv);
    if (my_strcmp(fenv->cmd[0], "cd") == 0)
        return my_cd(fenv);
    return -1;
}

char *get_execute(env_t *fenv)
{
    char *full = NULL;
    char *save = fenv->cmd[0];
    int find = -1;

    if (my_strncmp(fenv->cmd[0], "./", 2) == 0) {
        find = execve(fenv->cmd[0], fenv->cmd, fenv->env);
        fenv->cmd[0] = save;
        if (find == -1)
            return NULL;
        return fenv->cmd[0];
    }
    for (int i = 0; find == -1; i++) {
        if (!fenv->paths[i])
            break;
        full = str_catcat(fenv->paths[i], "/", fenv->cmd[0]);
        find = execve(full, fenv->cmd, fenv->env);
        fenv->cmd[0] = save;
    }
    return find != -1 ? full : NULL;
}

void get_path(char **env, env_t *fenv)
{
    char *path = NULL;

    fenv->env = my_strdump2d(env, 0);
    for (int i = 0; env[i]; i++) {
        if (my_strncmp("PATH=", env[i], 5) == 0)
            path = my_strdup(env[i] + 5);
        if (my_strncmp("USER=", env[i], 5) == 0)
            fenv->user = env[i] + 5;
        if (my_strncmp("NAME=", env[i], 5) == 0)
            fenv->host = env[i] + 5;
    }
    fenv->lenh = fenv->user != NULL ? 5 + my_strlen(fenv->user) : 0;
    fenv->paths = str_split(":", path, 1);
    fenv->lenp = my_strlen_2d(fenv->paths);
    fenv->paths[fenv->lenp] = malloc(PATH_MAX);
    fenv->puser = malloc(fenv->lenh);
    if (fenv->lenh) {
        my_strcat(fenv->puser, "/home/");
        my_strcat(fenv->puser, fenv->user);
    }
}

void bash_print(env_t *fenv)
{
    char back = 0;
    char *cwd;

    getcwd(fenv->paths[fenv->lenp], PATH_MAX);
    cwd = fenv->paths[fenv->lenp];
    if (my_strncmp(cwd, fenv->puser, fenv->lenh) == 0) {
        cwd += fenv->lenh;
        back = cwd[0];
        cwd[0] = '~';
    }
    if (isatty(0))
        my_printf("\033[4m%s\033[0m:\033[1m%s\033[0m> ", fenv->host, cwd);
    if (back != 0)
        cwd[0] = back;
}

int main(int argc, char **argv, char **env)
{
    env_t *fenv = malloc(sizeof(env_t));
    int exit_code = 0;
    size_t len = 0;
    ssize_t read;
    char *line;

    get_path(env, fenv);
    bash_print(fenv);
    while ((read = getline(&line, &len, stdin)) > 0) {
        line = strtok(line, ";");
        if (read == 1 || line[0] == '\n' || line[0] == '\0') {
            bash_print(fenv);
            continue;
        }
        while (line != NULL) {
            fork_wait(fenv, &exit_code, line);
            line = strtok(NULL, ";");
        }
    }
    return (exit_code < 0 ? 0 : (exit_code));
}
