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

Test(eval_expr, test_division6, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "-99/5", 5));
    cr_assert_stdout_eq_str("-19");
}

Test(eval_expr, test_division7, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "-100/-6", 7));
    cr_assert_stdout_eq_str("16");
}

Test(eval_expr, test_division8, .init=redirect_all_stdout)
{
    char s[] = "99999999999999999999999999999999999999999999999999/22222222222\
222222222222222222222222222222222222222";

    my_putstr(eval_expr("0123456789", "()+-*/%", s, 101));
    cr_assert_stdout_eq_str("4");
}

Test(eval_expr, test_division9, .init=redirect_all_stdout)
{
    char s[] = "53287632572309573276537265092387529108652716490217508376595861\
9735783269562109874921861297664298769874621987642/1246912874601294628648937648\
736764376534726897469126412604926142816482154785276814527816489216";

    my_putstr(eval_expr("0123456789", "()+-*/%", s, 206));
    cr_assert_stdout_eq_str("427356503070421071");
}

Test(eval_expr, test_division10, .init=redirect_all_stdout)
{
    char s[] = "-5328763257230957327653726509238752910865271649021750837659586\
19735783269562109874921861297664298769874621987642/124691287460129462864893764\
8736764376534726897469126412604926142816482154785276814527816489216";

    my_putstr(eval_expr("0123456789", "()+-*/%", s, 207));
    cr_assert_stdout_eq_str("-427356503070421071");
}
