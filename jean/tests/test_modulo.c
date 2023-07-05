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

Test(eval_expr, test_modulo1, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "6%2", 3));
    cr_assert_stdout_eq_str("0");
}

Test(eval_expr, test_modulo2, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "2%10", 4));
    cr_assert_stdout_eq_str("2");
}

Test(eval_expr, test_modulo3, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "100%4", 5));
    cr_assert_stdout_eq_str("0");
}

Test(eval_expr, test_modulo4, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "99%2", 4));
    cr_assert_stdout_eq_str("1");
}

Test(eval_expr, test_modulo5, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "99%99", 5));
    cr_assert_stdout_eq_str("0");
}
