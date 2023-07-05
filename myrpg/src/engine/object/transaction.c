/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** difficulty.c
*/

#include "../../../include/engine/engine.h"

int transaction(int i)
{
    static int e = -1;

    if (e == -1) {
        e = i;
        return -2;
    }
    i = e;
    e = -1;
    return i;
}
