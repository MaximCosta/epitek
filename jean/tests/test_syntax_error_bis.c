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

Test(eval_expr, eval_expr6, .init=redirect_all_stdout, .exit_code = 84)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "4+ 2", 4));
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, eval_expr7, .init=redirect_all_stdout, .exit_code = 84)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "4a+2", 4));
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, eval_expr8, .init=redirect_all_stdout, .exit_code = 84)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "4(2+1)", 6));
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, eval_expr9, .init=redirect_all_stdout, .exit_code = 84)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "(2+1)4", 6));
    cr_assert_stderr_eq_str("syntax error");
}
