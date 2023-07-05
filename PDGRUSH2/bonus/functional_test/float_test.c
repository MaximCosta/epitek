/*
** EPITECH PROJECT, 2021
** player_test.c
** File description:
** Player Tests
*/

#include "../../float.h"
#include "../../new.h"

int main(void)
{
    Object *f = new(Float, 10.5);
    Object *f2 = new(Float, 10.5);

    printf("%s\n", str(addition(f, f2)));
    printf("%s\n", str(subtraction(f, f2)));
    printf("%s\n", str(multiplication(f, f2)));
    printf("%s\n", str(division(f, f2)));
    printf("%d\n", eq(f, f2));
    printf("%d\n", gt(f, f2));
    printf("%d\n", lt(f, f2));

    delete(f2);
    delete(f);
    // // Test crash
    // f = new (Float, 10.5);
    // f2 = new (Float, 0.00);
    // division (f, f2);
}
