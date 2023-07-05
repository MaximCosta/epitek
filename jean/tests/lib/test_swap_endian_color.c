/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include "my.h"

Test(swap_endian_color, swap_endian_color_in_lower)
{
    cr_assert_eq(swap_endian_color(540033104), 1346383904);
}
