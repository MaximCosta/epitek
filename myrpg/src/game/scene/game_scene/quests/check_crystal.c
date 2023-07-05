/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** check_crystal.c
*/

#include "../../../../../include/game/rpg.h"

int findnflitem(game *scene, char *find)
{
    int i = 0;
    int r = 0;

    for (; i != 32; i++) {
        if (scene->cases[i].info.name == NULL || scene->cases[i].item == NULL)
            continue;
        if (equal(find, scene->cases[i].info.name))
            r += 1;
    }
    for (i = 0; i != 5; i++) {
        if (scene->equiped[i].info.name == NULL ||
        scene->equiped[i].item == NULL)
            continue;
        if (equal(find, scene->equiped[i].info.name))
            r += 1;
    }
    return r;
}

void crystal_update(game *scene, textobject_t *emeraude,
textobject_t *redstone, textobject_t *lapis)
{
    object_t *main_quest = OGFuuid_t(&scene->objects, MAIN_QUEST);
    V2F q_pos = OGP(main_quest);

    TSP(lapis, (V2F){q_pos.x + 55, q_pos.y + 109});
    TSP(emeraude, (V2F){q_pos.x + 67, q_pos.y + 122});
    TSP(redstone, (V2F){q_pos.x + 75, q_pos.y + 136});
    if (!scene->quests->on_click || !scene->quests->active) {
        object_set_visible(emeraude->object, false);
        object_set_visible(lapis->object, false);
        object_set_visible(redstone->object, false);
    } else {
        object_set_visible(emeraude->object, true);
        object_set_visible(lapis->object, true);
        object_set_visible(redstone->object, true);
    }
}

void check_crystal(game *scene)
{
    textobject_t *emeraude = TOGFUUID(&scene->objects, EMERAUDE_TEXT);
    textobject_t *redstone = TOGFUUID(&scene->objects, REDSTONE_TEXT);
    textobject_t *lapis = TOGFUUID(&scene->objects, LAPIS_TEXT);
    scene->quests->n_emeraude = findnflitem(scene, "Emeraude");
    scene->quests->n_redstone = findnflitem(scene, "Redstone");
    scene->quests->n_lapis = findnflitem(scene, "Lapis");

    if (scene->quests->n_emeraude >= 1)
        TOSTR(emeraude, my_strcat(MI(scene->quests->n_emeraude, 0), "/1"));
    else
        TOSTR(emeraude, "0/1");
    if (scene->quests->n_lapis >= 1)
        TOSTR(lapis, my_strcat(MI(scene->quests->n_lapis, 0), "/1"));
    else
        TOSTR(lapis, "0/1");
    if (scene->quests->n_redstone >= 1)
        TOSTR(redstone, my_strcat(MI(scene->quests->n_redstone, 0), "/1"));
    else
        TOSTR(redstone, "0/1");
    crystal_update(scene, emeraude, redstone, lapis);
}