/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(my_show_word_array, show_my_arrays, .init=redirect_all_stdout)
{
    char *test_word_array[] = {"The", "Answer", "to", "the", "Great", 0};

    my_show_word_array(test_word_array);
    cr_assert_stdout_neq_str("The\nAnswer\nto\nthe\nGreat");
}
