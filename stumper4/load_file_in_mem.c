/*
** EPITECH PROJECT, 2022
** Duostumper 4
** File description:
** load file in mem
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *load_file(char *fp)
{
    struct stat st;
    int fd = 0;
    char *buffer = NULL;

    if (stat(fp, &st) < 0)
        exit(84);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    fd = open(fp, O_RDONLY);
    if ((buffer == NULL) || (fd < 0) || (read(fd, buffer, st.st_size) < 0))
        exit(84);
    buffer[st.st_size] = 0;
    close(fd);
    check_digits(buffer);
    return buffer;
}
