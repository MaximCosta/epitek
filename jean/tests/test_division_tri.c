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

Test(eval_expr, test_division11, .init=redirect_all_stdout, .exit_code = 84)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "42/0", 4));
    cr_assert_stderr_eq_str("error");
}

Test(eval_expr, test_division12, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "10/(-3)", 7));
    cr_assert_stdout_eq_str("-3");
}
