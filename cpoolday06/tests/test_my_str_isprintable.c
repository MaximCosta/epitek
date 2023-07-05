/*
** EPITECH PROJECT, 2021
** test_my_isprintable
** File description:
** Is printable Unit test
*/

#include <criterion/criterion.h>

char my_str_isprintable(char const *str);

Test(my_str_isprintable, isprintable_1)
{
    char dest[] = "Hello\nWorld";

    my_str_isprintable(dest);
    cr_assert_eq(my_str_isprintable(dest), 0);
}

Test(my_str_isprintable, isprintable_2)
{
    char dest[] = "HelloWorld";

    my_str_isprintable(dest);
    cr_assert_eq(my_str_isprintable(dest), 1);
}
