/*
** EPITECH PROJECT, 2021
** btree_apply_prefix
** File description:
** check your malloc!
*/

#include "include/btree.h"

void btree_apply_prefix(btree_t *root, int (*applyf)(void*))
{
    if (root != 0) {
        (*applyf)(root->item);
        btree_apply_prefix(root->left, applyf);
        btree_apply_prefix(root->right, applyf);
    }
}
