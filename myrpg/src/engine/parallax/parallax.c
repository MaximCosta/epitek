/*
** EPITECH PROJECT, 2021
** window
** File description:
** window.c
*/
#include "../../../include/engine/engine.h"

void parallax_draw_image(sfRenderWindow *window, ParallaxImage *image,
        int speed)
{
    sfVector2f first_pos;
    sfVector2f second_pos;
    sfVector2u window_size = sfRenderWindow_getSize(window);

    first_pos = sfSprite_getPosition(image->first_sprite);
    second_pos = sfSprite_getPosition(image->second_sprite);
    if (first_pos.x <= -window_size.x) {
        first_pos.x = second_pos.x + window_size.x;
        sfSprite_setPosition(image->first_sprite, first_pos);
    }
    if (second_pos.x <= -window_size.x) {
        second_pos.x = first_pos.x + window_size.x;
        sfSprite_setPosition(image->second_sprite, second_pos);
    }
    first_pos.x -= speed;
    second_pos.x -= speed;
    sfSprite_setPosition(image->first_sprite, first_pos);
    sfSprite_setPosition(image->second_sprite, second_pos);
    sfRenderWindow_drawSprite(window, image->first_sprite, NULL);
    sfRenderWindow_drawSprite(window, image->second_sprite, NULL);
}

void parallax_draw(sfRenderWindow *window, Parallax *parallax)
{
    ParallaxImage **images = parallax->images;

    for (int i = 0; i < 10; i++)
        parallax_draw_image(window, images[i], images[i]->speed);
}

ParallaxImage *parallax_load_image(sfRenderWindow *window, float speed,
        char *path)
{
    ParallaxImage *image = malloc(sizeof(ParallaxImage));
    sfSprite *first_sprite = sfSprite_create();
    sfSprite *second_sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfVector2u window_size = sfRenderWindow_getSize(window);

    sfSprite_setTexture(first_sprite, texture, sfTrue);
    sfSprite_setTexture(second_sprite, texture, sfTrue);
    sfSprite_setPosition(second_sprite, (sfVector2f){window_size.x, 0});
    image->speed = speed;
    image->first_sprite = first_sprite;
    image->second_sprite = second_sprite;
    return image;
}
