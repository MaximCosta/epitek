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

Test(eval_expr, test_addition1, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "21+21", 5));
    cr_assert_stdout_eq_str("42");
}

Test(eval_expr, test_addition2, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "18+24", 5));
    cr_assert_stdout_eq_str("42");
}

Test(eval_expr, test_addition3, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "100+1", 5));
    cr_assert_stdout_eq_str("101");
}

Test(eval_expr, test_addition4, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "1+100", 5));
    cr_assert_stdout_eq_str("101");
}

Test(eval_expr, test_addition5, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "9999999+1", 9));
    cr_assert_stdout_eq_str("10000000");
}
