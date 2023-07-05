/*
** EPITECH PROJECT, 2021
** Pool Day09
** File description:
** get_color
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int r = red << 16;
    int g = green << 8;
    int b = blue;

    return (r | g | b);
}
