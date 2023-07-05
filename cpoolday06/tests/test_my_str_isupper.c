/*
** EPITECH PROJECT, 2021
** test_my_isupper
** File description:
** isupper unit test
*/

#include <criterion/criterion.h>

int my_str_isupper(char const *str);

Test(my_str_isupper, isupper_1)
{
    char dest[] = "HELLOWORLD";

    my_str_isupper(dest);
    cr_assert_eq(my_str_isupper(dest), 1);
}

Test(my_str_isupper, isupper_2)
{
    char dest[] = "helLoworld";

    my_str_isupper(dest);
    cr_assert_eq(my_str_isupper(dest), 0);
}
