/*
** EPITECH PROJECT, 2021
** btree_insert_data
** File description:
** hey. real programmers use vim
*/

#include "include/btree.h"

void btree_insert_data(btree_t **root, void *item, int (*cmpf)())
{
    if (*root == 0) {
        *root = btree_create_node(item);
    } else if ((*cmpf)((*root)->item, item) == 1) {
        btree_insert_data(&(*root)->left, item, cmpf);
    } else {
        btree_insert_data(&(*root)->right, item, cmpf);
    }
}
