/*
** EPITECH PROJECT, 2021
** cat
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#include "../include/my.h"
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

void errors_print(int i, char **av, int ev)
{
    switch (ev) {
    case EACCES:
        write(2, av[i], my_strlen(av[i]));
        write(2, " Permission denied\n", 20);
        break;
    case ENOENT:
        write(2, av[i], my_strlen(av[i]));
        write(2, " No such file or directory\n", 28);
        break;
    case EISDIR:
        write(2, av[i], my_strlen(av[i]));
        write(2, " Error on open\n", 16);
        break;
    default:
        write(2, av[i], my_strlen(av[i]));
        write(2, " Error\n", 8);
    }
}

int user_get_input()
{
    int fd = 0;
    int fix_size = 30000;
    char buf[fix_size];
    int size = 1;

    while (size) {
        size = read(fd, buf, fix_size);
        buf[size] = 0;
        my_putstr(buf);
    }
    return 0;
}

int cat(int ac, char **av)
{
    int fd;
    int fix_size = 30000;
    char buf[fix_size];
    int size = 0;

    if (ac == 1)
        return user_get_input();
    for (int i = 1; i < ac; i++) {
        fd = open(av[i], O_RDONLY);
        if (fd == -1) {
            errors_print(i, av, errno);
            return 1;
        }
        size = read(fd, buf, fix_size);
        buf[size] = 0;
        my_putstr(buf);
        close(fd);
    }
    return 0;
}

int main(int ac, char **av)
{
    cat(ac, av);
}

