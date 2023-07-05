/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** inventory.c
*/

#include "../../../../../include/game/rpg.h"

void just_check(object_t *object);

void drag_and_drop(game *scene, object_t *get, inventory_t *invent, int i);

void undisplay_info(game *scene, bool item);

void equiped(game *scene);

void cursor_select(object_t *cursor, object_t *get);

void visible(game *scene, object_t *inventory_o, object_t *player, object_t *case_o);

void display_info_money(game *scene, inventory_t *invent)
{
    char *str = "You have : ";
    char *money = my_itoa(scene->player->money, 0);
    char *devise = " $";

    if (invent->info.name == NULL)
        return;
    if (equal(invent->info.name, "MONEY"))
        invent->info.description =
            my_strdup(my_strcat(my_strcat(str, money), devise));
}

void display_info(game *scene, inventory_t *invent, bool *item)
{
    object_t *info = object_get_from_uuid(&scene->objects, INFO);
    object_t *cursor = object_get_from_uuid(&scene->objects, CURSOR_GAME);
    textobject_t *name = textobject_get_from_uuid(&scene->objects, INFO_NAME);
    textobject_t *description =
        textobject_get_from_uuid(&scene->objects, INFO_DESCRIPTION);
    sfVector2f pos = object_get_position(cursor);

    if (invent->item == NULL)
        return;
    pos.y -= 140;
    *item = true;
    display_info_money(scene, invent);
    object_set_position(info, pos);
    object_set_visible(info, true);
    textobject_set_string(name, invent->info.name);
    textobject_set_string(description, invent->info.description);
    textobject_set_size(name, 18);
    textobject_set_size(description, 10);
    textobject_set_position(name, (sfVector2f){pos.x - 65, pos.y - 102});
    textobject_set_position(description, (sfVector2f){pos.x - 70, pos.y - 60});
}

void box_rect(game *scene, bool *hover, inventory_t *invent, bool *item)
{
    object_t *cursor = object_get_from_uuid(&scene->objects, CURSOR_GAME);

    if (object_on_hover(invent->box, &just_check)) {
        *hover = true;
        if (!scene->mouse_press)
            object_set_rect(invent->box, (sfIntRect){100, 0, 100, 100});
        else
            object_set_rect(invent->box, (sfIntRect){200, 0, 100, 100});
        display_info(scene, invent, item);
    }
    if (object_on_unhover(invent->box, &just_check) && !scene->mouse_press)
        object_set_rect(cursor, (sfIntRect){0, 0, 32, 32});
    if (*hover) {
        if (!scene->mouse_press)
            object_set_rect(cursor, (sfIntRect){32, 0, 48, 48});
        else
            cursor_select(cursor, invent->box);
    } else
        object_set_rect(invent->box, (sfIntRect){0, 0, 100, 100});
}

void cases(game *scene, bool *item, bool *hover)
{
    sfVector2f pos = {960, 540};
    sfVector2f origin;
    *hover = false;

    pos.x -= 360;
    pos.y -= 220;
    origin = pos;
    for (int i = 0; i != 32; i++) {
        object_set_position(scene->cases[i].box, pos);
        if (scene->cases[i].item != NULL) {
            object_set_position(
                scene->cases[i].item, (sfVector2f){pos.x + 50, pos.y + 50});
            drag_and_drop(scene, scene->cases[i].item, &scene->cases[i], i);
        }
        box_rect(scene, hover, &scene->cases[i], item);
        pos.x += 120;
        if (pos.x > origin.x + 900) {
            pos.x = origin.x;
            pos.y += 120;
        }
    }
}

void inventory(game *scene)
{
    object_t *inventory_o = object_get_from_uuid(&scene->objects, INVENTORY);
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    object_t *case_o = object_get_from_uuid(&scene->objects, CASE);
    static bool item = false;
    static bool hover = false;

    visible(scene, inventory_o, player, case_o);
    undisplay_info(scene, hover);
    if (!scene->player->INVENTORY_O)
        return;
    cases(scene, &item, &hover);
    equiped(scene);
}
