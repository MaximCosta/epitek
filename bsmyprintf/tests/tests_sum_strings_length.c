/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-bsmyprintf-maxim.costa
** File description:
** tests_sum_strings_length
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/bsprintf.h"

Test(sum_strings_length, sum_str_lengths)
{
    int value = sum_strings_length(5, "Hello", "a", "toto", "", "plop");
    cr_assert_eq(value, 14);
}