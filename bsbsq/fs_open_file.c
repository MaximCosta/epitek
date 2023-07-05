/*
** EPITECH PROJECT, 2021
** main
** File description:
** vim-epitech made by x4m3
*/

#include <fcntl.h>
#include <unistd.h>

int my_putstr(char const *str);
int my_putstr_err(char const *str);

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        my_putstr_err("FAILURE\n");
    else
        my_putstr("SUCCESS\n");
    return fd;
}
