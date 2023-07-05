/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_crystal.c
*/

#include "../../../../../include/game/rpg.h"

static char *LAPIS_S = "./assets/GameScene/inventory/lapis.png";
static char *LAPIS_FLI_S = "./assets/GameScene/inventory/lapis_item.png";
static char *REDSTONE_S = "./assets/GameScene/inventory/redstone.png";
static char *REDSTONE_FLI_S = "./assets/GameScene/inventory/redstone_item.png";
static char *EMERAUDE_S = "./assets/GameScene/inventory/emeraude.png";
static char *EMERAUDE_FLI_S = "./assets/GameScene/inventory/emeraude_item.png";

void add_flitem(game *scene, int *id, fli_transfert_t data, sfVector2f pos);
char *find_name(char *filepath);
char *find_description(char *filepath);

bool get_if_drop(void)
{
    int lower = 0;
    int upper = 100;
    int num = 0;

    srand(time(0));
    num = (rand() % (upper - lower + 1)) + lower;
    if (num < 99)
        return true;
    return false;
}

char *get_name(char *type)
{
    if (equal(type, "DROID"))
        return "lapis.txt";
    if (equal(type, "BIG"))
        return "redstone.txt";
    if (equal(type, "PHANTOM"))
        return "emeraude.txt";
    return NULL;
}

void *get_image(char *filepath, fli_transfert_t *data, int *id)
{
    if (equal(filepath, "emeraude.txt")) {
        *id = EMERAUDE;
        data->image_item = EMERAUDE_S;
        data->image_flitem = EMERAUDE_FLI_S;
    }
    if (equal(filepath, "redstone.txt")) {
        *id = REDSTONE;
        data->image_item = REDSTONE_S;
        data->image_flitem = REDSTONE_FLI_S;
    }
    if (equal(filepath, "lapis.txt")) {
        *id = LAPIS;
        data->image_item = LAPIS_S;
        data->image_flitem = LAPIS_FLI_S;
    }
}

void add_crystal(game *scene, char *type, V2F pos)
{
    fli_transfert_t data = { 0 };
    char *filepath = NULL;
    int id = 0;
    static int idd = 2000;
    V2F player_pos = OGP(OGFuuid_t(&scene->objects, PLAYER));

    if (!get_if_drop())
        return;
    filepath = my_strcat("data/items/", my_strdup(get_name(type)));
    if (filepath == NULL)
        return;
    data.description = find_description(filepath);
    data.name = find_name(filepath);
    get_image(my_strdup(get_name(type)), &data, &id);
    data.id_link = 0;
    data.filepath = get_name(type);
    add_flitem(scene, (int[2]){idd++, id}, data, pos);
}
