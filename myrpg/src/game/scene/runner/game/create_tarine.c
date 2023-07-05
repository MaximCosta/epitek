/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** init_tartines.c
*/

#include "../../../../../include/game/rpg.h"

static const char *R_TARTINE = "./assets/runner/tartine.png";
static const char *R_TARTINEB = "./assets/runner/tartineb.png";

void add_tartine(runner_game_t *runner, sfVector2f pos, int dir)
{
    int i = 0;

    for (i = 0; i < MAX_TARTINES; i++) {
        if (runner->tartines[i]->set)
            continue;
        runner->tartines[i]->set = 1;
        runner->tartines[i]->clicked = 0;
        runner->tartines[i]->obj->on_click = my_click;
        object_set_position(runner->tartines[i]->obj, pos);
        object_set_texture(runner->tartines[i]->obj,
                        sfTexture_createFromFile(R_TARTINE, NULL));
        object_set_visible(runner->tartines[i]->obj,
                                runner->tartines[i]->set);
        runner->tartines[i]->dir = dir;
        return;
    }
}

void add_tartine_random(runner_game_t *runner)
{
    int rd = random_int(100, 700);
    int rd2 = random_int(1, 256);

    if (rd2 % 2)
        add_tartine(runner, (sfVector2f) {-100, rd}, 1);
    else
        add_tartine(runner, (sfVector2f) {1920, rd}, -1);
}
