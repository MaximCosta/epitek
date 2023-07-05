/*
** EPITECH PROJECT, 2021
** test_my_strncmp
** File description:
** strncmp test unite
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, my_strncmp_1)
{
    char s1[] = "maXim";
    char s2[] = "maxim";

    my_strncmp(s1, s2, 4);
    cr_assert_eq(my_strncmp(s1, s2, 4), 1);
}

Test(my_strncmp, my_strncmp_2)
{
    char s1[] = "maxim";
    char s2[] = "maXim";

    my_strncmp(s1, s2, 4);
    cr_assert_eq(my_strncmp(s1, s2, 4), -1);
}

Test(my_strncmp, my_strncmp_3)
{
    char s1[] = "maxi";
    char s2[] = "maxim";

    my_strncmp(s1, s2, 4);
    cr_assert_eq(my_strncmp(s1, s2, 4), 0);
}
