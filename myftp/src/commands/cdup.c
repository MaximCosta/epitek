/*
** EPITECH PROJECT, 2023
** myftp [WSL: Ubuntu]
** File description:
** cdup
*/

#include "myftp.h"

int handle_cdup_command(char *buffer, client_t *client)
{
    (void) buffer;

    if (check_state(-1, client))
        return 1;
    return 1;
}
