/*
** EPITECH PROJECT, 2022
** test [SSH: 192.168.177.128]
** File description:
** utils
*/

#include "game.h"
#include "my.h"
#include "my_printf.h"

sfVector2f gp(const int x, const int y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

sfIntRect gt(const int t, const int l, const int w, const int h)
{
    sfIntRect rect;

    rect.top = t;
    rect.left = l;
    rect.width = w;
    rect.height = h;
    return (rect);
}

sfText *get_text(sfVector2f pos, const char *str, const int sz, sfFont *ft)
{
    sfText *text = sfText_create();

    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setFont(text, ft);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, sz);
    return (text);
}

sfBool key_press(sfKeyCode key, game_t *gm)
{
    return gm->event.type == sfEvtKeyPressed && gm->event.key.code == key;
}

float asSec(const sfClock *clock)
{
    return sfTime_asSeconds(sfClock_getElapsedTime(clock));
}
