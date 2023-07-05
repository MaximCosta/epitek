/*
** EPITECH PROJECT, 2021
** FILE
** File description:
** create.c
*/

#include "../../../../../../include/game/rpg.h"

file_t *create_file(char *name)
{
    file_t *file = my_calloc(sizeof(file_t));

    file->name = my_strdup(name);
    file->type = T_FILE;
    return file;
}

file_t *create_folder(char *name)
{
    file_t *folder = my_calloc(sizeof(file_t));

    folder->name = my_strdup(name);
    folder->type = T_DIRECTORY;
    return folder;
}

void path_add_elem(file_t **root, file_t *elem)
{
    file_t *tmp = *root;

    if (!*root) {
        *root = elem;
        return;
    }
    if ((*root)->type != T_DIRECTORY)
        return;
    for (int i = 0; i < 256; i++) {
        if (!tmp->dir[i]) {
            tmp->dir[i] = elem;
            tmp->dir[i]->parent = tmp;
            return;
        }
    }
}