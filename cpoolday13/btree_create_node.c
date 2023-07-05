/*
** EPITECH PROJECT, 2021
** btree_create_node
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#include "include/btree.h"
#include <stdlib.h>

btree_t *btree_create_node(void *item)
{
    btree_t *node = malloc(sizeof(btree_t));

    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
}
