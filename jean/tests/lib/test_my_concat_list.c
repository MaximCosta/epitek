/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include "mylist.h"

Test(my_concat_list, concat_list)
{
    char *av1[] = {"test", "./a.out", "test1"};
    char *av2[] = {"arg2", "arg3", "test2"};
    char *av3[] = {"test1", "./a.out", "test",
        "test2", "arg3", "arg2"};
    linked_list_t *list1 = my_params_to_list(3, av1);
    linked_list_t *list2 = my_params_to_list(3, av2);
    int i = 0;

    my_concat_list(&list1, list2);
    while (list1 && av3[i]) {
        cr_assert_str_eq((char*)list1->data, av3[i]);
        list1 = list1->next;
        i++;
    }
}
