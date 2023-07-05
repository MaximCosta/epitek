/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** test my_str_isnum
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_isnum, is_string_only_digits)
{
    char find1[] = "0123456789";
    char find2[] = "01527h2808";
    char find3[] = "1628 6890";
    char find4[] = "1037870 ";

    cr_assert_eq(my_str_isnum(find1), 1);
    cr_assert_eq(my_str_isnum(find2), 0);
    cr_assert_eq(my_str_isnum(find3), 0);
    cr_assert_eq(my_str_isnum(find4), 0);
}
