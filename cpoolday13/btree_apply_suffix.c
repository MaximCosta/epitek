/*
** EPITECH PROJECT, 2021
** btree_apply_suffix
** File description:
** csfml is the best thing ever
*/

#include "include/btree.h"

void btree_apply_suffix(btree_t *root, int (*applyf)(void*))
{
    if (root != 0) {
        btree_apply_suffix(root->left, applyf);
        btree_apply_suffix(root->right, applyf);
        (*applyf)(root->item);
    }
}
