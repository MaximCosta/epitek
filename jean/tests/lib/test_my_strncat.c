/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strncat, concatenate_n_char_of_two_strings)
{
    char dest[30] = "Hello word ";
    char dest2[30] = "Hello word ";
    char dest3[30] = "Hello word ";
    char src[] = "and all people !";
    char src2[20] = "";

    cr_assert_str_eq(my_strncat(dest, src, 7), "Hello word and all");
    cr_assert_str_eq(my_strncat(dest2, src, 30), "Hello word and all people !");
    cr_assert_str_eq(my_strncat(dest3, src2, 5), "Hello word ");
    cr_assert_str_eq(my_strncat(src2, dest, 0), "");
}
