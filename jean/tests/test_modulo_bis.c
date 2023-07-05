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

Test(eval_expr, test_modulo6, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "-99%5", 5));
    cr_assert_stdout_eq_str("-4");
}

Test(eval_expr, test_modulo7, .init=redirect_all_stdout)
{
    my_putstr(eval_expr("0123456789", "()+-*/%", "-100%-6", 7));
    cr_assert_stdout_eq_str("-4");
}

Test(eval_expr, test_modulo8, .init=redirect_all_stdout)
{
    char s[] = "99999999999999999999999999999999999999999999999999%22222222222\
222222222222222222222222222222222222222";
    char r[] = "11111111111111111111111111111111111111111111111111";

    my_putstr(eval_expr("0123456789", "()+-*/%", s, 101));
    cr_assert_stdout_eq_str(r);
}

Test(eval_expr, test_modulo9, .init=redirect_all_stdout)
{
    char s[] = "53287632572309573276537265092387529108652716490217508376595861\
9735783269562109874921861297664298769874621987642%1246912874601294628648937648\
736764376534726897469126412604926142816482154785276814527816489216";
    char r[] = "92016717695868382735940627546950693279789919135842608627813362\
9785907078296694601764571317306";

    my_putstr(eval_expr("0123456789", "()+-*/%", s, 206));
    cr_assert_stdout_eq_str(r);
}

Test(eval_expr, test_modulo10, .init=redirect_all_stdout)
{
    char s[] = "-5328763257230957327653726509238752910865271649021750837659586\
19735783269562109874921861297664298769874621987642%124691287460129462864893764\
8736764376534726897469126412604926142816482154785276814527816489216";
    char r[] = "-9201671769586838273594062754695069327978991913584260862781336\
29785907078296694601764571317306";

    my_putstr(eval_expr("0123456789", "()+-*/%", s, 207));
    cr_assert_stdout_eq_str(r);
}
