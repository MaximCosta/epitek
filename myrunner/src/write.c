/*
** EPITECH PROJECT, 2022
** test [SSH: 192.168.177.128]
** File description:
** write
*/

#include "game.h"
#include "my.h"
#include "my_printf.h"

void init_score(game_t *games)
{
    games->sc = malloc(sizeof(score_t));
    games->sc->font = sfFont_createFromFile("./assets/fonts/pixelates.ttf");
    games->sc->text = get_text(gp(10, 0), "0", 38, games->sc->font);
    games->sc->score = 0;
}

void write_score(game_t *gm)
{
    char buf[255] = {0};
    my_itoa(gm->sc->score, buf, 10);
    write_text(gm, buf);
}

void write_text(game_t *gm, const char *str)
{
    sfText_setString(gm->sc->text, str);
    sfRenderWindow_drawText(gm->window, gm->sc->text, NULL);
}
