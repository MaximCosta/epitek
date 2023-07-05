/*
** EPITECH PROJECT, 2021
** player_test.c
** File description:
** Player Tests
*/

#include "../../vertex.h"
#include "../../new.h"

int main(void)
{
    Object *vertex = new (Vertex, 10, 20, 30);
    Object *vertex2 = new (Vertex, 10, 20, 30);

    printf ("%s\n", str (vertex));
    printf ("%s\n", str (vertex2));
    printf ("%s\n", str (addition (vertex, vertex2)));
    printf ("%s\n", str (subtraction (vertex, vertex2)));
    delete (vertex2);
    delete (vertex);
}
