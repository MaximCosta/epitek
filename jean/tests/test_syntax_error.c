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

Test(eval_expr, eval_expr1, .init=redirect_all_stdout, .exit_code = 84)
{
    eval_expr("012345678+", "()+-*/%", "4+2", 3);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, eval_expr2, .init=redirect_all_stdout, .exit_code = 84)
{
    my_putstr(eval_expr("0123456799", "()+-*/%", "4+2", 3));
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, eval_expr3, .init=redirect_all_stdout, .exit_code = 84)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "(4+2", 4));
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, eval_expr4, .init=redirect_all_stdout, .exit_code = 84)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "4+2)", 4));
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, eval_expr5, .init=redirect_all_stdout, .exit_code = 84)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "4+*2", 4));
    cr_assert_stderr_eq_str("syntax error");
}
