/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** drag_and_drop.c
*/

#include "../../../../../include/game/rpg.h"

static char *MONEY_ITEM_S = "./assets/GameScene/inventory/money_item.png";

void just_check(object_t *object);

bool get_all_selected(game *scene, inventory_t *invent);

void add_flitem(game *scene, int *id, fli_transfert_t data, sfVector2f pos);

void remove_invent(inventory_t *invent)
{
    invent->item = NULL;
    invent->info.description = NULL;
    invent->info.filepath = NULL;
    invent->info.image_item = NULL;
    invent->info.image_flitem = NULL;
    invent->info.name = NULL;
    invent->info.name_text = NULL;
}

void flitem_drop(game *scene, inventory_t *invent, object_t *get)
{
    object_t *all_inventory = object_get_from_uuid(&scene->objects, INVENTORY);
    static int idd = 3500;
    fli_transfert_t data;

    if (!equal(invent->info.name, "MONEY"))
        data.name = my_strdup(invent->info.name);
    else {
        data.name = my_strcat(my_itoa(scene->player->money, 0), " $");
        scene->player->money = 0;
    }
    data.id_link = get->uuid;
    data.description = my_strdup(invent->info.description);
    data.filepath = my_strdup(invent->info.filepath);
    data.image_item = my_strdup(invent->info.image_item);
    data.image_flitem = my_strdup(invent->info.image_flitem);
    object_set_visible(get, false);
    object_set_rect(all_inventory, (sfIntRect){0, 0, 1300, 600});
    add_flitem(scene, (int[2]){idd++, FLI_MONEY}, data,
        object_get_position(object_get_from_uuid(&scene->objects, PLAYER)));
    remove_invent(invent);
}

void find_new_box(inventory_t *invent, game *scene, object_t *get, int i)
{
    object_t *all_inventory = object_get_from_uuid(&scene->objects, INVENTORY);
    bool equiped = false;

    if (i < 0)
        equiped = true;
    for (int i = 0; i != 32; i++) {
        if (object_on_hover(scene->cases[i].box, &just_check)
            && scene->cases[i].item == NULL) {
            invent->item = NULL;
            scene->cases[i].item = get;
            scene->cases[i].info.name = my_strdup(invent->info.name);
            scene->cases[i].info.description =
                my_strdup(invent->info.description);
            scene->cases[i].info.filepath = my_strdup(invent->info.filepath);
            scene->cases[i].info.image_item =
                my_strdup(invent->info.image_item);
            scene->cases[i].info.image_flitem =
                my_strdup(invent->info.image_flitem);
            invent->info.name = NULL;
        }
        if (object_on_unhover(all_inventory, &just_check) && !equiped)
            return flitem_drop(scene, invent, get);
    }
}

void cursor_select(object_t *cursor, object_t *get)
{
    static DeltaTime delta = {.time = 0.00, .saved = 0.00};

    for (int i = 0; i != 2; i++)
        if (elapsed_time_milliseconds(2, &delta.time, &delta.saved)
            && object_get_rect(cursor).left
                < object_get_origin_size(cursor).x - 47)
            object_set_rect(cursor,
                (sfIntRect){object_get_rect(cursor).left + 47, 0, 48, 48});
}

void drag_and_drop(game *scene, object_t *get, inventory_t *invent, int i)
{
    object_t *cursor = object_get_from_uuid(&scene->objects, CURSOR_GAME);
    object_t *all_inventory = object_get_from_uuid(&scene->objects, INVENTORY);

    if ((object_get_rect(cursor).left >= object_get_origin_size(cursor).x - 47)
        && (object_on_hover(invent->box, &just_check) || invent->selected)
        && get_all_selected(scene, invent)) {
        invent->selected = true;
        scene->save_hover = i;
        object_set_rect(get, (sfIntRect){48, 0, 48, 48});
        object_set_rect(all_inventory, (sfIntRect){1300, 0, 1300, 600});
        object_set_position(get, object_get_position(cursor));
    } else if (get_all_selected(scene, invent))
        object_set_rect(all_inventory, (sfIntRect){0, 0, 1300, 600});
    if (!scene->mouse_press) {
        if (invent->selected)
            find_new_box(invent, scene, get, i);
        invent->selected = false;
        object_set_rect(get, (sfIntRect){0, 0, 48, 48});
    }
}
