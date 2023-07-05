/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** add_menu.c
*/

#include "../../../../../include/game/rpg.h"

static const char *SETTINGS_MENU_S = "./assets/GameScene/GUI/"
"settings_menu.png";
static const char *M_RESUME_S = "./assets/GameScene/GUI/menu/resume.png";
static const char *M_RESTART_S = "./assets/GameScene/GUI/menu/restart.png";
static const char *M_LEAVE_S = "./assets/GameScene/GUI/menu/"
"leave_the_game.png";
static const char *M_BACK_TO_MENU_S = "./assets/GameScene/GUI/menu/"
"back_to_menu.png";
static const char *M_SAVE_S = "./assets/GameScene/GUI/menu/save.png";

void add_menu_obj_input(game *scene, menu_t *menu);
void add_sliders(game *scene);
void center_text(game *scene, textobject_t *text);

void add_priority(game *scene)
{
    object_set_render_priority(scene->menu->right_key->object, 400);
    object_set_render_priority(scene->menu->left_key->object, 401);
    object_set_render_priority(scene->menu->up_key->object, 402);
    object_set_render_priority(scene->menu->down_key->object, 403);
    object_set_render_priority(scene->menu->inventory_key->object, 404);
    object_set_render_priority(scene->menu->interact_key->object, 405);
    object_set_render_priority(scene->menu->dash_key->object, 406);
    object_set_render_priority(scene->menu->jetpack_key->object, 407);
    center_text(scene, scene->menu->dash_key);
}

void add_text_input(game *scene, menu_t *menu)
{
    menu->right_key = TOC(M_RIGHT_KEY_T, (loc_t){1710 , 360}, "d");
    menu->left_key = TOC(M_LEFT_KEY_T, (loc_t){1710 , 420}, "q");
    menu->up_key = TOC(M_UP_KEY_T, (loc_t){1710 , 480}, "z");
    menu->down_key = TOC(M_DOWN_KEY_T, (loc_t){1710 , 540}, "s");
    menu->interact_key = TOC(M_INTERACT_KEY_T, (loc_t){1710 , 660}, "f");
    menu->inventory_key = TOC(M_INVENTORY_KEY_T, (loc_t){1710 , 300}, "a");
    menu->dash_key = TOC(M_DASH_KEY_T, (loc_t){1710 , 720}, "SHIFT");
    menu->jetpack_key = TOC(M_JETPACK_KEY_T, (loc_t){1710 , 600}, "e");
    SAT(&scene->objects, scene->menu->right_key);
    SAT(&scene->objects, scene->menu->left_key);
    SAT(&scene->objects, scene->menu->up_key);
    SAT(&scene->objects, scene->menu->down_key);
    SAT(&scene->objects, scene->menu->interact_key);
    SAT(&scene->objects, scene->menu->inventory_key);
    SAT(&scene->objects, scene->menu->dash_key);
    SAT(&scene->objects, scene->menu->jetpack_key);
    add_priority(scene);
}

void init_all_left(game *scene)
{
    object_set_rect(scene->menu->resume, (sfIntRect){0, 0, 229, 57});
    object_set_rect(scene->menu->restart, (sfIntRect){0, 0, 229, 57});
    object_set_rect(scene->menu->leave, (sfIntRect){0, 0, 229, 57});
    object_set_rect(scene->menu->back_to_menu, (sfIntRect){0, 0, 229, 57});
    object_set_rect(scene->menu->save, (sfIntRect){0, 0, 229, 57});
}

void create_all_left(game *scene)
{
    scene->menu->resume = OCFI(M_RESUME, (loc_t){131, 350}, M_RESUME_S);
    scene->menu->save = OCFI(M_SAVE, (loc_t){131, 426}, M_SAVE_S);
    scene->menu->restart = OCFI(M_RESTART, (loc_t){131, 505}, M_RESTART_S);
    scene->menu->leave = OCFI(M_LEAVE, (loc_t){131, 660}, M_LEAVE_S);
    scene->menu->back_to_menu = OCFI(M_BACK_TO_MENU, (loc_t){131, 580},
    M_BACK_TO_MENU_S);
    SAO(&scene->objects, scene->menu->resume);
    SAO(&scene->objects, scene->menu->restart);
    SAO(&scene->objects, scene->menu->leave);
    SAO(&scene->objects, scene->menu->back_to_menu);
    SAO(&scene->objects, scene->menu->save);
    object_set_render_priority(scene->menu->resume, 301);
    object_set_render_priority(scene->menu->restart, 302);
    object_set_render_priority(scene->menu->leave, 303);
    object_set_render_priority(scene->menu->back_to_menu, 304);
    object_set_render_priority(scene->menu->save, 305);
    init_all_left(scene);
}

void add_settings_menu(game *scene)
{
    object_t *menu = NULL;

    scene->menu = malloc(sizeof(menu_t));
    scene->menu->edit_key = false;
    scene->menu->active = false;
    scene->menu->edit = 0;
    scene->menu->input = -1;
    SAO(&scene->objects, OCFI(SETTINGS_MENU,
        (loc_t){0, 0}, SETTINGS_MENU_S));
    menu = OGFuuid_t(&scene->objects, SETTINGS_MENU);
    object_set_render_priority(menu, 300);
    create_all_left(scene);
    add_text_input(scene, scene->menu);
    add_menu_obj_input(scene, scene->menu);
    add_sliders(scene);
}
