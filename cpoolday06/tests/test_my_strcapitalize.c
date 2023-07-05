/*
** EPITECH PROJECT, 2021
** test_my_strcapitalize
** File description:
** my_strcapitalize test unite
*/

#include <criterion/criterion.h>

char *my_strcapitalize(char *str);

Test(my_strcapitalize, strcapitalize_1)
{
    char str[] = "hello world heLLo";

    my_strcapitalize(str);
    cr_assert_str_eq(str, "Hello World Hello");
}
