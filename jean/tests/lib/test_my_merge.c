/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include "my_all.h"

Test(my_merge, test_my_merge)
{
    char *av1[] = {"8", "6", "3", "1"};
    char *av2[] = {"9", "3", "2", "0"};
    char *av3[] = {"0", "1", "2", "3", "3", "6", "8", "9"};
    linked_list_t *list1 = my_params_to_list(4, av1);
    linked_list_t *list2 = my_params_to_list(4, av2);
    int i = 0;

    my_merge(&list1, list2, my_strcmp);
    while (list1 && av3[i]) {
        cr_assert_str_eq((char*) list1->data, av3[i]);
        list1 = list1->next;
        i++;
    }
}
