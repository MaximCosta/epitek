/*
** EPITECH PROJECT, 2021
** test_my_strlowcase
** File description:
** to lower unit test
*/

#include <criterion/criterion.h>

int my_strlowcase(char const *str);

Test(my_strlowcase, tolower_1)
{
    char dest[] = "HelloWorLd";

    my_strlowcase(dest);
    cr_assert_str_eq(dest, "helloworld");
}
