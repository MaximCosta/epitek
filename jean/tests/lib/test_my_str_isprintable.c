/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** test my_str_isprintable
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_isprintable, is_string_only_printable_char)
{
    char *find1 = "vzof_@& ;=edfkjb";
    char find2[] = "";
    char find3[] = "zfkjh\nad";
    char find4[] = "593 et prnqf";
    char find5[] = "héllo world";

    cr_assert_eq(my_str_isprintable(find1), 1);
    cr_assert_eq(my_str_isprintable(find2), 1);
    cr_assert_eq(my_str_isprintable(find3), 0);
    cr_assert_eq(my_str_isprintable(find4), 1);
    cr_assert_eq(my_str_isprintable(find5), 0);
}
