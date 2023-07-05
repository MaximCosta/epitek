/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** flitem.c
*/

#include "../../../../../include/game/rpg.h"

void flitem_process(game *scene)
{
    flitem_t *tmp = scene->flitem;
    sfVector2f pos;

    if (scene->player->PAUSE)
        return;
    for (; tmp != NULL; tmp = tmp->next) {
        pos = object_get_position(tmp->data->item);
        if (tmp->data->animation_path == 0
            && object_get_position(tmp->data->item).y
                < tmp->data->initial_pos + 5)
            object_set_position(tmp->data->item,
                (sfVector2f){pos.x, pos.y + (0.00001 * ENGINE->delta_time)});
        else
            tmp->data->animation_path = 1;
        if (tmp->data->animation_path == 1
            && object_get_position(tmp->data->item).y
                > tmp->data->initial_pos - 5)
            object_set_position(tmp->data->item,
                (sfVector2f){pos.x, pos.y - (0.00001 * ENGINE->delta_time)});
        else
            tmp->data->animation_path = 0;
        textobject_set_position(
            tmp->data->name, (sfVector2f){pos.x + 5, pos.y - 10});
    }
}

void flitem_settings(game *scene, flitem_t *new)
{
    textobject_set_size(new->data->name, 10);
    scene_add_object(&scene->objects, new->data->item);
    scene_add_text(&scene->objects, new->data->name);
    object_set_render_priority(new->data->item, 3);
}

void add_flitem(game *scene, int *id, fli_transfert_t data, sfVector2f pos)
{
    flitem_t *new = malloc(sizeof(flitem_t));
    flitem_t *tmp;

    new->data = malloc(sizeof(flidata_t));
    new->data->name =
        textobject_create(id[0], (loc_t){pos.x, pos.y}, data.name);
    new->data->initial_pos = pos.y;
    new->data->animation_path = 0;
    new->data->filepath = data.filepath;
    new->data->image_item = data.image_item;
    new->data->image_flitem = data.image_flitem;
    new->data->data = my_strdup(data.name);
    new->data->item = object_create_from_image(
        id[1], (loc_t){pos.x, pos.y}, data.image_flitem);
    new->data->id_link = data.id_link;
    new->data->description = data.description;
    new->next = NULL;
    if (scene->flitem != NULL) {
        tmp = scene->flitem;
        for (; tmp->next != NULL; tmp = tmp->next)
            ;
        tmp->next = new;
    } else
        scene->flitem = new;
    flitem_settings(scene, new);
}
