/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** init.c
*/

/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** init.c
*/

#include "../../../../../include/game/rpg.h"

static const char *KITCHEN = "./assets/runner/kitchen.jpg";
static const char *BTN = "./assets/runner/5.png";
static const char *RED = "./assets/runner/red.png";
static const char *BLUE = "./assets/runner/blue.png";
static const char *BUTTER = "./assets/runner/butter.png";
static const char *R_TARTINE = "./assets/runner/tartine.png";
static const char *R_TARTINEB = "./assets/runner/tartineb.png";
static const char *SOUND_BUTTER = "./assets/runner/squish.ogg";
static const char *SOUND_BITE = "./assets/runner/bite.ogg";
static const char *BOY = "./assets/runner/boy.png";
static const char *BOY2 = "./assets/runner/boy2.png";
static const char *DEAD_ROBLOX_INSANE = "./assets/runner/dead.ogg";
static const char *HEART = "./assets/runner/heart.png";
static const char *FONT = "./assets/runner/font.ttf";

void my_click(object_t *object)
{
    runner_game_t *runner = ((runner_t *)scene_get(RUNNER))->game;

    sfSound_play(runner->sound);
    runner->tartines[object->uuid]->clicked = 1;
    object->on_click = NULL;
    object_set_texture(object, sfTexture_createFromFile(R_TARTINEB, NULL));
}

static void runner_init_sound(runner_game_t *runner)
{
    runner->sbuffer = sfSoundBuffer_createFromFile(SOUND_BUTTER);
    runner->sound = sfSound_create();
    runner->sbuffer_bite = sfSoundBuffer_createFromFile(SOUND_BITE);
    runner->sbite = sfSound_create();
    runner->sbuffer_dead = sfSoundBuffer_createFromFile(DEAD_ROBLOX_INSANE);
    runner->sdead = sfSound_create();
    sfSound_setBuffer(runner->sound, runner->sbuffer);
    sfSound_setBuffer(runner->sbite, runner->sbuffer_bite);
    sfSound_setBuffer(runner->sdead, runner->sbuffer_dead);
}

void runner_reset_heart(runner_game_t *runner)
{
    runner->life = 3;
    for (int i = 0; i < runner->life; i++)
        object_set_visible(object_get_from_uuid(&runner->obj, 666 + i), true);
}

void runner_init_tartines(runner_game_t *runner)
{
    int i = 0;

    for (i = 0; i < MAX_TARTINES; i++) {
        if (!runner->tartines[i])
            runner->tartines[i] = my_calloc(sizeof(tartine_t));
        if (!runner->tartines[i]->obj) {
            runner->tartines[i]->obj = object_create(i, (loc_t) {-200, -300});
            scene_add_object(&runner->obj, runner->tartines[i]->obj);
        }
        runner->tartines[i]->obj->on_click = my_click;
        runner->tartines[i]->obj->visible = 0;
        object_set_position(runner->tartines[i]->obj,
            (sfVector2f) {-200, -300});
        runner->tartines[i]->clicked = 0;
        runner->tartines[i]->set = 0;
        runner->tartines[i]->dir = 0;
    }
    for (int i = 0; i < 3; i++)
        add_tartine_random(runner);
    runner_reset_heart(runner);
    runner->score = 0;
}

void runner_game_create(runner_t *runner)
{
    runner_game_t *menu = runner->game;
    textobject_t *text = NULL;
    object_t *obj = NULL;

    obj = object_create_from_image(0, (loc_t) {0, 0}, KITCHEN);
    object_set_render_priority(obj, -1);
    scene_add_object(&menu->obj, obj);

    menu->boy = object_create_from_image(0, (loc_t){0, 870}, BOY);
    scene_add_object(&menu->obj, menu->boy);
    menu->boy2 = object_create_from_image(0, (loc_t){0, 870}, BOY2);
    scene_add_object(&menu->obj, menu->boy2);
    menu->boy2->visible = false;
    scene_add_object(&menu->obj,
    object_create_from_image(666, (loc_t){35, 35}, HEART));
    scene_add_object(&menu->obj,
    object_create_from_image(667, (loc_t){95, 35}, HEART));
    scene_add_object(&menu->obj,
    object_create_from_image(668, (loc_t){155, 35}, HEART));
    text = textobject_create(0, (loc_t){85, -7}, "LIFE");
    textobject_set_font(text, runner->font);
    textobject_set_size(text, 43);
    scene_add_text(&menu->obj, text);
    runner_init_sound(menu);
    menu->score_text = textobject_create(0, (loc_t){0, 0}, "SCORE : ");
    textobject_set_font(menu->score_text, runner->font);
    textobject_set_size(menu->score_text, 43);
    scene_add_text(&menu->obj, menu->score_text);
    runner_init_tartines(menu);
}