/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-maxim.costa
** File description:
** fs_cat_500_bytes
*/

#include <fcntl.h>
#include <unistd.h>

int fs_open_file(char const *filepath);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);

void fs_cat_500_bytes(char const *filepath)
{
    char buff[501] = { 0 };
    int fd;

    if ((fd = open(filepath, O_RDONLY)) < 0) return;
    if (read(fd, buff, 500) > 0) my_putstr(buff);
    close(fd);
}
