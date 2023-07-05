/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** create_planete.c
*/

#include "../../../../include/game/rpg.h"

static const char *TARTINE_FONT = "./assets/SpaceShip/bark.otf";

static void init_text(
    SpaceShip *scene_menu, space_planete_t *pl, SpacePlanetInit init)
{
    sfFont *font = sfFont_createFromFile(TARTINE_FONT);

    textobject_set_font(pl->text, font);
    textobject_set_size(pl->text, 20);
    pl->desc = textobject_create(init.id, init.text_pos, init.desc);
    pl->desc->object->visible = false;
    scene_add_text(&scene_menu->objects, pl->desc);
    pl->func = init.func;
    pl->object->on_click = init.func;
}

all_planet_t *init_planet(float i, float speed)
{
    all_planet_t *planete = malloc(sizeof(all_planet_t));

    planete->a.x = 1920 / 2;
    planete->a.y = 1080 / 2;
    planete->b.x = 1920 / 2 + ((i + 1) * 250);
    planete->b.y = 1080 / 2;
    planete->dist = (i + 1) * 250;
    planete->prog = 0;
    planete->speed = speed;
    planete->cs[0] = 0;
    planete->cs[1] = 1;
    return (planete);
}

void create_planete(SpaceShip *scene_menu, SpacePlanetInit init)
{
    space_planete_t *planete = malloc(sizeof(space_planete_t));
    space_planete_t *pl = scene_menu->planete;
    sfFloatRect rect;

    planete->object =
        object_create_from_image(init.id, init.obj_pos, init.name);
    planete->icon_planet = OCFI(init.id, (loc_t){0, 0}, init.name);
    rect = sfSprite_getGlobalBounds(planete->object->sprite);
    sfSprite_setOrigin(planete->object->sprite,
        (sfVector2f){rect.width / 2, rect.height / 2});
    SAO(&scene_menu->objects, planete->object);
    SAO(&scene_menu->objects, planete->icon_planet);
    object_set_visible(planete->icon_planet, false);
    object_set_render_priority(planete->icon_planet, 201);
    object_set_scale(planete->icon_planet, (V2F){2, 2});
    object_set_centered_origin(planete->icon_planet);
    planete->text = textobject_create(init.id, init.text_pos, init.text);
    init_text(scene_menu, planete, init);
    scene_add_text(&scene_menu->objects, planete->text);
    planete->lock = init.lock;
    planete->obj_position = init.obj_pos;
    planete->text_position = init.text_pos;
    planete->is_active = true;
    planete->next = NULL;
    planete->id = init.id;
    planete->title = TOC(init.idd, init.text_pos, init.title);
    planete->stats_speed = TOC(init.idd + 100, init.text_pos, "0");
    planete->difficulty = TOC(init.idd + 200, init.text_pos, init.difficulty);
    SAT(&scene_menu->objects, planete->title);
    SAT(&scene_menu->objects, planete->stats_speed);
    SAT(&scene_menu->objects, planete->difficulty);
    planete->title->object->visible = false;
    planete->stats_speed->object->visible = false;
    planete->difficulty->object->visible = false;
    planete->info = init_planet(init.id, init.speed);
    object_set_render_priority(planete->desc->object, 150);
    object_set_render_priority(planete->title->object, 150);
    object_set_render_priority(planete->stats_speed->object, 150);
    object_set_render_priority(planete->difficulty->object, 150);
    sfText_setColor(planete->desc->text, sfBlack);
    sfText_setColor(planete->title->text, sfBlack);
    sfText_setColor(planete->stats_speed->text, sfBlack);
    sfText_setColor(planete->difficulty->text, sfBlack);
    planete->speed = init.speed;
    if (!pl) {
        scene_menu->planete = planete;
        return;
    }
    while (pl->next)
        pl = pl->next;
    pl->next = planete;
}
