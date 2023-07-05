/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** set_difficulty.c
*/

#include "../../../../../include/game/rpg.h"

static const char *ITEM_RESURRECTION_S = "./assets/GameScene/items/"
"resurrection.png";
static const char *FLITEM_ITEM_RESURRECTION_S = "./assets/GameScene/inventory/"
"resurrection.png";

void add_item(game *scene, char *filepath, int id, char const **image);

void set_difficulty(game *scene)
{
    static bool pass = false;
    char const *tab[2] = {ITEM_RESURRECTION_S, FLITEM_ITEM_RESURRECTION_S};

    scene->difficulty = transaction(0);
    if (pass == true)
        return;
    for (; scene->difficulty > 0; scene->difficulty -= 1)
        add_item(scene, "resurrection.txt", ITEM_RESURRECTION, tab);
    pass = true;
}
