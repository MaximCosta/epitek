/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include "my_all.h"

Test(my_sort_list, sort_list)
{
    char *av[] = {"8", "4", "7", "1", "9", "0"};
    char *av2[] = {"0", "1", "4", "7", "8", "9"};
    linked_list_t *list = my_params_to_list(6, av);
    int i = 0;

    my_sort_list(&list, my_strcmp);
    while (list && av2[i]) {
        cr_assert_str_eq((char*) list->data, av2[i]);
        list = list->next;
        i++;
    }
}
