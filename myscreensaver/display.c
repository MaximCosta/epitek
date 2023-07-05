/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myscreensaver-maxim.costa [WSL: Ubuntu]
** File description:
** display
*/

#include "include/my.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t *pointer = malloc(sizeof(framebuffer_t));
	pointer->width = width;
	pointer->height = height;
	pointer->pixels = malloc(width * height * 4);
	return pointer;
}

sfColor my_rgba(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a) {
	sfColor color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return color;
}

int my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color)
{
	if (x > 799 || y > 599 || x < 1 || y < 1) return (ERROR);
	buffer->pixels[4 * (y * buffer->width + x)] = color.r;
	buffer->pixels[4 * (y * buffer->width + x) + 1] = color.g;
	buffer->pixels[4 * (y * buffer->width + x) + 2] = color.b;
	buffer->pixels[4 * (y * buffer->width + x) + 3] = color.a;
	return EXIT;
}