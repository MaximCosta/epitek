/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** text_position.c
*/

#include "../../../../include/engine/engine.h"

void textobject_set_position(textobject_t *object, sfVector2f pos)
{
    sfText_setPosition(object->text, pos);
}
