/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-maxim.costa
** File description:
** fs_cat_x_bytes
*/

#include <fcntl.h>
#include <unistd.h>

int fs_open_file(char const *filepath);
void my_putchar(char c);

void fs_cat_x_bytes(char const *filepath, int x)
{
    char buff[1];
    int fd;

    if ((fd = open(filepath, O_RDONLY)) < 0) return;
    for (int i = 0; i < x && read(fd, buff, 1) > 0; i++)
        my_putchar(buff[0]);
    close(fd);
}