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

Test(eval_expr, test_substraction11, .init=redirect_all_stdout)
{
    char s[] = "-1-9999999999999999999999999999999999999999999999999999999999";
    char r[] = "-10000000000000000000000000000000000000000000000000000000000";

    my_putstr(eval_expr("0123456789", "()+-*/%", s, 61));
    cr_assert_stdout_eq_str(r);
}

Test(eval_expr, test_substraction12, .init=redirect_all_stdout)
{
    char s[] = "99999999999999999999999999999999999999999999999999999999999-1";
    char r[] = "99999999999999999999999999999999999999999999999999999999998";

    my_putstr(eval_expr("0123456789", "()+-*/%", s, 61));
    cr_assert_stdout_eq_str(r);
}

Test(eval_expr, test_substraction13, .init=redirect_all_stdout)
{
    char s[] = "12764827412078461289745201784629842619845120874601294612874520\
714612098-1247606126412948126497124601298460129846208714112487652412785";
    char r[] = "12764827410830855163332253658132718018546660744755085898762033\
062199313";

    my_putstr(eval_expr("0123456789", "()+-*/%", s, 133));
    cr_assert_stdout_eq_str(r);
}

Test(eval_expr, test_substraction14, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "-3-(-2)", 7));
    cr_assert_stdout_eq_str("-1");
}
