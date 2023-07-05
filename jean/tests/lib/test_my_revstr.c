/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** test my_revstr
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_revstr, reverse_my_string)
{
    char my_dest[] = "Hello world !";

    my_revstr(my_dest);
    cr_assert_str_eq(my_dest, "! dlrow olleH");
}

