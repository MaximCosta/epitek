/*
** EPITECH PROJECT, 2021
** FILE
** File description:
** myfile.h
*/

#ifndef MYFILE_H
    #define MYFILE_H

    #include "utils.h"

typedef struct file_s file_t;

enum FILE_TYPE {
    T_UNKNOW = -1,
    T_FILE = 0,
    T_DIRECTORY = 1,
    T_LINK = 2,
};

struct file_s {
    char *name;
    enum FILE_TYPE type;
    file_t *link;
    file_t *dir[256];
    file_t *parent;
    char *content;
};

//! Create

file_t *create_file(char *name);
file_t *create_folder(char *name);

void path_add_elem(file_t **root, file_t *elem);

int my_mkdir(file_t **root, char *path);
int my_touch(file_t **root, char *path);

//! get Path

file_t *my_get_path(file_t **root, char *path);
file_t *get_path_single(file_t *root, char *path);

char *get_cwd(file_t *root, char *cwd);

//! ERRORS

    #define ERROR_MSG get_error_message(error_code(-1))

const char *get_error_message(int error);
int error_code(int error);

//! Utils

char **split_path(char *path);

#endif /* MYFILE_H */