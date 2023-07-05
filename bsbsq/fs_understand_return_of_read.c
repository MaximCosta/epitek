/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-maxim.costa
** File description:
** fs_understand_return_of_read
*/

#include <fcntl.h>
#include <unistd.h>

void my_putstr(char const *str);
void my_putstr_err(char const *str);

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int len = read(fd, buffer, size);

    if (len == -1) {
        my_putstr_err("read failed\n");
        return;
    }
    if (len == 0) {
        my_putstr("read has nothing more to read\n");
        return;
    }
    if (len < size) {
        my_putstr("read didn't complete the entire buffer\n");
        return;
    }
    if (len == size) {
        my_putstr("read completed the entire buffer\n");
        return;
    }
}
