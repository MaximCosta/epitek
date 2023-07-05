/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include "my.h"

Test(get_color, transform_rgb_to_int)
{
    cr_assert_eq(get_color(255, 255, 255), 16777215);
    cr_assert_eq(get_color(0, 0, 0), 0);
    cr_assert_eq(get_color(23, 75, 93), 1526621);
}
