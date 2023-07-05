/*
** EPITECH PROJECT, 2021
** test [WSL: Ubuntu]
** File description:
** main 48 / 27 5 1 0 7 9
*/

#include "game.h"
#include "my.h"
#include "my_printf.h"
#include <math.h>

void game_event(game_t *gm)
{
    while (sfRenderWindow_pollEvent(gm->window, &gm->event)) {
        if (gm->event.type == sfEvtClosed)
            sfRenderWindow_close(gm->window);
        if (key_press(sfKeyEscape, gm))
            sfRenderWindow_close(gm->window);
        if (key_press(sfKeySpace, gm))
            gm->jumped = true;
        if (key_press(sfKeyF, gm))
            gm->rpause = true;
        if (key_press(sfKeyD, gm))
            gm->dh->death = true;
        if (key_press(sfKeyRight, gm))
            gm->pl->m = (gm->pl->m + 1) % 7;
        if (key_press(sfKeyLeft, gm))
            gm->pl->m = (gm->pl->m - 1) % 7;
    }
}

void request_pause(game_t *games, maps_t *maps, float clock)
{
    if (games->rpause) {
        games->rpause = false;
        games->pause = !games->pause;
        games->spause = clock - maps->time;
    }
    games->sclock = clock;
}

void time_controller(game_t *games, maps_t *maps, float clock)
{
    if (!games->pause) {
        maps->time = clock;
        maps->m = maps->w - maps->time < 48 ? maps->w - 48 : maps->time;
        games->sc->score = (int)maps->time;
    }
}

void loop_game(game_t *games, maps_t *maps)
{
    float clock = asSec(games->clock) * 4 - games->spause;

    time_controller(games, maps, clock);
    game_event(games);
    reset_pos_back(games);
    get_move(games);
    draw_sprites(games);
    tmp_map_render(games, maps);
    if (!games->pause) player_controller(games, maps);
    if (games->dh->death) death_animation(games, maps);
    if (!games->dh->death) player_render(games);
    if (clock < 6) show_nb_death(games);
    write_score(games);
    sfRenderWindow_display(games->window);
    request_pause(games, maps, clock);
}

int main(int argc, char *argv[])
{
    game_t *games = malloc(sizeof(game_t));
    maps_t *maps;

    if (argc == 1) return help(0);
    if (my_strcmp(argv[1], "-h") == 0) help(1);
    maps = create_map(argv[1]);
    if (maps == NULL) return 84;
    init_all(games, maps);
    while (sfRenderWindow_isOpen(games->window)) {
        loop_game(games, maps);
    }
    destroy_loop(games, maps);
    return 0;
}
