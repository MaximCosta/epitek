/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** create_enemy.c
*/

#include "../../../../../include/game/rpg.h"

static const char *E_BIG_S = "./assets/GameScene/Enemy/big.png";
static const char *E_DROID_S = "./assets/GameScene/Enemy/droid.png";
static const char *E_PHANTOM_S = "./assets/GameScene/Enemy/phantom.png";

void init_mob(game *scene, object_t *mob);
sfVector2i random_spawn(game *scene);
char *get_score(int n1, int n2);

void init_big(enemy_t *data, game *scene)
{
    data->as = 2000;
    data->damage = 25;
    data->detection = 200;
    data->pvmax = 500;
    data->pv = data->pvmax;
    data->speed = 1;
    data->vision = 500;
    data->top_attack = 504;
    data->top_idle = 444;
    data->top_damage = 444;
    data->top_run = 564;
    data->delay = 100;
    data->xpdrop = 250;
    data->dattack = (DeltaTime){.time = 0.00, .saved = 0.00};
    data->distance_attack = 60;
    data->dimension = (sfVector2f){145, 74};
    data->pv_text = textobject_create(PV_TEXT, (loc_t){0, 0},
    get_score(data->pv, data->pvmax));
    scene_add_text(&scene->objects, data->pv_text);
}

void init_droid(enemy_t *data, game *scene)
{
    data->as = 2500;
    data->damage = 5;
    data->detection = 400;
    data->pvmax = 75;
    data->pv = data->pvmax;
    data->speed = 2;
    data->vision = 600;
    data->top_attack = 240;
    data->top_idle = 240;
    data->top_damage = 660;
    data->top_run = 360;
    data->delay = 100;
    data->xpdrop = 100;
    data->distance_attack = 150;
    data->dattack = (DeltaTime){.time = 0.00, .saved = 0.00};
    data->dimension = (sfVector2f){135, 60};
    data->pv_text = textobject_create(PV_TEXT, (loc_t){0, 0},
    get_score(data->pv, data->pvmax));
    scene_add_text(&scene->objects, data->pv_text);
}

void init_phantom(enemy_t *data, game *scene)
{
    data->as = 1000;
    data->damage = 12.5;
    data->detection = 130;
    data->pvmax = 300;
    data->pv = data->pvmax;
    data->speed = 3;
    data->vision = 900;
    data->top_attack = 2604;
    data->top_idle = 1116;
    data->top_damage = 1116;
    data->top_run = 1240;
    data->delay = 20;
    data->xpdrop = 300;
    data->distance_attack = 60;
    data->dattack = (DeltaTime){.time = 0.00, .saved = 0.00};
    data->dimension = (sfVector2f){119, 124};
    data->pv_text = textobject_create(PV_TEXT, (loc_t){0, 0},
    get_score(data->pv, data->pvmax));
    scene_add_text(&scene->objects, data->pv_text);
}

object_t *create_mob(game *scene, enemy_t *data, char *type)
{
    sfVector2i spawn = random_spawn(scene);

    data->type = my_strdup(type);
    data->state = my_strdup("IDLE");
    data->delta.time = 0.00;
    data->delta.saved = 0.00;
    if (equal(type, "BIG")) {
        init_big(data, scene);
        return object_create_from_image(E_BIG, (loc_t){spawn.x, spawn.y},
        E_BIG_S);
    } else if (equal(type, "DROID")) {
        init_droid(data, scene);
        return object_create_from_image(E_DROID, (loc_t){spawn.x, spawn.y},
        E_DROID_S);
    }
    if (equal(type, "PHANTOM")) {
        init_phantom(data, scene);
        return object_create_from_image(E_PHANTOM, (loc_t){spawn.x,
        spawn.y}, E_PHANTOM_S);
    }
}

void create_enemy(game *scene, char *type)
{
    static int id = 0;
    mob_t *tmp = NULL;
    mob_t *new = NULL;
    enemy_t *data = malloc(sizeof(enemy_t));
    object_t *mob = NULL;

    if (scene->mobs == NULL) {
        scene->mobs = malloc(sizeof(mob_t));
        scene->mobs->data = data;
        scene->mobs->mob = create_mob(scene, scene->mobs->data, type);
        mob = scene->mobs->mob;
        scene->mobs->next = NULL;
        scene->mobs->id = id++;
        scene_add_object(&scene->objects, scene->mobs->mob);
    } else {
        tmp = scene->mobs;
        new = malloc(sizeof(mob_t));

        new->data = data;
        new->mob = create_mob(scene, new->data, type);
        new->next = NULL;
        for (;tmp->next != NULL; tmp = tmp->next);
        tmp->next = new;
        mob = new->mob;
        new->id = id++;
        scene_add_object(&scene->objects, new->mob);
    }
    init_mob(scene, mob);
}
