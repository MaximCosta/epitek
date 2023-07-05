/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-maxim.costa
** File description:
** fs_get_number_from_first_line
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int find_my_num(char *buf, int i, int neg, int n)
{
    if ((buf[i] < '0' || buf[i] > '9') && neg == 1) neg = 0;
    if (buf[i] == '-') neg = 1;
    if (buf[i] >= '0' && buf[i] <= '9' && neg == 0) n = n * 10 + buf[i] - 48;
    if (buf[i] != '\n' && buf[i] != '\0') n = find_my_num(buf, i + 1, neg, n);
    return n;
}

int fs_get_number_from_first_line(char *filepath)
{

    int fd = open(filepath, O_RDONLY);
    struct stat buf;
    char *buff;
    int n = 0;

    stat(filepath, &buf);
    buff = malloc(sizeof(char) * (buf.st_size + 1));
    buff[buf.st_size + 1];
    close(fd);
    read(fd, buff, buf.st_size);
    n = find_my_num(buff, 0, 0, 0);
    if (n <= 0) return -1;
    return n;
}
