/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** addè_menu_obj_input.c
*/

#include "../../../../../include/game/rpg.h"

static const char *M_RIGHT_OS = "./assets/GameScene/GUI/menu/right_key.png";
static const char *M_LEFT_OS = "./assets/GameScene/GUI/menu/left_key.png";
static const char *M_DOWN_OS = "./assets/GameScene/GUI/menu/down_key.png";
static const char *M_UP_OS = "./assets/GameScene/GUI/menu/up_key.png";
static const char *M_INTERACT_OS = "./assets/GameScene/GUI/menu/"
"interaction_key.png";
static const char *M_INVENTORY_OS = "./assets/GameScene/GUI/menu/"
"mouse_key.png";
static const char *M_DASH_OS = "./assets/GameScene/GUI/menu/dash_key.png";
static const char *M_JETPACK_OS = "./assets/GameScene/GUI/menu/"
"jetpack_key.png";
static const char *M_ANY_KEY_S = "./assets/GameScene/GUI/menu/"
"press_any_key.png";
static const char *CHECKER_S = "./assets/GameScene/GUI/menu/checker.png";

void add_checkers(game *scene, menu_t *menu)
{
    menu->invincibility = OCFI(INVINCIBILITY, (loc_t){426, 573}, CHECKER_S);
    menu->auto_save = OCFI(AUTO_SAVE, (loc_t){426, 620}, CHECKER_S);
    SAO(&scene->objects, menu->invincibility);
    SAO(&scene->objects, menu->auto_save);
    object_set_rect(menu->invincibility, (sfIntRect){0, 0, 30, 30});
    object_set_rect(menu->auto_save, (sfIntRect){0, 0, 30, 30});
    object_set_render_priority(menu->invincibility, 314);
    object_set_render_priority(menu->auto_save, 315);
}

void button_priority(game *scene, menu_t *menu)
{
    object_set_render_priority(menu->right_o, 306);
    object_set_render_priority(menu->left_o, 307);
    object_set_render_priority(menu->down_o, 308);
    object_set_render_priority(menu->up_o, 309);
    object_set_render_priority(menu->interact_o, 310);
    object_set_render_priority(menu->inventory_o, 311);
    object_set_render_priority(menu->dash_o, 312);
    object_set_render_priority(menu->jetpack_o, 313);
    object_set_render_priority(OGFuuid_t(&scene->objects, M_ANY_KEY), 410);
}

void add_menu_obj_input(game *scene, menu_t *menu)
{
    menu->right_o = OCFI(M_RIGHT_O, (loc_t){1460 , 350}, M_RIGHT_OS);
    menu->left_o = OCFI(M_LEFT_O, (loc_t){1460 , 410}, M_LEFT_OS);
    menu->down_o = OCFI(M_DOWN_O, (loc_t){1460 , 530}, M_DOWN_OS);
    menu->up_o = OCFI(M_UP_O, (loc_t){1460 , 470}, M_UP_OS);
    menu->interact_o = OCFI(M_INTERACT_O, (loc_t){1460 , 650}, M_INTERACT_OS);
    menu->inventory_o = OCFI(M_INVENTORY_O, (loc_t){1460 , 290}, M_INVENTORY_OS);
    menu->dash_o = OCFI(M_DASH_O, (loc_t){1460 , 710}, M_DASH_OS);
    menu->jetpack_o = OCFI(M_JETPACK_O, (loc_t){1460 , 590}, M_JETPACK_OS);
    SAO(&scene->objects, OCFI(M_ANY_KEY, (loc_t){1460 , 236}, M_ANY_KEY_S));
    SAO(&scene->objects, menu->right_o);
    SAO(&scene->objects, menu->left_o);
    SAO(&scene->objects, menu->down_o);
    SAO(&scene->objects, menu->up_o);
    SAO(&scene->objects, menu->interact_o);
    SAO(&scene->objects, menu->inventory_o);
    SAO(&scene->objects, menu->dash_o);
    SAO(&scene->objects, menu->jetpack_o);
    button_priority(scene, menu);
    add_checkers(scene, menu);
}
