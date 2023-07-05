/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-maxim.costa [WSL: Ubuntu]
** File description:
** bsq
*/

#include "include/my.h"
#include "include/bsq.h"

void bc_bsq(bsq_file *st_bsq)
{
    for (int x = 0; x < st_bsq->size_y * st_bsq->size_x; x++)
        bsq(st_bsq, x);
}

int get_min(bsq_file *st_bsq, int x)
{
    int cord[3][2] = {
        {x - 1, 0},
        {x - st_bsq->size_x, 0},
        {x - st_bsq->size_x - 1, 0}
    };

    if (cord[0][0] / st_bsq->size_x != x / st_bsq->size_x)
        return 0;
    for (int i = 0; i < 3; i++)
        if (0 <= cord[i][0] && cord[i][0] <= st_bsq->size_x * st_bsq->size_y)
            cord[i][1] = st_bsq->buf[cord[i][0]];
    return MIN(MIN(cord[0][1],cord[1][1]), cord[2][1]);
}

void bsq(bsq_file *st_bsq, int x)
{
    if (st_bsq->buf[x] > 0) {
        st_bsq->buf[x] = get_min(st_bsq, x) + 1;
        if (st_bsq->buf[x] > st_bsq->max) {
            st_bsq->max = st_bsq->buf[x];
            st_bsq->find = x;
        }
    }
}
