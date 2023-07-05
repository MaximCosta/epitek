/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** take_item.c
*/

#include "../../../../../include/game/rpg.h"

void add_item(game *scene, char *filepath, int id, char const **image);

void delete_filtem(game *scene, flitem_t *tmp, flitem_t *previous)
{
    textobject_set_size(tmp->data->name, 0);
    textobject_set_string(tmp->data->name, "");
    object_set_visible(tmp->data->item, false);
    if (previous == NULL) {
        scene->flitem = scene->flitem->next;
        tmp = tmp->next;
        scene->player->INTERACTION = false;
        return;
    }
    previous->next = tmp->next;
}

bool findflitem(game *scene, char *find)
{
    int i = 0;

    for (; i != 32; i++) {
        if (scene->cases[i].info.name == NULL)
            continue;
        if (equal(find, scene->cases[i].info.name))
            return true;
    }
    for (i = 0; i != 5; i++) {
        if (scene->equiped[i].info.name == NULL)
            continue;
        if (equal(find, scene->equiped[i].info.name))
            return true;
    }
    return false;
}

void in_contact(game *scene, flitem_t *tmp, flitem_t *previous)
{
    if (!strfind(tmp->data->data, "XP")) {
        if (!charnfind(tmp->data->data, '$') || !findflitem(scene, "MONEY")) {
            add_item(scene, tmp->data->filepath, tmp->data->id_link,
                (char const *[2]){
                    tmp->data->image_item, tmp->data->image_flitem});
            scene->player->money += my_getnbr(tmp->data->data);
        } else
            scene->player->money += my_getnbr(tmp->data->data);
    } else
        scene->player->xp += my_getnbr(tmp->data->data);
    delete_filtem(scene, tmp, previous);
}

void take_item(game *scene)
{
    object_t *player = object_get_from_uuid(&scene->objects, PLAYER);
    flitem_t *tmp = scene->flitem;
    flitem_t *previous = NULL;
    sfFloatRect player_rect = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect item_rect = {0};
    int i = 0;

    if (!scene->player->INTERACTION)
        return;
    previous = NULL;
    for (; tmp != NULL && scene->player->INTERACTION; tmp = tmp->next) {
        item_rect = sfSprite_getGlobalBounds(tmp->data->item->sprite);
        if (sfFloatRect_intersects(&player_rect, &item_rect, NULL) == sfTrue) {
            i++;
            in_contact(scene, tmp, previous);
        }
        previous = tmp;
    }
    if (i != 0)
        scene->player->INTERACTION = false;
}
