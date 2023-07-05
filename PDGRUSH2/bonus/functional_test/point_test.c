/*
** EPITECH PROJECT, 2021
** player_test.c
** File description:
** Player Tests
*/

#include "../../point.h"
#include "../../new.h"

int main(void)
{
    Object *point = new(Point, 10, 20);

    printf("%s\n", str (point));
    delete(point);
}
