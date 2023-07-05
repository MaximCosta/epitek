/*
** EPITECH PROJECT, 2021
** main
** File description:
** fireplace 4k
*/

#include "include/my.h"
#include "include/bsq.h"

int get_size(int fd, int *x_size)
{
    char arr[1];
    int size = 0;

    while (read(fd, arr, 1) == 1 && arr[0] != '\n') {
        size = size * 10 + NUM(arr[0]);
        (*x_size)--;
    }
    (*x_size)--;
    return size;
}

bsq_file *init_bsq_file(char **av, int fd)
{
    bsq_file *st_bsq = malloc(sizeof(bsq_file));
    struct stat st;

    stat(av[1], &st);
    st_bsq->size_x = st.st_size;
    st_bsq->size_y = get_size(fd, &st_bsq->size_x);
    st_bsq->size = st_bsq->size_x - 1;
    st_bsq->size_x = (st_bsq->size_x - st_bsq->size_y) / st_bsq->size_y;
    if (st_bsq->size_x == 0 || st_bsq->size_y == 0 || st_bsq->size == 0)
        my_exit(84, "size Invalide");
    st_bsq->find = 0;
    st_bsq->max = 0;
    return st_bsq;
}

void map_2d_array(bsq_file *st_bsq, int fd)
{
    st_bsq->buf = my_calloc(sizeof(int), -1,
        st_bsq->size_y * st_bsq->size_x + 1);
    st_bsq->cbuf = my_calloc(sizeof(char), 0, st_bsq->size);
    read(fd, st_bsq->cbuf, st_bsq->size);
    for (int y = 0, i = 0; y < st_bsq->size; y++) {
        if (st_bsq->cbuf[y] == '.')
            st_bsq->buf[i++] = 1;
        if (st_bsq->cbuf[y] == 'o')
            st_bsq->buf[i++] = 0;
    }
}

void draw_square(bsq_file *st_bsq)
{
    int cons = st_bsq->find / st_bsq->size_x;

    for (int y = 0; y < st_bsq->max; y++) {
        for (int x = 0; x < st_bsq->max; x++, st_bsq->find -= 1)
            st_bsq->cbuf[st_bsq->find + cons] = 'x';
        st_bsq->find -= (st_bsq->size_x - st_bsq->max + 1);
    }
}

int main(int ac, char **av)
{
    int fd;
    bsq_file *st_bsq = NULL;

    if (ac != 2)
        my_exit(84, "Argument invalide");
    if ((fd = open(av[1], O_RDONLY)) == -1)
        my_exit(84, "open file failed");
    st_bsq = init_bsq_file(av, fd);
    map_2d_array(st_bsq, fd);
    bc_bsq(st_bsq);
    draw_square(st_bsq);
    write(1, st_bsq->cbuf, st_bsq->size);
    my_putchar('\n');
    free(st_bsq->buf);
    free(st_bsq->cbuf);
    free(st_bsq);
    close(fd);
}
