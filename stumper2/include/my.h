/*
** EPITECH PROJECT, 2022
** Stumper 2
** File description:
** Game of life
*/

#ifndef __MY_H__
    #define __MY_H__
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>

char *load_file_in_mem(char *fp);
char **str_to_array(char *buffer, int cols, int rows);
void free_map(char **map);
int check_file(char *str);
int check_lines(char *buffer);
int count_rows(char *buffer);
int count_cols(char *buffer);
int life_algo(char **map, char **new_map, int y, int x);
int life_algo_replace(char s, int nb);
int ck(char **map, int y, int x);
int life_algo_loop(char **map, int size_y, int size_x);
int life_algo_main(char **map, int nb_loop, int size_y, int size_x);
char **strdup_2d(char **map, int size_y, int size_x);
#endif
