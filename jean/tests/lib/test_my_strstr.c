/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** test my_strstr
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strstr, find_string_in_an_other_string)
{
    char find1[] = "Hello";
    char find2[] = "Hello world !";
    char find3[] = "Hello world";
    char find4[] = "world";
    char find5[] = "l";
    char find6[] = "";
    char str[] = "Hello world";

    cr_assert_str_eq(my_strstr(str, find1), "Hello world");
    cr_assert_null(my_strstr(str, find2));
    cr_assert_str_eq(my_strstr(str, find3), "Hello world");
    cr_assert_str_eq(my_strstr(str, find4), "world");
    cr_assert_str_eq(my_strstr(str, find5), "llo world");
    cr_assert_str_eq(my_strstr(str, find6), str);
}
