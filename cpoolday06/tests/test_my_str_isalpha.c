/*
** EPITECH PROJECT, 2021
** test_my_isalpha
** File description:
** isalpha unit test
*/

#include <criterion/criterion.h>

int my_str_isalpha(char const *str);

Test(my_str_isalpha, isalpha_1)
{
    char dest[] = "helloworld";

    my_str_isalpha(dest);
    cr_assert_eq(my_str_isalpha(dest), 1);
}

Test(my_strstr, isalpha_2)
{
    char dest[] = "Hello World";

    my_str_isalpha(dest);
    cr_assert_eq(my_str_isalpha(dest), 0);
}
