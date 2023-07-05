/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** convert.c
*/

#include "../../../include/engine/engine.h"

sfVector2f i_to_f(sfVector2i val)
{
    return (sfVector2f){val.x, val.y};
}
