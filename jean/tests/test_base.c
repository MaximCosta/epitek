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

Test(eval_expr, test_base1, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("01", "()+-*/%", "10101*10", 8));
    cr_assert_stdout_eq_str("101010");
}

Test(eval_expr, test_base2, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789abcdef", "()+-*/%", "ab+cd", 5));
    cr_assert_stdout_eq_str("178");
}

Test(eval_expr, test_base3, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0A@!;ie& ]", "()+-*/%", "-(e@-(;*!@))", 12));
    cr_assert_stdout_eq_str("ee");
}

Test(eval_expr, test_base4, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "[]+-(/%", "5(10", 4));
    cr_assert_stdout_eq_str("50");
}
