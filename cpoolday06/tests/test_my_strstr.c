/*
** EPITECH PROJECT, 2021
** test_my_strstr
** File description:
** StrStr test unite
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, compare_length_1)
{
    char dest[] = "HelloWorld";

    my_strstr("ll", dest);
    cr_assert_str_eq(my_strstr("ll", dest), "lloWorld");
}

Test(my_strstr, compare_length_2)
{
    char dest[] = "HelloWorld";

    my_strstr("aa", dest);
    cr_assert_str_eq(my_strstr("ll", dest), 0);
}

Test(my_strstr, compare_length_3)
{
    char dest[] = "";

    my_strstr("aa", dest);
    cr_assert_str_eq(my_strstr("ll", dest), 0);
}
