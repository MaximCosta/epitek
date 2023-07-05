/*
** EPITECH PROJECT, 2022
** myrpg [WSL: Ubuntu]
** File description:
** pixel_trace
*/

#include "../../../../include/game/rpg.h"

sfColor rgba(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a)
{
    sfColor color;

    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return color;
}

void put_pixel(framebuffer_t *buffer, int x, int y, sfColor color)
{
    if (x < 0 || x >= buffer->width || y < 0 || y >= buffer->height)
        return;
    buffer->pixels[4 * (y * buffer->width + x)] = color.r;
    buffer->pixels[4 * (y * buffer->width + x) + 1] = color.g;
    buffer->pixels[4 * (y * buffer->width + x) + 2] = color.b;
    buffer->pixels[4 * (y * buffer->width + x) + 3] = color.a;
}

void reduce_pixel(framebuffer_t *bufsc)
{
    for (int i = 0; i < bufsc->width * bufsc->height * 4; i++)
        bufsc->pixels[i] = MAX(bufsc->pixels[i] - 1, 0);
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *pt = malloc(sizeof(framebuffer_t));
    pt->width = width;
    pt->height = height;
    pt->pixels = my_calloc(width * height * 4);
    pt->tx = sfTexture_create(width, height);
    pt->sp = sfSprite_create();
    sfSprite_setTexture(pt->sp, pt->tx, sfTrue);
    return pt;
}
