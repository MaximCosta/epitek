/*
** EPITECH PROJECT, 2021
** btree_search_item
** File description:
** you're a bad developer
*/

#include "include/btree.h"
#include <stdlib.h>

void *btree_search_item(btree_t const *root, void const *data_ref, 
        int (*cmpf)())
{
    if (root != 0) {
        if ((*cmpf)(root->item, data_ref) == 0)
            return root->item;
        if ((*cmpf)(root->item, data_ref) == 1)
            return btree_search_item(root->left, data_ref, cmpf);
        if ((*cmpf)(root->item, data_ref) == -1)
            return btree_search_item(root->right, data_ref, cmpf);
    } else {
        return NULL;
    }
}
