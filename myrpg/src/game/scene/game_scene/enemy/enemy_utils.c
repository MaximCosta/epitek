/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** enemy_utils.c
*/

#include "../../../../../include/game/rpg.h"

static char *MONEY_ITEM_S = "./assets/GameScene/inventory/money_item.png";
static char *MONEY_S = "./assets/GameScene/inventory/money.png";
static char *XP_S = "./assets/GameScene/inventory/xp.png";

void add_flitem(game *scene, int *id, fli_transfert_t data, sfVector2f pos);
void add_crystal(game *scene, char *name, V2F pos);

char *get_score(int n1, int n2)
{
    return my_strcat(my_strcat(my_itoa(n1, 0), " / "), my_itoa(n2, 0));
}

void action_delete(mob_t *previous, mob_t *actual, game *scene)
{
    if (previous != NULL) {
        scene_remove_object(&scene->objects, actual->data->pv_text);
        scene_remove_object(&scene->objects, actual->mob);
        previous->next = actual->next;
    } else {
        scene_remove_object(&scene->objects, actual->data->pv_text);
        scene_remove_object(&scene->objects, actual->mob);
        scene->mobs = scene->mobs->next;
    }
}

fli_transfert_t drop_money(fli_transfert_t data)
{
    data.description = my_strdup("");
    data.filepath = "money.txt";
    data.id_link = 0;
    data.image_item = MONEY_S;
    data.image_flitem = MONEY_ITEM_S;
    return data;
}

fli_transfert_t drop_xp(fli_transfert_t xp, mob_t *mob)
{
    xp.description = my_strdup("");
    xp.filepath = my_strdup("");
    xp.id_link = 0;
    xp.image_item = "";
    xp.image_flitem = XP_S;
    return xp;
}

bool delete_enemy(game *scene, mob_t *mob, int id)
{
    static int idd = 1000;
    mob_t *tmp = mob;
    mob_t *previous;
    sfVector2f pos = {0};
    fli_transfert_t data = drop_money(data);
    fli_transfert_t xp = drop_xp(xp, mob);

    previous = NULL;
    for (; tmp != NULL; previous = tmp, tmp = tmp->next)
        if (tmp->id == id) {
            data.name = my_strcat(my_itoa(tmp->data->pvmax, 0), " $");
            xp.name = my_strcat(my_itoa(tmp->data->xpdrop, 0), " XP");
            pos = object_get_position(tmp->mob);
            add_flitem(scene, (int[2]){idd++, idd++}, data, pos);
            add_flitem(scene, (int[2]){idd++, idd++}, xp,
            (sfVector2f){pos.x, pos.y - 45});
            add_crystal(scene, tmp->data->type, (V2F){pos.x + 20, pos.y - 15});
            action_delete(previous, tmp, scene);
            scene->nb_enemy -= 1;
            return true;
        }
    return false;
}
