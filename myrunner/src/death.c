/*
** EPITECH PROJECT, 2022
** test [SSH: 192.168.177.128]
** File description:
** death
*/

#include "game.h"
#include "my.h"
#include "my_printf.h"

void death_init(game_t *gm)
{
    gm->dh = malloc(sizeof(death_t));
    gm->dh->s = sfSprite_create();
    gm->dh->t = sfTexture_createFromFile("./assets/images/death.png", NULL);
    gm->dh->death = false;
    gm->dh->count = 0;
    gm->dh->curr = 0;
    gm->dh->music = sfMusic_createFromFile("./assets/music/death.ogg");
    sfSprite_setTexture(gm->dh->s, gm->dh->t, sfTrue);
    sfSprite_setTextureRect(gm->dh->s, gt(0, 0, 266, 255));
    gm->dh->text = get_text(gp(20, 20), "0", 128, gm->sc->font);
}

void death_animation(game_t *gm, maps_t *mp)
{
    sfVector2f pos = sfSprite_getPosition(gm->pl->sp[gm->pl->m]);
    int i = gm->dh->curr * 266;
    if (gm->dh->curr == 0) sfMusic_play(gm->dh->music);
    if (!gm->pause) gm->rpause = true;
    pos.x -= 133;
    pos.y -= 127.5;
    sfSprite_setTextureRect(gm->dh->s, gt(0, i, 266, 255));
    sfSprite_setPosition(gm->dh->s, pos);
    sfRenderWindow_drawSprite(gm->window, gm->dh->s, NULL);
    gm->dh->curr = (gm->dh->curr + 1) % 33;
    if (gm->dh->curr == 0) {
        gm->dh->death = false;
        reset_maps(gm, mp);
    }
}

void show_nb_death(game_t *gm)
{
    char buf[255] = {0};
    sfVector2f pos = {0, 0};

    my_itoa(gm->dh->count, buf, 10);
    sfText_setString(gm->dh->text, buf);
    pos = sfText_getScale(gm->dh->text);
    sfText_setOrigin(gm->dh->text, gp(pos.x/2, pos.y/2));
    sfText_setPosition(gm->dh->text, gp(860, 450));
    sfRenderWindow_drawText(gm->window, gm->dh->text, NULL);
}

void reset_maps(game_t *gm, maps_t *mp)
{
    sfMusic_stop(gm->music);
    play_music(gm);
    sfMusic_stop(gm->dh->music);
    sfClock_restart(gm->clock);
    gm->sclock = 0;
    gm->spause = 0;
    gm->spause = 0;
    gm->jumped = false;
    gm->rpause = false;
    gm->pause = false;
    gm->pl->jump = 0;
    gm->pl->px = 0;
    gm->pl->py = 0;
    gm->dh->count++;
    mp->time = 0;
    mp->m = 0;
    sfSprite_setPosition(gm->pl->sp[gm->pl->m], mp->start);
}
