/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** do_game.c
*/

#include "../../../../../include/game/rpg.h"

static void do_tartine_nclick(runner_game_t *runner, tartine_t *tartine,
                                sfVector2f pos)
{
    if (tartine->clicked)
        return;
    pos.x += ((2 + (float) runner->score / 700.f) *
            (ENGINE->delta_time / 10000) * tartine->dir);
    tartine->set = !(pos.x <= -100 || pos.x >= 1920);
    object_set_visible(tartine->obj, tartine->set);
    if (!tartine->set) {
        sfSound_play(runner->sdead);
        runner->life--;
        runner->score -= 50;
        if (runner->life < 0) {
            ((runner_t *)scene_get(RUNNER))->state = 2;
            return;
        }
        object_set_visible(
            object_get_from_uuid(&runner->obj, 666 + runner->life), false);
        return add_tartine_random(runner);
    }
    object_set_position(tartine->obj, pos);
}

static void do_tartine_click(runner_game_t *runner, tartine_t *tartine,
                            sfVector2f pos)
{
    if (!tartine->clicked)
        return;
    pos.y += ((4 + (float) runner->score / 700.f) *
            (ENGINE->delta_time / 10000));
    object_set_position(tartine->obj, pos);
    tartine->set = pos.y >= 1080 ||
    test_colide(tartine->obj, runner->boy) ? 0 : 1;
    object_set_visible(tartine->obj, tartine->set);
    if (pos.y < 1080 && !tartine->set) {
        sfSound_play(runner->sbite);
        runner->score += 100;
    }
    else if (!tartine->set) {
        sfSound_play(runner->sdead);
        runner->life--;
        if (runner->life < 0) {
            ((runner_t *)scene_get(RUNNER))->state = 2;
            return;
        }
        object_set_visible(
            object_get_from_uuid(&runner->obj, 666 + runner->life), false);
    }
    if (!tartine->set)
        add_tartine_random(runner);
}

void do_tartine(runner_game_t *runner)
{
    int i = 0;
    sfVector2f pos = {0};

    for (i = 0; i < MAX_TARTINES; i++) {
        if (!runner->tartines[i]->set)
            continue;
        pos = object_get_position(runner->tartines[i]->obj);
        if (runner->tartines[i]->clicked)
            do_tartine_click(runner, runner->tartines[i], pos);
        else
            do_tartine_nclick(runner, runner->tartines[i], pos);
    }
}

void runner_game_setscore(runner_game_t *runner, int score)
{
    str_t *str = str_create("Score: ");
    sfFloatRect rect = {0, 0, 0, 0};

    str_add_nbr(str, score);
    textobject_set_string(runner->score_text, str->str);
    rect = sfText_getLocalBounds(runner->score_text->text);
    textobject_set_position(runner->score_text,
                        (sfVector2f){1920 - rect.width - 25, 10});
}

void runner_do_game(runner_game_t *runner)
{
    sfVector2f pos = object_get_position(runner->boy);

    do_tartine(runner);
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        runner->boy->visible = false;
        runner->boy2->visible = true;
        pos.x -= (5 * (ENGINE->delta_time / 10000));
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        runner->boy->visible = true;
        runner->boy2->visible = false;
        pos.x += (5 * (ENGINE->delta_time / 10000));
    }
    pos.x = MAX(pos.x, 0);
    pos.x = MIN(pos.x, 1760);
    object_set_position(runner->boy, pos);
    object_set_position(runner->boy2, pos);
    runner_game_setscore(runner, runner->score);
}