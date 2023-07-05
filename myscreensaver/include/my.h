/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** done for the my_screensaver project
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#define ERROR 84
#define EXIT_HELP 1
#define EXIT_OPTIONS 2
#define EXIT 0
#include "SFML/Graphics.h"
#include "SFML/Audio.h"
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
typedef struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
} framebuffer_t;
int my_put_nbr(int nb);
void my_putchar(char c);
int my_screensaver(char id);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
int my_put_pixel(framebuffer_t *bufsc, unsigned int x, unsigned int y, sfColor color);
int my_put_line(framebuffer_t *bufsc, sfColor color, int x0, int x1);
sfColor my_rgba(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a);
int screen_1(framebuffer_t *bufsc);
int screen_2(framebuffer_t *framebuffer, int i);

int ligne(void);

#endif /* !STRUCT_H_ */
