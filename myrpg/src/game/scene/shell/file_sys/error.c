/*
** EPITECH PROJECT, 2021
** FILE
** File description:
** error.c
*/

#include "../../../../../include/game/rpg.h"

static const char *error_messages[] = {
    "No Error",
    "No such file or directory",
    "Permission denied",
    "Not a directory",
    "Is a directory",
    "File exists",
};

const char *get_error_message(int error)
{
    return error_messages[error];
}

int error_code(int error)
{
    static int err = 0;

    if (error != -1)
        err = error;
    return err;
}
