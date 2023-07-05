/*
** EPITECH PROJECT, 2021
** EPITECH
** File description:
** bark.c
*/

#include <criterion/criterion.h>
int coverages_hundred(int a);

Test(coverages_hundred, bark)
{
    cr_assert(coverages_hundred(6) == 1);
}

Test(coverages_hundred, bark2)
{
    cr_assert(coverages_hundred(5) == 0);
}
