/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_stdout(void);
char *eval_expr(char const *base, char const *ops,
    char const *expr, unsigned int size);

Test(eval_expr, test_multiplication1, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "2*3", 3));
    cr_assert_stdout_eq_str("6");
}

Test(eval_expr, test_multiplication2, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "4*5", 3));
    cr_assert_stdout_eq_str("20");
}

Test(eval_expr, test_multiplication3, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "5*200", 5));
    cr_assert_stdout_eq_str("1000");
}

Test(eval_expr, test_multiplication4, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "99*99", 5));
    cr_assert_stdout_eq_str("9801");
}

Test(eval_expr, test_multiplication5, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "-4*25", 5));
    cr_assert_stdout_eq_str("-100");
}
