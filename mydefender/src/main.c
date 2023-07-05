/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** main
*/

#include "defender.h"

void state_pause(game_t *game)
{
    if (game->state == PLAY)
        game->state = PAUSE;
    else if (game->state == PAUSE)
        game->state = PLAY;
}

void handle_event(game_t *game)
{
    sfEvent event;

    game->is_press = 0;
    while (sfRenderWindow_pollEvent(game->wd, &event)) {
        if (event.type == sfEvtClosed)
            game->state = EXIT;
        if (event.type == sfEvtMouseButtonReleased)
            game->is_press = 1;
        if (key_press(sfKeyEscape, event))
            state_pause(game);
    }
}

void loop_game(game_t *game)
{
    game->delta = sfClock_getElapsedTime(game->clock).microseconds;
    sfRenderWindow_clear(game->wd, (sfColor){101, 132, 92, 1});
    handle_event(game);
    switch_scene(game);
    update_score(game);
    sfRenderWindow_display(game->wd);
    sfClock_restart(game->clock);
}

int main(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return 84;
    load_map(game, "./maps/map");
    init_gm(game, 1200, 920);
    init_all(game);
    for (; game->state != EXIT; ) {
        if (sfRenderWindow_isOpen(game->wd))
            loop_game(game);
    };
    destroy_all(game);
    return 0;
}
