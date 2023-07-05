/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** cd.c
*/

#include "mysh.h"

static const char *cd_errors[] = {
    NULL,
    "%s: No such file or directory.\n",
    "%s: Permission denied.\n",
    "cd: Too many arguments.\n",
    "%s: Not a directory.\n",
    "%s: No such file or directory.\n",
    "cd: No home directory.\n",
};

int minishell_cd_error(minishell_t *minishell, int n, char *dest)
{
    ERROR(cd_errors[n], dest ? dest : "");
    minishell->exit_status = 1;
    return 1;
}

int minishell_cd_exec(minishell_t *minishell, char *dest)
{
    char pwd[1024] = {0};
    struct stat buff = {0};

    if (stat(dest, &buff) == -1)
        return minishell_cd_error(minishell, 1, dest);
    getcwd(pwd, 1024);
    if (chdir(dest) == -1 && !isit_file(dest))
        return minishell_cd_error(minishell, 2, dest);
    if (isit_file(dest))
        return minishell_cd_error(minishell, 4, dest);
    minishell_env_modif_value(minishell, "OLDPWD", pwd);
    minishell_env_modif_value(minishell, "PWD", getcwd(pwd, 1024));
    free(minishell->oldpwd);
    minishell->oldpwd = my_strdup(minishell_getenv(minishell, "OLDPWD"));
    return 1;
}

int minishell_cd(minishell_t *minishell, char **split)
{
    char pwd[1024] = {0};
    char *dest = split[1];
    struct stat buff = {0};

    if (split[1] == NULL)
        dest = minishell->home;
    if (!dest)
        return minishell_cd_error(minishell, 6, dest);
    if (split[1] && split[2])
        return minishell_cd_error(minishell, 3, dest);
    if (dest && !my_strcmp(dest, "-"))
        dest = minishell->oldpwd;
    if (!dest && !my_strcmp(split[1], "-"))
        return minishell_cd_error(minishell, 5, dest);
    minishell_cd_exec(minishell, dest);
    return 1;
}
