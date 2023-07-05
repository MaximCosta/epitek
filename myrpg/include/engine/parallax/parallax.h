/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef PARALLAX_H
    #define PARALLAX_H
    #include "../engine.h"

typedef struct s_parallax_img ParallaxImage;
typedef struct s_parallax Parallax;

struct s_parallax_img {

    float speed;
    sfSprite *first_sprite;
    sfSprite *second_sprite;

};

struct s_parallax {

    ParallaxImage **images;

};

void parallax_draw_image(sfRenderWindow *window, ParallaxImage *image,
        int speed);

void parallax_draw(sfRenderWindow *window, Parallax *parallax);

ParallaxImage *parallax_load_image(sfRenderWindow *window, float speed,
        char *path);

#endif //PARALLAX_H
