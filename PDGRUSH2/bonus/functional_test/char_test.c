/*
** EPITECH PROJECT, 2021
** player_test.c
** File description:
** Player Tests
*/

#include "../../char.h"
#include "../../new.h"

int main(void)
{
    Object *c = new (Char, 'a');
    Object *c2 = new (Char, 'b');

    printf("%s\n", str (addition (c, c2)));
    printf("%s\n", str (subtraction (c, c2)));
    printf("%s\n", str (multiplication (c, c2)));
    printf("%s\n", str (division (c, c2)));
    printf("%d\n", eq (c, c2));
    printf("%d\n", gt (c, c2));
    printf("%d\n", lt (c, c2));

    delete (c2);
    delete (c);

    // // Test crash
    // c = new (Char, 'a');
    // c2 = new (Char, 0);
    // division (c, c2);
}
