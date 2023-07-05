/*
** EPITECH PROJECT, 2022
** Stumper 2
** File description:
** Game of life
*/

#include "./include/my.h"

char *load_file_in_mem(char *fp)
{
    struct stat st;
    char *buffer;
    int ssize;
    int size;
    int fd;

    stat(fp, &st);
    size = st.st_size;
    fd = open(fp, O_RDONLY);
    if (fd < 0)
         exit(84);
    buffer = malloc(sizeof(char) * size + 1);
    if (buffer == NULL)
        exit(84);
    ssize = read(fd, buffer, size);
    if (ssize < 0)
        exit(84);
    buffer[size] = 0;
    return buffer;
}
