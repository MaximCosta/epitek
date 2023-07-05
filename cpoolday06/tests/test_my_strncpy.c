/*
** EPITECH PROJECT, 2021
** test_my_strncpy
** File description:
** Test unit strncpy
*/

#include <criterion/criterion.h>

char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, strncpy_1)
{
    char dest[6] = { 0 };

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}
