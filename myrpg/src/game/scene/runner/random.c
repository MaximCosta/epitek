/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** random.c
*/

#include "../../../../include/game/rpg.h"

int random_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}