/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strcat, concatenate_two_strings)
{
    char dest[30] = "Hello word ";
    char src[] = "and all people !";

    cr_assert_str_eq(my_strcat(dest, src), "Hello word and all people !");
}
