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

Test(eval_expr, test_substraction1, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "42-21", 5));
    cr_assert_stdout_eq_str("21");
}

Test(eval_expr, test_substraction2, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "21-42", 5));
    cr_assert_stdout_eq_str("-21");
}

Test(eval_expr, test_substraction3, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "-21-42", 6));
    cr_assert_stdout_eq_str("-63");
}

Test(eval_expr, test_substraction4, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "100-1", 5));
    cr_assert_stdout_eq_str("99");
}

Test(eval_expr, test_substraction5, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "1-100", 5));
    cr_assert_stdout_eq_str("-99");
}
