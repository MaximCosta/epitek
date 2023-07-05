/*
** EPITECH PROJECT, 2021
** Pool day06
** File description:
** test my_strncpy
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strncpy, copy_n_characters_in_empty_array)
{
    char my_dest[6] = {0};
    char dest[6] = {0};
    char my_dest2[] = "Hello world";
    char my_dest3[] = "Hello world";

    my_strncpy(my_dest, "Hello", 6);
    my_strncpy(dest, "Hello", 6);
    cr_assert_str_eq(my_dest, dest);
    cr_assert_str_eq(my_strncpy(my_dest2, "Hello", 10), dest);
    cr_assert_str_eq(my_strncpy(my_dest3, "olleH", 5), "olleH world");
}
