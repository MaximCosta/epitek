/*
** EPITECH PROJECT, 2021
** player_test.c
** File description:
** Player Tests
*/

#include "../../vertex.h"
#include "../../new.h"
#include "../../int.h"

int main(void)
{
    Object *i = new (Int, 10);
    Object *i2 = new (Int, 20);

    printf ("%s\n", str (addition (i, i2)));
    printf ("%s\n", str (subtraction (i, i2)));
    printf ("%s\n", str (multiplication (i, i2)));
    printf ("%s\n", str (division (i, i2)));
    printf ("%d\n", eq (i, i2));
    printf ("%d\n", gt (i, i2));
    printf ("%d\n", lt (i, i2));

    delete (i2);
    delete (i);

    // Test crash
    // i = new (Int, 10);
    // i2 = new (Int, 0);
    // division (i, i2);
}
