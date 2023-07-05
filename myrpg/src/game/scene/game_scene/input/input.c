/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** input.c
*/

#include "../../../../../include/game/rpg.h"

void trader_input(game *scene, sfEvent *event);

void mouse_input(game *scene, sfEvent *event)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);

    if (sfMouse_isButtonPressed(sfMouseLeft) && !scene->player->ATTACK
        && !scene->player->PAUSE && !scene->player->DASH
        && !scene->player->JETPACK && !scene->player->ENERGY_ATTACK) {
        scene->player->ATTACK = true;
        object_set_rect(player, (sfIntRect){1536, 0, 128, 64});
    }
}

void inventory_input(game *scene, sfEvent *event)
{
    static int id = 0;

    if (event->type == sfEvtKeyPressed &&
    event->key.code == scene->key_input->inventory && !scene->menu->active) {
        if (!scene->player->INVENTORY_O) {
            scene->player->INVENTORY_O = true;
            scene->player->PAUSE = true;
            scene->trader->active = false;
            scene->player->is_profile_gui_opened = false;
        } else {
            scene->player->INVENTORY_O = false;
            scene->player->PAUSE = false;
        }
    }
    if (event->type == sfEvtKeyPressed &&
    event->key.code == scene->key_input->interact &&
    !scene->player->INTERACTION && !scene->player->PAUSE
        && !scene->menu->active)
        scene->player->INTERACTION = true;
    if (!scene->player->INVENTORY_O && event->type == sfEvtKeyPressed
        && event->key.code == sfKeyP && !scene->menu->active) {
        if (scene->player->PAUSE) {
            scene->player->PAUSE = false;
            scene->trader->active = false;
        } else
            scene->player->PAUSE = true;
    }
}

void game_input_2(game *scene, sfEvent *event)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);

    if (event->type == sfEvtKeyPressed &&
    event->key.code == scene->key_input->jet_pack
        && scene->jet_power > 0 && !scene->player->ATTACK
        && !scene->player->PAUSE) {
        scene->player->JETPACK = true;
    }
    if (event->type == sfEvtKeyReleased &&
    event->key.code == scene->key_input->jet_pack)
        scene->player->JETPACK = false;

    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyE
        && !scene->player->ATTACK && !scene->player->ENERGY_ATTACK
        && !scene->player->PAUSE && !scene->player->DASH
        && !scene->player->JETPACK && scene->energy_power > 50) {
        scene->player->ENERGY_ATTACK = true;
        object_set_rect(player, (sfIntRect){384, 0, 128, 64});
    }
}

void game_input(game *scene, sfEvent *event)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);

    if (event->type == sfEvtKeyPressed &&
    event->key.code == scene->key_input->dash
        && !scene->player->DASH && !scene->player->ATTACK
        && !scene->player->PAUSE) {
        scene->dash_move = malloc(sizeof(int) * 3);
        scene->dash_move[0] = 8;
        scene->dash_move[1] = 4;
        scene->dash_move[2] = -128;
        if (object_get_scale(player).x > 0) {
            scene->dash_move[0] *= (-1);
            scene->dash_move[1] *= (-1);
            scene->dash_move[2] *= (-1);
        }
        scene->player->DASH = true;
        object_set_rect(player, (sfIntRect){256, 0, 128, 64});
    }
    game_input_2(scene, event);
}

void input(game *scene, sfEvent *event)
{
    mouse_input(scene, event);
    game_input(scene, event);
    inventory_input(scene, event);
    trader_input(scene, event);
    if (event->type == sfEvtKeyPressed &&
    event->key.code == scene->key_input->right)
        scene->player->RIGHT = true;
    if (event->type == sfEvtKeyReleased &&
    event->key.code == scene->key_input->right)
        scene->player->RIGHT = false;
    if (event->type == sfEvtKeyPressed &&
    event->key.code == scene->key_input->left)
        scene->player->LEFT = true;
    if (event->type == sfEvtKeyReleased &&
    event->key.code == scene->key_input->left)
        scene->player->LEFT = false;
    if (event->type == sfEvtKeyPressed &&
    event->key.code == scene->key_input->up)
        scene->player->UP = true;
    if (event->type == sfEvtKeyReleased &&
    event->key.code == scene->key_input->up)
        scene->player->UP = false;
    if (event->type == sfEvtKeyPressed &&
    event->key.code == scene->key_input->down)
        scene->player->DOWN = true;
    if (event->type == sfEvtKeyReleased &&
    event->key.code == scene->key_input->down)
        scene->player->DOWN = false;
}
