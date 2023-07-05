/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../include/asm.h"

static bool very_stupid_norm(op_t op, char **splitted, bool *found)
{
    if (my_strcmp(op.mnemonique, *splitted) == 0) {
        if (*found)
            return true;
        *found = true;
    }
    return false;
}

static bool stupid_norm(char **splitted, bool *found)
{
    op_t op;

    for (int i = 0; i < 16; i++) {
        op = op_tab[i];
        if (very_stupid_norm(op, splitted, found))
            return true;
    }
    return false;
}

bool has_multiple_operation(char *line)
{
    char **splitted = split(line, " \t");
    bool found = false;

    if (!splitted)
        return false;
    while (*splitted) {
        if (stupid_norm(splitted, &found))
            return true;
        splitted++;
    }
    return false;
}
