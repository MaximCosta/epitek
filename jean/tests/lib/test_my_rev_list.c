/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include "mylist.h"

void my_rev_list(linked_list_t **begin);
linked_list_t *my_params_to_list(int ac, char * const *av);

Test(my_rev_list, reverse_list)
{
    char *av[] = {"./a.out", "test", "arg2", "arg3"};
    linked_list_t *list = my_params_to_list(4, av);

    my_rev_list(&list);
    for (int i = 0; i < 4; i++) {
        cr_assert_str_eq((char*) list->data, av[i]);
        list = list->next;
    }
}
