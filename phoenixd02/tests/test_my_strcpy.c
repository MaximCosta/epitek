/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd02-maxim.costa [WSL: Ubuntu]
** File description:
** test_my_strcpy
*/

#include <criterion/criterion.h>

char *my_strcpy(char *dest, char const *src);

Test(my_strcpy, copy_in_empty_array)
{
    char dest[6] = {0};

    my_strcpy(dest, "Hello");
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strcpy, copy_string_in_empty_array)
{
    char my_dest[6] = {0};
    char dest[6] = {0};

    my_strcpy(my_dest, "Hello");
    strcpy(dest, "Hello");
    cr_assert_str_eq(my_dest, dest);
}