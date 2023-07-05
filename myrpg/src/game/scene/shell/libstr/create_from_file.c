/*
** EPITECH PROJECT, 2021
** libstr
** File description:
** create_from_file.c
*/

#include "../../../../../include/game/rpg.h"

// size_t get_file_size(const char *filepath)
// {
//     struct stat st = {0};

//     if (stat(filepath, &st) == -1)
//         return -1;
//     return st.st_size;
// }

// char *get_file_content(const char *filepath)
// {
//     char *content = NULL;
//     int fd = 0;
//     size_t size = get_file_size(filepath);

//     if (size == -1)
//         return NULL;
//     if (!(content = my_calloc(sizeof(char) * (size + 1))))
//         return NULL;
//     if ((fd = open(filepath, O_RDONLY)) == -1) {
//         free(content);
//         return NULL;
//     }
//     if (read(fd, content, size) == -1) {
//         free(content);
//         return NULL;
//     }
//     return content;
// }

// str_t *str_create_from_file(const char *filepath)
// {
//     char *content = get_file_content(filepath);
//     size_t file_size = get_file_size(filepath);
//     str_t *new_str = NULL;
//     int fd = 0;

//     if (!content)
//         return NULL;
//     new_str = my_calloc(sizeof(str_t));
//     if (!new_str) {
//         free(content);
//         return NULL;
//     }
//     new_str->str = content;
//     new_str->len = file_size;
//     new_str->size = file_size;
//     return new_str;
// }