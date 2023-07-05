/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** equiped.c
*/

#include "../../../../../include/game/rpg.h"

void just_check(object_t *object);

void display_info(game *scene, inventory_t *invent, bool *item);

void cursor_select(object_t *cursor, object_t *get);

void drag_and_drop(game *scene, object_t *get, inventory_t *invent, int i);

void add_equipement(game *scene)
{
    object_t *all_inventory = object_get_from_uuid(&scene->objects, INVENTORY);

    if (scene->save_hover == -1)
        return;
    for (int i = 0; i != 5; i++) {
        if (scene->equiped[i].item == NULL
            && scene->cases[scene->save_hover].item != NULL) {
            scene->equiped[i].item = scene->cases[scene->save_hover].item;
            scene->equiped[i].info.name =
                scene->cases[scene->save_hover].info.name;
            scene->equiped[i].info.description =
                scene->cases[scene->save_hover].info.description;
            scene->equiped[i].info.filepath =
                scene->cases[scene->save_hover].info.filepath;
            scene->equiped[i].info.image_item =
                scene->cases[scene->save_hover].info.image_item;
            scene->equiped[i].info.image_flitem =
                scene->cases[scene->save_hover].info.image_flitem;
            scene->cases[scene->save_hover].item = NULL;
            object_set_rect(all_inventory, (sfIntRect){0, 0, 1300, 600});
        }
    }
}

void equiped_event(game *scene, inventory_t *invent)
{
    object_t *cursor = object_get_from_uuid(&scene->objects, CURSOR_GAME);
    sfVector2f pos = object_get_position(invent->box);
    object_t *info = object_get_from_uuid(&scene->objects, INFO);
    bool item = true;

    if (object_on_hover(invent->box, &just_check) && !scene->mouse_press) {
        object_set_rect(cursor, (sfIntRect){32, 0, 48, 48});
        object_set_rect(invent->box, (sfIntRect){226, 0, 226, 89});
        add_equipement(scene);
    }
    if (object_on_hover(invent->box, &just_check) && invent->item != NULL)
        display_info(scene, invent, &item);
    if (object_on_unhover(invent->box, &just_check))
        object_set_rect(invent->box, (sfIntRect){0, 0, 226, 89});
    if (invent->item != NULL)
        object_set_position(
            invent->item, (sfVector2f){pos.x + 50, pos.y + 40});
}

void equiped_set_pos(inventory_t *invent, int i, object_t *player, game *scene)
{
    sfVector2f position = {960, 540};
    sfVector2f pos;

    if (i == 0)
        object_set_position(
            invent->box, (sfVector2f){position.x - 650, position.y - 180});
    else {
        pos = object_get_position(scene->equiped[i - 1].box);
        pos.y += object_get_size(scene->equiped[i - 1].box).y;
        object_set_position(invent->box, pos);
    }
}

void draw_name(game *scene, int draw)
{
    textobject_t *name = scene->equiped[draw].info.name_text;
    sfVector2f pos;

    if (scene->equiped[draw].item == NULL) {
        textobject_set_string(name, "");
        return;
    }
    pos = object_get_position(scene->equiped[draw].box);
    pos.x += 100;
    pos.y += 30;
    textobject_set_string(name, scene->equiped[draw].info.name);
    textobject_set_size(name, 15);
    textobject_set_position(name, pos);
}

void equiped(game *scene)
{
    object_t *cursor = object_get_from_uuid(&scene->objects, CURSOR_GAME);
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);

    for (int i = 0; i != 5; i++) {
        equiped_event(scene, &scene->equiped[i]);
        equiped_set_pos(&scene->equiped[i], i, player, scene);
        draw_name(scene, i);
        if (scene->mouse_press
            && object_on_hover(scene->equiped[i].box, &just_check))
            cursor_select(cursor, scene->equiped[i].box);
        if (scene->equiped[i].item != NULL)
            drag_and_drop(
                scene, scene->equiped[i].item, &scene->equiped[i], -1);
    }
    if (!scene->mouse_press)
        scene->save_hover = -1;
}
