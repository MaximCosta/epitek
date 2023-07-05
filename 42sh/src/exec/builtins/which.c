/*
** EPITECH PROJECT, 2022
** 42sh [WSL: Ubuntu]
** File description:
** which
*/

#include "mysh.h"

static int build_path(minishell_t *minishell, char *split, int i)
{
    char buffer[1024] = {0};

    if (split[0] != '/' && minishell->path != 0) {
        my_strcpy(buffer, minishell->path[i]);
        my_strcat(buffer, "/");
    }
    my_strcat(buffer, split);
    if (!is_exec(buffer))
        return 0;
    printf("%s\n", buffer);
    return 1;
}

static int is_buildin(char *split)
{
    char *builtins[] = {"cd", "exit", "env", "setenv", "unsetenv",
        "which", "echo", "history", "where", "foreach", "repeat",
        "if", "jobs", "fg", NULL};

    for (int i = 0; builtins[i]; i++) {
        if (my_strcmp(split, builtins[i]) == 0) {
            printf("%s: shell built-in command.\n", split);
            return 1;
        }
    }
    return 0;
}

int minishell_which(minishell_t *minishell, char **split)
{
    int find = 0;

    if (split[1] == NULL) {
        ERROR("which: Too few arguments.\n");
        minishell->exit_status = 1;
        return (1);
    }
    for (int i = 0; split[++i]; find = 0) {
        if (is_buildin(split[i]))
            continue;
        for (int j = 0; minishell->path[j] && !find;
            find = build_path(minishell, split[i], j++));
        if (find == 0) {
            printf("%s: Command not found.\n", split[i]);
            minishell->exit_status = 1;
        }
    }
    return 1;
}