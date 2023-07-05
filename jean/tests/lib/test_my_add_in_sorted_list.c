/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include "mylist.h"

void my_sort_list(linked_list_t **begin, int (*cmp)());
linked_list_t *my_params_to_list(int ac, char * const *av);
int my_strcmp(char const *s1, char const *s2);
void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)());

Test(my_add_in_sorted_list, add_in_sorted_list)
{
    char *av[] = {"8", "4", "7", "1", "8", "1"};
    char *av2[] = {"0", "1", "1", "4", "5", "7", "8", "8", "9"};
    char nbr1[] = "5";
    char nbr2[] = "0";
    char nbr3[] = "9";
    linked_list_t *list = my_params_to_list(6, av);
    int i = 0;

    my_sort_list(&list, my_strcmp);
    my_add_in_sorted_list(&list, nbr1, my_strcmp);
    my_add_in_sorted_list(&list, nbr2, my_strcmp);
    my_add_in_sorted_list(&list, nbr3, my_strcmp);
    while (list && av2[i]) {
        cr_assert_str_eq((char*) list->data, av2[i]);
        list = list->next;
        i++;
    }
}
