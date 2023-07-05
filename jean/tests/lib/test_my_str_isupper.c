/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** test my_str_isupper
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_isupper, is_string_only_upper_letters)
{
    char find1[] = "ANBFKSHF";
    char find2[] = "AHFK8DFHF";
    char find3[] = "";
    char find4[] = "AjDFJ";

    cr_assert_eq(my_str_isupper(find1), 1);
    cr_assert_eq(my_str_isupper(find2), 0);
    cr_assert_eq(my_str_isupper(find3), 1);
    cr_assert_eq(my_str_isupper(find4), 0);
}
