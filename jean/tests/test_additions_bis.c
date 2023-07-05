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

Test(eval_expr, test_addition6, .init=redirect_all_stdout)
{
    char expr[] = "99999999999999999999999999999999999999999999999999999999+\
22222222222222222222222222222222222222222222222222222222222222222222\
222222222222";

    my_putstr(eval_expr("0123456789", "()+-*/%", (char*) expr, 137));
    cr_assert_stdout_eq_str("222222222222222222222223222222222222222222222222\
22222222222222222222222222222221");
}

Test(eval_expr, test_addition7, .init=redirect_all_stdout)
{
    char expr[] = "5126748128762421244912841241278945921874128954297186428164\
521894612+65837698236081276408658360126049127496127846187520916491264\
78589214627164897252";

    my_putstr(eval_expr("0123456789", "()+-*/%", (char*) expr, 147));
    cr_assert_stdout_eq_str("658376982361325438899459843384982559085406356467\
3965778080775775642791686791864");
}

Test(eval_expr, test_addition8, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "-7+21", 5));
    cr_assert_stdout_eq_str("14");
}
