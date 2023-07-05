/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../include/asm.h"

static char *get_last_word(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i]) {
        if (str[i] == '/')
            j = i + 1;
        i++;
    }
    return str + j;
}

void create_compiled_file(char *filename, parsing_t *parsing)
{
    char *file_name = my_strndup(filename, my_strlen(filename) - 2);
    int file_name_len = my_strlen(file_name);
    file_name = (char *) realloc(file_name, file_name_len + 5);
    file_name = my_strcat(file_name, ".cor");
    int fd = 0;

    if (!parsing->has_name || my_strlen(parsing->name) == 0)
        exit(84);
    fd = open(get_last_word(file_name), O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        exit(84);
    free(file_name);
    parsing->file_fd = fd;
}
