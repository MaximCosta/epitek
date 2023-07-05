/*
** EPITECH PROJECT, 2021
** test_my_revstr
** File description:
** test Unit
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, return_value_is_reversed)
{
    char dest[] = "Hello";

    my_revstr(dest);
    cr_assert_str_eq(dest, "olleH");
}
