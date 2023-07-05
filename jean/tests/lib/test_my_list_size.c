/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include "mylist.h"

Test(my_list_size, size_of_list)
{
    char *av[] = {"./a.out", "test", "arg2", "arg3"};
    linked_list_t *list = my_params_to_list(4, av);

    cr_assert_eq(my_list_size(list), 4);
}
