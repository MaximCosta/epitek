/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myscreensaver-maxim.costa [WSL: Ubuntu]
** File description:
** screen_2
*/

#include "include/my.h"

int screen_2(framebuffer_t *framebuffer, int i)
{

    sfVector2f center = {400, 300};
    sfColor color = my_rgba(rand(), rand(), rand(), rand());
    sfColor black = my_rgba(0, 0, 0, 0);
    int radius = i%400;
    for (int y = center.y - radius ; y < (center.y + radius) ; y++) {
        if (y < 0) continue;
        else if (y > (int)(framebuffer->height)) break;
        for (int x = center.x - radius ; x < (center.x + radius) ; x++) {
            if (x < 0) continue;
            else if (x > (int)(framebuffer->width)) break;
            if (pow(x - center.x, 2) + pow(y - center.y, 2) <= pow(radius, 2))
                my_put_pixel(framebuffer, x, y, color);
        }
    }
    return 0;
}