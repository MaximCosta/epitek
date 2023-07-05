/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** trader_input.c
*/

#include "../../../../../include/game/rpg.h"

void trader_input(game *scene, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed &&
    event->key.code == scene->key_input->interact && !scene->menu->active) {
        scene->player->INVENTORY_O = false;
        scene->trader->click = true;
    }
    if (event->type == sfEvtKeyReleased &&
    event->key.code == scene->key_input->interact && !scene->menu->active)
        scene->trader->click = false;
    if (scene->menu->edit_key && event->type == sfEvtKeyPressed) {
        scene->menu->input = event->text.unicode;
        scene->menu->edit_key = false;
    }
}
