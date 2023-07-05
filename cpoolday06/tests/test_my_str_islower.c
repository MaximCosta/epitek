/*
** EPITECH PROJECT, 2021
** test_my_islower
** File description:
** islower unit test
*/

#include <criterion/criterion.h>

int my_str_islower(char const *str);

Test(my_str_islower, isprintable_1)
{
    char dest[] = "hello world";

    my_str_islower(dest);
    cr_assert_eq(my_str_islower(dest), 1);
}

Test(my_strstr, isprintable_2)
{
    char dest[] = "Hello World";

    my_str_islower(dest);
    cr_assert_eq(my_str_islower(dest), 0);
}
