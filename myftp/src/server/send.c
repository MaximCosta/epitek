/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** socket
*/

#include "myftp.h"

int psend(int fd, const void *buf)
{
    printf("-(%d)-> %s\n", fd, (char *) buf);
    return send(fd, buf, strlen(buf), 0);
}
