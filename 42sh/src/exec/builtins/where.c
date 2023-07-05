/*
** EPITECH PROJECT, 2022
** 42sh [WSL: Ubuntu]
** File description:
** where
*/

#include "mysh.h"

static void build_path(minishell_t *minishell, char *split, int i)
{
    char buffer[1024] = {0};

    if (split[0] != '/' && minishell->path != 0) {
        my_strcpy(buffer, minishell->path[i]);
        my_strcat(buffer, "/");
    }
    my_strcat(buffer, split);
    if (is_exec(buffer))
        printf("%s\n", buffer);
}

static void is_buildin(char *split)
{
    char *builtins[] = {"cd", "exit", "env", "pwd", "setenv", "unsetenv",
        "which", "echo", "history", "where", "foreach", "repeat",
        "if", "jobs", "fg", NULL};

    for (int i = 0; builtins[i]; i++)
        if (my_strcmp(split, builtins[i]) == 0)
            printf("%s is a shell built-in\n", split);
}

static int slash_in_path(minishell_t *minishell, char *split)
{
    for (int i = 0; split[i]; i++)
        if (split[i] == '/') {
            ERROR("where: / in command makes no sense\n");
            minishell->exit_status = 1;
            return 1;
        }
    return 0;
}

int minishell_where(minishell_t *minishell, char **split)
{
    if (split[1] == NULL) {
        ERROR("where: Too few arguments.\n");
        minishell->exit_status = 1;
        return (1);
    }
    for (int i = 1; split[i]; i++) {
        if (slash_in_path(minishell, split[i]))
            continue;
        is_buildin(split[i]);
        for (int j = 0; minishell->path[j];
            build_path(minishell, split[i], j++));
    }
    return 1;
}