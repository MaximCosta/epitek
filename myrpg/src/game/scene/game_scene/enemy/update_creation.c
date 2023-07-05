/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** update_creation.c
*/

#include "../../../../../include/game/rpg.h"
#include <time.h>

void add_enemy(game *scene, int difficulty)
{
    int mob_ni = 0;

    if (difficulty == 1)
        mob_ni = (rand() % (100 - 0 + 1)) + 0;
    if (difficulty == 2)
        mob_ni = (rand() % (100 - 10 + 1)) + 10;
    if (difficulty == 3)
        mob_ni = (rand() % (100 - 30 + 1)) + 30;
    if (difficulty == 4)
        mob_ni = (rand() % (100 - 40 + 1)) + 40;
    if (mob_ni < 50)
        create_enemy(scene, "DROID");
    if (mob_ni >= 50 && mob_ni < 85)
        create_enemy(scene, "BIG");
    if (mob_ni >= 85 && mob_ni <= 100)
        create_enemy(scene, "PHANTOM");
}

void update_creation_enemy(game *scene)
{
    static DeltaTime delta = {.time = 0.00, .saved = 0.00};
    static int enemy_max = 0;

    srand(time(0));
    if (scene->difficulty == 1)
        enemy_max = (rand() % (15 - 5 + 1)) + 5;
    if (scene->difficulty == 2)
        enemy_max = (rand() % (20 - 10 + 1)) + 10;
    if (scene->difficulty == 3)
        enemy_max = (rand() % (25 - 15 + 1)) + 15;
    if (scene->difficulty == 4)
        enemy_max = (rand() % (35 - 25 + 1)) + 25;
    if (!elapsed_time_milliseconds(8000 / scene->difficulty,
    &delta.time, &delta.saved) || scene->player->PAUSE)
        return;
    if (scene->nb_enemy < enemy_max) {
        add_enemy(scene, scene->difficulty);
        scene->nb_enemy += 1;
    }
}
