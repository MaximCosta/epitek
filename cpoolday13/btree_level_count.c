/*
** EPITECH PROJECT, 2021
** btree_level_count
** File description:
** C-x C-c
*/

#include "include/btree.h"
#include <stdlib.h>

static int get_max(int s1, int s2)
{
    if (s1 >= s2)
        return s1;
    else
        return s2;
}

size_t btree_level_count(btree_t const *root)
{
    int s1;
    int s2;

    if (root == 0)
        return 0;
    s1 = btree_level_count(root->left);
    s2 = btree_level_count(root->right);
    return 1 + get_max(s1, s2);
}
