/*
** EPITECH PROJECT, 2021
** tests/test_my_putnbr_base
** File description:
** test unit base number
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_putnbr_base(int nbr, char const *base);

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(my_putnbr_base, convert_to_base, .init=redirect_all_stdout)
{
    char dest[] = "01";

    my_putnbr_base(29, dest);
    cr_assert_stdout_neq_str("11101");
}

