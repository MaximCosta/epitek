/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** utils
*/

#include "defender.h"

char *concat(char *str1, char *str2)
{
    int s = 0;
    char *res = my_calloc(1UL, 0, my_strlen(str1) + my_strlen(str2) + 1);

    for (int i = 0; i < my_strlen(str1); res[s++] = str1[i++]) {};
    for (int i = 0; i < my_strlen(str2); res[s++] = str2[i++]) {};
    return res;
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

sfVector2f gp(const int x, const int y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

sfBool key_press(sfKeyCode key, sfEvent event)
{
    return event.type == sfEvtKeyPressed && event.key.code == key;
}

float asSec(const sfClock *clock)
{
    return sfTime_asSeconds(sfClock_getElapsedTime(clock));
}
