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

Test(eval_expr, test_eval_expr6, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "--+++++--6*--++--12", 19));
    cr_assert_stdout_eq_str("72");
}

Test(eval_expr, test_eval_expr7, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "(2+5)*2", 7));
    cr_assert_stdout_eq_str("14");
}

Test(eval_expr, test_eval_expr8, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "(18+42)+5*42", 12));
    cr_assert_stdout_eq_str("270");
}

Test(eval_expr, test_eval_expr9, .init=redirect_all_stdout)
{
    char s[] = "5+(((((2+4)*8+50*(10+1))+20)-42)+3*2)";

    my_putstr(eval_expr("0123456789", "()+-*/%", s, 37));
    cr_assert_stdout_eq_str("587");
}

Test(eval_expr, test_eval_expr10, .init=redirect_all_stdout)
{
    char s[] = "(-((5+(((((2+4)*8+50*(10+1))+20)-42)+3*2))))";

    my_putstr(eval_expr("0123456789", "()+-*/%", s, 44));
    cr_assert_stdout_eq_str("-587");
}
