/*
** EPITECH PROJECT, 2021
** FILE
** File description:
** get.c
*/

#include "../../../../../../include/game/rpg.h"

file_t *get_path_single(file_t *root, char *path)
{
    if (!root || root->type != T_DIRECTORY)
        return 0;
    for (int i = 0; root->dir[i]; i++) {
        if (my_strcmp(root->dir[i]->name, path) == 0)
            return root->dir[i];
    }
    return 0;
}

static int move_to_folder_test(file_t **root, file_t *folder)
{
    if (folder->type != T_DIRECTORY) {
        error_code(3);
        return 1;
    }
    *root = folder;
    return 0;
}

static int move_to_folder(file_t **root, char *path)
{
    file_t *file = *root;

    if (!path)
        return 1;
    for (int i = 0; file->dir[i]; i++) {
        if (my_strcmp(file->dir[i]->name, path) == 0)
            return move_to_folder_test(root, file->dir[i]);
    }
    error_code(1);
    return 1;
}

static file_t *get_root(file_t *root)
{
    while (root->parent)
        root = root->parent;
    return root;
}

file_t *my_get_path(file_t **root, char *path)
{
    file_t *file = *root;
    char **splited_path = path && *path && file ? split_path(path) : 0;

    if (!splited_path)
        return file;
    if (*path == '/')
        file = get_root(file);
    for (int i = 0; splited_path[i]; i++) {
        if (!my_strcmp(splited_path[i], "."))
            continue;
        if (!my_strcmp(splited_path[i], "..") && file->parent)
            file = file->parent;
        if (!my_strcmp(splited_path[i], ".."))
            continue;
        if (!splited_path[i + 1])
            return get_path_single(file, splited_path[i]);
        if (move_to_folder(&file, splited_path[i]))
            return 0;
    }
    return file;
}