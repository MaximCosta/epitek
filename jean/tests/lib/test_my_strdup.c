/*
** EPITECH PROJECT, 2021
** Pool Day08
** File description:
** test my_strdup
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strdup, return_new_string)
{
    char src[] = "Hello World !";
    char *dest = my_strdup(src);

    cr_assert_str_eq(dest, src);
    dest[5] = '\0';
    cr_assert_str_eq(dest, "Hello");
    cr_assert_str_eq(src, "Hello World !");
}

