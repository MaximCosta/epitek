/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** test my_str_islower
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_islower, is_string_only_lower_letters)
{
    char find1[] = "abdcjhfe";
    char find2[] = "abfie8fnefj";
    char find3[] = "";
    char find4[] = "anfpdBf";

    cr_assert_eq(my_str_islower(find1), 1);
    cr_assert_eq(my_str_islower(find2), 0);
    cr_assert_eq(my_str_islower(find3), 1);
    cr_assert_eq(my_str_islower(find4), 0);
}
