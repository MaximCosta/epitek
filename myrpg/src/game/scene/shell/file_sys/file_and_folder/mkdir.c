/*
** EPITECH PROJECT, 2021
** FILE
** File description:
** mkdir.c
*/

#include "../../../../../../include/game/rpg.h"
#include <stdio.h>
#include <stdlib.h>

static char *get_file_name(char *path)
{
    if (!path)
        return 0;
    while (path[my_strlen(path) - 1] == '/' && my_strlen(path) > 1)
        path[my_strlen(path) - 1] = '\0';
    while (get_index(path, '/') != -1)
        path = path + get_index(path, '/') + 1;
    return path;
}

static char *get_file_path(char *path)
{
    path = my_strdup(path);
    while (path[my_strlen(path) - 1] == '/' && my_strlen(path) > 1)
        path[my_strlen(path) - 1] = '\0';
    for (int i = my_strlen(path) - 1; i >= 0; i--) {
        if (path[i] == '/') {
            path[i] = '\0';
            return path;
        }
    }
    path[0] = '\0';
    return path;
}

static int mkdir_(file_t *file, char *name)
{
    if (!file || !name)
        return 1;
    if (file->type != T_DIRECTORY) {
        error_code(3);
        return 1;
    }
    if (get_path_single(file, name)) {
        error_code(5);
        return 1;
    }
    path_add_elem(&file, create_folder(name));
    return 0;
}

int my_mkdir(file_t **root, char *path)
{
    char *path_to_file = get_file_path(path);
    file_t *tmp = my_get_path(root, path_to_file);
    char *tp = my_strdup(path);

    if (!tmp || mkdir_(tmp, get_file_name(tp))) {
        free(tp);
        free(path_to_file);
        return 1;
    }
    free(tp);
    free(path_to_file);
    return 0;
}