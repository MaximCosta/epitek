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

Test(eval_expr, test_substraction6, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "100-95", 6));
    cr_assert_stdout_eq_str("5");
}

Test(eval_expr, test_substraction7, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "42-35", 5));
    cr_assert_stdout_eq_str("7");
}

Test(eval_expr, test_substraction8, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "35-42", 5));
    cr_assert_stdout_eq_str("-7");
}

Test(eval_expr, test_substraction9, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "42--21", 6));
    cr_assert_stdout_eq_str("63");
}

Test(eval_expr, test_substraction10, .init=redirect_all_stdout)
{
    char s[] = "1-99999999999999999999999999999999999999999999999999999999999";
    char r[] = "-99999999999999999999999999999999999999999999999999999999998";

    my_putstr(eval_expr("0123456789", "()+-*/%", s, 61));
    cr_assert_stdout_eq_str(r);
}
