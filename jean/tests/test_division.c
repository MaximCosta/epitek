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

Test(eval_expr, test_division1, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "6/2", 3));
    cr_assert_stdout_eq_str("3");
}

Test(eval_expr, test_division2, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "2/10", 4));
    cr_assert_stdout_eq_str("0");
}

Test(eval_expr, test_division3, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "100/4", 5));
    cr_assert_stdout_eq_str("25");
}

Test(eval_expr, test_division4, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "99/2", 4));
    cr_assert_stdout_eq_str("49");
}

Test(eval_expr, test_division5, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "99/99", 5));
    cr_assert_stdout_eq_str("1");
}
