/*
** EPITECH PROJECT, 2021
** tests/tests_cat
** File description:
** C-x C-c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int cat(int ac, char **av);
int errors_print(int i, char **av, int ev);

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(errors, exit_code_0, .init=redirect_all_stdout)
{
        char *params[1] = {"does"};
        cat(1, params);
        cr_assert_stderr_eq_str("does No such file or directory", "");
}

Test(errors, exit_code_1, .init=redirect_all_stdout)
{
        char *params[1] = {"/root"};
        cat(1, params);
        cr_assert_stderr_eq_str("does No such file or directory", "");
}
