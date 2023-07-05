/*
** EPITECH PROJECT, 2021
** test_my_strncmp
** File description:
** strcmp test unite
*/

#include <criterion/criterion.h>

int my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, my_strcmp_1)
{
    char s1[] = "maXim";
    char s2[] = "maxim";

    my_strcmp(s1, s2);
    cr_assert_eq(my_strcmp(s1, s2), 1);
}

Test(my_strcmp, my_strcmp_2)
{
    char s1[] = "maxi";
    char s2[] = "maXim";

    my_strcmp(s1, s2);
    cr_assert_eq(my_strcmp(s1, s2), -1);
}

Test(my_strcmp, my_strcmp_3)
{
    char s1[] = "maxim";
    char s2[] = "maxim";

    my_strcmp(s1, s2);
    cr_assert_eq(my_strcmp(s1, s2), 0);
}
