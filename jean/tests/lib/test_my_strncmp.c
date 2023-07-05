/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_strncmp
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strncmp, compare_the_tall_of_two_strings)
{
    char find1[] = "Hello";
    char find2[] = "Hello world !";
    char find3[] = "Hello le monde";
    char find4[] = "Bonjour le monde";

    cr_assert_eq(my_strncmp(find1, find2, 5), 0);
    cr_assert_eq(my_strncmp(find1, find2, 10), -32);
    cr_assert_eq(my_strncmp(find3, find2, 8), -119);
    cr_assert_eq(my_strncmp(find3, find2, 6), 0);
    cr_assert_eq(my_strncmp(find3, find4, 5), 72);
    cr_assert_eq(my_strncmp(find1, find2, 20), -32);
}
