/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** test my_capitalize
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strcapitalize, capitalize_beggins_letters)
{
    char find1[] = "Hello  my WorLd";
    char find2[] = "Hello  My World";
    char find3[] = "Hey, How Are You? 42words Forty-Two; Fifty+One";
    char find4[] = "hey, how are you? 42WORds forty-two; fifty+one";

    cr_assert_str_eq(my_strcapitalize(find4), find3);
    cr_assert_str_eq(my_strcapitalize(find1), find2);
}
