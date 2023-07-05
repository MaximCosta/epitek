/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include "my_all.h"

int my_advanced_sort_word_array(char **t, int (*c)(char const *, char const *));

Test(my_advanced_sort_word_array, sort_char_tab)
{
    char str[] = "Ceci est un test, va til marcher";
    char **tab = my_str_to_word_array(str);
    char *result[] = {"Ceci", "est", "marcher",
        "test", "til", "un", "va"};
    int i = 0;

    my_advanced_sort_word_array(tab, &my_strcmp);
    while (*tab) {
        cr_assert_str_eq(*tab++, result[i]);
        i++;
    }
}
