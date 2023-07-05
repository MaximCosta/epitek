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

Test(eval_expr, test_eval_expr1, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "3+4*2", 5));
    cr_assert_stdout_eq_str("11");
}

Test(eval_expr, test_eval_expr2, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "3*4+2", 5));
    cr_assert_stdout_eq_str("14");
}

Test(eval_expr, test_eval_expr3, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "3-4-2", 5));
    cr_assert_stdout_eq_str("-3");
}

Test(eval_expr, test_eval_expr4, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "--++-6*12", 9));
    cr_assert_stdout_eq_str("-72");
}

Test(eval_expr, test_eval_expr5, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "6*--++-12", 9));
    cr_assert_stdout_eq_str("-72");
}
