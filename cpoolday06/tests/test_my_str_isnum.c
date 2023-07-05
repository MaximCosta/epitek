/*
** EPITECH PROJECT, 2021
** test_my_isnum
** File description:
** isupper unit test
*/

#include <criterion/criterion.h>

int my_str_isnum(char const *str);

Test(my_str_isnum, isnum_1)
{
    char dest[] = "123456789";

    my_str_isnum(dest);
    cr_assert_eq(my_str_isnum(dest), 1);
}

Test(my_str_isnum, isnum_2)
{
    char dest[] = "12L3";

    my_str_isnum(dest);
    cr_assert_eq(my_str_isnum(dest), 0);
}
