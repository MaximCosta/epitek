/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-maxim.costa [WSL: Ubuntu]
** File description:
** bsq
*/

#ifndef BSQ_H_
    #define BSQ_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
typedef struct {
    int size_y;
    int size_x;
    int max;
    int size;
    int find;
    int *buf;
    char *cbuf;
} bsq_file;
int get_size(int fd, int *x_size);
bsq_file *init_bsq_file(char **av, int fd);
void map_2d_array(bsq_file *st_bsq, int fd);
void draw_square(bsq_file *st_bsq);
void bc_bsq(bsq_file *st_bsq);
void bsq(bsq_file *st_bsq, int x);
int get_min(bsq_file *st_bsq, int x);
#endif
