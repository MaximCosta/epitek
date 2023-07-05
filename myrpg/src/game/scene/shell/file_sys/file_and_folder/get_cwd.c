/*
** EPITECH PROJECT, 2021
** FILE
** File description:
** get_cwd.c
*/

#include "../../../../../../include/game/rpg.h"

char *get_cwd_(file_t *root, char *cwd)
{
    if (root->parent) {
        cwd = get_cwd_(root->parent, cwd);
        cwd = my_strcat(cwd, root->name);
        if (root->type == T_DIRECTORY)
            cwd = my_strcat(cwd, "/");
    } else {
        cwd = my_strcat(cwd, "/");
    }
    return cwd;
}

char *get_cwd(file_t *root, char *cwd)
{
    cwd = get_cwd_(root, cwd);

    while (cwd[my_strlen(cwd) - 1] == '/' && my_strlen(cwd) > 1)
        cwd[my_strlen(cwd) - 1] = '\0';
    return cwd;
}