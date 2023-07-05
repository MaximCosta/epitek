/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../include/asm.h"

bool is_index(char *instruction, int parami)
{
    if (my_strcmp(instruction, "zjmp") == 0
        || my_strcmp(instruction, "fork") == 0
        || my_strcmp(instruction, "lfork") == 0) {
        if (parami == 1)
            return true;
    }
    if (my_strcmp(instruction, "ldi") == 0
        || my_strcmp(instruction, "lldi") == 0) {
        if (parami == 1 || parami == 2)
            return true;
    }
    if (my_strcmp(instruction, "sti") == 0) {
        if (parami == 2 || parami == 3)
            return true;
    }
    return false;
}
