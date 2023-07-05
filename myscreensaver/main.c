/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myscreensaver-maxim.costa [WSL: Ubuntu]
** File description:
** main
*/

#include "include/my.h"

int main(int ac, char **av)
{
	if (ac != 2) return ERROR;
	my_screensaver(av[1][0]);
}

int get_func_id(char id, sfRenderWindow *window, framebuffer_t *bufsc , int i)
{
	switch (id) {
		case '1': return screen_1(bufsc);
		case '2': return screen_2(bufsc, i);
	}
	exit(ERROR);
}

int my_screensaver(char id)
{
	int i = 0;
	framebuffer_t *bufsc = framebuffer_create(800, 600);
	sfVideoMode mode = {800, 600, 32};
	sfRenderWindow *window;
	sfTexture *texture = sfTexture_create(800, 600);
	sfTexture_updateFromPixels(texture, bufsc->pixels, bufsc->width, bufsc->height, 0, 0);
	sfSprite *sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfTexture_updateFromPixels(texture, bufsc->pixels, bufsc->width, bufsc->height, 0, 0);
	sfEvent event;
	window = sfRenderWindow_create(mode, "my_screensaver", sfResize | sfClose, NULL);
	while (sfRenderWindow_isOpen(window)) {
		i++;
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		//TODO list;
		get_func_id(id, window, bufsc, i);
		sfTexture_updateFromPixels(texture, bufsc->pixels, bufsc->width, bufsc->height, 0, 0);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfRenderWindow_display(window);
	}
	return 0;
}

