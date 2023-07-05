/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** test my_str_isalpha
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_isalpha, is_my_string_only_letters)
{
    char find1[] = "";
    char find2[] = "Hello world !";
    char find3[] = "Helloworld";
    char find4[] = "world ";

    cr_assert_eq(my_str_isalpha(find1), 1);
    cr_assert_eq(my_str_isalpha(find2), 0);
    cr_assert_eq(my_str_isalpha(find3), 1);
    cr_assert_eq(my_str_isalpha(find4), 0);
}
