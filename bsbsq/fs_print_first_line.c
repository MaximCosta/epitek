/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-maxim.costa
** File description:
** fs_print_first_line
*/

#include <fcntl.h>
#include <unistd.h>

int my_putchar(char c);

void fs_print_first_line(char const *filepath)
{
    char buff[1];
    int fd = open(filepath, O_RDONLY);
    int len = 0;

    while (( len = read(fd, buff, 1)) > 0 && buff[0] != '\n')
        my_putchar(buff[0]);
    close(fd);
}
