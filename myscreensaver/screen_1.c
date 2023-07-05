/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myscreensaver-maxim.costa [WSL: Ubuntu]
** File description:
** screen_1
*/


#include "include/my.h"

int screen_1(framebuffer_t *bufsc)
{
    sfColor random = my_rgba(rand(), rand(), rand(), rand());
	my_put_line(bufsc, random, rand()%800, rand()%800);
}

int my_put_line(framebuffer_t *buffer, sfColor color, int x0, int x1)
{
	int y0 = rand()%600;
	int y1 = rand()%600;
	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (1) {
		my_put_pixel(buffer, x0, y0, color);
		if (x0 == x1 && y0 == y1) return (EXIT);
		e2 = err;
		if (e2 > -dx) {
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy) {
			err += dx;
			y0 += sy;
		}
	}
}