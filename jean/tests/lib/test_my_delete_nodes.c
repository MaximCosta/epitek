/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include "my_all.h"

Test(my_delete_nodes, delete_nodes_data)
{
    char *av[] = {"test", "./a.out", "test", "arg2", "arg3", "test"};
    char *av2[] = {"arg3", "arg2", "./a.out"};
    char *av3[] = {"test", "test"};
    char data[] = "test";
    linked_list_t *list = my_params_to_list(6, av);
    linked_list_t *list2 = my_params_to_list(2, av3);
    int i = 0;

    my_delete_nodes(&list, data, &my_strcmp);
    my_delete_nodes(&list2, data, &my_strcmp);
    while (list && av2[i]) {
        cr_assert_str_eq((char*) list->data, av2[i]);
        list = list->next;
        i++;
    }
    cr_assert_null(list2);
}
