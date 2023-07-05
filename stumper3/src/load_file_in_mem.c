/*
** EPITECH PROJECT, 2022
** Duostumper 3
** File description:
** load file in mem
*/

#include "sand.h"

void compare_counts(int count1, int count2)
{
    if (count1 != count2)
        my_exit("Error: the number of lines is not the same\n", 84);
}

void check_lines_len(char *buffer)
{
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        count1++;
    for (int i = 0; buffer[i] != 0; i++) {
        if (buffer[i] == '\n') {
            compare_counts(count1, count2);
            count2 = 0;
            continue;
        }
        count2++;
    }
}

char *load_file_in_mem(char *fp, char *str)
{
    struct stat st;
    char *buffer = NULL;
    int fd;

    stat(fp, &st);
    buffer = calloc(sizeof(char), st.st_size + 1);
    fd = open(fp, O_RDONLY);
    if (fd < 0)
        my_exit("Error: can't open file\n", 84);
    if (read(fd, buffer, st.st_size) < 0)
        my_exit("Error: can't read file\n", 84);
    close(fd);
    check_lines_len(buffer);
    check_map(str, buffer);
    return buffer;
}
