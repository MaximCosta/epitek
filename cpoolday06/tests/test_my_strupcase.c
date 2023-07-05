/*
** EPITECH PROJECT, 2021
** test_my_strupcase
** File description:
** strupcase unit test
*/

#include <criterion/criterion.h>

int my_strupcase(char const *str);

Test(my_strupcase, toupper_1)
{
    char dest[] = "HelloWoLrd";

    my_strupcase(dest);
    cr_assert_str_eq(dest, "HELLOWOLRD");
}
